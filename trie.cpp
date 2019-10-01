#include"trie.h"

using namespace std;

string convert_to_index(string s)
{
    
    for (string::size_type i=0;i<s.size();++i)
    {
        if (s[i]=='\'')
            s[i]=26;
        else
            s[i]=s[i]-'a';
    }
    return s;
}

void Trie::insert(string s)
{
    s=convert_to_index(s);
    Trie *curr = this;
    for (int i =0;i<s.length();i++)
    {
        if (curr->children[s[i]]==nullptr)
            curr->children[s[i]] = new Trie();
        curr=curr->children[s[i]];
    }
    curr->is_word=true;
}

bool Trie::search(string s)
{
    s=convert_to_index(s);
    if(this==nullptr)
        return false;
    Trie *curr = this;
    for (int i =0;i<s.length();i++)
    {
        //root has h as children h has a a has t t is end of word 
        if(curr->children[s[i]]==nullptr)
            return false;
        curr=curr->children[s[i]];
    }
    return curr->is_word;
}
