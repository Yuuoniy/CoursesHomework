 #ifndef BT
#define BT
#define MAX 1000;
#include <iostream>
#include <map>
#include <string>
#include <vector>
using std::string;
using std::cout;
using std::endl;
using namespace std;
namespace HFM {
struct Node {
  char data;
  int weight;
  int left, right, parent;
  string code;
  int depth;
  Node(int _weight = 0, int _left = -1, int _right = -1, int _parent = -1)
      : weight(_weight),
        left(_left),
        right(_right),
        parent(_parent),
        code(""),
        data('\0') {}
};

class HuffmanCode {
 public:
  explicit HuffmanCode(const string& str);
  HuffmanCode(int w[], int n);
  void DisplayCode();
  string encode();
  void BuildTree();
  void SetCode(char flag, int node);
  void sort();
  int SetLength();
  void select(int& p1, int& p2, int i);

 private:
  Node nodes[70];
  string mess2;
  map<char, int> m;
  int nodeNum;
  int length;  //哈夫曼编码的长度
  int mode;
  int root;
};
}
#endif
