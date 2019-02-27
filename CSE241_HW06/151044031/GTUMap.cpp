#include "GTUSetBase.h"
#include "GTUSet.h"
#include "GTUMap.h"


using namespace GTUSetBaseN;
using namespace GTUSetN;
using namespace GTUMapN;

template <class T>
T * GTUMap<T>::find(T want)const {
    /* Override But Do Same Thing */

    shared_ptr<T> x;
    typename GTUSet<T>::Iterator _ptri;

    int i;

    for (i = 0; i <= this->leng; ++i) {
        if (want.first == this->isim.get()[i].first && want.second == this->isim.get()[i].second ) {
            x = this->isim;
            break;
        }
    }
    if( x != nullptr) {
        _ptri.setIt(&(*x) + i);
        return _ptri.getIt();
    }
    else{
        return nullptr;
    }

}

template <class T>
int GTUMap<T>::insert(T deger){
    /* Override But Do Same Thing */
    if(this->leng >= this->max_size()-1){
        cout << "You Reached Max Size(1000)\n";
        return -1;
    }

    for (int i = 0; i <= this->leng; ++i) {
        if (deger.first == this->isim.get()[i].first) {
            return -1;
        }
    }

    this->isim.get()[this->leng].first = deger.first;
    this->isim.get()[this->leng].second = deger.second;
    ++this->leng;
    return 0;
} // DONE DONE DONE
template <class T>
void GTUMap<T>::print()const{
    /* Override But Do Same Thing */
    for(int i = 0; i < this->leng; ++i) {
        cout << i+1 << ".First: " << this->isim.get()[i].first << "\n" << i+1 << ".Second: " << this->isim.get()[i].second << "\n\n";
    }
}
template <class T>
void GTUMap<T>::erase(int element){
    /* Override But Do Same Thing */
    if (element == this->leng) {
        this->isim.get()[element].second = nullptr;
        --this->leng;
    }
    else {
        int a = 0;

        T array[1000];
        for (int i = 0; i <= this->leng; ++i,++a) {
            if (element != i) {
                array[a].first = this->isim.get()[i].first;
                array[a].second = this->isim.get()[i].second;
            }
            else{
                --a;
            }
        }
        --this->leng;
        for (int i = 0; i <= this->leng; ++i) {
            this->isim.get()[i].first = array[i].first;
            this->isim.get()[i].second = array[i].second;
        }

    }

} // DONE DONE DONE
template <class T>
void GTUMap<T>::clear(){
    /* Override But Do Same Thing */
    this->isim = shared_ptr<T>(new T[1000],default_delete<T[]>());
    this->leng = 0;

} // DONE DONE DONE

template <class T>
string GTUMap<T>::operator[](int key){
    /* Override But Do Same Thing */
    shared_ptr<T> x;
    typename GTUSet<T>::Iterator _ptri;

    int i;

    for (i = 0; i <= this->leng; ++i) {
        if (key == this->isim.get()[i].first) {
            x = this->isim;
            break;
        }
    }
    if( x != nullptr) {
        _ptri.setIt(&(*x));

    }
    else{
        return " ";
    }

    return _ptri.getIt()[i].second;


} // DONE DONE DONE
