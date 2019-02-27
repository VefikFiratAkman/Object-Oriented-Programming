#include "ConnectFour.h"

using namespace std;

int main(){

    srand (time(NULL));
    /* random fonksiyonunu kullanmak icin vardir. */

    int i = 0;
    int choose;
    char mod;
    int flag = 1;
    int end1 = 1; int end2 = 1; int end3 = 1; int end4 = 1; int end5 = 1;
    int total = 1;


    while(flag == 1){
        cout<< "\nPlease Enter Game Mod: S for Single, M for Multi\n";
        cin>>mod;
        if(!cin) {
            cin.clear();
            cin.ignore();
        }
        /* Oyunun Single mi Multi Mod mu olacagi secilmistir. */

        if(mod == 'S' || mod == 's'){
            flag = 0;
            ConnectFour ob1;
            ob1.playGame();
        }
        /* Single oyun calistirilmis ve eger bu satiri gelinmisse oyun bitmistir. */

        else if(mod == 'M' || mod == 'm') {
            flag = 0;
            ConnectFour ob1(mod),ob2(mod), ob3(mod),ob4(mod),ob5(mod);
            ob1.playGame();
            ob2.playGame();
            ob3.playGame();
            ob4.playGame();
            ob5.playGame();
            /* ilk initiliaze icin her obje bir kez cagirilmistir. */
            /* aslinda burda file'li constructor kullanilabilirdi. Ama 
            input format sirasi odevle uymasi icin bu yol secildi. */

            while (total != 0) {
                ob1.bestGame(ob2,ob3,ob4,ob5);

                /*Obje secimi baslamistir. */
                cout << "Please Choose A Obje: ";
                cin >> choose;
                if(cin.eof()){
                    exit(1); /*input file biterse program biter. */
                }
                if(!cin) {
                    cin.clear();
                    cin.ignore();
                }
                /*Obje secimi tamamlanmistir. */

                if (choose == 1) {
                    if(end1 == 1) {
                        ob1.playGame();
                        end1 = !ob1.endGame();
                    }
                    else{
                        cout<< "\nBu objede oyun bitmiştir!\n";
                    }
                }
                else if (choose == 2) {
                    if(end2 == 1) {
                        ob2.playGame();
                        end2 = !ob2.endGame();
                    }
                    else{
                        cout<< "\nBu objede oyun bitmiştir!\n";
                    }
                }
                    
                        else if (choose == 3) {
                            if(end3 == 1) {
                                ob3.playGame();
                                end3 = !ob3.endGame();
                            }
                            else{
                                cout<< "\nBu objede oyun bitmiştir!\n";
                                }
                        }
                        else if (choose == 4) {
                            if(end4 == 1) {
                                ob4.playGame();
                                end4 = !ob4.endGame();
                            }
                            else{
                                cout<< "\nBu objede oyun bitmiştir!\n";
                            }
                        }

                        else if(choose == 5) {
                            if (end5 == 1) {
                                ob5.playGame();
                                end5 = !ob5.endGame();
                            }
                            else {
                                cout << "\nBu objede oyun bitmiştir!\n";
                            }
                        }
                       
                else{
                    cerr<<"\nHatalı Seçim. Tekrar deneyiniz.\n";
                }
                total = end1+end2+end3+end4+end5; 
                /*Endler basta 1'dir. Oyunu biten obje kendiyle ilgili
                endini 0 yapar. Hepsi 0 olunca oyun biter. */
            }/*while total'in sonu */
        }

        else{
            cerr<<("Error: Please Choose S or M; \n");
        }
    }/*while flag'in sonu */
}