#include "deck-of-cards.hpp"
#include "card.hpp"
#include <vector>

 DeckOfCards::DeckOfCards(){
    currentCard = 0;
    for(int i = 0;i<4;i++){
        for(int j = 0;j<13;j++){
            Card temp(j,i);
            deck.push_back(temp);
        }
    }
 }


Card DeckOfCards::dealCard(){
        return deck[currentCard++];
    }
bool DeckOfCards::moreCards() const{
    return currentCard<52?true:false;
}
