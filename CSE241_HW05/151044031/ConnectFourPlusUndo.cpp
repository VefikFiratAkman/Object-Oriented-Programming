#include "ConnectFourPlusUndo.h"

using namespace std;


namespace ConnectFourGame{
	/* PlayGame Sadece Vertical ve Horizontal Winleri Kontrol edecek sekilde Override Edildi.
	Ayrıca Undo Komutunu kabul edecegi yer eklendi. */
	int ConnectFourPlusUndo::playGame(){
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
	                if(select == "UNDO"){
	                	if(undo()){
	                		--player;
	                		--livingCell;
	                		printBoard();
	                	}
	                	
	                	
                	}
	                cout<<("\n");

	                /* Column veya Save Load komutlari secimi yapıldı.Ardından secim kontrol
	                ediliyor. */

	                if(select != "SAVE" && select != "LOAD" && select != "UNDO"){
	                    if(96< select[0] && select[0] < 123){
	                        cord = int(select[0])-96;
	                    }
	                    else{
	                        cord = int(select[0])-64;
	                    }

	                    if(LegalMove(cord)){
	                        ConnectFourAbstract::play(char(cord+65),player);
	                        history[livingCell] = cord;
	                        ++livingCell;
	                        printBoard();


	                        if(player % 2 == 1 ){
	                            cout<<("****** End Of Turn ****** \n\n");
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
	                    if(select == "UNDO"){
	                		undo();
	                		--livingCell;
	                		play();
	                        ++livingCell;
	                        printBoard();
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

	                if(select != "SAVE" && select != "LOAD" && select != "UNDO") {
	                    if (player % 2 == 0) {
	                        correct = 1;
	                        
	                        while(correct == 1) { 
							    if(cin.eof()){
						        	exit(1);
				                }               

		                		if (LegalMove(cord)) {
	                                ConnectFourAbstract::play(char(cord + 65), player);
	                                history[livingCell] = cord;
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
	/* Play ConnecFourPlusta ki Override edilmis aiSelecti Cagirsin diye override edildi. */
	void ConnectFourPlusUndo::play(){
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
	    history[livingCell] = cord;
	    cout << "\nComputer Choosed: " << char(cord+96) << "\n";
	}
	/* Save Undo Historysini tutsun  diye override edildi. */
	int ConnectFourPlusUndo::save(int players,char mod, string filename)const{
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

	            file1 <<livingCell << "\n";

	        /*Burda hizlica tekli degerleri atiyor. */


	        /* Ardindan Board'u olusturan Cell hucrelerinin
	        degerleri file'a isleniyor. */
	        for (int i = 0; i < height; ++i){
	            for (int j = 0; j < width; ++j){
	              file1 << gameCells[i][j].getValue();
	            }
	            file1 <<"\n";
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

	        for (int i = 0; i < livingCell; ++i){
	            file1 <<history[i];
	            file1 <<"\n";
	        }


	        file1.close();
	    }
	    return 1;
	}
	/* Load Undo Historysini alsin  diye override edildi. */
	int ConnectFourPlusUndo::load(int & players,char & mod,string filename){
	    /* Run time sırasında oyun oynanırken başka bir oyunu her şeyiyle belirtilen dosyadan getirir.
	    ve o dosyada ki oyuna devam edilir. */
	    char ch;
	    char chboard[100][100];
	    int a,i,k;


	    ifstream file1;
	    file1.open(filename);
	    if (!(file1.is_open())){
	        cerr << "File Cannot Open. \n";
	        cerr << "Try again or continue game. \n";
	        return 0;
	    }

	    /* Once ki oyunun dynamic array'i silinir.*/
	    else{

	        for(i = 0; i < height; ++i){
	            delete [] gameCells[i];
	        }

	        delete [] gameCells;

	      

	        file1>>players;
	        file1.get(ch); // for buffer endline

	        file1.get(ch);
	        mod = ch;
	        file1.get(ch);// for buffer endline

	        file1>>height;
	        file1.get(ch);// for buffer endline

	        file1>>width;
	        file1.get(ch);// for buffer endline


	        file1 >> livingCell;
	        file1.get(ch);// for buffer endline

	        /* Height width vs yeni degerleri alinmistir. */


	        /* Yeni size'la yeni bir dynamic array olusturulur. */
	        gameCells = new Cell *[height];
	        
	        for(i = 0; i < height; ++i){
	            
	                gameCells[i] = new Cell[width];
	            
	        }

	         /* Board'u olusturan yeni cell hucrelerinin degerleri
	         doldurulur. */
	        for (int i = 0; i < height; ++i){
	            for (int j = 0; j < width; ++j){
	                file1.get(chboard[i][j]);
	                gameCells[i][j].setValue(chboard[i][j]);
	            }
	            file1.get(ch);// for buffer endline
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

	        for (int i = 0; i < livingCell; ++i){
	            file1 >> history[i];
	        }

	        file1.close();
	    }
	    return 1;
	}
	/* HW05 new Func. Undo Ozelligi icin var */
	int ConnectFourPlusUndo::undo(){
		int i;
		int cord;
		
		cord = history[livingCell-1];
		/* LivingCell hamle sayisini belirlemekte kullanildi.
		Play fonksiyonuyla neredeyse ayni sadece X,O yerine . yapiyor. */
		if(livingCell - 1 >= 0){
		    for(i = height-1; i >= 0;){
		        if( gameCells[i][cord-1].getValue()== '.'){
		            gameCells[i+1][cord-1].setValue('.');
		            i = -1;
		            return 1;
		        }

		        else{
		            i = i - 1;
		        }

	    	}
		}
		else{
			cout<< "There Are No Moves To Be Taken Back\n";
			return 0;
		}	
    }



}