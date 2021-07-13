#include <iostream>
#include <vector>

struct Node {
  char data;
  int left;
  int right;
};

void InputTree(std::vector<Node>& tree, int& root) {
  int N;
  std::cin >> N;

  tree.reserve(N);
  for (int i = 0; i < N; ++i) {
    char data, left, right;
    std::cin >> data >> left >> right;
    int nleft = left == '-' ? -1 : left - '0';
    int nright = right == '-' ? -1 : right - '0';
    tree.push_back(Node{data, nleft, nright});
  }

  std::vector<bool> vIsChild(N, false);
  for (int i = 0; i < N; ++i) {
    if (tree[i].left != -1) {
      vIsChild[tree[i].left] = true;
    }
    if (tree[i].right != -1) {
      vIsChild[tree[i].right] = true;
    }
  }
  for (int i = 0; i < N; ++i) {
    if (vIsChild[i] == false) {
      root = i;
      break;
    }
  }
}

bool Isomorphic(const std::vector<Node>& tree1, int root1,
                const std::vector<Node>& tree2, int root2) {
  if (root1 == -1 && root2 == -1) {
    return true;
  }
  if (root1 == -1 || root2 == -1) {
    return false;
  }
  if (tree1[root1].data != tree2[root2].data) {
    return false;
  }
  if (Isomorphic(tree1, tree1[root1].left, tree2, tree2[root2].left) &&
      Isomorphic(tree1, tree1[root1].right, tree2, tree2[root2].right)) {
    return true;
  }
  if (Isomorphic(tree1, tree1[root1].left, tree2, tree2[root2].right) &&
      Isomorphic(tree1, tree1[root1].right, tree2, tree2[root2].left)) {
    return true;
  }
  return false;
}

int main() {
  std::vector<Node> tree1, tree2;
  int root1, root2;
  InputTree(tree1, root1);
  InputTree(tree2, root2);
    
  if(tree1.empty() && tree2.empty()) {
    std::cout << "Yes" << std::endl;
  }else if (tree1.size() != tree2.size()) {
    std::cout << "No" << std::endl;
  }else if (Isomorphic(tree1, root1, tree2, root2)) {
    std::cout << "Yes" << std::endl;
  } else {
    std::cout << "No" << std::endl;
  }

  return 0;
}
