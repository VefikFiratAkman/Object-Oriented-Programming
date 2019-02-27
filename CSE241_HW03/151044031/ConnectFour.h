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

    public:

    ConnectFour(){
        callFlag = 0;
        gameMod = 'S';
        while(true){
            cout<<("Please Enter Width A Number Between 4-27: ");
            cin>>width;
            if(!cin) {
                cin.clear();
                cin.ignore();
            }
            if(width >= 4 && width <=27){
                break;
            }
            else{
                cerr<<("Error: Please Choose A Number Between 4-27: \n");
            }
        }
        while(true){
            cout<<("Please Enter Height A Number Between 4-99: ");
            cin>>height;
            if(!cin) {
                cin.clear();
                cin.ignore();
            }
            if(height >= 4 && height <=99){
                break;
            }
            else{
                cerr<<("Error: Please Choose A Number Between 4-99: \n");
            }
        }
        cout << ("Please Choose Game Mod: P for PVP, C for PVC: ");
        while (true) {
            cin >> choose;

            if (choose == 'p' || choose == 'c') {
                choose = char(int(choose) - 32);
            }
            if (choose == 'P' || choose == 'C') {
                break;
            }
            cerr << ("Error: Wrong Choose. \nPlease Choose P for PVP, C for PVC: ");
        }
        setBoard();
    }

    ConnectFour(char mod){
        callFlag = 0;
        gameMod = mod;
        while(true){
            cout<<("Please Enter Width A Number Between 4-27: ");
            cin>>width;
            if(!cin) {
                cin.clear();
                cin.ignore();
            }
            if(width >= 4 && width <=27){
                break;
            }
            else{
                cerr<<("Error: Please Choose A Number Between 4-27: \n");
            }
        }
        while(true){
            cout<<("Please Enter Height A Number Between 4-99: ");
            cin>>height;
            if(!cin) {
                cin.clear();
                cin.ignore();
            }
            if(height >= 4 && height <=99){
                break;
            }
            else{
                cerr<<("Error: Please Choose A Number Between 4-99: \n");
            }
        }
        cout << ("Please Choose Game Mod: P for PVP, C for PVC: ");
        while (true) {
            cin >> choose;

            if (choose == 'p' || choose == 'c') {
                choose = char(int(choose) - 32);
            }
            if (choose == 'P' || choose == 'C') {
                break;
            }
            cerr << ("Error: Wrong Choose. \nPlease Choose P for PVP, C for PVC: ");
        }
        setBoard();

    }
    ConnectFour(char mod,int row,int col,char playermod){
        callFlag = 0;
        gameMod = mod;
        height = row;
        width = col;
        choose = playermod;
        setBoard();

    }

        void printBoard() const; 
        void setBoard();  
        void play();   
        void play(char position, int players); 

        int aiSelect( );
        int aiPlayerVerticalStopper( int & cord);
        int aiPlayerHorizontalStopper( int & cord);
        int aiPlayerDiagonal1Stopper( int & cord);
        int aiPlayerDiagonal2Stopper( int & cord);
        int aiWinVertical( int & cord);
        int aiWinHorizontal( int & cord);
        int aiWinDiagonal1( int & cord);
        int aiWinDiagonal2( int & cord);
        int checkWinVertical( );
        int checkWinHorizontal( );
        int checkWinDiagonal1( );
        int checkWinDiagonal2( );
        int LegalMove( int cord);
        int aiLegalMove( int cord);
        int boardFull( ) const;
        int save(int players,char mod, string filename);
        int load(int & players,char & mod,string filename);

        int endGame();
        int playGame();
        int reSize();
        int currentWidth();
        int currentHeight();


        int bestGame(ConnectFour a,ConnectFour b,ConnectFour c,ConnectFour d);

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
        vector<vector<Cell> > gameCells;


};

#endif
