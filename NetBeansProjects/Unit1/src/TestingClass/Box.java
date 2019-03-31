/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package TestingClass;

/**
 *
 * @author Neha
 */
public class Box {
    int width, height, depth;
    void setDim(int w, int d, int h)
    {
        width=w;
        depth=d;
        height= h;
    }
    double volume()
    {
        return (width * height * depth);
    }
}
