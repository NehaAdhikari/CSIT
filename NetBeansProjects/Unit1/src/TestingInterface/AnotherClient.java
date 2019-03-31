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
public class AnotherClient implements Callback {
    public void Callback(int q){
        System.out.println("Another version of Callback");
        System.out.println("Callback called with q as " + q);
    }
}
