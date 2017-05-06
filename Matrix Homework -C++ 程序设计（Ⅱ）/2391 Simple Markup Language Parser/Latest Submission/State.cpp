#include "State.hpp"
#include "Parser.hpp"
#include "Token.hpp"
State* DataState::_instance = NULL;
State* TagNameState::_instance = NULL;
State* DataState::getInstance() {
  if (_instance == NULL) {
    _instance = new DataState();
  }
  return _instance;
}
void DataState::destroyInstance() {
  if (_instance != NULL) delete _instance;
}

void DataState::handleOneChar(Parser* parser, char ch) {
  if (ch == '<') {
    parser->setState(TagNameState::getInstance());
     _cache.erase(0, _cache.find_first_not_of(" "));
    _cache.erase(_cache.find_last_not_of(" ") + 1);
    if (!_cache.empty()) emit(parser->getBulider());
    return;
  } 
  else
    _cache += ch;
}

void DataState::emit(Bulider* dest) {
  Token temp;
  temp.type = "DATA";
  temp.content = _cache;
  temp.depth = 0;
  dest->handleOneToken(temp);
  _cache.clear();
}

State* TagNameState::getInstance() {
  if (_instance == NULL) {
    _instance = new TagNameState();
  }
  return _instance;
}
void TagNameState::destroyInstance() {
  if (_instance != NULL) delete _instance;
}

void TagNameState::handleOneChar(Parser* parser, char ch) {
  if (ch == '>') {
    emit(parser->getBulider());
    parser->setState(DataState::getInstance());
    return;
  } else
    _cache += ch;
}

void TagNameState::emit(Bulider* dest) {
  Token temp;
  if (_cache[0] == '/') {
    temp.type = "CLOSE_TAG";
    temp.content = _cache.substr(1);
    temp.depth = 0;
  } else {
    temp.type = "OPEN_TAG";
    temp.content = _cache;
    temp.depth = 0;
  }
  // cout << temp.content << endl;
  dest->handleOneToken(temp);
  _cache.clear();
}
