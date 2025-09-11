#include "List.h"
#include <stdexcept>

List::List(){
    size = 0;
    cap = 4;
    a = new int[4];
}

int List::getSize() const{

    return size;
}

void List::insert(int val, int pos){

    if(pos < 0 || pos > size)
    {
        throw std::invalid_argument("Invalid position");

    }

    if(size == cap)
    {
        cap = cap * 2;
        // reservamos un nuevo arreglo dinámico 
        int *tmp = new int[cap];
        // copiamos los elementos de a a tmp
        for (int i = 0; i < size; i++) tmp[i] = a[i];
        // borramos el arreglo dinámico al que apuntaba a
        delete [] a;
        // hacemos que a apunte al nuevo arreglo dinámico
        a = tmp;
    }

    for(int i = size - 1; i >= pos; i--)
    {
        a[i+1] = a[i];
    }

    size++;


}


