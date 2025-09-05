#include "TList.h"
#include <sstream>

template <typename T>
void List<T>::expand() {
    cap *= 2;
    T *tmp = new T[cap];
    for (int i = 0; i < size; i++) {
        tmp[i] = a[i];
    }
    delete [] a;
    a = tmp;
}
template <typename T>
string List<T>::toStr(const T& value) const {
    ostringstream oss;
    oss << value;
    return oss.str();
}

template <typename T>
List<T>::List() :a(new T[4]), size(0), cap(4){}

template <typename T>
List<T>::List(const List &rSide): cap(rSide.cap), size(rSide.size)  {
    a = new T[cap];
    for (int i = 0; i < cap; i++) { 
        a[i] = rSide.a[i];
    }
}

template <typename T>
List<T>::List(List &&rSide) {
    if (this == &rSide) throw invalid_argument("Trying to pass the same object");

    // copy the data members
    cap = rSide.cap;
    size = rSide.size;
    // .. and grab its resource
    a = rSide.a;

    // clear the right side object
    rSide.a = nullptr;
    rSide.size = rSide.cap =  0;
}

template <typename T>
const List<T>& List<T>::operator=(const List<T> &rSide)  {
    if (this == &rSide) throw invalid_argument("Trying to pass the same object");

    cap = rSide.cap;
    size = rSide.size;

    delete [] a;
    a = new T[cap];
    for (int i = 0; i < size; i++) a[i] = rSide.a[i];
    
    return rSide;
}

template <typename T>
List<T>& List<T>::operator=(List<T> &&rSide) {
    if (this == &rSide) throw invalid_argument("Trying to pass the same object");

    // copy the data members
    cap = rSide.cap;
    size = rSide.size;

    // grab the right side's resource
    if (a != nullptr) delete [] a;
    a = rSide.a;
    
    // clear the right side object
    rSide.a = nullptr;
    rSide.size = rSide.cap =  0;
    return *this;
}

template <typename T>
List<T> List<T>::operator+(const List<T> &rsOp) {
    List res;
    return res;
}

template <typename T>
List<T>::~List() {
    if (a != nullptr) delete [] a;
}

template <typename T>
void List<T>::append(T n) {
    if (size == cap) expand(); //throw invalid_argument("Trying to insert into a full list.");
    a[size++] = n; 
}

template <typename T>
bool List<T>::operator==(const List<T> &rSideOp) const {
    if (size != rSideOp.size) return false;
    for (int i = 0; i < size; i++) {
        if (a[i] != rSideOp.a[i]) return false;
    }
    return true;
}

template <typename T>
int List<T>::getSize() const { return size;}


template <typename T>
string List<T>::toString() const {
    string st = "";
    if (size == 0) return st;
    for (int i = 0; i < size - 1; i++) {
        st = st + toStr(a[i]) + " ";
    }
    st = st + toStr(a[size-1]);
    return st;

}
