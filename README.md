#README
##DESCRIPTION
This program compresses data using a technique called Huffman coding.
The program accepts an input file of text with ASCII values from
0 to 127, and builds a Huffman tree. The tree is used to assign
codes to each character in the input file. These codes are then used
to compress the text. As a result, the program will output the
Huffman code of the input to the standard output stream.

##SOURCE FILES
* HuffmanMain.cpp
* TreeNode.cpp
* TreeNode.h

###HuffmanMain.cpp
####VARIABLES
  * RANGE: 128 characters
  * fin: file input stream
  * line: temporary string for reading file
  * freq: number of occurences of each character
  * total: total number of characters
  * input: string that represents the file input
  * huffcode: the Huffman code for each unique character
  * tree: the Huffman tree (heap-based priority queue)
  
  The main source file. The program reads in from an input file and
  tabulates the number of occurrences of each unique character in the
  input file. A const character set at RANGE + 10 is used as a
  delimeter for getline (). This is done because characters will never
  be greater than the ASCII value of 127. It forces the program to read
  every character, including '\n' for Huffman compression.
  The program inserts a tree node, which contains the character and
  its probability into the priority queue. If there is more than one
  node in the priority queue, the program creates an internal node
  containing two nodes with highest priority as children and inserts
  it back into the queue. As a result, the program will create
  one big tree called the Huffman tree.
  The program then traverses through the tree storing the Huffman
  code for each character and finally outputing the
  compressed text - the Huffman code.
  
  * k: number of unique characters
  * n: number of characters
  * Program requires O(k) space.
  * Tabulating frequency and probability calculations run in O(n) time.
  * Inserting nodes to heap-based priority queue run in O(k) time.
  * Creating internal nodes until tree is size 1 run in O(k log k) time.
  * Accessing root of Huffman tree takes O(1) time.
  * Assigning code to each unique character takes O(k) time.
  * Printing Huffman code takes O(n) time.
  
###TreeNode.h
####VARIABLES
  * value: the character being stored
  * lchild: left child of this node
  * rchild: right child of this node
  
  This header file contains the Node class. Its constructor initializes 
  the character being stored and the probability of the character.
  The second constructor is used to construct an internal node with
  no character value. It only contains the sum of the probabilities of
  each child node. The destructor frees the children of the node, if there
  exist any.
  The class also defines how Node objects are compared. This was programmed
  for the priority queue to compare two different Node objects. In this
  assignment, the less likely the character is, the higher priority it has
  in the queue. When comparing two Nodes,
            Node n1 < Node n2 iff n1.probability > n2.probability
  So n2 has a higher priority in the above example if the statement is true.
  The store_code method, defined in TreeNode.cpp, stores the Huffman code.
  The class also has accessor methods (getters). This is done to
  enforce encapsulation.

###TreeNode.cpp
  This source file defines the method, store_code, in the header file.
  The method stores the huffman code for each unique character in the
  input file.

##DATA STRUCTURES
The main data structure used in this program is a priority queue.
The priority queue is a container adapter, which is implemented
by STL. A container adapter uses an existing container, in this case
vector, to implement a new container type. The priority queue
also has the comparison property used to compare Nodes. The 
TreeNode header file defines how to compare nodes so that
each node has a priority. The priority queue works the same way
as a queue except that it is highest priority out first, instead
of FIFO. The top () method will return the Node of the highest priority
in the queue. The push () and pop () methods run in logarithmic time.

####TEST FILES
  * DATA1.txt: A simple test file containing "SEASHELLS" with no newline.
  * DATA2.txt: Same as DATA1.txt but with newline.
  * DATA3.txt: A file containing both upper and lower case
  * DATA4.txt: A file containing non-alphabet
  * DATA5.txt: A file containing more than 50 characters
  * DATA6.txt: A file containing 2 repetitive characters
  * DATA7.txt: A file containing repetitive characters
  * DATA8.txt: A file containing characters with equal probabilities
  * DATA9.txt: A file with just newlines and spaces
  * DATA10.txt: A large test file
