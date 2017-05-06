 #ifndef HEADER_H
#define HEADER_H
#include <iostream>
#include <vector>
using namespace std;
class gameobject {
 protected:
  double x, y;
  int hp, speed;

 public:
  gameobject(int _x, int _y, int _speed)
      : x(_x), y(_y), speed(_speed), hp(10) {}
  virtual void select() = 0;
  virtual void move() {
    x += speed;
    y += speed;
  }
  int get_hp() const { return hp; }
  void change_hp(int sign) {
    if (sign == -1)
      hp--;
    else
      hp = 10;
  }
  ~gameobject() {}
};

class worker : public gameobject {
 public:
  worker(int x, int y) : gameobject(x, y, 1) {}
  ~worker() {}
  void select() { cout << "Scv good to go, sir!" << endl; }
  void move() {
    gameobject::move();
    cout << "Worker moves to "
         << "(" << x << ", " << y << ")" << endl;
  }
  void build(int height);
  void repair(gameobject* other) { other->change_hp(1); }
};

class zealot : public gameobject {
 public:
  zealot(int x, int y) : gameobject(x, y, 2) {}
  ~zealot() {}
  void select() { cout << "My life for Aiur!" << endl; }
  void move() {
    gameobject::move();

    cout << "Zealot moves to "
         << "(" << x << ", " << y << ")" << endl;
  }
  void attack(gameobject* other) { other->change_hp(-1); }
};
class tower : public gameobject {
 public:
  tower(int x, int y) : gameobject(x, y, 0) {}
  ~tower() {}
  void select() { cout << "~" << endl; }
  void move() {
    gameobject::move();

    cout << "Tower cannot move." << endl;
  }
  void attack(gameobject* other) { other->change_hp(-1); }
};

void worker::build(int height) {
  for (int i = 1; i <= height; i++) {
    printf("%*c", height - i+1, '*');
    for (int j = 1; j < i * 2 - 1; j++) printf("*");
    printf("\n");
  }
}

#endif
