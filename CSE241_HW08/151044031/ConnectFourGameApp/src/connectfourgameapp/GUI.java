/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package connectfourgameapp;

import java.awt.Color;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.Random;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.SwingConstants;
import javax.swing.border.LineBorder;

/**
 *
 * @author VefikFiratAkman
 */
public class GUI {
    private JButton [] buttons;
    private JPanel board;
    private JFrame frame;
    private JLabel [][] slots;
    private int cordinator;
    private int width;
    private int height;
    private char choose;
    private Cell [][] gameCells;
    private boolean clicked = false;
    private JPanel panel;
    

    /**Constructor Mode ve BoardSize alip paneli ve boardu hazirliyor 
    */
    public GUI(){
       
    frame = new JFrame("Connect Four Game"); // frame oluşuyor. Frame yazan yazı icinde
    panel = (JPanel) frame.getContentPane(); // olusan frame le panel olusturuyor
    
    String BoardSize = JOptionPane.showInputDialog("Please enter the board size [4-40]: "); //input dialog çıkarıyor.
    if(BoardSize == null){
        System.out.println("Cancel'a Tıklayarak Programı Tamamen Sonlandirdiniz.");
        System.exit(1);
    }
    width =  Integer.parseInt(BoardSize);  
    while(!(width >= 4 && width <= 40)){
        BoardSize = JOptionPane.showInputDialog("Error board size must be[4-40]: ");
        if(BoardSize == null){
            System.out.println("Cancel'a Tıklayarak Programı Tamamen Sonlandirdiniz.");
            System.exit(1);
        }
        width =  Integer.parseInt(BoardSize);  
    }
    height = width;
    
    String GameMode= JOptionPane.showInputDialog("Please enter the game mode: ");
        if(GameMode == null){
           System.out.println("Cancel'a Tıklayarak Programı Tamamen Sonlandirdiniz.");
            System.exit(1);
        }
    
    choose = GameMode.charAt(0);
    while(!(choose == 'P' || choose =='p') && !(choose == 'C' || choose =='c')){
        GameMode= JOptionPane.showInputDialog("Please enter the game mode: ");
        if(GameMode == null){
            System.out.println("Cancel'a Tıklayarak Programı Tamamen Sonlandirdiniz.");
            System.exit(1);
        }
        choose = GameMode.charAt(0);
    }
    if(choose == 'p'){
        choose = 'P';
    }
    if(choose == 'c'){
        choose = 'C';
    }
   
    
    panel.setLayout(new GridLayout(width+1, width + 2)); // panelin arayüzünü olusturuyor
    slots = new JLabel[width+1][width+1]; // slots arrayine yer alıyor. Size 1 büyük
    // çünkü buttonlarda 1 birim yer kaplıyor.
    buttons = new JButton[width+1]; // button arrayine yer alıyor
    

    setBoard();
   }
   
    /** Boardu oluşturan double arrayin sonra ki fonksiyonlar da junk değerler
     * yüzünden sorun çıkarması için array boşluk karakteriyle doldurulur. 
    */
    public final void setBoard(){ 

            
            int i, k;

            gameCells = new Cell[40][40];

            for(i = 0; i < height; ++i){
                for(k = 0; k < width; ++k){
                    Cell x = new Cell();
                    x.setheight(i);
                    x.setPosition(((char)(k+65)));
                    x.setValue(' ');
                    gameCells[i][k] = x;
                }
            }
        }  // DONE DONE     

    /** Bu fonksiyon kullanıcının oynamak istediği hamleyi boarda
     *  yani arraye işler. 
     * @param position
     * @param players
    */
    public void play(char position, int players){    
        
        int i;
        Integer cord = new Integer(2);
        cord = ((int)position)-65;

        for(i = height-1; i >= 0;){
            if( gameCells[i][cord-1].getValue()== ' '){

                if(players % 2 == 0){
                    gameCells[i][cord-1].setValue('X');
                    slots[i][cord-1].setOpaque(true);
                    slots[i][cord-1].setBackground(Color.blue); // Slotu maviye boyuyor
                }
                else{
                    gameCells[i][cord-1].setValue('O');
                    slots[i][cord-1].setOpaque(true);
                    slots[i][cord-1].setBackground(Color.red);  // Slotu kırmızıya boyuyor
                }

                i = -1;
            }

            else{
                i = i - 1;
            }

        }
    }   
    
