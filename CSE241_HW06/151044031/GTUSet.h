#ifndef UNTITLED_GTUSET_H
#define UNTITLED_GTUSET_H

#include "GTUSetBase.h"

using namespace GTUSetBaseN;


namespace GTUSetN {

    template<class T>
    class GTUSet : public GTUSetBase<T> {
    /* Default Big Three Is Working */
    public:

        GTUSet() {
            isim = shared_ptr<T>(new T[1000], default_delete<T[]>());
            leng = 0;
        }
        /* Non - Parameter Constructor */

        bool empty() const;
        /* Check Set is Empty or Not */
        int insert(T deger);
        /* Add element in Set*/
        void erase(int element);
        /* Delete element in  Set*/
        void clear();
        /* Delete all element in  Set*/
        int count() const;
        /* Member count in  Set*/
        void print() const;
        /* Print  Set */
        T *begin() const;
        /* Give First element adress of  Set*/
        T *end() const;
        /* Give Last element adress of  Set */
        T *find(T want) const;
        /* Find Address of Wanted Element in Set */
        size_t size() const;
        /* Size Of One Class Object of Set */
        size_t max_size() const;
        /* Capacity Of  Class Object of Set */
        
        //friend shared_ptr<GTUSet<T> > setIntersection (const GTUSet<T>& first, const GTUSet<T>& second);

        /* ---------- START OF ITERATOR CLASS ---------- */
        class Iterator {

        public:

            Iterator() {

                // yazmayinca calismiyor.
            }
            /* Non - Parameter Constructor */
            Iterator(T *other) : it(other) {}
            /*  Constructor */


            /* ------------ Operator Overloading ------------- */
            T *operator++() {
                it++;

                return it;
            }
            Iterator &operator++(int ignoreMe) {
                Iterator temp(it);
                it = it + 1;
                return temp;
            }
            T *operator--() {
                it = it - 1;

                return it;
            }
            Iterator &operator--(int ignoreMe) {
                Iterator temp(it);
                it = it - 1;
                return temp;
            }
            bool operator==(const Iterator &rtSide) const {
                return (it == rtSide.it);
            }
            bool operator!=(const Iterator &rtSide) const {
                return (it != rtSide.it);
            }
            T *getIt() const {
                return it;
            }
            void setIt(T *it) {
                Iterator::it = it;
            }
            const T &operator*() const {
                return *it;
            }
            const T *operator->() const {
                return it;
            }
            /* ------------ Operator Overloading ------------- */

        protected:
            T *it;
        };
        /* ---------- END OF ITERATOR CLASS ---------- */

    protected:
        shared_ptr<T> isim;
        int leng; // Length of isim

    };

}


#endif //GTUSET_H
