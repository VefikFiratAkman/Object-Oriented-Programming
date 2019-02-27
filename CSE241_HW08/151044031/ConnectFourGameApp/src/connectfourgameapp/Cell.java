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
 public class Cell{
    
        /** Getter for Position
        */
        public char getPosition()  {
            return position;
        }
        /** Setter for Position
        */
        public void setPosition(char p) {
            position = p;
        }
        /** Getter for Height
        */
        public int getheight()  {
            return height;
        }
        /** Setter for Height
        */
        public void setheight(int h) {
            height = h;
        }
        /** Getter for Value
        */
        public char getValue() {
            return value;
        }
        /** Setter for Value
        */
        public void setValue(char v) {
            value = v;
        }

        private char position;
        private int height;
        private char value;


    };