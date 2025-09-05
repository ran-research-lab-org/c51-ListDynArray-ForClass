
#ifndef LIST_H
#define LIST_H

#include <string>

using namespace std;


class List {
private:
    int *a;
    int cap;
    int size;
    
    void expand();
    
public:
    List();

    List(const List &rSide);

    List(List &&rSide);
    
    const List& operator=(const List &rSide);

    List& operator=(List &&rSide);

    List operator+(const List &rsOp);

    ~List();

    void append(int n);

    bool operator==(const List &rSideOp) const ;
    int getSize() const ;
    string toString() const;
    
};

#endif