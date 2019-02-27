#ifndef CONNECTFOURPLUSUNDO_H__
#define CONNECTFOURPLUSUNDO_H__

#include "ConnectFourPlus.h"

using namespace std;

namespace ConnectFourGame{

class ConnectFourPlusUndo : public ConnectFourPlus {
    /*Bu class icin big three yazilmistir. */
    public: 

        ConnectFourPlusUndo() : ConnectFourPlus(){
            /*No-Parameter Constructor */
        }

        ConnectFourPlusUndo(const ConnectFourPlusUndo & other): ConnectFourPlus(other){
            /*Copy Constructor */
            for(int i = 0; i < livingCell; ++i){
           
                history[i] = other.history[i];
            }
        }

        ~ConnectFourPlusUndo(){
        	/*ConnectFourAbstract Destructor Enough For Kill Object
        	And Dynamic Array */
        }     
    /* -------- HW05 ----- Override Functions --------- */
    int playGame();
    int save(int players,char mod, string filename) const;
    int load(int & players,char & mod,string filename);
    int undo();
    void play();

    ConnectFourPlusUndo & operator =(const ConnectFourPlusUndo & other);
    /* -------- HW05 ----- Override Functions --------- */
    
    private:
    int history[1000];
};



}
#endif

