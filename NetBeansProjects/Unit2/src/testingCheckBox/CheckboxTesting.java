/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package testingCheckBox;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.JFrame;
import javax.swing.JOptionPane;
import testingButton.ButtonFrame;

/**
 *
 * @author Neha
 */
public class CheckboxTesting {
    public static void main(String[] args) {
        CheckboxFrame ob1 = new CheckboxFrame();
        ob1.setVisible(true);
        ob1.setSize(500,500);
        ob1.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }
}
