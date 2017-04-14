#include <iostream>
#include <list>
#include <vector>
#include "global.hpp"
#ifndef SNAKE_H
#define SNAKE_H
using std::vector;
using std::cout;
class snake {
 private:
  int SnakeLength;
  vector<point> bodys;

 public:
  snake(const point&);
  snake& SnakeMove(direction dir);
  void EatFood(direction dir);
  int GetLength();
  vector<point>& Getbodys();
  ~snake();
};

snake::snake(const point& _head) {
  bodys.push_back(_head);
  SnakeLength = 1;
}
snake::~snake() {}
void snake::EatFood(direction dir) {
  point temp = bodys[0];
  temp.move(dir);
  bodys.insert(bodys.begin(), temp);
  SnakeLength++;
}

int snake::GetLength() { return SnakeLength; }
vector<point>& snake::Getbodys() { return bodys; }

snake& snake::SnakeMove(direction dir) {
  for (int i = SnakeLength - 1; i > 0; i--) {
    bodys[i] = bodys[i - 1];
  }
  bodys[0].move(dir);
}

#endif
