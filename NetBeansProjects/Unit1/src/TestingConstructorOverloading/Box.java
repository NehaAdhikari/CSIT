/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package TestingConstructorOverloading;

/**
 *
 * @author Neha
 */
public class Box {
    double width, breadth, height ;
    Box(){
      width = breadth = height = -1;
    }
    Box(double len){
        width = breadth = height = len;
    }
    Box(double w, double b, double h){
        width = w;
        breadth = b;
        height = h;
    }
    double Volume(){
        return (width * breadth * height);
    }
}
