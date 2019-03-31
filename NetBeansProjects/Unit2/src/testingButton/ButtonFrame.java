/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package testingButton;

import java.awt.FlowLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.Icon;
import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JOptionPane;
import javax.swing.SwingConstants;

/**
 *
 * @author Neha
 */
public class ButtonFrame extends JFrame {
   public JButton button1, button2;
   public ButtonFrame(){
       super("Set Button");
       setLayout(new FlowLayout());
       button1 = new JButton("Plain button");
       
       add(button1);
       Icon flag = new ImageIcon(getClass().getResource("flag.png"));
       button2 = new JButton();
       button2.setText("Fancy button");
       button2.setIcon(flag);
       button2.setHorizontalTextPosition(SwingConstants.CENTER);
       button2.setVerticalTextPosition(SwingConstants.BOTTOM);
       add(button2);
       
       ButtonHandler handler = new ButtonHandler();
       button1.addActionListener(handler);
       button2.addActionListener(handler);
   }
   private class ButtonHandler implements ActionListener{
       public void actionPerformed(ActionEvent event){
           String action = event.getActionCommand();
           String message = "You pressed " + action;
           JOptionPane.showMessageDialog(ButtonFrame.this, message);
       }
   }
}
