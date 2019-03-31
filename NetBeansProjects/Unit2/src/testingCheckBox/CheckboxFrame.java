/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package testingCheckBox;

import java.awt.FlowLayout;
import java.awt.Font;
import java.awt.event.ActionEvent;
import java.awt.event.ItemEvent;
import java.awt.event.ItemListener;
import javax.swing.JFrame;
import javax.swing.JCheckBox;
import javax.swing.JTextField;

/**
 *
 * @author Neha
 */
public class CheckboxFrame extends JFrame{
   public JCheckBox bold1,italic1;
   public JTextField txt1;
   public CheckboxFrame(){
    super("Bold and Italic");
    setLayout(new FlowLayout());
    
    txt1 = new JTextField("Enter text");
    add(txt1);
    
    bold1 = new JCheckBox("Bold");
    add(bold1);
    italic1 = new JCheckBox("Italic");
    add(italic1);
    
//    CheckboxHandler handler = new CheckboxHandler();
//    bold1.addItemListener(handler);
//    italic1.addItemListener(handler);
}
//    private class CheckboxHandler implements ItemListener{
//       public void actionPerformed(ItemEvent event){
////           String action = event.getActionCommand();
////           Font font = null;
////           if(action=="Bold"){
////               font = new Font("",Font.BOLD,12);
////               txt1.setFont(font);
////           }
////           else if (action=="Italic"){
////               font = new Font("",Font.ITALIC,12);
////               txt1.setFont(font);
////           }
//
//       }
//   }
}
