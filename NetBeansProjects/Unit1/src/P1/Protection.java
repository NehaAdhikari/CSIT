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
public class Protection {
    int n = 1;
    private int n_pri = 2;
    protected int n_pro = 3;
    public int n_pub = 4; 
    
    public Protection(){
        System.out.println(n);
        System.out.println(n_pri);
        System.out.println(n_pro);
        System.out.println(n_pub);
    }
}
