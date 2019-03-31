/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package TestingInterface;

/**
 *
 * @author Neha
 */
public class Client implements Callback {
    public void Callback(int p){
        System.out.println("Callback called with p as " + p);
    }
    void nonInterfaceMeth(){
        System.out.println("Classes that implement interfaces" + " may also define other members too");
    }
}
