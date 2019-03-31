/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package testingFrame;

import javax.swing.JFrame;

/**
 *
 * @author Neha
 */
public class SimpleFrameTest {
    public static void main(String[] args){
        SimpleFrame ob1 = new SimpleFrame();
        ob1.setVisible(true);
        ob1.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        //ob1.setTitle("1st Window");
       
    }
}
