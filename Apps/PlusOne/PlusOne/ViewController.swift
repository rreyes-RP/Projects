//
//  ViewController.swift
//  PlusOne
//
//  Created by Rorie Reyes on 2/10/23.
//

import UIKit

class ViewController: UIViewController {

    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view.
    }

    /**
     * Play button on home screen
     */
    @IBAction func clickPlay(_ sender: Any) {
        print("Play Button Pressed")
        performSegue(withIdentifier: "launchGame", sender: self)
    }
    
    /**
     * High Score button on home screen
     */
    @IBAction func clickHighScore(_ sender: Any) {
        print("High Score Button Pressed")
        performSegue(withIdentifier: "launchHighScore", sender: self)
    }
    
    
    @IBAction func clickInstructions(_ sender: Any) {
        print("Instructions Button Pressed")
        performSegue(withIdentifier: "launchInstructions", sender: self)
    }
    
    
}

