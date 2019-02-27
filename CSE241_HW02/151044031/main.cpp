#include <iostream>
#include <stdlib.h> 
#include <time.h>
#include <fstream>
#include <string>

using namespace std;
#define MAX 100

void printBoard(char board[][MAX],const int & row,const int & col);
void setBoard(char board[][MAX],int row, int col);
int boardFull(char board[][MAX],int row, int col);
int move(char board[][MAX],int row, int col, int cord, int players);
int game(char board[][MAX],int row, int col);
int checkWinVertical(char board[][MAX],int row, int col);
int checkWinHorizontal(char board[][MAX],int row, int col);
int checkWinDiagonal1(char board[][MAX],int row, int col);
int checkWinDiagonal2(char board[][MAX],int row, int col);
int LegalMove(char board[][MAX],int row, int col, int cord);
int aiLegalMove(char board[][MAX],int row, int col, int cord);
int aiSelect(char board[][MAX],int row, int col);
int aiPlayerVerticalStopper(char board[][MAX],int row, int col,int & cord);
int aiPlayerHorizontalStopper(char board[][MAX],int row, int col,int & cord);
int aiPlayerDiagonal1Stopper(char board[][MAX],int row, int col,int & cord);
int aiPlayerDiagonal2Stopper(char board[][MAX],int row, int col,int & cord);
int aiWinVertical(char board[][MAX],int row, int col,int & cord);
int aiWinHorizontal(char board[][MAX],int row, int col,int & cord);
int aiWinDiagonal1(char board[][MAX],int row, int col,int & cord);
int aiWinDiagonal2(char board[][MAX],int row, int col,int & cord);
int save(char board[][MAX],int players,char mod,int size, string filename = "game.txt");
int load(char board[][MAX],int & players,char & mod,int & size, string filename);

int main(){
	/*Burada kullanıcıdan board'un size alınır. Ve game fonksiyonu çağrılır. */
	char board[MAX][MAX];
	int col,row;
	srand (time(NULL));
	cout<<("Please Enter Row&Column Even Number Between 4-20: ");
	while(true){
		
		cin>>row;
		if(!cin){
			cin.clear();
			cin.ignore();
		}
		col = row;
		if((row >= 4 && row <=20) && row % 2 == 0){
			break;
		}
		else{
			cerr<<("Error: Please Choose A Even Number Between 4-20: ");
		}
	}

	game(board,row,col);  
}

void printBoard(char board[][MAX],const int & row,const int & col){
	/*Oyun tahtasını terminale kuralına uygun basar. */
	int i;
	auto k = 0;
	decltype(i*1) j;

	for(i = 0; i < row; ++i){
		for(k = 0; k < col; ++k){
			cout<<("| ") << board[i][k] << (" ");
		}
		cout<<("|\n");
		for(j = 0; j < col*4; ++j){
	  		cout<<("-");
		}
		cout<<("-\n");
	}
	
	for(k = 1; k <= col; ++k){
		cout<<("  ") << char(k+96) << " ";
	}
	cout<<("\n");
}

void setBoard(char board[][MAX],int row, int col){
	/* Boardu oluşturan double arrayin sonra ki fonksiyonlar da junk değerler
	yüzünden sorun çıkarması için array boşluk karakteriyle doldurulur. */
	int i, k;

	for(i = 0; i < row; ++i){
		for(k = 0; k < col; ++k){
			board[i][k] = ' ';
			//board[i][k] = k+(i*col);
		}
	}
}

int boardFull(char board[][MAX],int row, int col){
	/*Bu fonksiyon oyun boardunun dolup dolmadığını kontrol eder. Boşsa 0 
	doluysa 1 return eder. */
	int i,k;

	for(i = 0; i < row; ++i){
		for(k = 0; k < col; ++k){
			if(board[i][k] == ' '){
				return 0;
			}
		}
	}

	return 1;
}

