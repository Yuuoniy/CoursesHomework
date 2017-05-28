#include "User.hpp"
#include <cstring>
#include <string>
#include <utility>
#include <vector>
#include "Mediator.hpp"
using std::pair;
using std::string;
using std::vector;
using std::make_pair;
int User::Count = 0;

User::User(const string& name, const int& money,
           const vector<pair<string, int> >& dresses) {
  this->name = name;
  this->money = money;
  this->id = Count++;
  //  list<User*>::iterator iter = users.begin();

  for (int i = 0; i < dresses.size(); i++) {
    Dress temp(dresses[i].first, dresses[i].second);
    this->dresses.push_back(temp);
  }
  Mediator::getInstance()->RegisterHandler(this);
}

void User::BuyBeautifulDress(const int& id, const int& pay,
                             const string& name) {
  if (pay > money) {
    cout << this->name << " : "
         << "Forget to Check Wallet!" << endl;
    return;
  }
  pair<int, string> result =
      Mediator::getInstance()->TradeHandler(id, pay, name);
  if (result.second == "")
    cout << this->name << " : "
         << "I'm so sorry maybe just because I love it so much." << endl;
  else if (result.first == -1)
    cout << this->name << " : "
         << "OMG! Why it is so Expensive!" << endl;
  else if (result.first == -2) {
  }

  else {
    cout << this->name << " : "
         << "So happy to get new Dress!" << endl;
    money -= pay;
    Dress temp(name, result.first);
    dresses.push_back(temp);
  }
}

void User::SendMessage(const int& to, const string& msg) {
  Mediator::getInstance()->ChatHandler(to, msg);
}
void User::GetDressInfo(const int& id) {
  cout << this->name << " : "
       << "I wanna see your beautiful suits!" << endl;
  Mediator::getInstance()->DressInfoHandler(id);
}
void User::GetMessage(const string& msg) {
  cout << this->name << " : I got a Msg - " << msg << endl;
}
void User::ShowMyCuteDresses() {
  cout << this->name << " : ok,these are all I have : " << endl;
  for (int i = 0; i < dresses.size(); ++i) {
    cout << dresses[i].getName() << "-" << dresses[i].getPrice() << endl;
  }
}

pair<int, string> User::SellBeautifulDress(const int& pay,
                                           const string& dname) {
  pair<int, string> result;
  for (int i = 0; i < dresses.size(); ++i) {
    if (dresses[i].getName() == dname) {
      if (pay >= dresses[i].getPrice()) {
        money += pay;
        dresses.erase(dresses.begin() + i);
        cout << this->name << " : "
             << "What a good taste you have !" << endl;
        result = make_pair(dresses[i].getPrice(), dname);
      } else {
        cout << this->name << " : "
             << "No monry then no talking" << endl;
        result = make_pair(-1, dname);
      }
      return result;
    }
  }
  cout << this->name << " : "
       << "I never have this Dress stupid!" << endl;
  result = make_pair(pay, "");
  return result;
}
