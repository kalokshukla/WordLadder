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

Set<string> nextWords(Lexicon & english,string word);
Set<string> nextWordsSpec(Lexicon & english,string word, int pos);


int main() {
	Lexicon english("EnglishWords.dat");
    string word=getLine("Enter a word: ");
    Set<string> set;
    if (!english.contains(word)) {
        //cout<<<<endl;
        error("Sorry! this term is not defined in our dictionary");
    }
    cout<<"Following are all the words that are just one character differnt from "<<"\""<<word<<"\":"<<endl;
    cout<<"[ ";
    int i=0;
    set=nextWords(english,word);
    foreach(string s in set){
        if (i++!=0) {
            cout<<", "<<s;
        }
        else {
            cout<<s;

        }
    }
    cout<<" ]"<<endl;
	return 0;
}

 Set<string> nextWords(Lexicon & english,string word){
 Set<string> allNext;
 for (int i=0; i<word.length(); i++) {
     foreach (string s in nextWordsSpec(english, word, i)){
         allNext.add(s);
     }
 
 }
 return allNext;
 }
 

Set<string> nextWordsSpec(Lexicon & english,string word, int pos){
    string temp=word;
    Set<string> next;
    char c=word[pos];
    for (int i=0; i<26; i++) {
        if (char(i+'a')!=c){
            word[pos]=char(i+'a');
            if (english.contains(word)) {
                next.add(word);
            }
        }
        
    }
    return next;
}
