#include<iostream>
#include<string>
#include<fstream>
#include<vector>

#include"trie.h"

using namespace std;

//trie to store dictionary
Trie *root = new Trie();

//load the dict in the trie on main memory and implement a spell checker

void load()
{
    ifstream inFile;
    inFile.open("large");
    string word;
    while (inFile >> word)
    {   
        root->insert(word);
    }

}
//checks correct words in the file and return vector of wrong words

vector<string> spell_checker(string s)
{
    vector<string> mis_spelled;
    ifstream inFile;
    inFile.open(s);
    string word;
    while (inFile >> word)
    {   
        if (!root->search(word))
            mis_spelled.push_back(word);
    }
    return mis_spelled;
} 

//write misspelled words into a file 
void write_misspelled(vector<string> v)
{
    ofstream f;
    f.open("misspelled.txt");
    for (vector<string>::const_iterator it=v.begin();it!=v.end();++it)
        f<<*it;
    return;
}

int main()
{
    //load dict into trie 
    load();    
    vector<string> mis_spelled =spell_checker("test.txt");
    
    if (mis_spelled.empty())
        cout<<"Correct";
    else 
    {
        cout<<"Incoorect words are: ";
        for (vector<string>::const_iterator it=mis_spelled.begin();it!=mis_spelled.end();++it)
            cout<<*it<<" ";
        cout<<endl;
    }
    
    //writes the misspelled words into the file 
    write_misspelled(mis_spelled);

    return 0;
}