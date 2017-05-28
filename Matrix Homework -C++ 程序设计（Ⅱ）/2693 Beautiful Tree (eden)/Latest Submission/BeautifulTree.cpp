 #include "BeautifulTree.hpp"
using namespace HFM;

HuffmanCode::HuffmanCode(const string& str) : mode(1), length(0) {
  map<char, int> m;
  for (int i = 0; i < str.size(); ++i) {
    if (str[i] != ' ') {
      m[str[i]]++;
      mess2 += str[i];
    }
  }
  nodeNum = m.size();
  int i = 0;
  for (map<char, int>::iterator iter = m.begin(); iter != m.end(); ++iter) {
    nodes[i].data = iter->first;
    nodes[i].weight = iter->second;
    i++;
  }
  BuildTree();
  SetCode('l', root);
}

HuffmanCode::HuffmanCode(int w[], int n) : nodeNum(n), mode(0), length(0) {
  for (int i = 0; i < n; ++i) {
    nodes[i].weight = w[i];
  }
  BuildTree();
  SetCode('l', root);
}

void HuffmanCode::DisplayCode() {
  if (mode == 1) {
    std::vector<Node> v;
    for (int i = 0; i < nodeNum; ++i) {
      v.push_back(nodes[i]);
    }
    for (int i = 0; i < nodeNum; ++i) {
      int min = v[0].weight, min2 = v[0].data, index = 0;
      for (int j = 0; j < v.size(); ++j) {
        if (v[j].weight < min || (v[j].weight == min && v[j].data < min2)) {
          min = v[j].weight;
          min2 = v[j].data;
          index = j;
        }
      }
      cout << "(" << v[index].data << ") Weight = " << v[index].weight
           << "; Code = " << v[index].code << endl;
      v.erase(v.begin() + index);
    }
    cout << "Huffman's codeLength = " << SetLength() << endl;
    cout << "Origin Text: " << mess2 << endl;
    cout << "Huffman's Code: " << encode() << endl;
  } else {
    std::vector<Node> v;
    for (int i = 0; i < nodeNum; ++i) {
      v.push_back(nodes[i]);
    }
    for (int i = 0; i < nodeNum; ++i) {
      int min = v[0].weight, index = 0;
      for (int j = 0; j < v.size(); ++j) {
        if (v[j].weight < min) {
          min = v[j].weight;
          index = j;
        }
      }
      cout << "Weight = " << v[index].weight << "; Code = " << v[index].code
           << endl;
      v.erase(v.begin() + index);
    }
    cout << "Huffman's codeLength = " << SetLength() << endl;
  }
}
string HuffmanCode::encode() {
  string str;
  for (int i = 0; i < mess2.size(); ++i) {
    for (int j = 0; j < nodeNum; ++j) {
      if (mess2[i] == nodes[j].data) {
        str += nodes[j].code;
        break;
      }
    }
  }

  return str;
}
void HuffmanCode::BuildTree() {
  for (int i = 0; i < nodeNum; ++i) {
    nodes[i].parent = nodes[i].left = nodes[i].right = -1;
  }
  int p1 = 0, p2 = 0, i = 0;
  for (i = nodeNum; i < nodeNum * 2 - 1; ++i) {
    select(p1, p2, i);
    nodes[p1].parent = nodes[p2].parent = i;
    nodes[i].left = p1;
    nodes[i].right = p2;
    nodes[i].parent = -1;
    nodes[i].weight = nodes[p1].weight + nodes[p2].weight;
  }
  root = i - 1;
}
void HuffmanCode::select(int& p1, int& p2, int i) {
  int min1 = MAX;
  int min2 = MAX;
  p1 = p2 = 0;
  for (int j = 0; j < i; ++j) {
    if (nodes[j].parent == -1) {
      if (nodes[j].weight < min1) {
        min2 = min1;
        p2 = p1;
        min1 = nodes[j].weight;
        p1 = j;
      } else if (nodes[j].weight < min2) {
        min2 = nodes[j].weight;
        p2 = j;
      }
    }
  }
}
void HuffmanCode::sort() {
  // if (mode == 0) {
  //   n
  // }
}
int HuffmanCode::SetLength() {
  if (mode == 1)
    length = encode().size();
  else {
    for (int i = 0; i < nodeNum; ++i)
      length += (nodes[i].weight * (nodes[i].code.size()));
  }
  return length;
}
void HuffmanCode::SetCode(char flag, int node) {
  if (node == -1) return;
  if (flag == 'l' && node != root)
    nodes[node].code = nodes[nodes[node].parent].code + "1";
  else if (flag == 'r' && node != root)
    nodes[node].code = nodes[nodes[node].parent].code + "0";
  SetCode('l', nodes[node].left);
  SetCode('r', nodes[node].right);
}
