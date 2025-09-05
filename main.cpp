// Gran cantidad de este código fue generado por chatGPT
// Yo lo adapté para simplificarlo para la clase

#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>
#include <fstream>
#include <chrono>

using namespace std;

class List {
private:
    int *a;
public:
    List() {
        cout << "\tCalling the default constructor\n";
    }
    List(List &rSide) {
        cout << "\tCalling the copy constructor\n";
    }

    List(List &&rSide) {
        cout << "\tCalling the copy move constructor\n";
    }

    List& operator=(List &rSide) {
        cout << "\tCalling the assignment operator\n";
        return rSide;
    }

    List& operator=(List &&rSide) {
        cout << "\tCalling the move assignment operator\n";
        return rSide;
    }

    List operator+(const List &rsOp) {
        List res;
        return res;
    }
};


int main() {
    cout << "For this declaration: List L;" << endl;
    List L;

    cout << "For this declaration: List M(L);" << endl;
    List M(L);

    cout << "For this declaration: List N = std::move(L);" << endl;
    List N = std::move(L);

    cout << "Creating another object with: List P;" << endl;
    List P;

    cout << "Assigning with this expression: P = L;" << endl;
    P = L;

    cout << "Assigning with this expression: P = std::move(N);" << endl;
    P = std::move(N);

    P = N + P;
    return 0;
}
