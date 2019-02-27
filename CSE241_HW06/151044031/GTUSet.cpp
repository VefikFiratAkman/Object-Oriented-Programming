#include "GTUSet.h"
using namespace GTUSetBaseN;
using namespace GTUSetN;


template <class T>
bool GTUSet<T>::empty()const{
    /*  Check Set is Empty Or Not */
    if(leng == 0){
        return true;
    }
    else{
        return false;
    }
}

template <class T>
int GTUSet<T>::count()const{
    /* Return length of Set */
    return leng;
}

template <class T>
void GTUSet<T>::clear(){
    /* Delete all elements of Set */
    isim = shared_ptr<T>(new T[1000],default_delete<T[]>());
    leng = 0;
}

template <class T>
void GTUSet<T>::erase(int element) {
    /* Delete 'element' in Set */
    if (element == leng) {
        isim.get()[element];// = nullptr;
        --leng;
    }
    else {
        int a = 0;

        T array[1000];
        for (int i = 0; i <= leng; ++i,++a) {
            if (element != i) {
                array[a] = isim.get()[i];
            }
            else{
                --a;
            }
        }
        --leng;
        for (int i = 0; i <= leng; ++i) {
            isim.get()[i] = array[i];
        }

    }
}

template <class T>
void GTUSet<T>::print()const{
    /* Print all elements in Set */
    cout << "\nSet Member List: \n";
    for(int i = 0; i <= leng ;++i){
        cout << isim.get()[i] << "\n";
    }
}

template <class T>
T * GTUSet<T>::find(T want)const {
    /* Find 'Want'ed element in Set. If it's available
       in Set return element's Address.
       But it's not available return nullptr. */
    shared_ptr<T> x;
    Iterator _ptri;

    int i;
    for (i = 0; i <= leng; ++i) {
        if (want == isim.get()[i]) {
            x = isim;
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
int GTUSet<T>::insert(T deger) {
    /* Add element in Set */
    if(leng >= this->max_size()-1){
        cout << "You Reached Max Size(1000)\n";
        return -1;
    }

    if (find(deger)) {
        throw 1;
    }
    else{
        isim.get()[leng] = deger;
        ++leng;
    }


}
template <class T>
T * GTUSet<T>::begin()const{
    /* Return first element's address in Set */
    Iterator _ptri;
    _ptri.setIt(&(*isim));
    return _ptri.getIt();

}
template <class T>
T * GTUSet<T>::end()const{
    /* Return last element's address in Set */
    T * _ptr;
    _ptr = &(*isim);
    return _ptr+(leng-1);
}

template <class T>
size_t GTUSet<T>::size() const{
    /* Return sizeof(Class) */
    size_t x;
    x = sizeof(GTUSet);
    return x;


}
template <class T>
size_t GTUSet<T>::max_size() const{
    /* Return Capacity Of Set[capacity] */
    return 1000;
}

