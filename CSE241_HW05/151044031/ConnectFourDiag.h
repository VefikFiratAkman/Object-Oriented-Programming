#ifndef CONNECTFOURDIAG_H__
#define CONNECTFOURDIAG_H__

#include "ConnectFourAbstract.h"

using namespace std;

namespace ConnectFourGame{

class ConnectFourDiag : public ConnectFourAbstract {
    /*Bu class icin big three yazilmistir. */
    public: 

    ConnectFourDiag() : ConnectFourAbstract(){
        /*No-Parameter Constructor */
    }

    ConnectFourDiag(const ConnectFourDiag & other): ConnectFourAbstract(other){
        /*Copy Constructor */
    }
    ~ConnectFourDiag(){
        /*ConnectFourAbstract Destructor Enough For Kill Object
        And Dynamic Array */
    }      
    /* -------- HW05 ----- Override Functions --------- */
    int playGame();
    int aiSelect();
    void play();
    ConnectFourDiag & operator =(const ConnectFourDiag & other);
    /* -------- HW05 ----- Override Functions --------- */
    private:     
};


}

#endif
