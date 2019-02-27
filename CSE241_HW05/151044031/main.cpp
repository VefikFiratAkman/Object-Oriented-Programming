#include "ConnectFourAbstract.h"
#include "ConnectFourPlus.h"
#include "ConnectFourPlusUndo.h"
#include "ConnectFourDiag.h"

using namespace std;
using namespace ConnectFourGame;

int main(){

    srand (time(NULL));
    /* random fonksiyonunu kullanmak icin vardir. */

    int i = 0;
    int choose;
    char mod;
    int flag = 1;


    while(flag == 1){
        cout<< "\nPlease Enter Game Mod: P,D,U\n";
        cin>>mod;
        if(!cin) {
            cin.clear();
            cin.ignore();
        }
        if(mod == 'P' || mod == 'p'){
            flag = 0;
            ConnectFourPlus ob1;
            ob1.playGame();
        }
        
        else if(mod == 'D' || mod == 'd') {
            flag = 0;
            ConnectFourDiag ob1;
            ob1.playGame();
        }

        else if(mod == 'U' || mod == 'u') {
            flag = 0;
            ConnectFourPlusUndo ob1;
            ob1.playGame();
        }

        else{
            cerr<<("Error: Please Choose P,D,U; \n");
        }
    }/*while flag'in sonu */
}