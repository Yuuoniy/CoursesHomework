 #include "BinaryTree.hpp"
#include <iostream>
#include <queue>

using std::queue;
using std::vector;
using std::cout;
using std::endl;

BinaryTree::Node* NewNode(char val);
void Construct(BinaryTree::Node*& ptr, const vector<char>& preOrder,
               const vector<char>& inOrder, int preHead, int preEnd, int inHead,
               int inEnd);
void DeleteNode(BinaryTree::Node* temp);
void BuildTree(BinaryTree::Node* Source_Root, BinaryTree::Node*& Target_Root);

BinaryTree::BinaryTree(const BinaryTree& other) {
  root = NULL;
  if (other.root) {
    (*this) = other;
  }
}

BinaryTree::BinaryTree(std::vector<char>& other) {
  if (!other.size()) {
    root = NULL;
    return;
  }
  int index = 0;
  queue<Node*> q;
  root = NewNode(other[index++]);
  q.push(root);
  while (!q.empty()) {
    Node* temp = q.front();
    q.pop();
    if (temp != NULL) {
      if (index == other.size()) break;
      temp->left = NewNode(other[index++]);
      q.push(temp->left);
      if (index == other.size()) break;
      temp->right = NewNode(other[index++]);
      q.push(temp->right);
    }
  }
}
// created by preorder and inorder
BinaryTree::BinaryTree(const std::vector<char>& preOrder,
                       const std::vector<char>& inOrder) {
  int size = preOrder.size();
  if (size == 0) {
    root = NULL;
    return;
  } else
    // cout << "in trouble" << endl;
    Construct(root, preOrder, inOrder, 0, size - 1, 0, size - 1);
}
BinaryTree::~BinaryTree() { clear(); }
BinaryTree& BinaryTree::operator=(const BinaryTree& other) {
  if (this == &other) return *this;
  clear();
  BuildTree(other.getRoot(), root);
  return *this;
}

BinaryTree::Node* BinaryTree::getRoot() const { return root; }

void BinaryTree::clear() {
  postOrder(DeleteNode, getRoot());
  root = NULL;
}

void BinaryTree::preOrder(void (*visite)(BinaryTree::Node*), Node* p) {
  if (p) {
    visite(p);
    preOrder(visite, p->left);
    preOrder(visite, p->right);
  }
}
void BinaryTree::inOrder(void (*visite)(BinaryTree::Node*), Node* p) {
  if (p) {
    inOrder(visite, p->left);
    visite(p);
    inOrder(visite, p->right);
  }
}

void BinaryTree::postOrder(void (*visite)(BinaryTree::Node*), Node* p) {
  if (p) {
    postOrder(visite, p->left);
    postOrder(visite, p->right);
    visite(p);
  }
}

BinaryTree::Node* NewNode(char val) {
  if (val == '#')
    return NULL;
  else
    return new BinaryTree::Node(val);
}

void BuildTree(BinaryTree::Node* Source_Root, BinaryTree::Node*& Target_Root) {
  if (Source_Root == NULL) {
    Target_Root = NULL;
  } else {
    Target_Root = new BinaryTree::Node(Source_Root->val);
    BuildTree(Source_Root->left, Target_Root->left);
    BuildTree(Source_Root->right, Target_Root->right);
  }
}

void DeleteNode(BinaryTree::Node* temp) { delete temp; }

void Construct(BinaryTree::Node*& ptr, const vector<char>& preOrder,
               const vector<char>& inOrder, int preHead, int preEnd, int inHead,
               int inEnd) {
  if (preHead > preEnd || inHead > inEnd) return;
  // cout << "in Construct" << endl;
  ptr = new BinaryTree::Node(preOrder[preHead]);
  // cout << ptr->val<<endl;
  int count = 0;
  while (inOrder[count] != preOrder[preHead]) count++;
  int diff = count - inHead - 1;
  Construct(ptr->left, preOrder, inOrder, preHead + 1, preHead + 1 + diff,
            inHead, inHead + diff);
  Construct(ptr->right, preOrder, inOrder, preHead + diff + 2, preEnd,
            count + 1, inEnd);
}
