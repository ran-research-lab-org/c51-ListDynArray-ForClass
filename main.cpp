// Gran cantidad de este código fue generado por chatGPT
// Yo lo adapté para simplificarlo para la clase

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"

#include "List.h"

using namespace std;

TEST_CASE("Test default constructor") {
   CHECK_NOTHROW(List());
   List L;
   CHECK(L.getSize() == 0);
   CHECK_THROWS(L.insert(42, 2));
   L.insert(42, 0);
   CHECK(L.getSize() == 1);
   L.insert(33, 0);
   L.insert(1, 0);
   L.insert(77, 2);
   L.insert(9, 0);
   CHECK(L.getSize() == 5);

}

