/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package P1;

/**
 *
 * @author Neha
 */
public class SamePackage {
    SamePackage(){
        Protection p = new Protection();
        System.out.println(p.n);
        System.out.println(p.n_pro);
        System.out.println(p.n_pub);
    }
}
