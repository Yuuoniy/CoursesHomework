#include <iostream>
#include <map>
#include <set>
#include <string>
using namespace std;
int main() {
  int n = 0;
  cin >> n;
  map<string, set<string> > qqip;
  map<string, set<string> > ipqq;
  string tempqq, tempip;
  for (int i = 0; i < n; ++i) {
    cin >> tempqq >> tempip;
    qqip[tempqq].insert(tempip);
    ipqq[tempip].insert(tempqq);
  }
  cin >> tempip;
  set<string> qqs = ipqq[tempip];
  if (qqs.empty())
    cout << "no qq" << endl;
  else {
    cout << tempip << " ==> [ ";
    for (set<string>::iterator i = qqs.begin(); i != qqs.end(); ++i) {
      cout << *i << " ";
    }
    cout << "]" << endl;
  }
  cin >> tempqq;
  set<string> ips = qqip[tempqq];
  if (ips.empty())
    cout << "no ip" << endl;
  else {
    cout << tempqq << " ==> [ ";
    for (set<string>::iterator i = ips.begin(); i != ips.end(); ++i) {
      cout << *i << " ";
    }
    cout << "]" << endl;
  }
}
