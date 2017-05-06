 #include "Mediator.hpp"
#include <list>
#include <utility>
using std::list;
using std::pair;
Mediator* Mediator::Ins = NULL;

void Mediator::RegisterHandler(User* u) { users.push_back(u); }

void Mediator::ChatHandler(const int& to, const string& msg) {
  list<User*>::iterator iter = users.begin();
  for (iter; iter != users.end(); ++iter) {
    if ((*iter)->getId() == to) {
      (*iter)->GetMessage(msg);
      break;
    }
  }
}

pair<int, string> Mediator::TradeHandler(const int& to, const int& pay,
                                         const string& dressName) {
  list<User*>::iterator iter = users.begin();
  for (iter; iter != users.end(); ++iter) {
    if ((*iter)->getId() == to) {
      return (*iter)->SellBeautifulDress(pay, dressName);
    }
  }
  cout << "Are you kidding ? There is no such a guy!" << endl;
  pair<int, string> result(-2, dressName);
  return result;
}
void Mediator::DressInfoHandler(const int& to) {
  list<User*>::iterator iter = users.begin();
  for (iter; iter != users.end(); ++iter) {
    if ((*iter)->getId() == to) {
      (*iter)->ShowMyCuteDresses();
      return;
    }
  }
  cout << "There is no Such a guy!" << endl;
}
