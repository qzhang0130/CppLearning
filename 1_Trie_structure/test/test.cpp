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

// Test extreme cases
TEST_CASE( "Trie Structure Stress test", "[general]"){
    std::Trie trie;
    std::string longStr = "abcdefghigklmnopqrestvwxyzsjlfaslfjsalfjsjlsfjsldfjsadklfjsdlkfsdklfsdfkjsfjsdkfsdfsdkjfslkfjsdlkfjsdkfjsdklfjsklfsdjkfsdjfklsjflksdjfsdlfjsdlkfjsdlfjsdlkfjsdfklsjdlkfjsdlkfsjdkflsjdflksdjfsldkfjsdklfjsdklfjsdlkfjsdk";
    trie.insert(longStr);
    REQUIRE(trie.find(longStr) == true);
    REQUIRE(trie.find(longStr.substr(0,20))==false);
    REQUIRE(trie.startWith(longStr)==true);
    REQUIRE(trie.startWith(longStr.substr(0,20))==true);
    REQUIRE(trie.find(longStr)==true);
}

TEST_CASE( "Exceptions", "[exceptions]"){
    std::Trie trie;
    // CHECK_THROWS(trie.insert(""));
    REQUIRE_THROWS(trie.print());	
}
