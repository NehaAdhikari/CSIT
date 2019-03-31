/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package testingDialogBox;

import javax.swing.JOptionPane;

/**
 *
 * @author Neha
 */
public class Addition extends JOptionPane{
    public static void main(String[] args) {
        int number1 = Integer.parseInt(JOptionPane.showInputDialog("Enter first number"));
        int number2 = Integer.parseInt(JOptionPane.showInputDialog("Enter second number"));
        //int number1 = Integer.parseInt(firstnum);
        //int number2 = Integer.parseInt(secondnum);
        int sum =  number1 + number2;
        JOptionPane.showMessageDialog(null, "Sum of " + number1 + " and " + number2 + " is " + sum ,"Addition",JOptionPane.PLAIN_MESSAGE);
    }
}
