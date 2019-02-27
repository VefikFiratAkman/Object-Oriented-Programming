/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package connectfourgameapp;

/**
 *
 * @author VefikFiratAkman
 */
public class ConnectFourGameApp {

    /**
     * @param args the command line arguments
     * @throws java.lang.InterruptedException
     */
    public static void main(String[] args) throws InterruptedException {
       while(true){
       GUI x = new GUI();
       x.playGame();
       }
       
    }
    
}
