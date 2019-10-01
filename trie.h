#ifndef GUARD_trie_h
#define GUARD_trie_h

#include<string>

#define ALPHABETS 28

std::string convert_to_index(std::string);

class Trie {
    
    public:
        bool is_word;
        Trie* children[ALPHABETS];
        Trie()
        {
            this->is_word = false;

            for (int i=0;i<ALPHABETS;i++)
                this->children[i]=nullptr;  
        }
        void insert(std::string s);
        bool search(std::string s);
};

#endif
