
#ifndef LIST_H
#define LIST_H

#include <string>

using namespace std;


class List {
private:
    int *a;
    int size;
    int cap;
public:

List();

int getSize() const;

void insert(int val, int pos);
};

#endif