/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package testingMouseEventHandling;

import javax.swing.JFrame;

/**
 *
 * @author Neha
 */
public class MouseTracker {
    public static void main(String[] args) {
        MouseTrackerFrame ob1 = new MouseTrackerFrame();
        ob1.setVisible(true);
        ob1.setSize(500,500);
        ob1.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }
}
