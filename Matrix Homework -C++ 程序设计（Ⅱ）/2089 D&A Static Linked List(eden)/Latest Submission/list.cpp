#include "list.hpp"
#include <iostream>
#include <sstream>
using namespace std;
list::list() {
  head = nullpointer;
  empty_head = 0;
  for (int i = 0; i < MAX_STORAGE; i++) {
    storage[i].next = i + 1;
  }
  _size = 0;
}

list::list(const list& another) {
  head = nullpointer;
  _size = 0;
  *this = another;
}
list& list::operator=(const list& other) {
  if (this == &other) return *this;
  clear();
  head = other.head;
  empty_head = other.empty_head;
  for (int i = 0; i < MAX_STORAGE; i++) storage[i] = other.storage[i];
  _size = other._size;
  return *this;
}
list::~list() {}
bool list::empty(void) const { return _size == 0 ? true : false; }
list::size_type list::size(void) const { return _size; }

std::string list::toString(void) const {
  // cout << "intostring" << endl;
  std::string str = "";
  std::string shorts;
  if (_size == 0)
    str = "NULL";
  else {
    pointer temp = head;
    while (temp != nullpointer) {
      std::stringstream ss;
      ss << storage[temp].data;
      ss >> shorts;
      str += shorts + "->";
      temp = storage[temp].next;
    }
    str += "NULL";
  }
  // cout << "intostring" << endl;
  return str;
}
void list::insert(int position, const int& data) {
  if (position > _size || position < 0 || _size == MAX_STORAGE) return;
  if (head == nullpointer || position == 0) {
    pointer temp = empty_head;

    empty_head = storage[empty_head].next;

    storage[temp] = data;
    if (head != nullpointer)
      storage[temp].next = head;
    else
      storage[temp].next = nullpointer;
    head = temp;

    _size++;
  } else {
    pointer find = head;
    for (int i = 0; i < position - 1; i++) {
      find = storage[find].next;
    }
    _size++;
    pointer temp = empty_head;
    empty_head = storage[empty_head].next;
    storage[temp] = data;
    storage[temp].next = storage[find].next;
    storage[find].next = temp;
  }
}
void list::erase(int position) {
  if (position < 0 || position >= _size)
    return;
  else if (position == 0) {
    pointer temp = head;
    head = storage[head].next;
    _size--;
    storage[temp].next = empty_head;
    empty_head = temp;
  } else {
    pointer find = head;
    for (int i = 0; i < position - 1; i++) {
      if (find == nullpointer || storage[find].next == nullpointer) return;
      find = storage[find].next;
    }
    _size--;
    pointer del = storage[find].next;
    storage[find].next = storage[del].next;
    storage[del].next = empty_head;
    empty_head = del;
  }
}
void list::clear(void) {
  head = nullpointer;
  empty_head = 0;
  for (int i = 0; i < MAX_STORAGE; i++) {
    storage[i].next = i + 1;
  }
  _size = 0;
}

list& list::sort(void) {
  if (head == nullpointer || storage[head].next == nullpointer) return *this;
  pointer i = head;
  pointer j = head;
  int temp = 0;
  for (; storage[i].next != nullpointer; i = storage[i].next) {
    for (j = head; storage[j].next != nullpointer; j = storage[j].next) {
      if (storage[j].next == nullpointer) break;
      if (storage[j].data > storage[storage[j].next].data) {
        temp = storage[storage[j].next].data;
        storage[storage[j].next].data = storage[j].data;
        storage[j].data = temp;
      }
    }
  }
  return *this;
}
