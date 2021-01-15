#ifndef RADIXTREEPROJECT_RADIXTREE_H
#define RADIXTREEPROJECT_RADIXTREE_H
#include <fstream>
using namespace std;

class RadixTree {
private:

    // Radix Tree's private inner class: Node
    class Node {
    public:

        // The value of the node
        char* key;

        // Number of characters in the node (includes the null character - if it exists)
        int len;

        // The following two pointers are the core operational linker nodes of the radix tree

        // ---- The "next" node. This resembles a "sister" node to the current node, meaning that it is at the same tree level
        Node* next;

        // ---- The "link" node. This resembles a "child" node from the next tree level, not necessarily the only child
        Node* link;

        // Basic constructor, initializes the node members as follows:
        // -- Node length:  n
        // -- Link node:    NULL
        // -- Next node:    NULL
        // -- Node value:   Loop sets character array
        Node(char* x, int n) : len(n), link(0), next(0)
        {
            // Create dynamic character array
            key = new char[n];

            // Set array
            for (int i = 0; i < n; i++) key[i] = x[i];
        }

        // Basic deconstructor, deletes node value
        ~Node() { delete[] key; }
    };

    // Radix Tree's root node
    Node* root;

    // File streams to print to right files
    ofstream segmentsFile;
    ofstream nodesFile;
    ofstream treeFile;

    // ----------------------------------------------------------------------------------------
    // Prefix function, responsible for comparing two character arrays "x" and "key",
    // of lengths "n" and "m" respectively.
    //
    int prefix(char* x, int n, char* key, int m);
    // Returns the number of common prefix characters
    // ----------------------------------------------------------------------------------------

    // ----------------------------------------------------------------------------------------
    // Finder function, responsible for finding key "x" in tree of root node "t"
    //
    Node* find(Node* t, char* x, int n = 0);
    // Returns pointer to the node corresponding to "x", if found
    // ----------------------------------------------------------------------------------------

    // ----------------------------------------------------------------------------------------
    // Splitting function, responsible for splitting a node into two at "k"
    // Used as part of the insertion process
    //
    void split(Node* t, int k);
    // ----------------------------------------------------------------------------------------

    // ----------------------------------------------------------------------------------------
    // Insertion function, responsible for inserting a node in its right position
    //
    Node* insert(Node* t, char* x, int n = 0);
    // Returns pointer to the inserted node
    // ----------------------------------------------------------------------------------------

    // ----------------------------------------------------------------------------------------
    // Joining function, responsible for joining a node with its link
    // Used as part of the removal process
    //
    void join(Node* t);
    // ----------------------------------------------------------------------------------------

    // ----------------------------------------------------------------------------------------
    // Removal function, responsible for removing key "x" in tree of root node "t"
    //
    Node* remove(Node* t, char* x, int n = 0);
    // Returns pointer to the node that takes place of removed node
    // ----------------------------------------------------------------------------------------

    // ----------------------------------------------------------------------------------------
    // String counting function, responsible for counting strings in tree of root node "t"
    //
    int countStringsAux(Node* t);
    // ----------------------------------------------------------------------------------------

    // ----------------------------------------------------------------------------------------
    // Node counting function, responsible for counting nodes in tree of root node "t"
    //
    int countNodesAux(Node* t);
    // ----------------------------------------------------------------------------------------

    // ----------------------------------------------------------------------------------------
    // Single node and prefix printing function, prints node "n" and its prefix "p"
    // Has the option to echo output to console - false by default
    //
    void printNodeAndPrefix(Node* n, char* p, int pLen, bool echo = false);
    // ----------------------------------------------------------------------------------------

    // ----------------------------------------------------------------------------------------
    // Node printing function, responsible for printing all nodes in tree of root node "t"
    // The function uses the printNodeAndPrefix function defined previously to print them
    // Has the option to echo output to console - false by default
    //
    void printNodesAux(Node* t, bool echo = false);
    // ----------------------------------------------------------------------------------------

    // ----------------------------------------------------------------------------------------
    // Tree printing function, responsible for visualizing the entire tree of root node "t"
    // Has the option to echo output to console - false by default
    //
    void printTreeAux(char* p, const Node* t, int pLen, bool echo = false);
    // ----------------------------------------------------------------------------------------

    // ----------------------------------------------------------------------------------------
    // To heapify a subtree rooted with node i which is an index in arr. n is size of heap
    //
    void heapifyNodes(Node** arr, int n, int i);
    // ----------------------------------------------------------------------------------------

    // ----------------------------------------------------------------------------------------
    // Node sorting function, responsible for sorting "arr" array of nodes of size "size"
    //
    void heapSortNodes(Node** arr, int size);
    // ----------------------------------------------------------------------------------------

    // ----------------------------------------------------------------------------------------
    // Strings printing function, responsible for printing all strings in tree of root "t"
    // The function uses the sortNodes function defined previously to sort them alphabetically
    // Has the option to echo output to console - false by default
    //
    void printStringsAux(Node* t, char* p, int plen, bool echo = false);
    // ----------------------------------------------------------------------------------------

public:

    // Basic constructor, initializes root node to NULL
    RadixTree() : root(0) {};

    // Publicly usable functions, names self-explanatory
    void addString(char* str);
    void deleteString(char* str);
    bool searchString(char* str);
    int countStrings();
    int countNodes();

    // Printing functions, take the address of the file to print to and a console echo option
    void printStrings(const char* address, bool echo = false);
    void printNodes(const char* address, bool echo = false);
    void printTree(const char* address, bool echo = false);
};

#endif //RADIXTREEPROJECT_RADIXTREE_H