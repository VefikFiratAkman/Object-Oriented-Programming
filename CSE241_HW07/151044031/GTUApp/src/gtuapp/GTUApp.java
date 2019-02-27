/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package gtuapp;
        
import java.security.InvalidParameterException;
import javafx.util.Pair;

/**
 *
 * @author VefikFiratAkman
 */
public class GTUApp {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        
        System.out.println("This Program Made By Vefik Fırat Akman - 151044031 \n"
        + "-------------------------------------------------------------------------------------------------------\n"
        + "-------------------------------------------- START OF SET ---------------------------------------------\n"
        + "-------------------------------------------------------------------------------------------------------\n");

        System.out.println("Creating String Set;\nGtuSet <string> obje;\n");

        GTUSet <String> obje = null;
           obje = new GTUSet();
        System.out.println("Set String Size: " + obje.size() + "\n"  + "Set String MaxSize: " + obje.max_size() + "\n"
        + "-------------------------------------------------------------------------------------------------------\n"
        + "Now Insert 'Gtu','Computer','Engineering','Gtu'\n");
        try {
        obje.insert("Gtu");
        obje.insert("Computer");
        obje.insert("Engineering");
        obje.insert("Gtu");

        }
        catch(Exception InvalidParameterException){
             System.out.println("Insert Throw Exception For GTUSet. Because The Element Is Already In The Set\n");
        }
        System.out.println(obje);

        System.out.println("Member Count: " + obje.size() + "\n"
         + "We Can See 'Gtu' didn't Repeat\n");
         System.out.println("-------------------------------------------------------------------------------------------------------\n"
         + "Try Find Function For Find 'Computer'");
        if (obje.find("Computer") != null) {
             System.out.println("Set 'Computer' Address is:" + obje.find("Computer") + " \n"
            + "And This Address *: " + obje.find("Computer").itself() + " \n");
        }
        else {
            System.out.println("Couldn't Found");
        }
        System.out.println("-------------------------------------------------------------------------------------------------------\n"
        + "Now Erase 'Gtu' And Call Print Function\n");

        obje.erase(0);
        System.out.println(obje);

        System.out.println("Member Count: " + obje.size() + "\n"
         + "-------------------------------------------------------------------------------------------------------\n"
         + "Now Call Clear Function And Call Print Function\n");
        obje.clear();
        System.out.println(obje);
        System.out.println("Member Count: " + obje.size() + "\n");
        System.out.println("-------------------------------------------------------------------------------------------------------\n"
        + "--------------------------------------------- END OF SET ----------------------------------------------\n"
        + "-------------------------------------------------------------------------------------------------------\n");

        System.out.println("");

        System.out.println("-------------------------------------------------------------------------------------------------------\n"
        + "-------------------------------------------- START OF MAP ---------------------------------------------\n"
        + "-------------------------------------------------------------------------------------------------------");

        Pair <Integer,String> test  = new Pair<>(120,"James");
        Pair <Integer,String> test1  = new Pair<>(130,"Jessie");
        Pair <Integer,String> test2  = new Pair<>(140,"Miav");
        Pair <Integer,String> test3  = new Pair<>(150,"Roket Takimi");

        System.out.println( "\nCreating Int,String Map;\nGTUMap<int,string> objeM;\n");

        GTUMap<Integer,String> objeM = null;
        objeM = new GTUMap();


        System.out.println( "Map Int,String Size: " + objeM.size() + "\n"  + "Set String MaxSize: " + objeM.max_size() + "\n"
        + "-------------------------------------------------------------------------------------------------------\n"
        + "Now Insert \"120,James\",\"130,Jessie\",\"140,Miav\",\"150,Roket Takimi\",\"130,Jessie\"\n");

        try {
            objeM.insert(test);
            objeM.insert(test1);
            objeM.insert(test2);
            objeM.insert(test3);
            objeM.insert(test1);
        }
        catch(Exception InvalidParameterException){
            System.out.println( "Insert Throw Exception For GTUMap. Because The Element Is Already In The Map\n");
        }
        System.out.println(objeM);
        System.out.println("Member Count: " + objeM.size() + "\n"
        + "We Can See \"130,Jessie\" didn't Repeat\n"
        + "-------------------------------------------------------------------------------------------------------\n"
        + "Try Find Function For Find \"140,Miav\" \n");
        if (objeM.find(140) != null) {
            GTUSet.Iterator A = objeM.begin();
            A.Next();
            A.Next();
            System.out.println( "Map \"140,Miav\" Find(140) is:" + objeM.find(140).itself() + " \n"
            + "And This Equal To Begin+2: " + (A.itself()) + " \n");
        }
        else {
             System.out.println("Couldn't Found");
        }
        System.out.println("-------------------------------------------------------------------------------------------------------\n");

