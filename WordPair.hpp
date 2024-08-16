/*
Name: Conor Benson
External help: 
1. Word Pair class was provided by Professor Victor Cheung 
*/

#ifndef _WORDPAIR_HPP_
#define _WORDPAIR_HPP_

#include <string>
#include <ostream>
using namespace std;

struct WordPair {
    private:
        string srcWord;
        string destWord;
    public:
        //default constructor
        WordPair() {
            srcWord = "";
            destWord = "";
        }
        //parameterized constructor
        WordPair(string srcW, string destW) {
            srcWord = srcW;
            destWord = destW;
        }
        //getters and setters
        string getSourceWord() { return srcWord; }
        string getDestinationWord() { return destWord; }
        void setSourceWord(string str) { srcWord = str; }
        void setDestinationWord(string str) { destWord = str; }
        //override comparison operators
        bool operator==(const WordPair& rhs) const {
            return srcWord.compare(rhs.srcWord) == 0; //if equal the compare method returns 0
        }
        bool operator!=(const WordPair& rhs) const {
            return (*this) == rhs; //reuse the overidden operator==
        }
        bool operator<(const WordPair& rhs) const {
            return srcWord.compare(rhs.srcWord) < 0; //if lhs < rhs the compare method returns -ve
        }
        bool operator>=(const WordPair& rhs) const {
            return !((*this) < rhs); //reuse the overridden operator<
        }
        bool operator>(const WordPair& rhs) const {
            return srcWord.compare(rhs.srcWord) > 0; //if lhs > rhs the compare method returns +ve
        }
        bool operator<=(const WordPair& rhs) const {
            return !((*this) > rhs); //reuse the overridden operator>
        }
        friend ostream& operator<<(ostream& os, const WordPair& wp) {
            os << wp.srcWord << ":" << wp.destWord;
            return os;
        }

};

#endif