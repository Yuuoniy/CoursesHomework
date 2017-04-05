#include "player.hpp"

#include <iostream>
std::string roless(Player::Role role){
    switch(role){
      case Player::Werewolf:
        return "Werewolf";
      case  Player::Seer:
        return "Seer";
      case  Player::Witch:
        return "Witch";
      case   Player::Hunter:
        return "Witch";
      case  Player::Villager:
        return "Villager";
    }
  }

 Player::Player(){
     m_role = Uninitialized;
 }
 Player::~Player(){   
  }
  void Player::init(std::string name, Role role){
      m_name = name;
      m_role = role;
  }
  

  Player::Role Player::role() const{
      return m_role;
  }
  void Player::answer() const{
      std::cout << "" << m_name <<": Shh... I am a "<< roless(role()) <<"." << std::endl;
  }
  void Player::pretend() const{
      std::cout << "" << m_name << ": I am the villager!!"<< std::endl;
  }
