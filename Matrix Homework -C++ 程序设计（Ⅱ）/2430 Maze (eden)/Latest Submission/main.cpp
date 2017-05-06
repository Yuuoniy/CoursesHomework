#include <iostream>
#include <queue>
#include <utility>
using std::cin;
using std::cout;
using std::endl;
using std::queue;
using std::pair;
using std::make_pair;
int main() {
  int n = 0, m = 0;
  cin >> n >> m;
  char map[n][m] = {0};
  int mark[n][m];
  int count = 0;
  int move[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
  queue<pair<int, int> > myque;
  pair<int, int> start, end;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> map[i][j];
      mark[i][j] = 0;
      if (map[i][j] == 'S') {
        start = make_pair(i, j);
        myque.push(start);
      }
      if (map[i][j] == 'E') {
        end = make_pair(i, j);
      }
    }
  }
  int flag = 1;
  mark[start.first][start.second] = 1;
  pair<int, int> head(100, 100);
  while (!myque.empty()) {
    pair<int, int> current(myque.front());
    myque.pop();
    if (current.first == head.first && current.second == head.second) {
      count++;
      flag = 1;
    }
    pair<int, int> temp(100, 100);
    for (int i = 0; i < 4; i++) {
      temp = make_pair(current.first + move[i][0], current.second + move[i][1]);
      if (temp.first == end.first && temp.second == end.second) {
        count++;
        cout << count << endl;
        return 0;
      }
      if (temp.first < n && temp.first >= 0 && temp.second < m &&
          temp.second >= 0) {
        if (!mark[temp.first][temp.second] &&
            map[temp.first][temp.second] == '.') {
          myque.push(temp);
          mark[temp.first][temp.second] = 1;
          if (flag) {
            head = make_pair(temp.first, temp.second);
            flag = 0;
          }
        }
      }
    }
  }
  cout << "-1" << endl;
  return 0;
}
