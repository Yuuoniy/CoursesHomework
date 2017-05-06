 #include <iostream>
#include <sstream>
#include "DouList.h"
using namespace std;
DouList::DouList() {
  m_head = 0;
  m_tail = 0;
}
DouList::DouList(const DouList &src) {
  m_head = m_tail = 0;
  (*this) = src;
}
DouList::~DouList() {
  clear();
}
void DouList::clear() {
  if (this->m_head != 0) {
    DouListNode *ptr = m_head;
    while (ptr != 0) {
      DouListNode *temp = ptr;
      ptr = ptr->next;
      delete temp;
    }
  }
  m_head = m_tail = 0;
}
bool DouList::empty() const { return m_head == 0 ? true : false; }
std::string DouList::to_str() const {
  ostringstream op;
  if (m_head == 0) {
    op << "[]";
    return op.str();
  }
  if(m_head==m_tail){
    op << "["<< m_head->elem <<"]";
  }
  else {
    for( DouListNode* ptr = m_head;ptr->next;ptr = ptr->next){
      if(ptr==m_head){
        op << "[" << m_head->elem;
      }
      else
        op << ", " << ptr->elem;
    }
    op << ", " << m_tail->elem << "]";
  }
return op.str();
}
int DouList::front() const { return m_head->elem; }
int DouList::back() const { return m_tail->elem; }
void DouList::push_front(const int &e) {
  DouListNode *temp = new DouListNode(e);
  if (m_head == 0) {
    m_head = m_tail = temp;
  } else {
    temp->next = m_head;
    temp->prev = 0;
    m_head->prev = temp;
    m_head = temp;
  }
}
void DouList::push_back(const int &e) {
  DouListNode *temp = new DouListNode(e);
  if (m_head == 0) {
    m_head = m_tail = temp;
  } else {
    temp->prev = m_tail;
    m_tail->next = temp;
    m_tail = temp;
  }
}
void DouList::pop_front() {
  if (m_head == 0) return;
  DouListNode *temp = m_head;
  if (m_head->next != 0) {
    m_head->next->prev = 0;
    m_head = m_head->next;
  } else
    m_tail = 0;
  delete temp;
}
void DouList::pop_back() {
  if (m_head == 0) return;
  DouListNode *temp = m_tail;
  if (m_tail->prev != 0) {
    m_tail->prev->next = 0;
    m_tail = m_tail->prev;
  } else
    m_head = m_tail = 0;
  delete temp;
}
DouList & DouList:: operator=(const DouList &other) {

  if (this == &other) return *this;
    clear();
  int temp = 0;
  DouListNode *current = other.m_head;
  while (current != 0) {
    temp = current->elem;
    (*this).push_back(temp);
    current = current->next;
  }
  return *this;
}

std::ostream &operator<<(std::ostream &out, const DouList &list) {
 out << list.to_str();
  return out;
}
// non-meaning static value
int DouList::_error_sign;
