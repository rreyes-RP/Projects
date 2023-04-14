//
//  GameViewController.swift
//  PlusOne
//
//  Created by Rorie Reyes on 2/24/23.
//

import UIKit
import InstantSearchVoiceOverlay

class GameViewController: UIViewController, VoiceOverlayDelegate {
    let voiceOverlay = VoiceOverlayController()
    
    @IBOutlet var myButton: UIButton!
    @IBOutlet weak var numbersLabel:UILabel?
    @IBOutlet weak var scoreLabel:UILabel?
    @IBOutlet weak var inputField:UITextField?
    @IBOutlet weak var rightOrWrongLabel:UILabel?
    @IBOutlet weak var plusOrMinusOneLabel:UILabel?
    @IBOutlet weak var timeLabel:UILabel?
    
    var arrScore = [Int](repeating: 0, count: 10)
    var score:Int = 0
    var answer:String = ""
    var getScore:String = ""
    var timer:Timer?
    var seconds: Int = 15
    
    /**
     * Generated buttons to act as number inputs and delete in replacement of keyboard
     */
    @IBAction func button0Tap(_ sender: UIButton) {
        if inputField?.text?.count ?? 0 < 4 {
            inputField?.text?.append("0")
            return
        }
        
        textFieldDidChange(textField:UITextField())
    }
    
    @IBAction func button1Tap(_ sender: UIButton) {
        if inputField?.text?.count ?? 0 < 4 {
            inputField?.text?.append("1")
            return
        }
        
        textFieldDidChange(textField:UITextField())
    }
    
    @IBAction func button2Tap(_ sender: UIButton) {
        if inputField?.text?.count ?? 0 < 4 {
            inputField?.text?.append("2")
            return
        }
        
        textFieldDidChange(textField:UITextField())
    }
    
    @IBAction func button3Tap(_ sender: UIButton) {
        if inputField?.text?.count ?? 0 < 4 {
            inputField?.text?.append("3")
            return
        }
        
        textFieldDidChange(textField:UITextField())
    }
    
    @IBAction func button4Tap(_ sender: UIButton) {
        if inputField?.text?.count ?? 0 < 4 {
            inputField?.text?.append("4")
            return
        }
        
        textFieldDidChange(textField:UITextField())
    }
    
    @IBAction func button5Tap(_ sender: UIButton) {
        if inputField?.text?.count ?? 0 < 4 {
            inputField?.text?.append("5")
            return
        }
        
        textFieldDidChange(textField:UITextField())
    }
    
    @IBAction func button6Tap(_ sender: UIButton) {
        if inputField?.text?.count ?? 0 < 4 {
            inputField?.text?.append("6")
            return
        }
        
        textFieldDidChange(textField:UITextField())
    }
    
    @IBAction func button7Tap(_ sender: UIButton) {
        if inputField?.text?.count ?? 0 < 4 {
            inputField?.text?.append("7")
            return
        }
        
        textFieldDidChange(textField:UITextField())
    }
    
    @IBAction func button8Tap(_ sender: UIButton) {
        if inputField?.text?.count ?? 0 < 4 {
            inputField?.text?.append("8")
            return
        }
        
        textFieldDidChange(textField:UITextField())
    }
    
    @IBAction func button9Tap(_ sender: UIButton) {
        if inputField?.text?.count ?? 0 < 4 {
            inputField?.text?.append("9")
            return
        }
        
        textFieldDidChange(textField:UITextField())
    }
    
    @IBAction func buttonEnterTap(_ sender: Any) {
        if inputField?.text?.count ?? 0 < 4 {
            inputField?.text?.append("0")
            return
        }
        
        textFieldDidChange(textField:UITextField())
    }
    
    @IBAction func buttonDeleteTap(_ sender: Any) {
        if var text = inputField?.text, !text.isEmpty {
            text.removeLast()
            inputField?.text = text
        }
    }
    
    /**
     * Micrphone button
     */
    @IBAction func didTapButton() {
        voiceOverlay.delegate = self
        voiceOverlay.settings.autoStart = false
        voiceOverlay.settings.autoStop = true
        voiceOverlay.settings.autoStopTimeout = 0.5
        voiceOverlay.start(on: self, textHandler: { text, final, _ in
            if final {
                let digitsOnly = text.filter { $0.isNumber }
                print("Final text: \(text)")
                self.inputField?.text?.append("\(digitsOnly)")
            }

        }, errorHandler: { error in })
        
        
    }
    
