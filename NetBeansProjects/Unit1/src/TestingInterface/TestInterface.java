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
public class TestInterface {
    public static void main(String[] args) {
        Client ob1 = new Client();
        AnotherClient ob2 = new AnotherClient();
        ob1.Callback(5);
        ob2.Callback(5);
    }
}