int move(char board[][MAX],int row, int col, int cord, int players){
	/* Bu fonksiyon kullanıcı ya da computerın oynamak istediği hamleyi boarda
	yani arraye işler. */
	int i;

	for(i = row-1; i >= 0;){
		if( board[i][cord-1]== ' '){

	 		if(players % 2 == 0){
				board[i][cord-1] = 'X';
			}
			else{
				board[i][cord-1] = 'O';
			}

			i = -1;
		}

		else{
			i = i - 1;
		}

	}
}

int LegalMove(char board[][MAX],int row, int col, int cord){
	/*Bu fonksiyon kullanıcının oynamak istediği hamlenin oynanabilir olup olmadığını 
	kontrol eder. Oynanabilir ise true return eder. */
	int i,k,check;
	check = 0;

	if(cord >0 && cord < col+1 ){
		for(i = 0;i < col;++i){
				if(board[i][cord-1] == ' '){
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

int aiLegalMove(char board[][MAX],int row, int col, int cord){
	/*Bu fonksiyon computer'ın oynamak istediği hamlenin oynanabilir
	olup olmadığını kontrol eder. LegalMove fonksiyonundan farkı kullanıcıyı uyarmak
	için kullanılan bildirimlerden temizlenmiş olmasıdır. Amacı temiz bir oyun sunmaktır. */
	int i,k,check;
	check = 0;

	if(cord >0 && cord < col+1 ){
		for(i = 0;i < col;++i){
				if(board[i][cord-1] == ' '){
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

int game(char board[][MAX],int row, int col){
	/*Oyunun temelini oluşturan fonksiyondur. Oyunu oluşturan diğer fonksiyonlar
	burada bir bütün halinde çağırılır.Oyunun oynanışı ve işleyişi bu fonksiyonda gerçekleşir.*/
	int cord;
	char choose;
	string select;
	string filename;
	int player = 0;
	int flag = 0;

	setBoard(board,row,col);
	cout<<("\n Welcome to Connect Four Game\n\n");
	printBoard(board,row,col);
	
	cout<<("Please Choose Game Mod: P for PVP, C for PVC: ");	
	while(true){
		cin>> choose;
		
		if( choose == 'p' || choose == 'c'){
			choose = char(int(choose) - 32);
		}
		if(choose == 'P' || choose == 'C'){
			break;
		}
		cerr<<("Error: Wrong Choose. \nPlease Choose P for PVP, C for PVC: ");
	}

	while((( choose == 'P' || choose == 'C' ) && flag <= 1)){
		
		if(choose == 'P'){
			while(!boardFull(board,row,col) && !checkWinVertical(board,row,col) && !checkWinHorizontal(board,row,col) && 
				!checkWinDiagonal1(board,row,col) && !checkWinDiagonal2(board,row,col) && choose == 'P' ){
				
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
					save(board,player,choose,row,filename);
				}

				if(select == "LOAD"){
					cin>> filename;
					if(load(board,player,choose,row,filename)){
						col = row;
						cout<<("Selected Game is Loading...\nPlease Wait...\n");
						cout<<("The Game Was Succesfully Loaded:\n");
						printBoard(board,row,col);
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

					if(LegalMove(board,row,col,cord)){
						move(board,row,col,cord,player);
						printBoard(board,row,col);
						if(player % 2 == 1 ){
							cout<<("****** End Of Turn ****** \n\n");					
						}	
						player += 1;
					}
				}
			}
			if(!boardFull(board,row,col) && !checkWinVertical(board,row,col) && !checkWinHorizontal(board,row,col) && 
				!checkWinDiagonal1(board,row,col) && !checkWinDiagonal2(board,row,col) && choose == 'P' ){
				flag = 2;
			}
			if(boardFull(board,row,col)){
				flag = 2;
			}
		}

		if(choose == 'C'){
			while(!boardFull(board,row,col) && !checkWinVertical(board,row,col) && !checkWinHorizontal(board,row,col) && 
				!checkWinDiagonal1(board,row,col) && !checkWinDiagonal2(board,row,col) && choose == 'C' ){

				if(player % 2 == 0){
					cout<<("****** Start Of Turn ****** \n");
					cout<<("Player 1 Please choose a column: ");
					cin>> select;
					if(select == "SAVE"){
						cin>> filename;
						save(board,player,choose,row,filename);
					}
					if(select == "LOAD"){
						cin>> filename;
						if(load(board,player,choose,row,filename)){
							col = row;
							cout<<("Selected Game is Loading...\nPlease Wait...\n");
							cout<<("The Game Was Succesfully Loaded:\n");
							printBoard(board,row,col);
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
					cord = aiSelect(board,row,col);	
				}
				
				if(select != "SAVE" && select != "LOAD"){
					if(LegalMove(board,row,col,cord)){
						move(board,row,col,cord,player);
						printBoard(board,row,col);
						if(player % 2 == 1){
							cout << "Computer Choosed: "<< char(cord+96) << "\n";
							cout<<("****** End Of Turn ****** \n\n");
						}
						player += 1;
						
					} 
				}
			}
			if(!boardFull(board,row,col) && !checkWinVertical(board,row,col) && !checkWinHorizontal(board,row,col) && 
				!checkWinDiagonal1(board,row,col) && !checkWinDiagonal2(board,row,col) && choose == 'C' ){
				flag = 2;
			}
			if(boardFull(board,row,col)){
				flag = 2;
			}
		}
	}

	if(boardFull(board,row,col) && !checkWinVertical(board,row,col) && !checkWinHorizontal(board,row,col) &&
		!checkWinDiagonal1(board,row,col) && !checkWinDiagonal2(board,row,col)){
		cout<<("Game Is Tie !!!\n");
	}
	else{
		printBoard(board,row,col);
	}
}

int checkWinVertical(char board[][MAX],int row, int col){
	/*Bu fonksiyon herhangi birinin vertical olarak 
	kazanıp kazanmadığını kontrol eder. */
	int check1,check2,i,k,a;
		check1 = 0;
		check2 = 0;
	
	for(i = 0;i < row;++i){
		for(k = 0; k < col; ++k){
			if(board[k][i] == 'X'){
				++check1;
			}
			else{
				check1 = 0;
			}
			if(board[k][i] == 'O'){
				++check2;
			}
			else{
				check2 = 0;
			}

			if(check1 >= 4 ){
				for(a = 0; a < 4; ++a){
					board[k-a][i] = 'x';
				}
				cout << "\n***** Game Result *****\n";
				cout<<("Player 1 Vertical Win!!!\n\n");
				return true;
			}
			if(check2 >= 4 ){
				for(a = 0; a < 4; ++a){
					board[k-a][i] = 'o';
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

int checkWinHorizontal(char board[][MAX],int row, int col){
	/*Bu fonksiyon herhangi birinin horizontal olarak 
	kazanıp kazanmadığını kontrol eder. */
	int check1,check2,i,k,a;
		check1 = 0;
		check2 = 0;
	
	for(i = 0;i < row;++i){
		for(k = 0; k < col; ++k){
			if(board[i][k] == 'X'){
				++check1;
			}
			else{
				check1 = 0;
			}	
			if(board[i][k] == 'O'){
				++check2;
			}
			else{
				check2 = 0;
			}

			if(check1 >= 4 ){
				for(a = 0; a < 4; ++a){
					board[i][k-a] = 'x';
				}
				cout << "\n***** Game Result *****\n";
				cout<<("Player 1 Horizontal Win!!!\n\n");
				return true;
			}
			if(check2 >= 4 ){
				for(a = 0; a < 4; ++a){
					board[i][k-a] = 'o';
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

int checkWinDiagonal1(char board[][MAX],int row, int col){
	/*Bu fonksiyon herhangi birinin Diagonal1 \ olarak 
	kazanıp kazanmadığını kontrol eder. */
	int check1,check2,i,k,a;

		check1 = 0;
		check2 = 0;
	
		for(i = 0;i < col;++i){
			for(k = 0; k < row; ++k){
				if(board[i+k][k] == 'X'){
					++check1;
				}
				else{
					check1 = 0;
				}
				if(board[i+k][k] == 'O'){
					++check2;
				}
				else{
					check2 = 0;
				}

				if(check1 >= 4 ){
					for(a = 0; a < 4; ++a){
						board[i+k-a][k-a] = 'x';
					}
				cout << "\n***** Game Result *****\n";
				cout<<("Player 1 Diagonal1 \\ Win!!!\n\n");
					return true;
				}
				if(check2 >= 4 ){
					for(a = 0; a < 4; ++a){
						board[i+k-a][k-a] = 'o';
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
	
		for(i = 0;i < col;++i){
			for(k = 0; k < row; ++k){
				if(board[k][i+k] == 'X'){
					++check1;
				}
				else{
					check1 = 0;
				}
				if(board[k][i+k] == 'O'){
					++check2;
				}
				else{
					check2 = 0;
				}

				if(check1 >= 4 ){
					for(a = 0; a < 4; ++a){
						board[k-a][k+i-a] = 'x';
					}
				cout << "\n***** Game Result *****\n";
				cout<<("Player 1 Diagonal1 \\ Win!!!\n\n");
					return true;
				}
				if(check2 >= 4 ){
					for(a = 0; a < 4; ++a){
						board[k-a][k+i-a] = 'o';
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

int checkWinDiagonal2(char board[][MAX],int row, int col){
	/*Bu fonksiyon herhangi birinin Diagonal2 / olarak 
	kazanıp kazanmadığını kontrol eder. */
	int check1,check2,i,k,a;
		
		check1 = 0;
		check2 = 0;
	
		for(i = 0;i < col;++i){
			for(k = 0; k < row; ++k){
				if(board[i+k][col-k-1] == 'X'){
					++check1;
				}
				else{
					check1 = 0;
				}
				if(board[i+k][col-k-1] == 'O'){
					++check2;
				}
				else{
					check2 = 0;
				}

				if(check1 >= 4 ){
					for(a = 0; a < 4; ++a){
						board[i+k-a][col-k-1+a] = 'x';
					}
				cout << "\n***** Game Result *****\n";
				cout<<("Player 1 Diagonal2 / Win!!!\n\n");
					return true;
				}
				if(check2 >= 4 ){
					for(a = 0; a < 4; ++a){
						board[i+k-a][col-k-1+a] = 'o';
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
	
		for(i = 0;i < col;++i){
			for(k = 0; k < row; ++k){
				if(board[k][col-k-1-i] == 'X'){
					++check1;
				}
				else{
					check1 = 0;
				}
				if(board[k][col-k-1-i] == 'O'){
					++check2;
				}
				else{
					check2 = 0;
				}

				if(check1 >= 4 ){
					for(a = 0; a < 4; ++a){
						board[k-a][col-k-1-i+a] = 'x';
					}
				cout << "\n***** Game Result *****\n";
				cout<<("Player 1 Diagonal2 / Win!!!\n\n");
					return true;
				}
				if(check2 >= 4 ){
					for(a = 0; a < 4; ++a){
						board[k-a][col-k-1-i+a] = 'o';
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

int aiSelect(char board[][MAX],int row, int col){
	/*Bu fonksiyon computerın hangi hamleyi yapacağını
	oyunun durumunu kontrol ederek belirler. */
	int check1,check2,i,k,a;
	int cord;

	if(aiWinVertical(board,row,col,cord)){
		cout<< "\nAiVerticalWinner: " << char(cord+96) << "\n";
			return cord;
	}
	else if(aiWinHorizontal(board,row,col,cord)){

		cout<< "\nAiHorizontalWinner: " << char(cord+96) << "\n";
			return cord;
		}
	else if(aiWinDiagonal1(board,row,col,cord)){
		cout<< "\nAiDiagonal1Winner: " << char(cord+96) << "\n";
			return cord;
		}
	else if(aiWinDiagonal2(board,row,col,cord)){
			cout<< "\nAiDiagonal2Winner: " << char(cord+96) << "\n";
			return cord;
		}
	else if(aiPlayerHorizontalStopper(board,row,col,cord)){
		cout<< "\nAiPLayerHorizontalStopper: " << char(cord+96) << "\n";
			return cord;
		}
	else if(aiPlayerDiagonal1Stopper(board,row,col,cord)){
			cout<< "\nAiPLayerDiagonal1Stopper: " << char(cord+96) << "\n";
			return cord;
	}
	else if(aiPlayerDiagonal2Stopper(board,row,col,cord)){
			cout<< "\nAiPLayerDiagonal2Stopper: " << char(cord+96) << "\n";
			return cord;
	}
	else if(aiPlayerVerticalStopper(board,row,col,cord)){
			cout<< "\nAiPLayerVerticalStopper: " << char(cord+96) << "\n";
			return cord;
	}
	do{
		cord = rand() % col + 1;
	}while(!aiLegalMove(board,row,col,cord));
	cout << "\nRANDOM\n";
	return cord;
}

int aiPlayerVerticalStopper(char board[][MAX],int row, int col,int & cord){
	/*Bu fonksiyon oyuncunun bir sonra ki hamlede
	vertical olarak kazanıp kazanamayacağını kontrol eder. Eğer kazanabilecekse
	kazanmasını engellemek adına hamle yapar.. */
	int check,i,k;
	check = 0;
        
	for(i = 0;i < row;++i){
		for(k = 0; k < col; ++k){
	
			if(board[k][i] == 'X'){
				++check;
			}
			else{
				check = 0;
			}
			if(board[k][i] == 'X' && board[k-1][i] == 'O' ){
				--check;
			}

			if(check >= 3  && board[k-3][i] != 'O' && aiLegalMove(board,row,col,i+1)){
				cord = i + 1;
				return true;
			}
		
		}
		check = 0;
	}

	return false;
}

int aiPlayerHorizontalStopper(char board[][MAX],int row, int col,int & cord){
	/*Bu fonksiyon oyuncunun bir sonra ki hamlede Horizontal
	olarak kazanıp kazanamayacağını kontrol eder. Eğer kazanabilecekse
	kazanmasını engellemek adına hamle yapar. */
	int check,i,k;
		check = 0;
		

	for(i = 0;i < row;++i){
		for(k = 0; k < col; ++k){
			if(board[i][k] == 'X' && board[i][k+1] != 'O'){
				++check;
			}
			else{
				check = 0;
			}	
			
			if(check >= 3  && board[i+1][k+1] != ' ' && aiLegalMove(board,row,col,k+2)){
				cord = k+2;
				return true;
			}
		
		}

		check = 0;
	}

	for(i = 0;i < row;++i){
		for(k = col; k >= 0; --k){
			if(board[i][k] == 'X' && board[i][k-1] != 'O'){
				++check;
			}
			else{
				check = 0;
			}	
			
			if((check >= 3  && board[i+1][k-1] != ' ' && aiLegalMove(board,row,col,k))){
				cord = k;
				return true;
			}
		
		}

		check = 0;
	}

	return false;
}

int aiPlayerDiagonal1Stopper(char board[][MAX],int row, int col,int & cord){
	/*Bu fonksiyon oyuncunun bir sonra ki hamlede Diagonal1 \
	olarak kazanıp kazanamayacağını kontrol eder. Eğer kazanabilecekse
	kazanmasını engellemek adına hamle yapar. */
	int check,i,k,t;

		check = 0;

	
		for(i = 0;i < col;++i){
			for(k = 0; k < row; ++k){
				if(board[i+k][k] == 'X'){
					++check;
				}
				else{
					check = 0;
				}

				if(check >= 3 && board[i+k-3][k-3] != 'O' && board[i+k-2][k-3] != ' ' && aiLegalMove(board,row,col,k-2)){
					cord = k-2;
					return true;
				}
			
			}
			check = 0;

		}
	
		check = 0;

		for(i = 0;i < col;++i){
			for(k = 0; k < row; ++k){
				if(board[k][k+i] == 'X'){
					++check;
				}
				else{
					check = 0;
				}

				if(check >= 3 && board[k-3][i+k-3] != 'O' && board[i+k-2][k-3] != ' ' && aiLegalMove(board,row,col,i+k-2)){
					cord = i+k-2;
					return true;
				}
			}
			check = 0;
		}
	
	return false;
}	

int aiPlayerDiagonal2Stopper(char board[][MAX],int row, int col,int & cord){
	/*Bu fonksiyon oyuncunun bir sonra ki hamlede Diagonal2 /
	olarak kazanıp kazanamayacağını kontrol eder. Eğer kazanabilecekse
	kazanmasını engellemek adına hamle yapar. */
	int check,i,k,t;

		check = 0;

	
		for(i = 0;i < col;++i){
			for(k = 0; k < row; ++k){
				if(board[i+k][col-k-1] == 'X'){
					++check;
				}
				else{
					check = 0;
				}

				if(check >= 3 && board[k-3+i][col-1-k+3] != 'O' && board[k-2+i][col-1-k+3] != ' ' && aiLegalMove(board,row,col,col-k+3)){
					cord = col-k+3;
					return true;
				}
			
			}
			check = 0;

		}
	
		check = 0;

		for(i = 0;i < col;++i){
			for(k = 0; k < row; ++k){
				if(board[k][col-k-1-i] == 'X'){
					++check;
				}
				else{
					check = 0;
				}

				if(check >= 3 && board[k-3][col-1-k+3-i] != 'O' && board[k-2][col-1-k+3-i] != ' ' && aiLegalMove(board,row,col,col-k+3-i)){
					cord = col-k+3-i;
					return true;
				}

			}
			check = 0;
		}
	
	return false;
}	

int aiWinVertical(char board[][MAX],int row, int col,int & cord){
	/*Bu fonksiyon computer'ın bir sonra ki hamlede Vertical
	olarak kazanıp kazanamayacağını kontrol eder. Eğer computer kazanabilecekse
	kazanmasını sağlayacak şekilde hamle yapar. */
	int check,i,k;
		check = 0;

	for(i = 0;i < row;++i){
		for(k = 0; k < col; ++k){
	
			if(board[k][i] == 'O'){
				++check;
			}
			else{
				check = 0;
			}
			if(board[k][i] == 'O' && board[k-1][i] == 'X' ){
				--check;
			}

			if(check >= 3 && aiLegalMove(board,row,col,i+1)){
				cord = i + 1;
				return true;
			}
		
		}
		check = 0;
	}

	return false;
}

int aiWinHorizontal(char board[][MAX],int row, int col,int & cord){
	/*Bu fonksiyon computer'ın bir sonra ki hamlede Horizontal
	olarak kazanıp kazanamayacağını kontrol eder. Eğer computer kazanabilecekse
	kazanmasını sağlayacak şekilde hamle yapar. */
	int check,i,k;
		check = 0;
		

	for(i = 0;i < row;++i){
		for(k = 0; k < col; ++k){
			if(board[i][k] == 'O' && board[i][k+1] != 'X'){
				++check;
			}
			else{
				check = 0;
			}	
			
			if(check >= 3 && aiLegalMove(board,row,col,k+2) && board[i+1][k+1] != ' '){
				cord = k+2;
				return true;
			}
		
		}

		check = 0;
	}

	for(i = 0;i < row;++i){
		for(k = col; k >= 0; --k){
			if(board[i][k] == 'O' && board[i][k-1] != 'X'){
				++check;
			}
			else{
				check = 0;
			}	
			
			if((check >= 3 && aiLegalMove(board,row,col,k) && board[i+1][k-1] != ' ')){
				cord = k;
				return true;
			}
		
		}

		check = 0;
	}

	return false;
}

int aiWinDiagonal1(char board[][MAX],int row, int col,int & cord){
	/*Bu fonksiyon computer'ın bir sonra ki hamlede Diagonal1 \
	olarak kazanıp kazanamayacağını kontrol eder. Eğer computer kazanabilecekse
	kazanmasını sağlayacak şekilde hamle yapar. */
	int check,i,k,t;

		check = 0;

	
		for(i = 0;i < col;++i){
			for(k = 0; k < row; ++k){
				if(board[i+k][k] == 'O'){
					++check;
				}
				else{
					check = 0;
				}

				if(check >= 3 && board[i+k-3][k-3] != 'X' && board[i+k-2][k-3] != ' ' && aiLegalMove(board,row,col,k-2)){
					cord = k-2;
					return true;
				}
			
			}
			check = 0;

		}
	
		check = 0;

		for(i = 0;i < col;++i){
			for(k = 0; k < row; ++k){
				if(board[k][k+i] == 'O'){
					++check;
				}
				else{
					check = 0;
				}

				if(check >= 3 && board[k-3][i+k-3] != 'X' && board[i+k-2][k-3] != ' ' && aiLegalMove(board,row,col,i+k-2)){
					cord = i+k-2;
					return true;
				}
			}
			check = 0;
		}
	
	return false;
}

int aiWinDiagonal2(char board[][MAX],int row, int col,int & cord){
	/*Bu fonksiyon computer'ın bir sonra ki hamlede Diagonal2 /
	olarak kazanıp kazanamayacağını kontrol eder. Eğer computer kazanabilecekse
	computer'ın kazanmasını sağlayacak şekilde hamle yapar. */
	int check,i,k,t;

		check = 0;

	
		for(i = 0;i < col;++i){
			for(k = 0; k < row; ++k){
				if(board[i+k][col-k-1] == 'O'){
					++check;
				}
				else{
					check = 0;
				}

				if(check >= 3 && board[k-3+i][col-1-k+3] != 'X' && board[k-2+i][col-1-k+3] != ' ' && aiLegalMove(board,row,col,col-k+3)){
					cord = col-k+3;
					return true;
				}
			
			}
			check = 0;

		}
	
		check = 0;

		for(i = 0;i < col;++i){
			for(k = 0; k < row; ++k){
				if(board[k][col-k-1-i] == 'O'){
					++check;
				}
				else{
					check = 0;
				}

				if(check >= 3 && board[k-3][col-1-k+3-i] != 'X' && board[k-2][col-1-k+3-i] != ' '&& aiLegalMove(board,row,col,col-k+3-i)){
					cord = col-k+3-i;
					return true;
				}

			}
			check = 0;
		}
	
	return false;
}

int save(char board[][MAX],int players,char mod,int size, string filename){
	/* Run time sırasında oyun oynanırken o an ki oyunu istenilen dosyaya kaydeder. */
	ofstream file1;
	file1.open(filename);

	if (!(file1.is_open())){
			cerr << "File Cannot Created. \n";
			cerr << "Try again or continue game. \n";
			return 0;
		}
	else{
			file1 << players<<"\n"<< mod <<"\n" << size << "\n";
			for (int i = 0; i < size; ++i){
	        	for (int j = 0; j < size; ++j){
	            	file1 << board[i][j];
	        }
	    }
	    file1.close();
	}
	return 1;
}

int load(char board[][MAX],int & players,char & mod,int & size, string filename){
	/* Run time sırasında oyun oynanırken başka bir oyunu her şeyiyle belirtilen dosyadan getirir.
	ve o dosyada ki oyuna devam edilir. */ 
	char ch;
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
			
			file1>>size;
			file1.get(ch);// for buffer endline


			for (int i = 0; i < size; ++i){
	        	for (int j = 0; j < size; ++j){
	            	file1.get(board[i][j]);
	        	}
	    	}
	   	file1.close();
	    }
    return 1;
}
