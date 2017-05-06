 #include "Parser.hpp"


Parser* Parser::_instance = NULL;


Parser* Parser::getInstance(){
   if(_instance==NULL){
        _instance = new Parser();
    }
    return _instance;
 }


void Parser::destroyInstance(){
     if(_instance!=NULL)
        delete _instance;
  }

void Parser::consumeOneChar(char ch){
  _state->handleOneChar(getInstance(),ch);
  
}
