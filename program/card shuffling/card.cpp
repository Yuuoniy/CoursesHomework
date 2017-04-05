#include "card.hpp"
#include "deck-of-cards.hpp"

std::string temp = " of ";
Card:: Card(int cardFace, int cardSuit){
     face = cardFace;
     suit = cardSuit;
 }
std::string Card::toString() const{
    std::string str= faceNames[face] + temp + suitNames[suit];
    return str;
}

int Card::getFace() const{
        return face;
    }
int Card::getSuit() const{
        return suit;
    }
const char * Card::faceNames[13] = {"Ace", "Deuce", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};
const char * Card::suitNames[4] = {"Hearts", "Diamonds", "Clubs", "Spades"};

