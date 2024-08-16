/*
Name: Conor Benson
External help: 
1. Help with BSTs
-> https://www.geeksforgeeks.org/introduction-to-binary-tree/
2. Help with setting parent pointer in the insert method 
-> https://www.geeksforgeeks.org/binary-search-tree-insert-parent-pointer/
3. Code beautify used to format code nicely 
-> https://codebeautify.org/cpp-formatter-beautifier
4. Template Provided by professor Victor Cheung 
*/

#ifndef _BST_HPP_
#define _BST_HPP_

#include <exception>

#include <ostream>

using namespace std;

template < class T >
   class CMPT225BSTNode {
      private: T data;
      CMPT225BSTNode < T > * left; //pointer to the left child (nullptr if it is a leaf)
      CMPT225BSTNode < T > * right; //pointer to the right child (nullptr if it is a leaf)
      CMPT225BSTNode < T > * parent; //pointer to the parent (nullptr if it is the root)
      public:
         //parameterized constructor
         CMPT225BSTNode(T value) {
            data = value;
            right = nullptr;
            left = nullptr;
            parent = nullptr;
         }
      //getter of address of the left node
      CMPT225BSTNode < T > * getLeft() const {
         return left;
      }
      //getter of address of the right node
      CMPT225BSTNode < T > * getRight() const {
         return right;
      }
      //getter of address of the parent node
      CMPT225BSTNode < T > * getParent() const {
         return parent;
      }

      //setter of address of the left node
      void setLeft(CMPT225BSTNode < T > * node) {
         left = node;
      }
      //setter of address of the right node
      void setRight(CMPT225BSTNode < T > * node) {
         right = node;
      }
      //setter of address of the parent node
      void setParent(CMPT225BSTNode < T > * node) {
         parent = node;
      }
      //getter of data (returns a copy)
      T getData() const {
         return data;
      }
      //setter of data (sets a copy)
      void setData(const T & value) {
         data = value;
      }
      //no explicit destructor is needed for this class, assuming T will destroy itself properly
   };

// Exception thrown on having a existing node with the same value to be inserted
//a really simple class so we just define & implement it here
class ValueAlreadyExists: public exception {
   public: virtual
   const char * what() const noexcept {
      return "Exception: tree already has the value to be inserted";
   }
};

// Exception thrown on not able to find a node having the searched-for value
//a really simple class so we just define & implement it here
class NoSuchValue: public exception {
   public: virtual
   const char * what() const noexcept {
      return "Exception: value does not exist in the tree";
   }
};

template < class T >
   class CMPT225BST {
      private: CMPT225BSTNode < T > * root;
      int size;

      /*Internal copy constructor for BST nodes. 
       Creates a new node with the same data as the node its copying*/
      CMPT225BSTNode < T > * copy(const CMPT225BSTNode < T > * otherNode) {
         //Return nullptr if the user attempts to copy an non-existent node
         if (otherNode == nullptr) {
            return nullptr;
         } else {
            //Create a new node with the same data as the original node
            CMPT225BSTNode < T > * copyNode = new CMPT225BSTNode < T > (otherNode -> getData());
            copyNode -> setLeft(copy(otherNode -> getLeft()));
            copyNode -> setRight(copy(otherNode -> getRight()));
            copyNode -> setParent(otherNode -> getParent());
            return copyNode;
         }
      }

      //an internal recursive insert method that does the actual insertion
      //throws a ValueAlreadyExists exception if there is already a node storing the same value
      CMPT225BSTNode < T > * insert(CMPT225BSTNode < T > * node,
         const T & value) {

         //Base case when a free space to insert the new node is found
         if (node == nullptr) {
            CMPT225BSTNode < T > * newNode = new CMPT225BSTNode < T > (value);
            size++;
            return newNode;
         }

         /*If the the value of the current node is the same 
         as the value to be inserted 
         Throw a valueAlreadyExists exeception*/
         if (node -> getData() == value) {
            throw ValueAlreadyExists();
         }

         /*If the value is smaller then the current nodes value
         call the insert function on the left child of the current Node
         then set the leftChild of the current node to leftNode and 
         set the paretn of leftNode to the current node
         */

         if (node -> getData() > value) {
            CMPT225BSTNode < T > * leftNode = insert(node -> getLeft(), value);
            node -> setLeft(leftNode);
            leftNode -> setParent(node);

         }
         /*If the value is larger then the current nodes value
         call the insert function on the right child of the current Node
         then set the right Child of the current node to rightNode and 
         set the parent of rightNode to the current node*/
         else {
            CMPT225BSTNode < T > * rightNode = insert(node -> getRight(), value);
            node -> setRight(rightNode);
            rightNode -> setParent(node);
         }

         return node;
      }

      //an internal recursive search method that does the actual search
      //throws a NoSuchValue exception if not found
      T search(CMPT225BSTNode < T > * node,
         const T & key) const {
         //If the key is not in the tree, throw a NoSuchValue exception
         if (node == nullptr) {
            throw NoSuchValue();
         }
         //Base case when key is found in the tree
         if (node -> getData() == key) {
            return node -> getData();
         }
         /*
    If the key is smaller then the current nodes value
    call the search function on the left child of the current Node
    */
         if (node -> getData() > key) {
            return search(node -> getLeft(), key);
         }
         /*
         If the key is larger then the current nodes value
         call the search function on the right child of the current Node
         */
         else {
            return search(node -> getRight(), key);
         }

      }
      //an internal recursive print method that does the actual print using in-order
      void print(CMPT225BSTNode < T > * node, ostream & os) const {
         //If the tree is empty, inform user
         if (size == 0) {
            os << "Empty Tree" << " ";
            return;
         }

         //Base case. If node does not exists, print nothing
         if (node == nullptr) {
            return;
         }
         //Print according to in-order print criteria
         else {
            print(node -> getLeft(), os);
            os << node -> getData() << " ";
            print(node -> getRight(), os);
            return;
         }

      }
      //an internal recursive method that releases the memory of a node (and its subtrees)
      void destroy(CMPT225BSTNode < T > * node) {
         //As long as the node exist, call destroy on its children then delete the node
         if (node != nullptr) {
            destroy(node -> getLeft());
            destroy(node -> getRight());
            delete node;
         }

      }
      public:
         //Public default constructor 
         CMPT225BST() {

            root = nullptr;
            size = 0;

         }

      //Public copy constructor calls internal copy constructore
      CMPT225BST(const CMPT225BST < T > & other) {

         size = other.getSize();
         //Copy constructor starts with the root node of the BST
         root = copy(other.root);

      }
      //Public insert methods calls interal insert method with root node
      void insert(const T & value) {
         root = insert(root, value);

      }

      //Public search method calls internal search method
      T search(const T & key) const {

         return search(root, key);
      }
      //return the size of the tree
      int getSize() const {
         return size;
      }
      //Public print method calls internal print method 
      void print(ostream & os) const {

         print(root, os);
      }

      //Public destructor calls internal destroy method 
      ~CMPT225BST() {
         destroy(root);
      }
   };

#endif