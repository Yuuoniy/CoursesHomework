#include "Bulider.hpp"
#include <iostream>

using std::cout;
using std::endl;

Bulider* Bulider::_instance = NULL;
Bulider* Bulider::getInstance() {
  if (_instance == NULL) {
    _instance = new Bulider();
  }
  return _instance;
}
void Bulider::destroyInstance() {
  if (_instance != NULL) delete _instance;
}

// check the token's validity in current nesting structure
// if valid, record it in _tokens, if not, set _error true
void Bulider::handleOneToken(Token token) {
  if(token.type == "CLOSE_TAG"){
    if (!_stack.empty()&&(_stack.top()).content == token.content){
      _stack.pop();
    }
    else {
      _error = true;
    }
  }
  else {
     if ((_stack).empty())
      token.depth = 0;
     else 
      token.depth = (_stack.top()).depth + 1;
    _tokens.push_back(token);
    if(token.type=="OPEN_TAG")
      _stack.push(token);
  }
}

void Bulider::display() {
  if (_error)
    cout << "INVALID INPUT" << endl;
  else {
    for (int i = 0; i < _tokens.size(); i++) {
      if((_tokens[i].content).empty())
        continue;
      if (_tokens[i].type == "OPEN_TAG") {
        if(_tokens[i].depth!=0)
        printf("%*c", _tokens[i].depth * 2 ,' ');
      
        cout << _tokens[i].content<<":"<<endl;
      } else if (_tokens[i].type == "DATA"){

         if(_tokens[i-1].content.empty()){
      
           _tokens[i].depth=_tokens[i-1].depth;
          
         }
        printf("%*c", _tokens[i].depth * 2 ,' ');
        cout << _tokens[i].content<<endl;
       
    }
      }
  }
}
