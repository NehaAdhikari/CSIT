/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package testingButton;

import javax.swing.JFrame;

/**
 *
 * @author Neha
 */
public class ButtonTest {
     public static void main(String[] args) {
        ButtonFrame dialog1 = new ButtonFrame();
        dialog1.setVisible(true);
        dialog1.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        dialog1.setSize(200, 200);
    }
    
}
