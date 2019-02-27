
#include "ConnectFour.h"

int ConnectFour::livingCell = 0;

int ConnectFour::currentHeight(){
    return height;
}
int ConnectFour::currentWidth(){
    return width;
}
void ConnectFour::printBoard() const {
/*Oyun tahtasını terminale kuralına uygun basar. */
    int i;
    auto k = 0;
    decltype ( i*1) j;


    for(i = 0; i < height; ++i){
        for(k = 0; k < width; ++k){
            cout<<("| ") << gameCells[i][k].getValue() << (" ");
        }
        cout<<("|\n");
        for(j = 0; j < width*4; ++j){
            cout<<("-");
        }
        cout<<("-\n");
    }

    for(k = 1; k <= width; ++k){
        cout<<("  ") << char(k+96) << " ";
    }
    cout<<("\n");

    cout<<"Living Cell: " << livingCell << "\n";
}
void ConnectFour::setBoard(){

    /* Boardu oluşturan double arrayin sonra ki fonksiyonlar da junk değerler
  yüzünden sorun çıkarması için array boşluk karakteriyle doldurulur. */
    int i, k;

    gameCells.reserve(100);

    for(i = 0; i < height; ++i){
        vector<Cell> a;
        for(k = 0; k < width; ++k){
            Cell x;
            x.setheight(i);
            x.setPosition(char(k+65));
            x.setValue(' ');
            a.push_back(x);

        }
        gameCells.push_back(a);

    }
}
void ConnectFour::play(char position,int players) {
    /* Bu fonksiyon kullanıcıoynamak istediği hamleyi boarda
yani arraye işler. */
    int i;
    int cord;
    cord = int(position-65);

    for(i = height-1; i >= 0;){
        if( gameCells[i][cord-1].getValue()== ' '){

            if(players % 2 == 0){
                gameCells[i][cord-1].setValue('X');
            }
            else{
                gameCells[i][cord-1].setValue('O');
            }

            i = -1;
        }

        else{
            i = i - 1;
        }

    }
}
void ConnectFour::play(){
    /* Bu fonksiyon computerın oynamak istediği hamleyi boarda
yani arraye işler. */
    int i;
    int cord;

    cord = aiSelect();

    for(i = height-1; i >= 0;){
        if( gameCells[i][cord-1].getValue()== ' '){
                gameCells[i][cord-1].setValue('O');
            i = -1;
        }

        else{
            i = i - 1;
        }

    }
    cout << "\nComputer Choosed: " << char(cord+96) << "\n";
}
int ConnectFour::endGame(){
	/* BU fonksiyon objenin bitip bitmediğini kontrol eder.*/
    int i,k;

    for(i = 0; i < height; ++i) {
        for (k = 0; k < width; ++k) {
            if (gameCells[i][k].getValue() == 'x' || gameCells[i][k].getValue() == 'o' || boardFull()) {
                return 1;
            }
        }
    }
    return 0;
}
int ConnectFour::reSize(){
	/* BU fonksiyon boardu resize eder.*/
    char resize;
    int flag = 1;

    while(flag == 1) {
        cout << ("\nDo You Wanna Resize?: Y(yes) or N(no)\n");
        cin >> resize;
        if (!cin) {
            cin.clear();
            cin.ignore();
        }



        if (resize == 'Y' || resize == 'y') {
            while (true) {
                cout << ("Please Enter Width A Number Between 4-27: ");
                cin >> width;
                if (!cin) {
                    cin.clear();
                    cin.ignore();
                }
                if (width >= 4 && width <= 27) {
                    break;
                }
                else {
                    cerr << ("Error: Please Choose A Number Between 4-27: \n");
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

            gameCells.resize(height);
            for (int i = 0; i < height; ++i) {
                gameCells[i].resize(width);
            }
            for (int i = 0; i < height; ++i){
                for (int j = 0; j < width; ++j){
                    gameCells[i][j].setValue(' ');
                }
            }
            for (int i = 0; i < height; ++i){
                for (int j = 0; j < width; ++j){
                    gameCells[i][j].setPosition(j);
                }
            }
            for (int i = 0; i < height; ++i){
                for (int j = 0; j < width; ++j){
                    gameCells[i][j].setheight(i);
                }
            }


            printBoard();
            cout << ("\n Resize Succesful!\n");
            flag = 0;





        }



        else if (resize == 'N' || resize == 'n') {
            flag = 0;
        }
        else {
            cerr << ("\n Error: Wrong Choice. Try Again\n");
        }
    }
}
int ConnectFour::bestGame(ConnectFour a,ConnectFour b,ConnectFour c,ConnectFour d){

    int i,k;
    int number[5];
    int objeN = 0;
    int min = 10000;

    for(i=0;i<5;++i){
        number[i] = 0;
        }


    for(i = 0; i < height; ++i) {
        for (k = 0; k < width; ++k) {
            if (gameCells[i][k].getValue() == 'X' || gameCells[i][k].getValue() == 'O') {
            }
            else if(gameCells[i][k].getValue() == 'x' || gameCells[i][k].getValue() == 'o') {
                number[0] = 10000;
            }
            else{
                ++number[0];
            }
        }
    }

    for(i = 0; i < a.height; ++i) {
        for (k = 0; k < a.width; ++k) {
            if (a.gameCells[i][k].getValue() == 'X' || a.gameCells[i][k].getValue() == 'O') {
            }
            else if(a.gameCells[i][k].getValue() == 'x' || a.gameCells[i][k].getValue() == 'o') {
                number[1] = 10000;
            }
            else{
                ++number[1];
            }
        }
    }
    for(i = 0; i < b.height; ++i) {
        for (k = 0; k < b.width; ++k) {
            if (b.gameCells[i][k].getValue() == 'X' || b.gameCells[i][k].getValue() == 'O') {
            }
            else if(b.gameCells[i][k].getValue() == 'x' || b.gameCells[i][k].getValue() == 'o') {
                number[2] = 10000;
            }
            else{
                ++number[2];
            }
        }
    }
    for(i = 0; i < c.height; ++i) {
        for (k = 0; k < c.width; ++k) {
            if (c.gameCells[i][k].getValue() == 'X' || c.gameCells[i][k].getValue() == 'O') {
            }
            else if(c.gameCells[i][k].getValue() == 'x' || c.gameCells[i][k].getValue() == 'o') {
                number[3] = 10000;
            }
            else{
                ++number[3];
            }
        }
    }
    for(i = 0; i < d.height; ++i) {
        for (k = 0; k < d.width; ++k) {
            if (d.gameCells[i][k].getValue() == 'X' || d.gameCells[i][k].getValue() == 'O') {
            }
            else if(d.gameCells[i][k].getValue() == 'x' || d.gameCells[i][k].getValue() == 'o') {
                number[4] = 10000;
            }
            else{
                ++number[4];
            }
        }
    }


    for(i=0;i<5;++i){
        if(number[i]<min && number[i]>0){
            min = number[i];
            objeN = i;
        }
    }


    if(objeN == 0){
        cout << "First Obje Better Than Other For Finish Game\n";
    }
    else if(objeN == 1){
        cout << "Second Obje Better Than Other For Finish Game\n";
    }
    else if(objeN == 2){
        cout << "Third Obje Better Than Other For Finish Game\n";
    }
    else if(objeN == 3){
        cout << "Fourth Obje Better Than Other For Finish Game\n";
    }
    else{
        cout << "Fifth Obje Better Than Other For Finish Game\n";
    }
    /* BU fonksiyon en erken bitecek oyunu bulurr.*/

}

int ConnectFour::playGame(){
    /*Oyunun temelini oluşturan fonksiyondur. Oyunu oluşturan diğer fonksiyonlar
    burada bir bütün halinde çağırılır.Oyunun oynanışı ve işleyişi bu fonksiyonda gerçekleşir.*/

    int cord;
    string select;
    string filename;
    int player = 0;
    int flag = 0;
    int turnFlag = 1;
    int correct = 1;



        if (callFlag == 0 && gameMod =='S') {
            reSize();
            cout << ("\n Welcome to Connect Four Game\n\n");
            ++callFlag;
        }

        else if (gameMod =='M' || gameMod == 'm') {
            if(callFlag == 0) {
                reSize();
                cout << ("\n Welcome to Connect Four Game\n\n");
                ++callFlag;
            }
        }


        printBoard();

    while((( choose == 'P' || choose == 'C' ) && flag <= 1)){

        if(choose == 'P'){
            while(!boardFull() && !checkWinVertical() && !checkWinHorizontal() &&
                  !checkWinDiagonal1() && !checkWinDiagonal2() && choose == 'P' && turnFlag == 1){

                if(player % 2 == 0 ){

                    cout<<("****** Start Of Turn ****** \n");
                    cout<<("Player 1 Please ");
                }
                else{
                    cout<<("Player 2 Please ");
                }

                cout<<("choose a column: ");
                cin>> select;

                if(select == "SAVE"){
                    cin>> filename;
                    save(player,choose,filename);
                }

                if(select == "LOAD"){
                    cin>> filename;
                    if(load(player,choose,filename)){
                        cout<<("Selected Game is Loading...\nPlease Wait...\n");
                        cout<<("The Game Was Succesfully Loaded:\n");
                        printBoard();
                    }
                }
                cout<<("\n");

                if(select != "SAVE" && select != "LOAD"){
                    if(96< select[0] && select[0] < 123){
                        cord = int(select[0])-96;
                    }
                    else{
                        cord = int(select[0])-64;
                    }

                    if(LegalMove(cord)){
                        play(char(cord+65),player);
                        ++livingCell;
                        printBoard();


                        if(player % 2 == 1 ){

                            cout<<("****** End Of Turn ****** \n\n");
                            if(gameMod != 'S') {
                                turnFlag = 0;
                            }
                        }
                        player += 1;
                    }
                }
            }
            if(!boardFull() && !checkWinVertical() && !checkWinHorizontal() &&
               !checkWinDiagonal1() && !checkWinDiagonal2() && choose == 'P' ){
                flag = 2;
            }
            if(boardFull()){
                flag = 2;
            }
        }

        if(choose == 'C'){
            while(!boardFull() && !checkWinVertical() && !checkWinHorizontal() &&
                  !checkWinDiagonal1() && !checkWinDiagonal2() && choose == 'C' && turnFlag == 1 ){

                if(player % 2 == 0){

                    cout<<("****** Start Of Turn ****** \n");
                    cout<<("Player 1 Please choose a column: ");
                    cin>> select;
                    if(select == "SAVE"){
                        cin>> filename;
                        save(player,choose,filename);
                    }
                    if(select == "LOAD"){
                        cin>> filename;
                        if(load(player,choose,filename)){
                            cout<<("Selected Game is Loading...\nPlease Wait...\n");
                            cout<<("The Game Was Succesfully Loaded:\n");
                            printBoard();

                        }
                    }

                    cout<<("\n");
                    if(96< select[0] && select[0] < 123){
                        cord = int(select[0])-96;
                    }
                    else{
                        cord = int(select[0])-64;
                    }
                }

                else{
                    cout<<("Computer Turn: \n");
                    cout<<("Computer Choosing... ");
                }

                if(select != "SAVE" && select != "LOAD") {
                    if (player % 2 == 0) {
                        correct = 1;
                        while(correct == 1) {
                            if (LegalMove(cord)) {
                                play(char(cord + 65), player);
                                ++livingCell;
                                printBoard();
                                correct = 0;
                            }
                            else{
                                cout<<("Player 1 Please choose a column: ");
                                cin>>select;
                                if(96< select[0] && select[0] < 123){
                                    cord = int(select[0])-96;
                                }
                                else{
                                    cord = int(select[0])-64;
                                }
                            }
                        }
                    }
                    if (player % 2 == 1) {
                        play();
                        ++livingCell;
                        printBoard();


                        cout << ("****** End Of Turn ****** \n\n");
                        if (gameMod != 'S') {
                            turnFlag = 0;
                        }

                    }
                }
                player += 1;
            }

             if(!boardFull() && !checkWinVertical() && !checkWinHorizontal() &&
               !checkWinDiagonal1() && !checkWinDiagonal2() && choose == 'C' ){
                flag = 2;
            }
            if(boardFull()){
                flag = 2;
            }
        }
    }

    if(boardFull() && !checkWinVertical() && !checkWinHorizontal() &&
       !checkWinDiagonal1() && !checkWinDiagonal2()){
        cout<<("Game Is Tie !!!\n");
    }
    else{
            if(endGame()) {
                printBoard();

            }
    }
    return 1;
}


int ConnectFour::LegalMove( int cord){
    /*Bu fonksiyon kullanıcının oynamak istediği hamlenin oynanabilir olup olmadığını
    kontrol eder. Oynanabilir ise true return eder. */
    int i,k,check;
    check = 0;

    if(cord >0 && cord < width+1 ){
        for(i = 0;i < height;++i){
                if(gameCells[i][cord-1].getValue() == ' '){
                    ++check;
                }
        }
        if(check > 0){
            return true;
        }
        else{
            cerr<<("Sütun Dolu...\n");
            return false;
        }
    }

    else{
        cerr<<("Tahta dışına çıktınız...: \n");

        return false;
    }
}

int ConnectFour::aiLegalMove( int cord){
    /*Bu fonksiyon computer'ın oynamak istediği hamlenin oynanabilir
    olup olmadığını kontrol eder. LegalMove fonksiyonundan farkı kullanıcıyı uyarmak
    için kullanılan bildirimlerden temizlenmiş olmasıdır. Amacı temiz bir oyun sunmaktır. */
    int i,k,check;
    check = 0;

    if(cord >0 && cord < width+1 ){
        for(i = 0;i < height;++i){
                if(gameCells[i][cord-1].getValue() == ' '){
                    ++check;
                }
        }
        if(check > 0){
            return true;
        }
        else{
            return false;
        }
    }

    else{
        return false;
    }
}

int ConnectFour::boardFull() const{
    /*Bu fonksiyon oyun boardunun dolup dolmadığını kontrol eder. Boşsa 0
    doluysa 1 return eder. */
    int i,k;

    for(i = 0; i < height; ++i){
        for(k = 0; k < width; ++k){
            if(gameCells[i][k].getValue() == ' '){
                return 0;
            }
        }
    }

    return 1;
}

int ConnectFour::checkWinVertical(){
    /*Bu fonksiyon herhangi birinin vertical olarak
    kazanıp kazanmadığını kontrol eder. */
    int check1,check2,i,k,a;
    check1 = 0;
    check2 = 0;

    for(i = 0;i < width;++i){
        for(k = 0; k < height; ++k){
            if(gameCells[k][i].getValue() == 'X'){
                ++check1;
            }
            else{
                check1 = 0;
            }
            if(gameCells[k][i].getValue() == 'O'){
                ++check2;
            }
            else{
                check2 = 0;
            }

            if(check1 >= 4 ){
                for(a = 0; a < 4; ++a){
                    gameCells[k-a][i].setValue('x');
                }
                cout << "\n***** Game Result *****\n";
                cout<<("Player 1 Vertical Win!!!\n\n");
                return true;
            }
            if(check2 >= 4 ){
                for(a = 0; a < 4; ++a){
                    gameCells[k-a][i].setValue('o');
                }
                cout << "\n***** Game Result *****\n";
                cout<<("Player 2 Vertical Win!!!\n\n");
                return true;
            }

        }
        check1 = 0;
        check2 = 0;
    }

    return false;
}

int ConnectFour::checkWinHorizontal(){
    /*Bu fonksiyon herhangi birinin horizontal olarak
    kazanıp kazanmadığını kontrol eder. */
    int check1,check2,i,k,a;
    check1 = 0;
    check2 = 0;

    for(i = 0;i < height;++i){
        for(k = 0; k < width; ++k){
            if(gameCells[i][k].getValue() == 'X'){
                ++check1;
            }
            else{
                check1 = 0;
            }
            if(gameCells[i][k].getValue() == 'O'){
                ++check2;
            }
            else{
                check2 = 0;
            }

            if(check1 >= 4 ){
                for(a = 0; a < 4; ++a){
                    gameCells[i][k-a].setValue('x');
                }
                cout << "\n***** Game Result *****\n";
                cout<<("Player 1 Horizontal Win!!!\n\n");
                return true;
            }
            if(check2 >= 4 ){
                for(a = 0; a < 4; ++a){
                    gameCells[i][k-a].setValue('o');
                }
                cout << "\n***** Game Result *****\n";
                cout<<("Player 2 Horizontal Win!!!\n\n");
                return true;
            }

        }
        check1 = 0;
        check2 = 0;
    }

    return false;
}

int ConnectFour::checkWinDiagonal1(){
    /*Bu fonksiyon herhangi birinin Diagonal1 \ olarak
    kazanıp kazanmadığını kontrol eder. */
    int check1,check2,i,k,a;

    check1 = 0;
    check2 = 0;

    for(i = 0;i < height;++i){
        for(k = 0; k < width  && i+k < height; ++k){
            if(gameCells[i+k][k].getValue() == 'X'){
                ++check1;
            }
            else{
                check1 = 0;
            }
            if(gameCells[i+k][k].getValue() == 'O'){
                ++check2;
            }
            else{
                check2 = 0;
            }

            if(check1 >= 4 ){
                for(a = 0; a < 4; ++a){
                    gameCells[i+k-a][k-a].setValue('x');
                }
                cout << "\n***** Game Result *****\n";
                cout<<("Player 1 Diagonal1 \\ Win!!!\n\n");
                return true;
            }
            if(check2 >= 4 ){
                for(a = 0; a < 4; ++a){
                    gameCells[i+k-a][k-a].setValue('o');
                }
                cout << "\n***** Game Result *****\n";
                cout<<("Player 2 Diagonal1 \\ Win!!!\n\n");
                return true;
            }

        }
        check1 = 0;
        check2 = 0;
    }


    check1 = 0;
    check2 = 0;

    for(i = 0;i < width;++i){
        for(k = 0; k < height && i+k < width; ++k){
            if(gameCells[k][i+k].getValue() == 'X'){
                ++check1;
            }
            else{
                check1 = 0;
            }
            if(gameCells[k][i+k].getValue() == 'O'){
                ++check2;
            }
            else{
                check2 = 0;
            }

            if(check1 >= 4 ){
                for(a = 0; a < 4; ++a){
                    gameCells[k-a][k+i-a].setValue('x');
                }
                cout << "\n***** Game Result *****\n";
                cout<<("Player 1 Diagonal1 \\ Win!!!\n\n");
                return true;
            }
            if(check2 >= 4 ){
                for(a = 0; a < 4; ++a){
                    gameCells[k-a][k+i-a].setValue('o');
                }
                cout << "\n***** Game Result *****\n";
                cout<<("Player 2 Diagonal1 \\ Win!!!\n\n");
                return true;
            }

        }
        check1 = 0;
        check2 = 0;
    }


    return false;
}

int ConnectFour::checkWinDiagonal2(){
    /*Bu fonksiyon herhangi birinin Diagonal2 / olarak
    kazanıp kazanmadığını kontrol eder. */
    int check1,check2,i,k,a;

    check1 = 0;
    check2 = 0;

    for(i = 0;i < height;++i){
        for(k = 0; k <  width && i+k < height; ++k){
            if(gameCells[i+k][width-k-1].getValue() == 'X'){
                ++check1;
            }
            else{
                check1 = 0;
            }
            if(gameCells[i+k][width-k-1].getValue() == 'O'){
                ++check2;
            }
            else{
                check2 = 0;
            }

            if(check1 >= 4 ){
                for(a = 0; a < 4; ++a){
                    gameCells[i+k-a][width-k-1+a].setValue('x');
                }
                cout << "\n***** Game Result *****\n";
                cout<<("Player 1 Diagonal2 / Win!!!\n\n");
                return true;
            }
            if(check2 >= 4 ){
                for(a = 0; a < 4; ++a){
                    gameCells[i+k-a][width-k-1+a].setValue('o');
                }
                cout << "\n***** Game Result *****\n";
                cout<<("Player 2 Diagonal2 / Win!!!\n\n");
                return true;
            }

        }
        check1 = 0;
        check2 = 0;
    }

    check1 = 0;
    check2 = 0;

    for(i = 0;i < width;++i){
        for(k = 0; k < height && (width-k-1-i) >-1; ++k){
            if(gameCells[k][width-k-1-i].getValue() == 'X'){
                ++check1;
            }
            else{
                check1 = 0;
            }
            if(gameCells[k][width-k-1-i].getValue() == 'O'){
                ++check2;
            }
            else{
                check2 = 0;
            }

            if(check1 >= 4 ){
                for(a = 0; a < 4; ++a){
                    gameCells[k-a][width-k-1-i+a].setValue('x');
                }
                cout << "\n***** Game Result *****\n";
                cout<<("Player 1 Diagonal2 / Win!!!\n\n");
                return true;
            }
            if(check2 >= 4 ){
                for(a = 0; a < 4; ++a){
                    gameCells[k-a][width-k-1-i+a].setValue('o');
                }
                cout << "\n***** Game Result *****\n";
                cout<<("Player 1 Diagonal2 / Win!!!\n\n");
                return true;
            }

        }
        check1 = 0;
        check2 = 0;
    }

    return false;
}

int ConnectFour::aiSelect(){
    /*Bu fonksiyon computerın hangi hamleyi yapacağını
    oyunun durumunu kontrol ederek belirler. */
    int check1,check2,i,k,a;
    int cord;

    if(aiWinVertical(cord)){
        cout<< "\nAiVerticalWinner: " << char(cord+96) << "\n";
        return cord;
    }
    else if(aiWinHorizontal(cord)){

        cout<< "\nAiHorizontalWinner: " << char(cord+96) << "\n";
        return cord;
    }
    /* Difficult ayarı ekle...
    else if(aiWinDiagonal1(cord)){
        cout<< "\nAiDiagonal1Winner: " << char(cord+96) << "\n";
        return cord;
    }
    else if(aiWinDiagonal2(cord)){
        cout<< "\nAiDiagonal2Winner: " << char(cord+96) << "\n";
        return cord;
    }
    */
    else if(aiPlayerHorizontalStopper(cord)){
        cout<< "\nAiPLayerHorizontalStopper: " << char(cord+96) << "\n";
        return cord;
    }
    /* Difficult ayarı ekle...
    else if(aiPlayerDiagonal1Stopper(cord)){
        cout<< "\nAiPLayerDiagonal1Stopper: " << char(cord+96) << "\n";
        return cord;
    }
    else if(aiPlayerDiagonal2Stopper(cord)){
        cout<< "\nAiPLayerDiagonal2Stopper: " << char(cord+96) << "\n";
        return cord;
    }
    */
    else if(aiPlayerVerticalStopper(cord)){
        cout<< "\nAiPLayerVerticalStopper: " << char(cord+96) << "\n";
        return cord;
    }
    do{
        cord = rand() % width + 1;
    }while(!aiLegalMove(cord));

    cout << "\nRANDOM\n";
    return cord;
}

int ConnectFour::aiPlayerVerticalStopper( int & cord){
    /*Bu fonksiyon oyuncunun bir sonra ki hamlede
    vertical olarak kazanıp kazanamayacağını kontrol eder. Eğer kazanabilecekse
    kazanmasını engellemek adına hamle yapar.. */
    int check,i,k;
    check = 0;

    for(i = 0;i < width;++i){
        for(k = 0; k < height; ++k){

            if(gameCells[k][i].getValue() == 'X'){
                ++check;
            }
            else{
                check = 0;
            }
            if(k>-1){
                if (gameCells[k][i].getValue() == 'X' && (-1< k-1 && k-1 < height)) {
                    if(gameCells[k - 1][i].getValue() == 'O') {
                        --check;
                    }
                }
            }
            if(k-3>-1) {
                if (check >= 3 && gameCells[k - 3][i].getValue() != 'O' && aiLegalMove(i + 1)) {
                    cord = i + 1;
                    return true;
                }
            }

        }
        check = 0;
    }

    return false;
}

int ConnectFour::aiPlayerHorizontalStopper(int & cord){
    /*Bu fonksiyon oyuncunun bir sonra ki hamlede Horizontal
    olarak kazanıp kazanamayacağını kontrol eder. Eğer kazanabilecekse
    kazanmasını engellemek adına hamle yapar. */
    int check,i,k;
    check = 0;


    for(i = 0;i < height;++i){
        for(k = 0; k < width ; ++k){
            if(k != width-1){
                if(gameCells[i][k].getValue() == 'X' && gameCells[i][k+1].getValue() != 'O'){
                    ++check;
                }
                else{
                    check = 0;
                }
            }
                    if (check >= 3  && aiLegalMove(k + 2)) {
                        if(i != height-1 && k != width-1) {
                            if (gameCells[i + 1][k + 1].getValue() != ' ') {
                                cord = k + 2;
                                return true;
                            }
                        }
                        else{
                            cord = k + 2;
                            return true;
                        }
                    }


        }

        check = 0;
    }

    for(i = 0;i < height;++i){
        for(k = width; k >= 0; --k){
            if(k-1>-1) {
                if (gameCells[i][k].getValue() == 'X' && gameCells[i][k - 1].getValue() != 'O') {
                    ++check;
                }
                else{
                    check = 0;
                }
            }

            if( i+ 1<height && k-1 >-1) {
                if ((check >= 3 && gameCells[i + 1][k - 1].getValue() != ' ' && aiLegalMove(k))) {
                    cord = k;
                    return true;
                }
            }
        }

        check = 0;
    }

    return false;
}

int ConnectFour::aiPlayerDiagonal1Stopper( int & cord){
    /*Bu fonksiyon oyuncunun bir sonra ki hamlede Diagonal1 \
    olarak kazanıp kazanamayacağını kontrol eder. Eğer kazanabilecekse
    kazanmasını engellemek adına hamle yapar. */
    int check,i,k,t;

    check = 0;


    for(i = 0;i < width;++i){
        for(k = 0; k < height; ++k){
            if(i+k <height) {
                if (gameCells[i + k][k].getValue() == 'X') {
                    ++check;
                }
                else{
                    check = 0;
                }
            }


            if((check >= 3  && aiLegalMove(k-2))&&
                    (-1<i + k - 3 && i + k - 3 < height)&&
                    (-1<k - 3 && k - 3 < height)) {
                if (gameCells[i + k - 3][k - 3].getValue() != 'O' && gameCells[i + k - 2][k - 3].getValue() != ' ') {
                cord = k-2;
                return true;
            }

        }
        check = 0;

        }
    }

    check = 0;

    for(i = 0;i < width;++i){
        for(k = 0; k < height; ++k){
            if(k+i < width) {
                if (gameCells[k][k + i].getValue() == 'X') {
                    ++check;
                }
                else{
                    check = 0;
                }
            }


            if((check >= 3 && aiLegalMove(i+k-2)&&
                    (-1<k-3)&&
                    (-1<i+k-3 && i+k-3 < width)&&
                    (-1<i+k-2 && i+k-2 < height))){
                if(gameCells[k-3][i+k-3].getValue() != 'O' && gameCells[i+k-2][k-3].getValue() != ' ') {
                    cord = i + k - 2;
                    return true;
                }
            }
        }
        check = 0;
    }

    return false;
}

int ConnectFour::aiPlayerDiagonal2Stopper( int & cord){
    /*Bu fonksiyon oyuncunun bir sonra ki hamlede Diagonal2 /
    olarak kazanıp kazanamayacağını kontrol eder. Eğer kazanabilecekse
    kazanmasını engellemek adına hamle yapar. */
    int check,i,k,t;

    check = 0;


    for(i = 0;i < width;++i){
        for(k = 0; k < height && i+k < height; ++k){
            if(gameCells[i+k][width-k-1].getValue() == 'X'){
                ++check;
            }
            else{
                check = 0;
            }

            if(check >= 3 && gameCells[k-3+i][width-1-k+3].getValue() != 'O' && gameCells[k-2+i][width-1-k+3].getValue() != ' ' && aiLegalMove(width-k+3)){
                cord = width-k+3;
                return true;
            }

        }
        check = 0;

    }

    check = 0;

    for(i = 0;i < width;++i){
        for(k = 0; k < height && (width-k-1-i) >-1; ++k){
            if(gameCells[k][width-k-1-i].getValue() == 'X'){
                                    ++check;
            }
            else{
                check = 0;
            }

            if(check >= 3 && gameCells[k-3][width-1-k+3-i].getValue() != 'O' && gameCells[k-2][width-1-k+3-i].getValue() != ' ' && aiLegalMove(width-k+3-i)){
                cord = width-k+3-i;
                return true;
            }

        }
        check = 0;
    }

    return false;
}

int ConnectFour::aiWinVertical( int & cord){
    /*Bu fonksiyon computer'ın bir sonra ki hamlede Vertical
    olarak kazanıp kazanamayacağını kontrol eder. Eğer computer kazanabilecekse
    kazanmasını sağlayacak şekilde hamle yapar. */
    int check,i,k;
    check = 0;

    for(i = 0;i < width;++i){
        for(k = 0; k < height; ++k){

            if(gameCells[k][i].getValue() == 'O'){
                ++check;
            }
            else{
                check = 0;
            }
            if(k>-1){
                if (gameCells[k][i].getValue() == 'X' && (-1< k-1 && k-1 < height)){
                    if(gameCells[k - 1][i].getValue() == 'O') {
                        --check;
                    }
                }
            }
            if(check >= 3 && aiLegalMove(i+1)){
                cord = i + 1;
                return true;
            }

        }
        check = 0;
    }

    return false;
}

int ConnectFour::aiWinHorizontal( int & cord){
    /*Bu fonksiyon computer'ın bir sonra ki hamlede Horizontal
    olarak kazanıp kazanamayacağını kontrol eder. Eğer computer kazanabilecekse
    kazanmasını sağlayacak şekilde hamle yapar. */
    int check,i,k;
    check = 0;


    for(i = 0;i < height;++i){
        for(k = 0; k < width; ++k){
            if(gameCells[i][k].getValue() == 'O' && k+1<width){
                if(gameCells[i][k+1].getValue() != 'X') {
                    ++check;
                }
            }
            else{
                check = 0;
            }

            if(check >= 3 && aiLegalMove(k+2) && (i+1<height && k+1 < width)){
                if(gameCells[i+1][k+1].getValue() != ' ') {
                    cord = k + 2;
                    return true;
                }
            }

        }

        check = 0;
    }

    for(i = 0;i < height;++i){
        for(k = width; k >= 0; --k){
            if(gameCells[i][k].getValue() == 'O' && k-1 > -1){
                if(gameCells[i][k-1].getValue() != 'X') {
                    ++check;
                }
            }
            else{
                check = 0;
            }

            if((check >= 3 && aiLegalMove(k)) && (i+1<height && k-1 < width)){
                if(gameCells[i+1][k-1].getValue() != ' ') {
                    cord = k;
                    return true;
                }
            }

        }

        check = 0;
    }

    return false;
}

int ConnectFour::aiWinDiagonal1( int & cord){
    /*Bu fonksiyon computer'ın bir sonra ki hamlede Diagonal1 \
    olarak kazanıp kazanamayacağını kontrol eder. Eğer computer kazanabilecekse
    kazanmasını sağlayacak şekilde hamle yapar. */
    int check,i,k,t;

    check = 0;


    for(i = 0;i < width;++i){
        for(k = 0; k < height && i+k < height; ++k){
            if(gameCells[i+k][k].getValue() == 'O'){
                ++check;
            }
            else{
                check = 0;
            }

            if( (check >= 3 && aiLegalMove(k-2)) &&
                (-1 < i+k-3 && i+k-3 < height) &&
                    (-1 < k-3 && k-3 < width ) &&
                    (-1 < i+k-2 && i+k-2 < height)
                    ){
                if(gameCells[i+k-3][k-3].getValue() != 'X' && gameCells[i+k-2][k-3].getValue() != ' ') {
                    cord = k - 2;
                    return true;
                }
            }

        }
        check = 0;

    }

    check = 0;

    for(i = 0;i < width;++i){
        for(k = 0; k < height && k+i < width; ++k){
            if(gameCells[k][k+i].getValue() == 'O'){
                ++check;
            }
            else{
                check = 0;
            }

            if((check >= 3 && aiLegalMove(i+k-2))&&
                    (-1<k-3 )&&
                    (-1<i+k-3 && i+k-3 < width)&&
                    (-1<i+k-2 && i+k-2 < height)){
                if(gameCells[k-3][i+k-3].getValue() != 'X' && gameCells[i+k-2][k-3].getValue() != ' ' ) {
                    cord = i + k - 2;
                    return true;
                }
            }
        }
        check = 0;
    }

    return false;
}

int ConnectFour::aiWinDiagonal2( int & cord){
    /*Bu fonksiyon computer'ın bir sonra ki hamlede Diagonal2 /
    olarak kazanıp kazanamayacağını kontrol eder. Eğer computer kazanabilecekse
    computer'ın kazanmasını sağlayacak şekilde hamle yapar. */
    int check,i,k,t;

    check = 0;


    for(i = 0;i < height;++i){
        for(k = 0; k < width && i+k < height; ++k){
            if(gameCells[i+k][width-k-1].getValue() == 'O'){
                ++check;
            }
            else{
                check = 0;
            }

            if((check >= 3 && aiLegalMove(width-k+3))&&
                    (-1<k-3+i && k-3+i < height)&&
                    (-1<width-1-k+3 && width-1-k+3<height)&&
                    (-1<k-2+i && k-2+i < height)){
                if(gameCells[k-3+i][width-1-k+3].getValue() != 'X' && gameCells[k-2+i][width-1-k+3].getValue() != ' ') {
                    cord = width - k + 3;
                    return true;
                }
            }

        }
        check = 0;

    }

    check = 0;

    for(i = 0;i < width;++i){
        for(k = 0; k < height; ++k){
            if(-1< width-k-1-i && width-k-1-i < width ) {
                if (gameCells[k][width - k - 1 - i].getValue() == 'O') {
                    ++check;
                }
            }
            else{
                check = 0;
            }

            if((check >= 3 && aiLegalMove(width-k+3-i))&&
                    (-1<k-3 && k-3 < height)&&
                    (-1<width-1-k+3-i && width-1-k+3-i < width)&&
                    (-1<k-2 && k-2 < height)){
                if(gameCells[k-3][width-1-k+3-i].getValue() != 'X' && gameCells[k-2][width-1-k+3-i].getValue() != ' ') {
                    cord = width - k + 3 - i;
                    return true;
                }
            }

        }
        check = 0;
    }

    return false;
}

int ConnectFour::save(int players,char mod, string filename){
    /* Run time sırasında oyun oynanırken o an ki oyunu istenilen dosyaya kaydeder. */
    ofstream file1;
    file1.open(filename);

    if (!(file1.is_open())){
        cerr << "File Cannot Created. \n";
        cerr << "Try again or continue game. \n";
        return 0;
    }
    else{
        file1 << players<<"\n"<< mod <<"\n" << height << "\n" << width << "\n";
        for (int i = 0; i < height; ++i){
            for (int j = 0; j < width; ++j){
                file1 << gameCells[i][j].getValue();
            }
        }
        file1 << "\n";
        for (int i = 0; i < height; ++i){
            for (int j = 0; j < width; ++j){
                file1 << gameCells[i][j].getPosition();
            }
        }
        file1 << "\n";
        for (int i = 0; i < height; ++i){
            for (int j = 0; j < width; ++j){
                file1 << gameCells[i][j].getheight();
                file1 << "\n";
            }
        }
        file1.close();
    }
    return 1;
}

int ConnectFour::load(int & players,char & mod,string filename){
    /* Run time sırasında oyun oynanırken başka bir oyunu her şeyiyle belirtilen dosyadan getirir.
    ve o dosyada ki oyuna devam edilir. */
    char ch;
    char chboard[MAX][MAX];
    int a;
    ifstream file1;
    file1.open(filename);
    if (!(file1.is_open())){
        cerr << "File Cannot Open. \n";
        cerr << "Try again or continue game. \n";
        return 0;
    }

    else{
        file1>>players;
        file1.get(ch); // for buffer endline

        file1.get(ch);
        mod = ch;
        file1.get(ch);// for buffer endline

        file1>>height;
        file1.get(ch);// for buffer endline

        file1>>width;
        file1.get(ch);// for buffer endline

        gameCells.resize(height);
        for (int i = 0; i < height; ++i) {
            gameCells[i].resize(width);
        }
        for (int i = 0; i < height; ++i){
            for (int j = 0; j < width; ++j){
                file1.get(chboard[i][j]);
                gameCells[i][j].setValue(chboard[i][j]);
            }
        }
        file1.get(ch);// for buffer endline
        for (int i = 0; i < height; ++i){
            for (int j = 0; j < width; ++j){
                file1.get(chboard[i][j]);
                gameCells[i][j].setPosition(chboard[i][j]);
            }
        }
        file1.get(ch);// for buffer endline
        for (int i = 0; i < height; ++i){
            for (int j = 0; j < width; ++j){
                file1 >> a;
                gameCells[i][j].setheight(a);
                file1.get(ch);// for buffer endline
            }
        }
        file1.close();
    }
    return 1;
}


