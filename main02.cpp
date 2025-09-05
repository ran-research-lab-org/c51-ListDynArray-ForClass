// Gran cantidad de este código fue generado por chatGPT
// Yo lo adapté para simplificarlo para la clase


#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"
#include <stdexcept>
#include <iostream>
#include <string>
#include "List.h"

using namespace std;


TEST_CASE("Test default constructor") {
    CHECK_NOTHROW(List());
}
TEST_CASE("Let's grow some lists and compare them") {
    List L;
    L.append(9);
    
    List M;
    M.append(9);

    CHECK(L == M);

    L.append(3); L.append(5); L.append(4);
    CHECK(L.toString() == "9 3 5 4");

    L.append(6);
    CHECK(L.toString() == "9 3 5 4 6");

    CHECK_FALSE(L == M);
    
    M = L;
    CHECK(L == M);
    
    L.append(10);
    CHECK(M.toString() == "9 3 5 4 6");
    CHECK(L.toString() == "9 3 5 4 6 10");
    
}
