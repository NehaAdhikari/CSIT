/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package testingLabel;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.Icon;
import javax.swing.ImageIcon;
import java.awt.FlowLayout;
import javax.swing.SwingConstants;
/**
 *
 * @author Neha
 */
public class LabelFrame extends JFrame{
    JLabel label1, label2, label3;
    public LabelFrame(){
        super("Testing Jlabel");
        setLayout(new FlowLayout()); //set frame layout
        label1 = new JLabel("Label with text");
        label1.setToolTipText("This is Label1");
        add(label1);
        Icon flag = new ImageIcon(getClass().getResource("flag.png"));
        label2 = new JLabel("Label with text and icon",flag,SwingConstants.LEFT);
        label2.setToolTipText("This is Label2");
        add(label2);
        
        label3 = new JLabel();
        label3.setText("Label with icon & text in bottom");
        label3.setIcon(flag);
        label3.setHorizontalTextPosition(SwingConstants.CENTER);
        label3.setVerticalTextPosition(SwingConstants.BOTTOM);
        label3.setToolTipText("This is label3 with icon on top");
        add(label3);
    }
}
