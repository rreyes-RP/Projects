//
//  HighScoreViewController.swift
//  PlusOne
//
//  Created by Rorie Reyes on 2/24/23.
//

import UIKit

class HighScoreViewController: UIViewController {
    
    @IBOutlet weak var highScoreLabel:UILabel!
    
    var highScore = [Int](repeating:0, count: 10)
    
    override func viewDidLoad() {
        super.viewDidLoad()
            
        /**
         * Grabs the score array from the database
         * Via GameViewController
         */
        if let savedTopTenScores = UserDefaults.standard.array(forKey: "highScore") as? [Int] {
            highScore = savedTopTenScores
        }
        
    }
    
    /**
     * Updates the high score page with new scores
     */
    override func viewDidAppear(_ animated: Bool) {
        super.viewDidAppear(animated)
        upScoreLabel()
    }
    
    /**
     * Updates the high score label
     */
    func upScoreLabel() {
        var topTenScoresText = ""
        for (index, score) in highScore.enumerated() {
            topTenScoresText += "\(index + 1). \(score)\n"
        }
        
        highScoreLabel?.text = topTenScoresText
        print(highScoreLabel as Any)
    }
    
}
