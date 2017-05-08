#include "Set.hpp"
#include <iostream>
// Create an empty set.
Set::Set() { size = 0; }
// Create an set with some element.
Set::Set(int *m, int s) {
  for (int i = 0; i < s; i++) {
    members[i] = m[i];
  }
  size = s;
}
// Copy Constructor
Set::Set(Set const &s) {
  size = s.size;
  for (int i = 0; i < size; i++) members[i] = s.members[i];
}

// append a element to set.
// If element in the set, return false.
// Or insert in set and return true.
bool Set::append(int e) {
  if (isInSet(e)) return false;
  members[size++] = e;
  return true;
}

// remove a element by its value from set.
// If element in the set, then remove it and return true.
// Or return false.
bool Set::remove(int e) {
  if (!isInSet(e)) return false;
  for (int i = 0; i < size; i++) {
    if (members[i] == e) {
      int index = i;
      if (index == size - 1)
        ;
      else
        while (i < size - 1) {
          members[i] = members[i + 1];
          i++;
        }
    }
  }
  size--;
  return true;
}

// return true if the set is empty, or return false.
bool Set::isEmptySet() { return size == 0 ? true : false; }

// return true if the element e is in the set, or return false.
bool Set::isInSet(int e) {
  for (int i = 0; i < size; i++) {
    if (members[i] == e) return true;
  }
  return false;
}

// & is intersection of two set
Set Set::operator&(const Set &s) {
  Set inter;
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < s.size; j++) {
      if (members[i] == s.members[j]) {
        inter.members[inter.size++] = members[i];
      }
    }
  }
  return inter;
}
// | is union of two set
Set Set::operator|(const Set &s) {
  Set unio;
  for (int i = 0; i < size; i++) {
    unio.members[unio.size++] = members[i];
  }
  for (int i = 0; i < s.size; i++) {
    if (!unio.isInSet(s.members[i])) unio.members[unio.size++] = s.members[i];
  }
  return unio;
}
// A - B is the complement of B with respect to A
Set Set::operator-(const Set &s) {
  Set comp;
  int unfindb = 1;
  for (int i = 0, unfindb = 1; i < size; i++) {
    unfindb = 1;
    for (int j = 0; j < s.size; j++) {
      if (s.members[j] == members[i]) {
        unfindb = 0;
        break;
      }
    }
    if (unfindb) comp.members[comp.size++] = members[i];
  }
  return comp;
}

// A + B is their symmetric difference. A + B = (A - B) | (B - A)
Set Set::operator+(const Set &s) {
  Set symm;
  Set set1 = s;
  Set set2 = *this;
  symm = (set1 - set2) | (set2 - set1);
  return symm;
}

// return set.
int *Set::getMembers() { return members; }

// return size of set.
int Set::getSize() { return size; }
