#ifndef UNTITLED_GTUSETBASE_H
#define UNTITLED_GTUSETBASE_H

#include <iostream>
#include <string>
#include <utility>
#include <memory>

using namespace std;
/* This is just abstract class for Set And Map */
namespace GTUSetBaseN {
    template <class T>

    class GTUSetBase {

    public:
        virtual bool empty() const = 0;
        /* Check Set Or Map is Empty or Not */
        virtual int insert(T deger) = 0;
        /* Add element in Set Or Map */
        virtual void erase(int element) = 0;
        /* Delete element in  Set Or Map */
        virtual void clear() = 0;
        /* Delete all element in  Set Or Map */
        virtual int count() const = 0;
        /* Member count in  Set Or Map */
        void print()const;
        /* Print  Set Or Map */
        virtual T *begin() const = 0;
        /* Give First element adress of  Set Or Map */
        virtual T *end() const = 0;
        /* Give Last element adress of  Set Or Map */
        virtual T *find(T want) const = 0;
        /* Find Address of Wanted Element in Set Or Map  */
        virtual size_t size() const = 0;
        /* Size Of One Class Object of Set Or Map  */
        virtual size_t max_size() const = 0;
        /* Capacity Of Thousand Class Object of Set Or Map  */



    protected:


    };

}

#endif //GTUSETBASE_H
