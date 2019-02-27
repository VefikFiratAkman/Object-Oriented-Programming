#include "Cell.h"


using namespace std;

namespace ConnectFourGame{

#define MAX 100



    bool Cell::operator ==(const Cell & other) const{
        /*Bu fonksiyon operator overloadingtir.Ve == operatorunun
             iki Cell tipinde objeyi karsilastirmasini saglar. */
        if(position == other.position && height == other.height && value == other.value){
            return true;
        }
        else{
            return false;
        }
    }

    bool Cell::operator !=(const Cell & other) const{
        /*Bu fonksiyon operator overloadingtir.Ve != operatorunun
             iki Cell tipinde objeyi karsilastirmasini saglar. */
        return !(*this==other);
    }

    Cell Cell::operator ++(){
        /*Bu fonksiyon operator overloadingtir.Ve ++ (Prefix) operatorunun
        Cell tipinde ki objesinin valuesunu degistirir.*/
        if(value == 'X'){
            value = 'O';
        }
        else if(value == 'O'){
            value = '.';

        }
        else if(value == '.'){
            value = 'X';

        }
        else{
        /*do nothing */
        }
        return *this;
    }

    Cell Cell::operator ++(int ignoreMe){
        /*Bu fonksiyon operator overloadingtir.Ve ++ (PostFix) operatorunun
        Cell tipinde ki objesinin valuesunu degistirir.*/
        Cell temp  = *this;

        if(value == 'X'){
            value = 'O';
        }
        else if(value == 'O'){
            value = '.';

        }
        else if(value == '.'){
            value = 'X';

        }
        else{
            /*do nothing */
        }

        return temp;
    }

    Cell Cell::operator --(){
        /*Bu fonksiyon operator overloadingtir.Ve -- (Prefix) operatorunun
        Cell tipinde ki objesinin valuesunu degistirir.*/
        if(value == 'X'){
            value = '.';
        }
        else if(value == 'O'){
            value = 'X';

        }
        else if(value == '.'){
            value = 'O';

        }
        else{
            /*do nothing */
        }
        return *this;
    }

    Cell Cell::operator --(int ignoreMe){
       /*Bu fonksiyon operator overloadingtir.Ve -- (PostFix) operatorunun
        Cell tipinde ki objesinin valuesunu degistirir.*/
        Cell temp = *this;

        if(value == 'X'){
            value = '.';
        }
        else if(value == 'O'){
            value = 'X';

        }
        else if(value == '.'){
            value = 'O';

        }
        else{
            /*do nothing */
        }
        return temp;
    }
}