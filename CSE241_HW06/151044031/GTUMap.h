
#ifndef UNTITLED_GTUMAP_H
#define UNTITLED_GTUMAP_H
#include "GTUSetBase.h"
#include "GTUSet.h"

using namespace GTUSetBaseN;
using namespace GTUSetN;

namespace GTUMapN {

    template<class T>
    class GTUMap : public GTUSet<T> {

    public:
        GTUMap() : GTUSet<T>() {}

        T* find(T want) const;
        /* Override But Do Same Thing */
        int insert(T deger);
        /* Override But Do Same Thing */
        void erase(int element);
        /* Override But Do Same Thing */
        void clear();
        /* Override But Do Same Thing */
        void print() const;
        /* Override But Do Same Thing */

        /* ------------ Operator Overloading ------------- */
        string operator[](int key);
        /* ------------ Operator Overloading ------------- */

    };


}


#endif //GTUMAP_H
