/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package gtuapp;

import javafx.util.Pair;

/**
 *
 * @author VefikFiratAkman
 * @param <K>
 * @param <V>
 */
public class GTUMap <K,V> extends GTUSet<Pair<K,V>> {
    
    GTUMap(){
          super();
    }
    
  
    @Override
    public int count(Object deger) {
        K deger2 = (K) deger;
        Integer i;
        int c = 0;
         for(i = 0; i < this.size();++i){
            if(((Pair<K,V>) deger2).getKey().equals(((Pair<K,V>)isim[i]).getKey())){
                 return 1;
             }
         }
         return 0;
    }

    @Override
    public String toString(){
        String s = new String();
    /* Override But Do Same Thing */
    for(int i = 0; i < leng; ++i) {
        
        s +=isim[i];
        s += "\n";

    }
    return s;
}

    @Override
    public void erase(Object element){
    /* Override But Do Same Thing */
     K element2 = (K) element;
    
    int k = 0;
    
    for (int i = 0; i < leng; ++i,++k) {
        if (element2.equals(((Pair<K,V>)isim[i]).getKey())) {
            --k;
        }
        else{
            isim[k] = isim[i];
        }
    }
    --leng;
        

} // DONE DONE DONE

    @Override
     public Iterator find(Object want){
        /* Find 'Want'ed element in Set. If it's available
        in Set return element's Address.
        But it's not available return nullptr. */
        K want2 = (K) want;
        Iterator _ptri = new Iterator();
        K [] x = null;

       int i;
        for (i = 0; i <= leng; ++i) {
            if (want2.equals(((Pair<K,V>)isim[i]).getKey())) {
                x = (K[]) isim;
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
      /**
       * Take a key and return value.
       * @param key for the searching Key value.
       * @return V type object. The object is the object of given Key.
       * 
       */
     public V at(K key){
         GTUSet.Iterator _ptri = this.find(key);
         V value =  ((Pair<K,V>)_ptri.itself()).getValue();
         return  (V) value;
         
     }
     
     
     
    


}
