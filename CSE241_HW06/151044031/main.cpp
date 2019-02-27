#include <iostream>
#include <string>
#include <utility>
#include <memory>

#include "GTUSetBase.h"
#include "GTUSet.h"
#include "GTUMap.h"
#include "GTUSet.cpp"
#include "GTUMap.cpp"

using namespace std;
using namespace GTUSetBaseN;
using namespace GTUSetN;
using namespace GTUMapN;





// Fonksiyon dogru ama warning veriyor. Compile da oluyor exe de calisiyor lakin test edemedigim
// bir fonk yuzunden sorun cikmasin diye yorumda biraktim. Belki algoritmasina bakarsiniz.
// h dosyasinda da friend olarak da orda da yoruma aldim oldugu satiri.
/* template <class T>
shared_ptr<GTUSet<T> > setIntersection (const GTUSet<T>& first, const GTUSet<T>& second) {

    GTUSet<T> *obj = new GTUSet<T>();

    for(int i = 0; i < first.count(); i++){
        for (int i = 0; i < second.count(); i++) {
            if (first.isim.get()[i] == second.isim.get()[i]) {
                obj->insert(first);
            }
        }
    }
    return obj;
}
*/





int main(){

    cout << "This Program Made By Vefik Fırat Akman - 151044031 \n";

    cout << "-------------------------------------------------------------------------------------------------------\n"
         << "-------------------------------------------- START OF SET ---------------------------------------------\n"
         << "-------------------------------------------------------------------------------------------------------\n";

    cout << "Creating String Set;\nGtuSet <string> obje;\n";

    GTUSet <string> obje;

    cout << "Set String Size: " << obje.size() << "\n"  << "Set String MaxSize: " << obje.max_size() << "\n"
         << "-------------------------------------------------------------------------------------------------------\n"
         <<"Now Insert 'Gtu','Computer','Engineering','Gtu'\n";
    try {
        obje.insert("Gtu");
        obje.insert("Computer");
        obje.insert("Engineering");
        obje.insert("Gtu");

    }
    catch(...){
        cerr << "Insert Throw Exception For GTUSet. Because The Element Is Already In The Set\n";
    }
    obje.print();

    cout << "Member Count: " << obje.count() << "\n"
         << "We Can See 'Gtu' didn't Repeat\n"
         << "-------------------------------------------------------------------------------------------------------\n"
         << "Now Try *Begin* Address And Find 'Gtu' Address\n"
         << "They Need To Be Same \n"
         << "Set Begin Address is:" << obje.begin() <<" \n"
         << "Set 'Gtu' Address is:" << obje.find("Gtu") <<" \n"
         << "-------------------------------------------------------------------------------------------------------\n"
         << "Try Find Function Again. But This Time For Find 'Computer'\n";
    if (obje.find("Computer")) {
        cout << "Set 'Computer' Address is:" << obje.find("Computer") << " \n"
             << "And This Address *: " << *obje.find("Computer") << " \n";
    }
    else {
        cout << "Couldn't Found";
    }
    cout << "-------------------------------------------------------------------------------------------------------\n"
         << "Now Erase 'Gtu' And Call Print Function\n";

    obje.erase(0);
    obje.print();

    cout << "Member Count: " << obje.count() << "\n"
         << "-------------------------------------------------------------------------------------------------------\n"
         << "Now Call Clear Function And Call Print Function\n";
    obje.clear();
    obje.print();
    cout << "Member Count: " << obje.count() << "\n";
    cout << "-------------------------------------------------------------------------------------------------------\n"
         << "--------------------------------------------- END OF SET ----------------------------------------------\n"
         << "-------------------------------------------------------------------------------------------------------\n";

    cout << "\n";

    cout << "-------------------------------------------------------------------------------------------------------\n"
         << "-------------------------------------------- START OF MAP ---------------------------------------------\n"
         << "-------------------------------------------------------------------------------------------------------";

    pair <int,string> test  = make_pair(120,string("James"));
    pair <int,string> test1 = make_pair(130,string("Jessie"));
    pair <int,string> test2 = make_pair(140,string("Miav"));
    pair <int,string> test3 = make_pair(150,string("Roket Takimi"));

    cout << "\nCreating Int,String Map;\nGTUMap<int,string> objeM;\n";

    GTUMap <pair<int,string> > objeM;



    cout << "Map Int,String Size: " << objeM.size() << "\n"  << "Set String MaxSize: " << objeM.max_size() << "\n"
         << "-------------------------------------------------------------------------------------------------------\n"
         <<"Now Insert \"120,James\",\"130,Jessie\",\"140,Miav\",\"150,Roket Takimi\",\"130,Jessie\"\n";

    try {
        objeM.insert(test);
        objeM.insert(test1);
        objeM.insert(test2);
        objeM.insert(test3);
        objeM.insert(test1);
    }
    catch(...){
        cerr << "Insert Throw Exception For GTUMap. Because The Element Is Already In The Map\n";
    }
    cout << objeM[130] << "\n";
    objeM.print();
    cout << "Member Count: " << objeM.count() << "\n"
         << "We Can See \"130,Jessie\" didn't Repeat\n"
         << "-------------------------------------------------------------------------------------------------------\n"
         << "Now Try *Begin* Address And Find  \"120,James\" Address\n"
         << "They Need To Be Same \n"
         << "Set Begin Address is:" << objeM.begin() <<" \n"
         << "Set 'Gtu' Address is:" << objeM.find(test) <<" \n"
         << "-------------------------------------------------------------------------------------------------------\n"
         << "Try Find Function Again. But This Time For Find \"140,Miav\" \n";
    if (objeM.find(test2)) {
        cout << "Map \"140,Miav\" Address is:" << objeM.find(test2) << " \n"
             << "And This Address Equal To Begin+2: " << (objeM.begin()+2) << " \n";
    }
    else {
        cout << "Couldn't Found";
    }
    cout << "-------------------------------------------------------------------------------------------------------\n"
         << "Print Members With Operator[]. Like cout << ObjeM[120]\n";

    cout << "objeM[120]: " << objeM[120] << "\nobjeM[140]: " << objeM[140] << "\nobjeM[150]: " << objeM[150] << "\n";

    cout << "-------------------------------------------------------------------------------------------------------\n";


    cout << "-------------------------------------------------------------------------------------------------------\n"
         << "Now Erase \"140,Miav\" And Call Print Function\n";

    objeM.erase(2);
    objeM.print();

    cout << "Member Count: " << objeM.count() << "\n"
         << "-------------------------------------------------------------------------------------------------------\n"
         << "Now Call Clear Function And Call Print Function\n";
    objeM.clear();
    objeM.print();
    cout << "Member Count: " << objeM.count() << "\n";
    cout << "-------------------------------------------------------------------------------------------------------\n"
         << "--------------------------------------------- END OF MAP ----------------------------------------------\n"
         << "-------------------------------------------------------------------------------------------------------\n";


}





