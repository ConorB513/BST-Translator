/*
Name: Conor Benson
External help:
1. Help splitting strings using find and substr
-> https://www.javatpoint.com/how-to-split-strings-in-cpp
2. Code beautify used to format code nicely 
-> https://codebeautify.org/cpp-formatter-beautifier
*/

#include <iostream>

#include <fstream>

#include <string>

#include "BST.hpp"

#include "WordPair.hpp"

using namespace std;

int main() {
    //Search tree to store translations
   CMPT225BST < WordPair > translationTree; 
   string currentLine; //Keeps track of currentLine in input file
   string fileName; //Keeps track of the name of the file being "scanned"
   ifstream inputFile; //Creates file object for the input file
   string srcWord;
   string destWord;
   string key;
   WordPair keyWord; //WordPair object to store word be searched for
   WordPair foundWord;
   //WordPair object to store the translation of the searched word
   string delim = ":";
   //Stores value used to split search word and its translation
   int pos = 0;
   //keeps track of where in the string we want to split 
   int entries = 0; //Keeps track of number of entries

   cout << "Enter the name of the file: ";
   cin >> fileName;

   inputFile.open(fileName);

   /*Condition checks if file exists by seeing if its open, 
   if it isn't, quit the program */

   if (!inputFile.is_open()) {
      cout << "Cannot open the file ... quitting the program" << endl;
      return 0;

   }

   while (getline(inputFile, currentLine)) {

      pos = currentLine.find(delim);
      //Sets the position of the colon 

      srcWord = currentLine.substr(0, pos);
      //The search word becomes the substring of currentLine until the colon
      destWord = currentLine.substr(pos + 1);
      //The translation becomes everything after the colon

      WordPair words = WordPair(srcWord, destWord);
      translationTree.insert(words);
      entries++;

   }

   cout << "Read in " << entries << " entries." << endl;

   //Quit the loop only if the user enters a colon
   while (key != ":") {

      cout << "Enter a word to translate (input colon : to quit): ";

      cin >> key;

      //Quit the program
      if (key == ":") {
         break;
      }

      keyWord.setSourceWord(key);

      try {
         //Search for the inputed word, if found assign it to the foundWord object
         foundWord = translationTree.search(keyWord);
         cout << "The translation of " << keyWord.getSourceWord() <<
            " is " << foundWord.getDestinationWord() << endl;
      }
      //If the word is not in the list of translation catch the exception
      catch (NoSuchValue & nsvEx) {
         cout << "I have no translation for the word " 
         << keyWord.getSourceWord() << endl;
      }

   }

   cout << "Thank you for using the translator app!";
   inputFile.close();
   return 0;

}




