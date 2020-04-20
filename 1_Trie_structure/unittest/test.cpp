#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "../trie.h"
#include <vector>
unsigned int Factorial( unsigned int number ) {
    return number <= 1 ? number : Factorial(number-1)*number;
}
int getValue(){
    std::vector<int> a(10, 1);
    throw 1;
    return a[11];
}

TEST_CASE( "Factorials are computed", "[factorial]" ) {
    REQUIRE( Factorial(1) == 1 );
    REQUIRE( Factorial(2) == 2 );
    REQUIRE( Factorial(3) == 6 );
    REQUIRE( Factorial(10) == 3628800 );
    REQUIRE_THROWS( getValue());
}

TEST_CASE( "New test case", "[general]"){
    REQUIRE( 0 == 0);
    std::Trie trie;
    trie.insert("abc");
    REQUIRE(trie.find("abc") == true);
    REQUIRE(trie.find("cd") == false);
    REQUIRE(trie.startWith("ab") == true);
    REQUIRE(trie.find("abcde") == true);
}
