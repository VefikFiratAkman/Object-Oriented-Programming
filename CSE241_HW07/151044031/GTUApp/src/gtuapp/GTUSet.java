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
 * @param <T>
 */
public class GTUSet<T> implements GTUSetInt<T> {
    
    protected int leng = 0;
    protected Object[] isim;
    public class Iterator <T> {


            Iterator() {
                   index = 0;
                // yazmayinca calismiyor.
            }        
            /* Non - Parameter Constructor */
            public Iterator(T [] other) {
            it = other;
                    }
            /*  Constructor */
           
            public void Next() {
                ++index;
            }   
            public void Before() {
               --index;
            }
            public boolean HasNext() {
                ++index;
                if(this.itself()== null){
                    --index;
                    return false;
                }
                else{
                    --index;
                    return true;
                }
                      
                    
            }   
            public boolean HasBefore() {
                return index > 0;
            }      
            public void setIt(T itOther) {
                it = (T[]) itOther;
            }
            public T itself() {
                return it[index];
            }
            public T[] getIt() {
                return it;
            }
           
            protected T [] it;
            protected int index;
        }
    
    
    GTUSet() {
       isim = (T[]) new Object[1000];
    }
     
    @Override
    public boolean empty() {
        /*  Check Set is Empty Or Not */
        return leng == 0;
    }
    @Override
    public int insert(Object deger) throws InvalidParameterException {
        T deger2 = (T) deger;
        
         /* Add element in Set */
        if(leng >= this.max_size()-1){
           System.out.println("You Reached Max Size(1000)\n");
           return -1;
        }
        if (this.count(deger2) != 0) {
            throw new InvalidParameterException();
        }
        else{
            isim[leng] = deger2;
            ++leng;
            return 1;
        }
        
        
    } 
    @Override
    public void erase(Object element) {
        /* Delete 'element' in Set */
        Integer element2 = (Integer) element;
        if (element2 == leng) {
            isim[element2]= null;
            --leng;
        }
        else {
            int a = 0;

            for (int i = 0; i <= leng; ++i,++a) {
                if (element2 != i) {
                    isim[a] = isim[i];
                }
                else{
                    --a;
                }
            }
            --leng;

        }
    }
    @Override
    public void clear() {
        isim = null;
        leng = 0;
    }   
    
    @Override
    public int count(Object deger) {
        T deger2 = (T) deger;
        Integer i; 
         for(i = 0; i < this.size();++i){
             if( deger2.equals(isim[i])){
                return 1;
             }
         }
         return 0;
       
    }
    @Override
    public int size(){
        /*Return currently size*/
        return leng;
    }
    @Override
    public int max_size(){
        return 1000;
    }
    
    
    @Override
    public String toString(){
        String s = new String(); 
        int i;
        for(i = 0;i< leng; ++i ){
            s+= isim[i];
            s += "\n";
        }
        return s;
         }

    @Override
    public Iterator begin(){
        Iterator _ptri = new Iterator();
        _ptri.setIt(isim);
       
        return _ptri;
    }
    /* Give First element adress of  Set*/
    @Override
    public Iterator end(){
          Iterator _ptri =  new Iterator();
        _ptri.setIt(isim);
         _ptri.index = leng-1;
       return _ptri;
   }
    /* Give Last element adress of  Set */
    @Override
    public Iterator find(Object want){
        /* Find 'Want'ed element in Set. If it's available
        in Set return element's Address.
        But it's not available return nullptr. */
        T want2 = (T) want;
        Iterator _ptri = new Iterator();
         T [] x = null;

       int i;
        for (i = 0; i <= leng; ++i) {
            if (want2 == isim[i]) {
                x = (T[]) isim;
                break;
            }
        }
        
         
        
        if( x != null){
            _ptri.setIt(isim);
            _ptri.index = i;
            return _ptri;
        }
        else{
            return null;
        }
 

   }
    /* Find Address of Wanted Element in Set */
    
    @Override
    public GTUSetInt<T> intersection (GTUSetInt<T> other) {

    GTUSetInt<T> Obje = new GTUSet();
    int i;
   
    for( i = 0; i < this.size(); ++i){
        if (other.count(this.isim[i]) == 1) {
            Obje.insert(this.isim[i]);
        }  
    }
    return Obje;
}

}
