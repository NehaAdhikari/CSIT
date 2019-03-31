/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package TestingClass;

import static java.time.Clock.system;

/**
 *
 * @author Neha
 */
public class BoxDemo {
    public static void main(String args[]){
        Box myBox1= new Box();
        Box myBox2 = new Box();
        myBox1.setDim(4,5,6);
        myBox2.setDim(6,7,8);
        double vol1 = myBox1.volume();
        System.out.println("Volume of Box1 is " + vol1);
        vol1 = myBox2.volume();
        System.out.println("Volume of Box2 is " + vol1);
    }
}
