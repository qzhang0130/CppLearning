#include "trie.h"
#include <iostream>

int main(){
	Trie root;
	std::string test = "abc";
	root.insert(test);
	/*cout<<root.find(string("bcd"))<<endl;
	cout<<root.find(string("abc"))<<endl;
	cout<<root.startWith(string("ab"))<<endl;*/
	return 0;
}