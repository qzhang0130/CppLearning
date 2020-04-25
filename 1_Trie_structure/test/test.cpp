#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "../src/trie.h"
#include <vector>

TEST_CASE( "Basic Trie Structure Test", "[general]"){
    std::Trie trie;
    trie.insert("abc");
    REQUIRE(trie.find("abc") == true);
    REQUIRE(trie.find("cd") == false);
    REQUIRE(trie.startWith("ab") == true);
    REQUIRE(trie.find("abcde") == false);
    REQUIRE(trie.find("")==false);
}
