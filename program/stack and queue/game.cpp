#include "judge.hpp"
#include "player.hpp"
#include <cassert>
#include <iostream>
#include <string>
using std::cin;

void RunAllTests() {
  Judge judge;
  Player players[Judge::kMaxCountOfPlayers];
  std::string name;
  Player::Role role;

  for (int i = 0; i < Judge::kMaxCountOfPlayers; ++i) {
    switch (i) {
      case 0:
      case 1:
      case 2: { role = Player::Villager; break; }
      case 3:
      case 4:
      case 5: { role = Player::Werewolf; break; }
      case 6: { role = Player::Seer; break; }
      case 7: { role = Player::Witch; break; }
      case 8: { role = Player::Hunter; break; }
      default: assert(false);
    }

    cin >> name;
    players[i].init(name, role);
    judge.on(&players[i]);
  }

  int role_index;
  cin >> role_index;
  judge.call(static_cast<Player::Role>(role_index));

}

int main() {
  RunAllTests();
  return 0;
}
