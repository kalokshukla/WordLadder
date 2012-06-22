/*
 * File: WordLadder.cpp
 * --------------------
 * Name: Alok K Shukla
 * 
 */

#include <iostream>
#include "console.h"
#include "lexicon.h"
#include "queue.h"
#include "simpio.h"
#include "vector.h"
using namespace std;

Set<string> nextWords(string word);
Set<string> nextWordsSpec(string word, int pos);


int main() {
	Lexicon english("EnglishWords.dat");
    cout<<english.size();
    string word="code";
    Set<string> next;
    next=nextWords(word);
    foreach(string temp in next){
        cout<<temp<<" ";
    }
    cout<<endl;
	return 0;
}

Set<string> nextWords(string word){
    
}
