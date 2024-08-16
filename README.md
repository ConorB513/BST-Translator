# Binary Search Tree Translator

Translator application that stores words and their translation in a binary search tree.  

## Description

This program was written for my third assignment for my Data Structures and Algorithms class (CMPT 225) with Professor Victor Cheung. 

Using a binary search tree as an internal data structure, the translator app takes a Txt file containing English words and their translation in another language (separate by a colon). 
The program then reads in lines from the file and stores them as wordPair objects. The wordPair header file defines a basic class that stores both a word and its translation (Source word refers to the English word,
and destination word refers to its translation). The wordPair file was implemented and provided by Victor Cheung. Once a wordPair object is created, it is alphabetically stored in a binary search tree (translation
tree). The user then has the option to either enter words to translate or quit the program by entering a semicolon. Provided are two sample text translation files EnglishToKlingon (provided by Victor Cheung) and 
EnglishToFrench.

## Topics 
Binary Search Trees, File IO

## Version History
* 0.1
    * Initial Release

## Acknowledgments

*This project was given as an assignment for my Data Structures and Programming class (CMPT 225 - SFU)

*Help splitting strings using find and substr  -> https://www.javatpoint.com/how-to-split-strings-in-cpp

*Code beautify used to format code nicely  -> https://codebeautify.org/cpp-formatter-beautifier

*Help with BSTs -> https://www.geeksforgeeks.org/introduction-to-binary-tree/

*Help with setting parent pointer in the insert method -> https://www.geeksforgeeks.org/binary-search-tree-insert-parent-pointer/
