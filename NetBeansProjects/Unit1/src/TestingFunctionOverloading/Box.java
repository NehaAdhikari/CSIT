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
public class Box {
    double width, breadth, height ;
    void SetDim(){
        width = breadth = height = -1;
    }
    void SetDim(double len){
         width = breadth = height = len;
    }
    void SetDim(double w, double b, double h){
        width = w;
        breadth = b;
        height = h;
    }
    double Volume(){
        return (width * breadth * height);
    }
}
