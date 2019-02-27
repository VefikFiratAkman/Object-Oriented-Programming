#ifndef CELL_H__
#define CELL_H__
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include <string>
#include <vector>

using namespace std;
namespace ConnectFourGame{

    class Cell{
        public:

        char getPosition() const {
            return position;
        }

        void setPosition(char position) {
            Cell::position = position;
        }

        int getheight() const {
            return height;
        }

        void setheight(int height) {
            Cell::height = height;
        }

        char getValue() const {
            return value;
        }

        void setValue(char value) {
            Cell::value = value;
        }

        /* -------- HW04 Functions --------- */
        bool operator ==(const Cell & other) const;
        bool operator !=(const Cell & other) const;
        Cell operator ++();
        Cell operator ++(int ignoreMe);
        Cell operator --();
        Cell operator --(int ignoreMe);
        friend istream & operator >>(istream & in, Cell & other);
        friend ostream & operator <<(ostream & out, Cell & other);

        /* -------- HW04 Functions --------- */

        protected:
        char position;
        int height;
        char value;
    };
}
#endif