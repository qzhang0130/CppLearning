#include "trie.h"
#include <iostream>

int main(){
	Trie root;
	std::string test = "abc";
	root.insert(test);
	std::cout<<root.find("bcd")<<std::endl;
	std::cout<<root.find("abc")<<std::endl;
	std::cout<<root.startWith("ab")<<std::endl;
	return 0;
}