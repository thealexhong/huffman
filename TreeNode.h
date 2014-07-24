#ifndef __TREENODE_H__
#define __TREENODE_H__

#include <string>

/*
 * A Huffman Tree Node
 * Represents both leaf and internal nodes
 */
class Node
{
  private:
    unsigned char value;
    double prob;
    const Node* lchild;
    const Node* rchild;
  public:
    /*
     * Constructs a new leaf node for character _value
     */
    Node (unsigned char _value = 0, double _prob = -1)
    {
      value = _value;
      prob = _prob;
      lchild = 0;
      rchild = 0;
    }

    /*
     * Constructs a new internal node with the probability
     * equal to the sum of the probabilities of each
     * child node
     */
    Node (const Node* _lchild, const Node* _rchild)
    {
      value = 0;
      prob = _lchild -> prob + _rchild -> prob;
      lchild = _lchild;
      rchild = _rchild;
    }
    
    // Destructor
    ~Node ()
    {
      if (lchild)
        return;
      delete lchild;
      delete rchild;
    }
    
    /*
     * Overloading the '<' operator
     * Used as a comparison operator to order the priority queue
     * The less likely the character is, the higher the priority
     */
    bool operator < (const Node &n) const
    { return prob > n.prob; }

    /*
     * Stores the Huffman code
     */
    void  store_code (std::string* arr, std::string code = "") const;

    /*
     * Accessor Methods
     */
    const Node* get_lchild () const { return lchild; }
    const Node* get_rchild () const { return rchild; }
    unsigned char get_value () const { return value; }
};

#endif
