#include <string>
#include "TreeNode.h"

/*
 * Stores the Huffman code
 */
void Node::store_code (std::string* arr, std::string code) const
{
  if (get_lchild ())
  {
    get_lchild () -> store_code (arr, code + '0');
    get_rchild () -> store_code (arr, code + '1');
  }
  else
    arr [get_value ()] = code;
}