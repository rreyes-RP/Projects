import UIKit
import SceneKit
import ARKit

class ViewController: UIViewController, ARSCNViewDelegate {
    
    @IBOutlet var sceneView: ARSCNView!
    var colorIndex = 0 // to keep track of the current color index
    var timerLabel: UILabel! // to display the timer
    var startTime: Date? // to keep track of the start time
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        // Set the view's delegate
        sceneView.delegate = self
        
        // Show statistics such as fps and timing information
        sceneView.showsStatistics = true
        
        // Create a new scene
        let scene = SCNScene()
        
        // Create a red sphere
        let sphere = SCNSphere(radius: 0.05)
        sphere.firstMaterial?.diffuse.contents = UIColor.red
        
        // Add the sphere to the scene
        let sphereNode = SCNNode(geometry: sphere)
        scene.rootNode.addChildNode(sphereNode)
        
        // Set the scene to the view
        sceneView.scene = scene
        
        // Add tap gesture recognizer
        let tapGestureRecognizer = UITapGestureRecognizer(target: self, action: #selector(handleTap))
        sceneView.addGestureRecognizer(tapGestureRecognizer)
        
        // Add the timer label to the view
        timerLabel = UILabel(frame: CGRect(x: 0, y: 50, width: view.bounds.width, height: 50))
        timerLabel.textAlignment = .center
        timerLabel.font = UIFont.systemFont(ofSize: 24)
        view.addSubview(timerLabel)
    }
    
    override func viewWillAppear(_ animated: Bool) {
        super.viewWillAppear(animated)
        
        // Create a session configuration
        let configuration = ARWorldTrackingConfiguration()
        
        // Run the view's session
        sceneView.session.run(configuration)
    }
    
    override func viewWillDisappear(_ animated: Bool) {
        super.viewWillDisappear(animated)
        
        // Pause the view's session
        sceneView.session.pause()
    }
    
    func session(_ session: ARSession, didFailWithError error: Error) {
        // Present an error message to the user
    }
    
    func sessionWasInterrupted(_ session: ARSession) {
        // Inform the user that the session has been interrupted, for example, by presenting a message
    }
    
    func sessionInterruptionEnded(_ session: ARSession) {
        // Reset tracking and/or remove existing anchors if consistent tracking is required
    }
    
    /**
     * Handles the tap feature to do the following:
     * 1. 
     */
    @objc func handleTap(sender: UITapGestureRecognizer) {
        let location = sender.location(in: sceneView)
        let hitTestResults = sceneView.hitTest(location, options: [:])
        guard let hitTestResult = hitTestResults.first, let node = hitTestResult.node as? SCNNode else {
            return
        }
        // Rotate between red and green colors
        let colors: [UIColor] = [UIColor.red, UIColor.green]
        colorIndex = (colorIndex + 1) % colors.count
        node.geometry?.firstMaterial?.diffuse.contents = colors[colorIndex]
        // Start or stop the timer based on the color
        if colors[colorIndex] == UIColor.green {
            startTime = Date()
        } else {
            if let startTime = startTime {
                let elapsedTime = Date().timeIntervalSince(startTime)
                timerLabel.text = String(format: "Time: %.2f seconds", elapsedTime)
                self.startTime = nil
            }
        }
    }
}
