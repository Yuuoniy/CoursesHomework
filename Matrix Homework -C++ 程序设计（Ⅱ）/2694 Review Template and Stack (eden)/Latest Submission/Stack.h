#include <iostream>
#include <queue>
using std::endl;
using std::cout;
using std::queue;

template <typename T>
class Stack {
 public:
  Stack() : count(0) {}  // constructor.
  void push(const T& data) {
    while (!q1.empty()) {
      q1.pop();
    }
    q1.push(data);
    for (int i = 0; i < count; i++) {
      q1.push(q2.front());
      q2.pop();
    }
    q2 = q1;
    count++;

  }  // push operation.
  T pop() {
    T temp = q2.front();
    if (count != 0) {
      count--;
      q2.pop();
    }

    return temp;
  }  // return the value in the top and pop it out of the stack.
  T top() { return q2.front(); }       // return the value in top.
  int size() const { return count; }   // return size of the stack.
  bool empty() { return count == 0; }  // check whether is empty.
  friend void print(Stack& other) {
    other.q1 = other.q2;
    for (int i = 0; i < other.size(); ++i) {
      cout << (other.q1).front() << " ";
      (other.q1).pop();
    }
    cout << endl;
  }

 private:
  queue<T> q1;  // two queues.//辅
  queue<T> q2;  //主
  int count;    // the number of elements.
};
