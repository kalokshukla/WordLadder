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

//Set< Set < string > > nextWords(Lexicon & english,string word);
Set<string> nextWordsSpec(Lexicon & english,string word, int pos);


int main() {
	Lexicon english("EnglishWords.dat");
    cout<<english.size();
    string word="code";
    Set<string> next=nextWordsSpec(english,word,1);
    cout<<endl;
        int i=0;
    cout<<"[ ";
    foreach(string temp in next){
        i++;
        if (i!=1) {
            cout<<", "<<temp;
        }
        else {
            cout<<temp;
        }
    }
    cout<<" ]"<<endl;
    cout<<endl;
	return 0;
}

/*Set< Set < string > > nextWords(Lexicon & english,string word){
    Set<Set < string > > allNext;
    for (int i=0; i<word.length(); i++) {
        allNext.add(nextWordsSpec(english,word, i));
        
    }
    return allNext;
}
*/

Set<string> nextWordsSpec(Lexicon & english,string word, int pos){
    string temp=word;
    Set<string> next;
    char c=word[pos];
    for (int i=0; i<26; i++) {
    if (char(i+'a')!=c){
            word[1]=char(i+'a');
            if (english.contains(word)) {
                        next.add(word);
            }
    }
 
    }
    return next;
}
