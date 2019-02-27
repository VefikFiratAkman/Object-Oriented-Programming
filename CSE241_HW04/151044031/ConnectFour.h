#ifndef CONNECTFOUR_H__
#define CONNECTFOUR_H__

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

#define MAX 100

class ConnectFour {
    /*Bu class icin big three yazilmistir. */
    public:

        ConnectFour(){
            /*No-Parameter Constructor */
            callFlag = 0;
            gameMod = 'S';
            height = 5;
            width = 5;
            choose = 'P';
            setBoard();
        }

        ConnectFour(ConnectFour & other){
            /*Copy Constructor */
        	int i,k;
      	  	callFlag = other.callFlag;
            gameMod = other.gameMod;
            height = other.height;
            width = other.width;
            choose = other.choose;

             gameCells = new Cell *[height];

        	for(i = 0; i < height; ++i){
           
                gameCells[i] = new Cell[width];
            }

            for(i = 0; i < height; ++i){
            	for(k = 0; k < width; ++k){
            		gameCells[i][k] = other.gameCells[i][k];
            	}
        	}

            setBoard();
        }

        ConnectFour(string filename){
        	/*File Constructor */
        	int i,k;
        	int max;
        	char ch;

        	callFlag = 0;
            gameMod = 'M';
            choose = 'P';


    		maxcolumn(filename);
    		

        	ifstream file1;
    	    file1.open(filename);
    	    if (!(file1.is_open())){
    	        cerr << "File Cannot Open. \n";
    	        cerr << "Try again or continue game. \n";
    	    }

    	    gameCells = new Cell *[height];

    	    for(i = 0; i < height; ++i){
    	       
    	            gameCells[i] = new Cell[max];
    	        
    	    }


    	    for (int i = 0; i < height; ++i){
    	        for (int j = 0; j < width; ++j){
    	            file1.get(ch);
    	            if(ch == '*'){
    	                gameCells[i][j].setValue('.');
    	            }
    	            else{
    	                gameCells[i][j].setValue(' ');
    	            }
    	        }
    	    }

    	    for (int i = 0; i < height; ++i){
    	        for (int j = 0; j < width; ++j){
    	            ch = char('A' + j);
    	            gameCells[i][j].setPosition(ch);
    	        }
    	    }

    	    for (int i = 0; i < height; ++i){
    	        for (int j = 0; j < width; ++j){
    	            gameCells[i][j].setheight(i);
    	        }
    	    }
        }

        ConnectFour(char mod){
            /*Mod Constructor for MultiGame */
            callFlag = 0;
            gameMod = mod;
            height = 5;
            width = 5;
    		choose = 'P';		
            setBoard();
        }

        ConnectFour(int row,int col){
            /*Parametreli Constructor */
            callFlag = 0;
            gameMod = 'S';
            height = row;
            width = col;
            choose = 'P';
            setBoard();
        }

        ~ConnectFour(){
            /*Destructor */
            int i;

            for(i = 0; i < height; ++i){
                delete [] gameCells[i];
            }

            delete [] gameCells;
        }
        
        int endGame()const;
        int playGame();
        int bestGame(ConnectFour & a,ConnectFour & b,ConnectFour & c,ConnectFour & d)const;

        /* -------- HW04 Functions --------- */
        bool operator ==(const ConnectFour & other) const;
        bool operator !=(const ConnectFour & other) const;
        ConnectFour & operator =(const ConnectFour & other);
        /* -------- HW04 Functions --------- */


        inline int getWidth() const {
            return width;
        }

        inline void setWidth(int width) {
            ConnectFour::width = width;
        }

        inline int getHeight() const {
            return height;
        }

        inline void setHeight(int height) {
            ConnectFour::height = height;
        }

        inline static int getLivingCell() {
            return livingCell;
        }

        inline static void setLivingCell(int livingCell) {
            ConnectFour::livingCell = livingCell;
        }

    private:

        void printBoard() const;
        void setBoard();
        void play();
        void play(char position, int players);
        int aiSelect();
        int aiPlayerVerticalStopper(int & cord);
        int aiPlayerHorizontalStopper(int & cord);
        int aiPlayerDiagonal1Stopper(int & cord);
        int aiPlayerDiagonal2Stopper(int & cord);
        int aiWinVertical(int & cord);
        int aiWinHorizontal(int & cord);
        int aiWinDiagonal1(int & cord);
        int aiWinDiagonal2(int & cord);
        int checkWinVertical();
        int checkWinHorizontal();
        int checkWinDiagonal1();
        int checkWinDiagonal2();
        int LegalMove(int cord)const;
        int aiLegalMove( int cord)const;
        int boardFull() const;
        int save(int players,char mod, string filename) const;
        int load(int & players,char & mod,string filename);
        int currentWidth() const;
        int currentHeight() const;
        

        /* -------- HW04 Functions --------- */
        int readSet(string filename);
        int maxcolumn(string filename2);
        /* -------- HW04 Functions --------- */





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

        private:
            char position;
            int height;
            char value;


        };

        int width;
        int height;
        int callFlag;
        char choose;
        char gameMod;
        static int livingCell;
        Cell ** gameCells;

    public:
        /* -------- HW04 Functions --------- */
        friend istream & operator >>(istream & in, ConnectFour::Cell & other);
        friend ostream & operator <<(ostream & out, ConnectFour::Cell & other);
        /* -------- HW04 Functions --------- */
};




#endif
