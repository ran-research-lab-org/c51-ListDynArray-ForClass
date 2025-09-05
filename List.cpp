#include "List.h"

void List::expand() {
    cap *= 2;
    int *tmp = new int[cap];
    for (int i = 0; i < size; i++) {
        tmp[i] = a[i];
    }
    delete [] a;
    a = tmp;
}
List::List() :a(new int[4]), size(0), cap(4){}

List::List(const List &rSide): cap(rSide.cap), size(rSide.size)  {
    a = new int[cap];
    for (int i = 0; i < cap; i++) { 
        a[i] = rSide.a[i];
    }
}

List::List(List &&rSide) {
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

const List& List::operator=(const List &rSide)  {
    if (this == &rSide) throw invalid_argument("Trying to pass the same object");

    cap = rSide.cap;
    size = rSide.size;

    delete [] a;
    a = new int[cap];
    for (int i = 0; i < size; i++) a[i] = rSide.a[i];
    
    return rSide;
}

List& List::operator=(List &&rSide) {
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

List List::operator+(const List &rsOp) {
    List res;
    return res;
}

List::~List() {
    if (a != nullptr) delete [] a;
}

void List::append(int n) {
    if (size == cap) expand(); //throw invalid_argument("Trying to insert into a full list.");
    a[size++] = n; 
}

bool List::operator==(const List &rSideOp) const {
    if (size != rSideOp.size) return false;
    for (int i = 0; i < size; i++) {
        if (a[i] != rSideOp.a[i]) return false;
    }
    return true;
}

int List::getSize() const { return size;}



string List::toString() const {
    string st = "";
    if (size == 0) return st;
    for (int i = 0; i < size - 1; i++) {
        st = st + to_string(a[i]) + " ";
    }
    st = st + to_string(a[size-1]);
    return st;

}
