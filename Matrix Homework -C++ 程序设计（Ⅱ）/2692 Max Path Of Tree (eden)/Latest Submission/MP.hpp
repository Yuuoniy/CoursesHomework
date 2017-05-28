#ifndef MP_H
#define MP_H
#include <cmath>
#include <cstdlib>
#include <iostream>
using std::cout;
using std::endl;

namespace MP {
struct TreeNode {
  int val;
  int id;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x, int i) : val(x), id(i), left(NULL), right(NULL) {}
};
class MaxPath {
 private:
  int max;

 public:
  MaxPath() : max(0) {}
  int findMaxPath(MP::TreeNode *node) {
    if (!node) return max;
    int leftv = 0, rightv = 0;
    if (node->right) rightv = findMaxPath(node->right);
    if (node->left) leftv = findMaxPath(node->left);
    return std::max(leftv, rightv) + node->val;
  }
};
}
#endif
