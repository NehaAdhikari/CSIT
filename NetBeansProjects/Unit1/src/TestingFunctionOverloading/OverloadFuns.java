/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package TestingFunctionOverloading;

/**
 *
 * @author Neha
 */
public class OverloadFuns {
    public static void main(String[] args) {
         Box box1 = new Box();
         Box box2 = new Box();
         Box box3 = new Box();
         box1.SetDim();
         box2.SetDim(10, 20, 15);
         box3.SetDim(7);
        System.out.println("Volume of box1 = " + box1.Volume());
        System.out.println("Volume of box2 = " + box2.Volume());
        System.out.println("Volume of box3 = " + box3.Volume());
    }
}
