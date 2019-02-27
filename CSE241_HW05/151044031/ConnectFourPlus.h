#ifndef CONNECTFOURPLUS_H__
#define CONNECTFOURPLUS_H__

#include "ConnectFourAbstract.h"

using namespace std;

namespace ConnectFourGame{

class ConnectFourPlus : public ConnectFourAbstract {
    /*Bu class icin big three yazilmistir. */
    public: 

        ConnectFourPlus() : ConnectFourAbstract(){
            /*No-Parameter Constructor */
        }

        ConnectFourPlus(const ConnectFourPlus & other): ConnectFourAbstract(other){
        	/*Copy Constructor */
        }

        ~ConnectFourPlus(){
            /*ConnectFourAbstract Destructor Enough For Kill Object
            And Dynamic Array */
        } 
    /* -------- HW05 ----- Override Functions --------- */
    int playGame();
    int aiSelect();
    void setBoard();
    void play();
    ConnectFourPlus & operator =(const ConnectFourPlus & other);
    /* -------- HW05 ----- Override Functions --------- */
    
    private:     
};




}
#endif
