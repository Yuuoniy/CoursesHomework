 
#include <cstdlib>
template <typename T>

class Stack {
 public:
  Stack() : top_node(NULL), node_num(0) {}

  Stack(const Stack &stack) : top_node(NULL), node_num(0) {
    if (!stack.top_node) return;
    Node *temp = stack.top_node;
    while (temp->next) {
      push(temp->element);
      temp = temp->next;
    }
    push(temp->element);
    reverse();
  }

  ~Stack() { clear(); }

  bool empty() { return node_num == 0; }

  size_t size() const { return node_num; }

  T top() const { return top_node->element; }

  void push(T element) {
    Node *temp = new Node(element, top_node);
    top_node = temp;
    node_num++;
  }

  void pop() {
    if (empty()) return;
    Node *temp = top_node;
    top_node = top_node->next;
    node_num--;
    delete temp;
  }

  void swap(Stack &stack) {
    Node *temptr = stack.top_node;
    int tempnum = stack.node_num;
    stack.top_node = top_node;
    stack.node_num = node_num;
    top_node = temptr;
    node_num = tempnum;
  }

  void reverse() {
    Stack<T> temp;
    int num = node_num;
    for (int i = 0; i < num; ++i) {
      temp.push(top());
      pop();
    }
    swap(temp);
  } /*reverse the elements' order in the stack*/

  void clear() {
    if (top_node == NULL) return;
    Node *p = top_node;

    while (p != NULL) {
      Node *temp = p;
      p = p->next;
      delete temp;
    }
    top_node = NULL;
    node_num = 0;
  }

 private:
  struct Node {
    T element;
    Node *next;
    Node(T ele, Node *n = NULL) {
      element = ele;
      next = n;
    }
  };
  Node *top_node;
  size_t node_num;
};
