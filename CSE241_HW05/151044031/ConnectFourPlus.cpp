#include "ConnectFourPlus.h"


namespace ConnectFourGame{
/* PlayGame Sadece Vertical ve Horizontal Winleri Kontrol edecek sekilde Override Edildi. */
	int ConnectFourPlus::playGame(){
	    /*Oyunun temelini oluşturan fonksiyondur. Oyunu oluşturan diğer fonksiyonlar
	    burada bir bütün halinde çağırılır.Oyunun oynanışı ve işleyişi bu fonksiyonda gerçekleşir.*/
	    /* Bu fonksiyon cok uzun biliyorum. Lakin copy-paste yaptigim seyler kucuk degisikliklere
	    sahip oldugundan hic genel bir fonksiyona donusturulemiyor.*/
	    int cord;
	    string select;
	    string filename;
	    string fileboard;
	    int player = 0;
	    int flag = 0;
	    int turnFlag = 1;
	    int correct = 1;


	    createNewTable(); //New HW05 function in ConnectFourAbstract

	    cout << "Please Choose P for PVP, C for PVC: \n"; 
	    /*PVP veya PVC secilecek. */
	    while (true) {
	        cin >> choose;

	        if (choose == 'p' || choose == 'c') {
	            choose = char(int(choose) - 32);
	        }

	        if (choose == 'P' || choose == 'C') {
	            break;
	        }

	        cerr << ("Error: Wrong Choice. \nPlease Choose P for PVP, C for PVC: ");
	    }
		
	    if(callFlag == 1) {
	        cout << ("\n Welcome to Connect Four Game\n\n");
	        ++callFlag;
	    }
	    /* ----------------- Baslik basildi ---------------------- */
	    
	    printBoard();

	    /*Oyun burda donmeye baslayacak.Normal flag PVC'ken PVP load edilirse diye var. 
	    Ve tam tersi icin.*/

	    while((( choose == 'P' || choose == 'C' ) && flag <= 1)){ 
	    	/* PvP'deyken PVC load edince kod
	    	choose P if'inden cikip PVC'ye  PVC alt satirda diye devam edebiliyordu. Ama PVC'den PVP'ye
	    	donemiyordu.Bu yüzden bu while var. */
	        if(choose == 'P'){
	            while(!boardFull() && !checkWinVertical() && !checkWinHorizontal() && choose == 'P'){
	                /* While'da oyunun bitme durumlari kontrol ediliyor.Ardindan 2 kisilik oyun baslayacak 
	                oyun bitene kadar donecek.. */
	                if(player % 2 == 0 ){

	                    cout<<("****** Start Of Turn ****** \n");
	                    cout<<("Player 1 Please ");
	                }
	                else{
	                    cout<<("Player 2 Please ");
	                }

	                cout<<("choose a column: ");
	                cin>> select;
	                if(cin.eof()){
	                	exit(1);
	                }
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

	                /* Column veya Save Load komutlari secimi yapıldı.Ardından secim kontrol
	                ediliyor. */

	                if(select != "SAVE" && select != "LOAD"){
	                    if(96< select[0] && select[0] < 123){
	                        cord = int(select[0])-96;
	                    }
	                    else{
	                        cord = int(select[0])-64;
	                    }

	                    if(LegalMove(cord)){
	                        ConnectFourAbstract::play(char(cord+65),player);
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
	            } /*while sonu*/

	            if(!boardFull() && !checkWinVertical() && !checkWinHorizontal() && choose == 'P' ){
	                flag = 2;
	            }
	            if(boardFull()){
	                flag = 2;
	            }
	        } /*if secim P sonu */

	        if(choose == 'C'){
	             /*Pvp oyunu baslayacak oyun bitene(multiyse tur bitene) kadar donecek. */
	            while(!boardFull() && !checkWinVertical() && !checkWinHorizontal() && choose == 'C'){

	                if(player % 2 == 0){

	                    cout<<("****** Start Of Turn ****** \n");
	                    cout<<("Player 1 Please choose a column: ");
	                    cin>> select;
	                    if(cin.eof()){
	                		exit(1);
	                	}
	                    if(select == "SAVE"){
	                        cin>> filename;
	                        save(player,choose,filename);
	                    }
	                    if(select == "LOAD"){
	                        cin>> filename;
	                        if(load(player,choose,filename)){
	                            cout<<("Selected Game is Loading...\nPlease Wait...\n");
	                            cout<<("The Game Was Succesfully Loaded:\n");
	     					
	     					if(cin.eof()){
	                    		exit(1);
	                		}
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

	                else if(select != "SAVE" && select != "LOAD"){
	                    cout<<("Computer Turn: \n");
	                    cout<<("Computer Choosing... ");
	                }

	                if(select != "SAVE" && select != "LOAD") {
	                    if (player % 2 == 0) {
	                        correct = 1;
	                        
	                        while(correct == 1) { 
							    if(cin.eof()){
						        	exit(1);
				                }               

		                		if (LegalMove(cord)) {
	                                ConnectFourAbstract::play(char(cord + 65), player);
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
						                if(cin.eof()){
						                    exit(1);
						                }

				            		}
	                            }
	                        } // while correct 1 in sonu
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
	            } // while checkwin sonu

	            if(!boardFull() && !checkWinVertical() && !checkWinHorizontal() && choose == 'C' ){
	                flag = 2;
	            }
	            if(boardFull()){
	                flag = 2;
	            }
	        }/*if choose C sonu */
	    }/* en dis while'ın sonu */

	    if(boardFull() && !checkWinVertical() && !checkWinHorizontal()){
	        cout<<("Game Is Tie !!!\n");
	    }
	    else{
	        if(endGame()) {
	            printBoard();

	        }
	    }
	    return 1;
	}

	/* aiSelect Sadece Vertical ve Horizontal Durumlara Gore ozel hareket yapacak sekilde Override Edildi. */
	int ConnectFourPlus::aiSelect(){
	    /*Bu fonksiyon computerın hangi hamleyi yapacağını
	    oyunun durumunu kontrol ederek belirler. */

	    int cord;

	    if(aiWinVertical(cord)){
	        cout<< "\nAiVerticalWinner: " << char(cord+96) << "\n";
	        return cord;
	    }
	    else if(aiWinHorizontal(cord)){

	        cout<< "\nAiHorizontalWinner: " << char(cord+96) << "\n";
	        return cord;
	    }
	   
	    else if(aiPlayerHorizontalStopper(cord)){
	        cout<< "\nAiPLayerHorizontalStopper: " << char(cord+96) << "\n";
	        return cord;
	    }

	    else if(aiPlayerVerticalStopper(cord)){
	        cout<< "\nAiPLayerVerticalStopper: " << char(cord+96) << "\n";
	        return cord;
	    }
	    do{
	        cord = rand() % width + 1;
	    }while(!aiLegalMove(cord));

	    /*Hic stratejik hamle bulamazsa random atar.*/
	    cout << "\nRANDOM\n";
	    return cord;
	}
	/* Override PlayGame de bu versiyonu kullanilsin diye override edildi. */
	void ConnectFourPlus::setBoard(){
	    /* Boardu oluşturan double arrayin sonra ki fonksiyonlar da junk değerler
	    yüzünden sorun çıkarması için array boşluk karakteriyle doldurulur. */
	    int i, k;
	    
	    gameCells = new Cell *[height];
	    
	    for(i = 0; i < height; ++i){
	            gameCells[i] = new Cell[width];    
	    }
	    for(i = 0; i < height; ++i){
	        for(k = 0; k < width; ++k){
	            gameCells[i][k].setValue('.');
	        }
	    }
	    for(i = 0; i < height; ++i){
	        for(k = 0; k < width; ++k){
	            gameCells[i][k].setPosition(char('A'+i));
	        }
	    }
	    for(i = 0; i < height; ++i){
	        for(k = 0; k < width; ++k){
	            gameCells[i][k].setheight(i);
	        }
	    }
	}
	/* Play ConnecFourPlusta ki Override edilmis aiSelecti Cagirsin diye override edildi. */
	void ConnectFourPlus::play(){
	    /* Bu fonksiyon kullanıcı ya da computerın oynamak istediği hamleyi boarda
	    yani arraye işler. */
	    int i;
	    int cord;

	    cord = aiSelect();

	    for(i = height-1; i >= 0;){
	        if( gameCells[i][cord-1].getValue()== '.'){
	            gameCells[i][cord-1].setValue('O');
	            i = -1;
	        }

	        else{
	            i = i - 1;
	        }

	    }
	    cout << "\nComputer Choosed: " << char(cord+96) << "\n";
	}
}