    /** Bu fonksiyon bilgisayarin oynamak istediği hamleyi boarda
     *  yani arraye işler. 
    */
    public void play(){
        int i;
        Integer cord = new Integer(3);

        cord = aiSelect();

        for(i = height-1; i >= 0;){
            if( gameCells[i][cord-1].getValue()== ' '){
                    gameCells[i][cord-1].setValue('O');
                    slots[i][cord-1].setOpaque(true); 
                    slots[i][cord-1].setBackground(Color.red); // Slotu kırmızıya boyuyor
                i = -1;
            }

            else{
                i = i - 1;
            }

        }
    }  
    
    /**Bu fonksiyon computerın hangi hamleyi yapacağını
    * oyunun durumunu kontrol ederek belirler. 
     * @return 
    */
    public int aiSelect( ){ 
         Random rand = new Random(); 
        
        int check1,check2,i,k,a;
        Integer cordinat = new Integer(5);
        
        if(aiWinVertical(cordinat) > -1){
            cordinat = aiWinVertical(cordinat);
            return cordinat;
        }
        else if(aiWinHorizontal(cordinat) > -1){
             cordinat = aiWinHorizontal(cordinat);
            return cordinat;
        }

        else if(aiPlayerHorizontalStopper(cordinat) > -1){
             cordinat = aiPlayerHorizontalStopper(cordinat);
            return cordinat;
        }
        else if(aiPlayerVerticalStopper(cordinat) > -1){
             cordinat = aiPlayerVerticalStopper(cordinat);
            return cordinat;
        }
        do{
            cordinat = rand.nextInt() % width + 1;
        }while(!aiLegalMove(cordinat));
        return cordinat;
    }
    
