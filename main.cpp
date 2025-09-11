// Gran cantidad de este código fue generado por chatGPT
// Yo lo adapté para simplificarlo para la clase

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"

#include "List.h"

using namespace std;

TEST_CASE("Test default constructor") {
    CHECK_NOTHROW(List());
}
