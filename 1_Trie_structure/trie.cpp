#include "trie.h"

void Trie::insert(const std::string& word){
	auto cur = &root;
	for(auto ch: word){
		if(!cur->children.count(ch)){
			cur->children[ch] = TrieNode(); // Not sure if I shold use Trienode or TrieNode()
		}
		cur = &(cur->children[ch]);
	}
	cur->isWord = true;
}

bool Trie::find(const std::string& word){
	auto cur = &root;
	for(auto ch: word){
		if(!cur->children.count(ch)) return false;
		cur = &(cur->children[ch]);
	}
	return cur->isWord;
}

bool Trie::startWith(const std::string& prefix){
	auto cur = &root;
	for(auto ch: prefix){
		if(!cur->children.count(ch)) return false;
		cur = &(cur->children[ch]);
	}
	return true;
}

Trie::Trie(){
}