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

Set< Set < string > > nextWords(Lexicon & english,string word);
Set<string> nextWordsSpec(Lexicon & english,string word, int pos);


int main() {
	Lexicon english("EnglishWords.dat");
    cout<<english.size();
    string word="code";
    Set< Set < string > > next;
    next=nextWords(english,word);
    foreach(Set<string> temp in next){
        foreach(string temp2 in temp){
            cout<<temp2<<" ";
        }
    }
    cout<<endl;
	return 0;
}

Set< Set < string > > nextWords(Lexicon & english,string word){
    Set<Set < string > > allNext;
    for (int i=0; i<word.length(); i++) {
        allNext.add(nextWordsSpec(english,word, i));
        
    }
    return allNext;
}

Set<string> nextWordsSpec(Lexicon & english,string word, int pos){
    string temp=word;
    Set<string> set;
    int i;
    for (i=0; i<26; i++) {
        temp[pos]=char(i+'a');
        if (english.contains(temp)) {
            set.add(temp);

        }
    }
    return set;
}
