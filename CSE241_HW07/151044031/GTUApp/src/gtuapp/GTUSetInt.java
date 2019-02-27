/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package gtuapp;

import java.security.InvalidParameterException;

/**
 *
 * @author VefikFiratAkman
 * @version 2.00
 * GTUSetInt Class
 * @param <T> for create generic class Set Or Map.
 */
    public interface GTUSetInt <T> {
    /* 
    * @return Set Or Map is Empty or Not 
    */
    public boolean empty();
    /* Add element in Set Or Map
    * @param deger is a generic.
    * @exception InvalidParameterException
    */
    public int insert(Object deger) throws InvalidParameterException;
    /*
    * Delete element in  Set Or Map
    * Decreas size by 1.
    * @param input for deleting value.
    */
    public void erase(Object element);
    /* 
    * Delete all element in  Set Or Map
    * Size = 0;
    */
    public void clear();
      /**
     * Searches for given input's  in this object.
     * @param deger for searching value.
     * @return 0 or 1.
     */
    public int count(Object deger);
    /*
    * @return element number in isim array
    */
    public int size();
    /* 
    * @return array capacity 
    */
    public int max_size();
    
     /**
     * @return the begin of Set or Map object's iterator.
     */
    public GTUSet.Iterator begin();
   
     /**
     * @return the end of Set or Map object's iterator.
     */
    public GTUSet.Iterator end();
    
     /**
     * Search given input in this object. 
     * @param want for search.
     * @return GTUIterator.
     */
    public GTUSet.Iterator find(Object want);
     /**
     * Search same member in two object.And create new object with this
     * @return a new GTUSetInt
     * @param other for searching indexes.
     */
    public GTUSetInt<T> intersection (GTUSetInt<T> other);
    
   
    
}
