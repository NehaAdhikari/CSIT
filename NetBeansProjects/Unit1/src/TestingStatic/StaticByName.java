/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package TestingStatic;

/**
 *
 * @author Neha
 */
public class StaticByName {
    public static void main(String args[]){
        StaticDemo.callme();
        System.out.println("Value of a = " + StaticDemo.a);
    }
}
