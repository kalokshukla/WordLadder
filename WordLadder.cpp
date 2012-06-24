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

Lexicon english("EnglishWords.dat");
//string word,end;

Set<string> nextWords(string word);
Set<string> nextWordsSpec(string word, int pos);

void printVector(Vector<string> v){
    foreach(string i in v){
        cout<<i<<" ";
    }
    cout<<endl;
}

void printQueue(Queue< Vector<string> > q){
    int n=q.size();
    while (n-->0) {
        printVector(q.dequeue());
    }
    cout<<endl;
}

void printSet(Set<string> s){
    foreach(string st in s){
        cout<<st<<" ";
    }
    cout<<endl;
}

bool isPresent(Queue< Vector<string> > q, string st){
    int l=q.size();
    while (l-->0) {
        Vector<string> v=q.dequeue();
        foreach(string s in v){
            if (s==st) {
                return true;
            }
        }
    }
    return false;
}   


void wordLadder(string word, string end){
    Set<string> set;
    if (!english.contains(word)) {
        error("Sorry! this term is not defined in our dictionary");
    }
    Vector<string> start(1,word),ladder,copy,final;
    Queue< Vector<string> > ladders;
    ladders.enqueue(start);
    while (!ladders.isEmpty()) {
        ladder=ladders.dequeue();
        if (ladder[ladder.size()-1]==end) {
            cout<<"\nFound ladder:   ";
            printVector(ladder);
            cout<<endl;

            return;
        }
        foreach(string w in nextWords(ladder[ladder.size()-1])){
            if (!isPresent(ladders, w)) {
                copy=ladder;
                copy.add(w);
                ladders.enqueue(copy);
            }
        }
    }
    cout<<"No ladder found\n";
    return;
}

int main() {
	while (true) {
        string word=getLine("Enter starting word (RETURN to quit): ");
        if (word=="") {
            break;
        }
        string end=getLine("Terminating word: ");
        wordLadder(word,end);
    }
	return 0;
}

Set<string> nextWords(string word){
    Set<string> allNext;
    for (int i=0; i<word.length(); i++) {
        foreach (string s in nextWordsSpec(word, i)){
            allNext.add(s);
        }
        
    }
    return allNext;
}


Set<string> nextWordsSpec(string word, int pos){
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