        System.out.println( "Print Members With at(K Key) Func. Like System.out objeM.at(120)\n");
        System.out.println( "objeM.at(120): " + objeM.at(120) + "\nobjeM.at(140): " + objeM.at(140) 
        + "\nobjeM.at(150): " + objeM.at(150) + "\n");
             
        System.out.println("-------------------------------------------------------------------------------------------------------\n"
        + "Now Erase \"140,Miav\" And Call Print Function\n");
        objeM.erase(140);
        System.out.println(objeM);


        System.out.println("Member Count: " + objeM.size() + "\n"
        + "-------------------------------------------------------------------------------------------------------\n"
        + "Now Call Clear Function And Call Print Function\n");
        objeM.clear();
        System.out.println(objeM);
        System.out.println("Member Count: " + objeM.size() + "\n");
        System.out.println("-------------------------------------------------------------------------------------------------------\n"
        + "--------------------------------------------- END OF MAP ----------------------------------------------\n"
        +"-------------------------------------------------------------------------------------------------------\n");
        
        
        
         System.out.println("-------------------------------------------------------------------------------------------------------\n"
        + "----------------------------------------- START OF INTERSECTION ---------------------------------------\n"
        + "-------------------------------------------------------------------------------------------------------");
        
        
        GTUSetInt<String> IntersecSet = new GTUSet();
        GTUSet <String> Set1 = new GTUSet();
        GTUSet <String> Set2 = new GTUSet();
        Set1.insert("GTU");
        Set1.insert("Computer");
        Set1.insert("Engineering");
        
        Set2.insert("MIT");
        Set2.insert("Computer");
        Set2.insert("Engineering");
        IntersecSet = Set1.intersection(Set2);
        
        System.out.println("First Set: \n" + Set1 + "\nSecond Set: \n" + Set2);
        
        System.out.println("Intersection Of this Two Set: \n" + IntersecSet 
        + "----------------------------------------- Intersection Of Map ---------------------------------------\n");
        
        Pair <Integer,String> MapTest  = new Pair<>(1000,"Firat");
        Pair <Integer,String> MapTest1  = new Pair<>(1001,"Ali");
        Pair <Integer,String> MapTest2  = new Pair<>(1002,"Dursun");
        Pair <Integer,String> MapTest3  = new Pair<>(1003,"Temel");


        Pair <Integer,String> Map2Test  = new Pair<>(1008,"Cemil");
        Pair <Integer,String> Map2Test1  = new Pair<>(1007,"Kazım");
        Pair <Integer,String> Map2Test2  = new Pair<>(1002,"Dursun");
        Pair <Integer,String> Map2Test3  = new Pair<>(1003,"Temel"); 
       
        GTUSetInt<Pair<Integer,String> > IntersecMap = new GTUMap();
        GTUMap<Integer,String> Map1 = new GTUMap();
        GTUMap<Integer,String> Map2 = new GTUMap();
        
        
        Map1.insert(MapTest);
        Map1.insert(MapTest1);
        Map1.insert(MapTest2);
        Map1.insert(MapTest3);
        
        Map2.insert(Map2Test);
        Map2.insert(Map2Test1);
        Map2.insert(Map2Test2);
        Map2.insert(Map2Test3);
        System.out.println("First Map: \n" + Map1 + "\nSecond Map: \n" + Map2);
        
        System.out.println("Intersection Of this Two Map: \n" + IntersecMap);
        
        IntersecMap = Map1.intersection(Map2);
        System.out.println(IntersecMap);
        
        
         System.out.println("-------------------------------------------------------------------------------------------------------\n"
        + "--------------------------------------- END OF INTERSECTION -------------------------------------------\n"
        +"-------------------------------------------------------------------------------------------------------\n");

        
    }
    
    
}