    override func viewDidLoad() {
        
        super.viewDidLoad()
        myButton.backgroundColor = .systemCyan
        myButton.setTitleColor(.white, for: .normal)
        setRandNumLabel()
        updateScoreLabel()
        inputField?.addTarget(self, action: #selector(textFieldDidChange(textField:)), for: UIControl.Event.editingChanged)
        becomeFirstResponder()
    }
    
    /**
     * Updates the score label on the top left
     */
    func updateScoreLabel() {
        scoreLabel?.text = "\(score)"
    }
    
    /**
     * Updates the timer label on the top right
     */
    func updateTimeLabel() {
        
        if (timeLabel != nil) {
            
            let min:Int = (seconds / 60) % 60
            let sec:Int = seconds % 60
            
            let min_p:String = String(format: "%02d", min)
            let sec_p:String = String(format: "%02d", sec)
            
            timeLabel!.text = "\(min_p):\(sec_p)"
        }
    }
    
    /**
     * Sets the random 4 digit number in the yellow text box for the user to answer
     */
    func setRandNumLabel() {
        numbersLabel?.text = generateRandString()
    }
    
    /**
     * Label to show Correct or Incorrect notification after answer is submitted
     */
    func updateCorrectIncorrect() {
        rightOrWrongLabel?.text = "\(answer)"
    }
    
    /**
     * Label to show whether the score is plus 1 or minus 1
     */
    func updatePlusOrMinusOne() {
        plusOrMinusOneLabel?.text = "\(getScore)"
    }
    
    /**
     * Updates the input text field when 4 digits is reached
     * Once 4 digit max is reached, must press enter, and the answer will be submitted
     * Text box will will reset to blank after 0.1 seconds
     */
    @objc func textFieldDidChange(textField:UITextField) {
        
        if let numbers_text = numbersLabel?.text,
           let input_text = inputField?.text,
           let numbers = Int(numbers_text),
           let input = Int(input_text)
        {
            print("Comparing: \(input_text) minus \(numbers_text) == \(input - numbers)")
            
            /**
             * Checks if the answer is correct or incorrect by making sure the difference is 1111
             */
            if (input - numbers == 1111) {
                print("Correct!")
                answer = "Correct!"
                getScore = "+1"
                score += 1
            }
            
            else {
                print("Incorect!")
                answer = "Incorrect!"
                getScore = "-1"
                score -= 1
            }
            
            DispatchQueue.main.asyncAfter(deadline: .now() + 0.1) {
                self.inputField?.text = ""
            }
            
            DispatchQueue.main.asyncAfter(deadline: .now() + 1) {
                self.rightOrWrongLabel?.text = ""
                self.plusOrMinusOneLabel?.text = ""
            }
        }
        
        setRandNumLabel()
        updateScoreLabel()
        updateCorrectIncorrect()
        updatePlusOrMinusOne()
        
        if(timer == nil) {
            timer = Timer.scheduledTimer(timeInterval: 1.0, target: self, selector: #selector(onUpdateTimer), userInfo: nil, repeats: true)
        }
    }
    
    /**
     * Timer for the game
     * Keeps track of the final score
     * Saves the score in a top ten array for the High Score View
     */
    @objc func onUpdateTimer() -> Void {
        if(seconds > 0 && seconds <= 15) {
            
            seconds -= 1
            
            updateTimeLabel()
        }
        
        else if (seconds == 0) {
            
            if (timer != nil) {
                
                timer!.invalidate()
                timer = nil
                
                let gameOver = UIAlertController(title: "Times Up!",
                                                 message: "Your score: \(score) points", preferredStyle: .alert)
                
                let restart = UIAlertAction(title: "Restart", style: .default, handler: nil)
                gameOver.addAction(restart)
                
                self.present(gameOver, animated: true, completion: nil)
                
                arrScore += [score]
                arrScore.sort(by: >)
                arrScore.remove(at: arrScore.firstIndex(of: 0)!)
                
                UserDefaults.standard.set(arrScore, forKey: "highScore")
                
                print(arrScore)

                score = 0
                seconds = 15
                answer = ""
                
                updateTimeLabel()
                updateScoreLabel()
                setRandNumLabel()
                
            }
        }
    }
    
    /**
     * Generating a random 4 digit number at the begining of the
     * game and after the player inputted an answer
     */
    func generateRandString() -> String {
        
        var result:String = ""
        
        for _ in 1...4 {
            let digit:Int = Int(arc4random_uniform(8) + 1)
            
            result += "\(digit)"
        }
        
        return result
    }
    
    /*
     * Recordig function
     */
    func recording(text: String?, final: Bool?, error: Error?) {
        
    }
    
    /*
     * Shake to delete function
     */
    override func motionEnded(_ motion: UIEvent.EventSubtype, with event: UIEvent?) {
        if motion == .motionShake {
            inputField?.text = ""
        }
    }
    
    override var canBecomeFirstResponder: Bool {
        return true
    }
}
