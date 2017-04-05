#include "judge.hpp"
#include <iostream>
std::string roles(Player::Role role){
    switch(role){
      case Player::Werewolf:
        return "Werewolf";
      case  Player::Seer:
        return "Seer";
      case  Player::Witch:
        return "Witch";
      case   Player::Hunter:
        return "Hunter";
      case  Player::Villager:
        return "Villager";
    }
  }
  Judge::Judge(){
    m_players_count = 0;
  }
  Judge::~Judge(){

  }

  void Judge::on(const Player* player){
    m_players[m_players_count++] = player;
  }
  void Judge::call(Player::Role role){
    std::cout << "Calling: " << roles(role) << std::endl;
    for(int i = 0;i<kMaxCountOfPlayers;i++){
      if(role==Player::Villager)
        (*m_players[i]).pretend();
      else if(role==(*m_players[i]).role())
        (*m_players[i]).answer();

    }
  }
  
