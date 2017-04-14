#include <cstdio>
#include <cstring>
#include <iostream>
#include <list>
#include "global.hpp"
#include "snake.hpp"
#ifndef MAP_H
#define MAP_H
using std::list;
using std::endl;
using std::cout;
class map {
 private:
  point size;
  snake play;
  list<point> foods;
  char** show;

 public:
  map(const point& _size, const point& _head, const list<point> _food);
  void print(void);
  map& move(direction dir);
  bool isGameOver(void);
  map& eatfood(void);
  ~map(void);
};

map::map(const point& _size, const point& _head, const list<point> _food)
    : size(_size), foods(_food), play(_head) {
  show = new char*[size.x];
  for (int i = 0; i < size.x; i++) {
    show[i] = new char[size.y];
    for (int j = 0; j < size.y; j++) {
      show[i][j] = '\0';
    }
  }
  show[_head.x][_head.y] = HEAD;
  while (foods.size() != 0) {
    show[(foods.front()).x][(foods.front()).y] = FOOD;
    foods.pop_front();
  }
}

void map::print(void) {
  if (this->isGameOver()) {
    for (int i = 0; i < size.x; i++) {
      for (int j = 0; j < size.y; j++) printf("%c", show[i][j]);
      printf("\n");
    }
    printf("\n");
    return;
  }
  for (int i = 0; i < size.x; i++) {
    for (int j = 0; j < size.y; j++) {
      if (show[i][j] != FOOD) show[i][j] = EMPTY;
    }
  }
  show[(play.Getbodys())[0].x][(play.Getbodys())[0].y] = HEAD;
  for (int i = 1; i < (play.Getbodys()).size(); i++) {
    show[(play.Getbodys())[i].x][(play.Getbodys())[i].y] = BODY;
  }
  for (int i = 0; i < size.x; i++) {
    for (int j = 0; j < size.y; j++) printf("%c", show[i][j]);
    printf("\n");
  }
  printf("\n");
}

map& map::move(direction dir) {
  point temp = (play.Getbodys())[0];
  temp.move(dir);
  if (temp.x < size.x && temp.x >= 0 && temp.y < size.y && temp.y >= 0) {
    if (show[temp.x][temp.y] == FOOD) {
      play.EatFood(dir);
    } 
    else if (play.GetLength()!=1&&play.GetLength()!=2&&temp==play.Getbodys()[1]) {
      (play.Getbodys())[0].move(dir); 	
    }
     else {
      play.SnakeMove(dir);
    }
  } else
    (play.Getbodys())[0].move(dir);
  return *this;
}
bool map::isGameOver(void) {
  if (((play.Getbodys())[0]).x >= size.x || ((play.Getbodys())[0]).x < 0 ||
      ((play.Getbodys())[0]).y >= size.y || ((play.Getbodys())[0]).y < 0) {
    return true;
  }
  for (int i = 1; i < play.GetLength(); i++) {
    if ((play.Getbodys())[0] == (play.Getbodys())[i]) {
      return true;
    }
  }

  return false;
}

map::~map(void) {
  for (int i = 0; i < size.x; i++) {
    delete[] show[i];
  }
  delete[] show;
}

#endif