#ifndef CONNECTFOURABSTRACT_H__
#define CONNECTFOURABSTRACT_H__

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include <string>
#include <vector>
#include "Cell.h"
using namespace std;

namespace ConnectFourGame{

    class ConnectFourAbstract {
    /*Bu class icin big three yazilmistir. */
    public:

        ConnectFourAbstract(){
            /*No-Parameter Constructor */
            callFlag = 0;
            gameMod = 'S';
            height = 5;
            width = 5;
            choose = 'P';
            setBoard();
        }

        ConnectFourAbstract(const ConnectFourAbstract & other){
            /*Copy Constructor */
            int i,k;
            callFlag = other.callFlag;
            gameMod = other.gameMod;
            height = other.height;
            width = other.width;
            choose = other.choose;
            livingCell = other.livingCell;

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

        ConnectFourAbstract(string filename){
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

        ConnectFourAbstract(char mod){
            /*Mod Constructor for MultiGame */
            callFlag = 0;
            gameMod = mod;
            height = 5;
            width = 5;
            choose = 'P';       
            setBoard();
        }

        ConnectFourAbstract(int row,int col){
            /*Parametreli Constructor */
            callFlag = 0;
            gameMod = 'S';
            height = row;
            width = col;
            choose = 'P';
            setBoard();
        }

        ~ConnectFourAbstract(){
            /*Destructor */
            int i;

            for(i = 0; i < height; ++i){
                delete [] gameCells[i];
            }

            delete [] gameCells;
        }
        
        int endGame()const;
        int playGame();
        int bestGame(ConnectFourAbstract & a,ConnectFourAbstract & b,ConnectFourAbstract & c,ConnectFourAbstract & d)const;

        /* -------- HW04 Functions --------- */
        bool operator ==(const ConnectFourAbstract & other) const;
        bool operator !=(const ConnectFourAbstract & other) const;
        ConnectFourAbstract & operator =(const ConnectFourAbstract & other);
        /* -------- HW04 Functions --------- */


        inline int getWidth() const {
            return width;
        }

        inline void setWidth(int width) {
            ConnectFourAbstract::width = width;
        }

        inline int getHeight() const {
            return height;
        }

        inline void setHeight(int height) {
            ConnectFourAbstract::height = height;
        }

        inline static int getLivingCell() {
            return livingCell;
        }

        inline static void setLivingCell(int livingCell) {
            ConnectFourAbstract::livingCell = livingCell;
        }

    protected:

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

        /* -------- HW05 Functions --------- */  
        void createNewTable();
        /* -------- HW05 Functions --------- */
        
        /* ----- ConnectFourAbstract Protected Varible ---- */
        int width;
        int height;
        int callFlag;
        char choose;
        char gameMod;
        static int livingCell;
        Cell ** gameCells;
        /* ----- End ConnectFourAbstract Protected Varible ---- */
        
        /* ----- Start Again ConnectFourAbstract Class public ---- */
    public:
        /* -------- HW04 Functions --------- */
        friend istream & operator >>(istream & in, Cell & other);
        friend ostream & operator <<(ostream & out, Cell & other);
        /* -------- HW04 Functions --------- */
};
}
#endif



