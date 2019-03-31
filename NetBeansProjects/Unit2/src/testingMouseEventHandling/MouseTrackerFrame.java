/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package testingMouseEventHandling;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Dimension;
import java.awt.FlowLayout;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;

/**
 *
 * @author Neha
 */
public class MouseTrackerFrame extends JFrame {
    JPanel panel1;
    JLabel label1;
    public MouseTrackerFrame(){
        super("Mouse events");
        setLayout(new FlowLayout());
        
        panel1 = new JPanel();
        panel1.setBackground(Color.white);
        panel1.setPreferredSize(new Dimension(200,200));
        add(panel1,BorderLayout.CENTER);
        
        label1 = new JLabel();
        add(label1);
        
        MouseHandler handler = new MouseHandler();
        panel1.addMouseListener(handler);
        panel1.addMouseMotionListener(handler);
        
    }
    private class MouseHandler extends MouseAdapter{
        public void mouseClicked(MouseEvent event){
            label1.setText(String.format("Clicked at [%d,%d]", event.getX(),event.getY()));
        }
        public void mousePressed(MouseEvent event){
            
        }
    }
}
