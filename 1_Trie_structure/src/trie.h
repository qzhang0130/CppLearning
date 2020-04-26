#include <string>
#include <unordered_map>

namespace std{
	class Trie{
	public:
		void insert(const std::string& word);
		bool find(const std::string& word);
		bool startWith(const std::string& prefix);
		void print();
		Trie();
	private:
		struct TrieNode{
			bool isWord;
			std::unordered_map<char, TrieNode> children;

			TrieNode():isWord(false){}
		};

		TrieNode root;
	};
}