/**
 * Assigns codes to each character in a piece
 * of text based on the character's frequency.
 * These codes are used to compress some text
 * from file input.
 */


#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <queue>
#include "TreeNode.h"

#define RANGE 128

int main (int argc , char * argv [])
{
  if (argc != 2)
  { std::cout << "Invalid parameters" << std::endl; return -1; }
  
  std::ifstream fin (argv[1], std::ios_base::in);
  if (fin == false)
  { std::cout << "Bad filename" << std::endl; return -2; }
  std::string line;

  unsigned int freq [RANGE] = {0};
  unsigned int total = 0;
  std::string input = "";
  std::string huffcode [RANGE];

  // The Huffman Tree
  std::priority_queue <std::greater <Node>, std::vector <Node> > tree;

  /**
   * Tabulates the number of occurrences of each unique character in
   * the input file
   */
  const char c = RANGE + 10; // a random character not in the range
  while (getline (fin, line, c))
    for (int i = 0; i < line.length (); i++)
      { input+= line[i]; freq [line [i]]++; total++; }
  fin.close ();

  // Inserts in priority queue
  for (int i = 0; i < RANGE; i++)
    if (freq [i])
      tree.push (Node (i, (double) freq [i] / total));

  /**
   * Removes two nodes with highest priority and inserts an
   * internal node containing the two nodes as children
   */
  while (tree.size () > 1)
  {
    Node* lchild = new Node (tree.top ());
    tree.pop ();
    Node* rchild = new Node (tree.top ());
    tree.pop ();
    tree.push (Node (lchild, rchild));
  }

  // Prints out compressed text
  tree.top ().store_code (huffcode);
  for (int i = 0; i < input.length (); i++)
    std::cout << huffcode [input[i]] << " ";
  std::cout << std::endl;
}