    /** vertical olarak kazanıp kazanamayacağını kontrol eder. Eğer kazanabilecekse
     *  kazanmasını engellemek adına hamle yapar.. 
     * @param cord
     * @return 
    */
    public int aiPlayerVerticalStopper( Integer  cord){ 
        
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
                        return cord;
                    }
                }

            }
            check = 0;
        }

        return -1;


    }
    
    /**Bu fonksiyon oyuncunun bir sonra ki hamlede Horizontal
      *  olarak kazanıp kazanamayacağını kontrol eder. Eğer kazanabilecekse
      *  kazanmasını engellemek adına hamle yapar. 
     * @param cord
     * @return 
    */
    public int aiPlayerHorizontalStopper(Integer cord){
        
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
                                    return cord;
                                }
                            }
                            else{
                                cord = k + 2;
                                return cord;
                            }
                        }


            }

            check = 0;
        }

        for(i = 0;i < height;++i){
            for(k = width-1; k >= 0; --k){
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
                        return cord;
                    }
                }
            }
            
            check = 0;
        }
        return -1;
    }
    
     /**Bu fonksiyon computer'ın bir sonra ki hamlede Vertical
      * olarak kazanıp kazanamayacağını kontrol eder. Eğer computer kazanabilecekse
      * kazanmasını sağlayacak şekilde hamle yapar. 
     * @param cord
     * @return 
    */
    public int aiWinVertical( int  cord){
       
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
                    return cord;
                }

            }
            check = 0;
        }

        return -1;
    }
    
    /**Bu fonksiyon computer'ın bir sonra ki hamlede Horizontal
     *  olarak kazanıp kazanamayacağını kontrol eder. Eğer computer kazanabilecekse
     *  kazanmasını sağlayacak şekilde hamle yapar.
     * @param cord
     * @return 
    */
    public int aiWinHorizontal( int  cord){
        
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
                        return cord;
                    }
                }

            }

            check = 0;
        }

        for(i = 0;i < height;++i){
            for(k = width-1; k > 0; --k){
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
                        return cord;
                    }
                }

            }

            check = 0;
        }

        return -1;
    }
    
     /**Bu fonksiyon herhangi birinin vertical olarak
      * kazanıp kazanmadığını kontrol eder. 
     * @return 
    */
    public boolean checkWinVertical(){
       
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
                    JOptionPane.showInternalMessageDialog(panel,"Player 1 Vertical Win!!!");
                    return true;
                }
                if(check2 >= 4 ){
                    for(a = 0; a < 4; ++a){
                        gameCells[k-a][i].setValue('o');
                    }
                    
                    JOptionPane.showInternalMessageDialog(panel,"Player 2 Vertical Win!!!");
                    return true;
                }

            }
            check1 = 0;
            check2 = 0;
        }

        return false;
    } 
    
    /** Bu fonksiyon herhangi birinin horizontal olarak
     * kazanıp kazanmadığını kontrol eder. 
     * @return 
    */
    public boolean checkWinHorizontal(){
        
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
                    JOptionPane.showInternalMessageDialog(panel,"Player 1 Horizontal Win!!!");
                    return true;
                }
                if(check2 >= 4 ){
                    for(a = 0; a < 4; ++a){
                        gameCells[i][k-a].setValue('o');
                    }
                    JOptionPane.showInternalMessageDialog(panel,"Player 2 Horizontal Win!!!");
                    return true;
                }

            }
            check1 = 0;
            check2 = 0;
        }

        return false;
    }
    
    /** Bu fonksiyon herhangi birinin Diagonal1 \ olarak
     * kazanıp kazanmadığını kontrol eder. 
     * @return 
    */
    public boolean checkWinDiagonal1(){
        
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
                    JOptionPane.showInternalMessageDialog(panel,"Player 1 Diagonal1 \\ Win!!!");
                    return true;
                }
                if(check2 >= 4 ){
                    for(a = 0; a < 4; ++a){
                        gameCells[i+k-a][k-a].setValue('o');
                    }
                    JOptionPane.showInternalMessageDialog(panel,"Player 2 Diagonal1 \\ Win!!!");
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
                    JOptionPane.showInternalMessageDialog(panel,"Player 1 Diagonal1 \\ Win!!!\n\n");
                    return true;
                }
                if(check2 >= 4 ){
                    for(a = 0; a < 4; ++a){
                        gameCells[k-a][k+i-a].setValue('o');
                    }
                    JOptionPane.showInternalMessageDialog(panel,"Player 2 Diagonal1 \\ Win!!!\n\n");
                    return true;
                }

            }
            check1 = 0;
            check2 = 0;
        }


        return false;
    }
    
    /**Bu fonksiyon herhangi birinin Diagonal2 / olarak
     * kazanıp kazanmadığını kontrol eder.
     * @return 
    */
    public boolean checkWinDiagonal2(){
        
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
                    JOptionPane.showInternalMessageDialog(panel,"Player 1 Diagonal2 / Win!!!");
                    return true;
                }
                if(check2 >= 4 ){
                    for(a = 0; a < 4; ++a){
                        gameCells[i+k-a][width-k-1+a].setValue('o');
                    }
                    JOptionPane.showInternalMessageDialog(panel,"Player 2 Diagonal2 / Win!!!");
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
                    JOptionPane.showInternalMessageDialog(panel,"Player 1 Diagonal2 / Win!!!");
                    return true;
                }
                if(check2 >= 4 ){
                    for(a = 0; a < 4; ++a){
                        gameCells[k-a][width-k-1-i+a].setValue('o');
                    }
                    JOptionPane.showInternalMessageDialog(panel,"Player 2 Diagonal2 / Win!!!");
                    return true;
                }

            }
            check1 = 0;
            check2 = 0;
        }

        return false;
    }
    
    /** Bu fonksiyon kullanıcının oynamak istediği hamlenin oynanabilir olup olmadığını
     * kontrol eder. Oynanabilir ise true return eder.
     * @param cord
     * @return 
    */
    public boolean LegalMove( Integer cord){
      
        int i,k,check;
        check = 0;
        if(cord >=0 && cord < width+1 ){
            for(i = 0;i < height;++i){
                    if(gameCells[i][cord].getValue() == ' '){
                        ++check;
                    }
            }
            if(check > 0){
                return true;
            }
            else{
                JOptionPane.showInternalMessageDialog(panel,"Sütun Dolu!!!");
                return false;
            }
        }

        else{
            JOptionPane.showInternalMessageDialog(panel,"Tahta dışına nasıl çıktın yeeaa?");
            return false;
        }
    }
    
     /**Bu fonksiyon computer'ın oynamak istediği hamlenin oynanabilir
      * olup olmadığını kontrol eder. LegalMove fonksiyonundan farkı kullanıcıyı uyarmak
      * için kullanılan bildirimlerden temizlenmiş olmasıdır. Amacı temiz bir oyun sunmaktır. 
     * @param cord
     * @return 
    */
    public boolean aiLegalMove( Integer cord){
       
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
    
    /**Bu fonksiyon oyun boardunun dolup dolmadığını kontrol eder. Boşsa 0
     * doluysa 1 return eder. 
     * @return 
    */
    public boolean boardFull(){
        
        int i,k;

        for(i = 0; i < height; ++i){
            for(k = 0; k < width; ++k){
                if(gameCells[i][k].getValue() == ' '){
                    return false;
                }
            }
        }

        return true;
    }
    
    /** BU fonksiyon objenin bitip bitmediğini kontrol eder.
     * @return 
    */
    public boolean endGame(){
            
        int i,k;

        for(i = 0; i < height; ++i) {
            for (k = 0; k < width; ++k) {
                if (gameCells[i][k].getValue() == 'x' || gameCells[i][k].getValue() == 'o' || boardFull()) {
                    return true;
                }
            }
        }
        return false;
    }
    
    /** Oyunun temelini oluşturan fonksiyondur. Oyunu oluşturan diğer fonksiyonlar
     * burada bir bütün halinde çağırılır.Oyunun oynanışı ve işleyişi bu fonksiyonda gerçekleşir.
     * @return 
     * @throws java.lang.InterruptedException
    */
    public int playGame() throws InterruptedException{
    

    Integer cord = 0;
    int player = 0;


    
    /*  Hocam Burdan sonra bir kısmı internetten ogrendim. Biraz aynısı oldu ama
    * hepsini deneye deneye ne olduklarını nasıl calıstıklarını ogrendim. 
    * Kopyala yapıştır vs değil. Düzgünce Uyarladım.
    */

    for (int i = 0; i < width; i++) {
        buttons[i] = new JButton("" + (i + 1)); // Buttonları oluşturup buttuon arrayine atıyor
        buttons[i].setActionCommand("" + i); //Butona komut atıyor. 1 2 3 4 vs gibi
        buttons[i].addActionListener( // Buttondan gelen komutu algılıyor. Bir de hangi buton oldugunu
        new ActionListener() {   
            public void actionPerformed(ActionEvent e) { 
               cordinator = Integer.parseInt(e.getActionCommand());
               clicked = true;
            }
        }
    );       

    panel.add(buttons[i]); // buttonları panele ekliyor
    }

    Color ochre = new Color(204,119,34); // arkaplan icin renk
    for (int i = 0; i < width; i++) {    
        for (int k = 0; k < width; k++) {
            slots[i][k] = new JLabel(); // X ve O ile dolan kutuları olusturuyor
            slots[i][k].setHorizontalAlignment(SwingConstants.CENTER); // ortalıyor
            slots[i][k].setBackground(ochre); // arkaplan rengi
            slots[i][k].setBorder(new LineBorder(Color.white)); // hücreler arası renk.
            panel.add(slots[i][k]); // slotları panele ekliyor
        }
    }
    
    
    frame.setContentPane(panel); // frame e panel ekliyor
    frame.setSize(800, 900); // Panelin size'ını pixel cinsinden ayarlıyor
    frame.setVisible(true); // paneli görülebilir kılıyor
    
    frame.setLocationRelativeTo(null);
    
    
    frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE); // panelde ki çıkış butonunu ayarlıyor




    if(choose == 'P'){
        while(!boardFull() && !checkWinVertical() && !checkWinHorizontal() &&
              !checkWinDiagonal1() && !checkWinDiagonal2() ){
            if(clicked){
            cord = cordinator;
            if(LegalMove(cord)){
                play((char)(cord+66),player);
                player += 1;
            }
            else{

            }
            clicked = false;
            }
        }
    }


    if(choose == 'C'){
        while(!boardFull() && !checkWinVertical() && !checkWinHorizontal() &&
            !checkWinDiagonal1() && !checkWinDiagonal2()){
            if(clicked){
                if(player % 2 == 0){
                    cord = cordinator;
                    if (LegalMove(cord)) {
                        play((char)(cord+66),player);
                    }
                    else{
                        player -= 1;
                    }
                }
                else {
                    play();
                }
                player += 1;
            }
            if(player % 2 == 0)
                clicked = false;

        }

    }

if(boardFull() && !checkWinVertical() && !checkWinHorizontal() &&
   !checkWinDiagonal1() && !checkWinDiagonal2()){
    JOptionPane.showInternalMessageDialog(panel,"Game Is Tie !!!!");
}
else{
    if(endGame()) {
       
       
    }
}


     frame.setVisible(false);
    
    return 1;
}

    
    /** Getter for Width
     * @return 
    */
    public int getWidth() {
        return width;
    }
    /** Setter for Width
     * @param w
    */
    public void setWidth(int w) {
           width = w;
        }
    /** Getter for Height
     * @return 
    */
    public int getHeight() {
            return height;
    }
    /** Setter for Height
     * @param h
    */
    public void setHeight(int h) {
            height = h;
        }
        
     
}
