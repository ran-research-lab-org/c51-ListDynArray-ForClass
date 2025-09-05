
#ifndef TLIST_H
#define TLIST_H

#include <string>

using namespace std;

template <typename T>
class List {
private:
    T *a;
    int cap;
    int size;
    
    void expand();
    
    string toStr(const T& value) const;

public:
    List();

    List(const List &rSide);

    List(List &&rSide);
    
    const List& operator=(const List &rSide);



    List& operator=(List &&rSide);

    List operator+(const List &rsOp);

    ~List();

    void append(T n);

    bool operator==(const List &rSideOp) const ;
    int getSize() const ;
    string toString() const;
    
};

#endif