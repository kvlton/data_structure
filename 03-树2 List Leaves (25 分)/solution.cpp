#include <iostream>
#include <queue>
#include <vector>

void InputTree(std::vector<std::pair<int, int>>& tree, int& root) {
  size_t N;
  std::cin >> N;

  tree.reserve(N);
  for (size_t i = 0; i < N; ++i) {
    char left, right;
    std::cin >> left >> right;
    int nleft = left == '-' ? -1 : left - '0';
    int nright = right == '-' ? -1 : right - '0';
    tree.emplace_back(nleft, nright);
  }

  std::vector<bool> vIsChild(N, false);
  for (int i = 0; i < N; ++i) {
    if (tree[i].first != -1) {
      vIsChild[tree[i].first] = true;
    }
    if (tree[i].second != -1) {
      vIsChild[tree[i].second] = true;
    }
  }
  for (int i = 0; i < N; ++i) {
    if (vIsChild[i] == false) {
      root = i;
      break;
    }
  }
}

// 层序遍历
void LevelorderTraversal(const std::vector<std::pair<int, int>>& tree,
                         int root) {
  if (tree.empty() || root == -1) {
    return;
  }
  std::queue<int> qIndex;
  qIndex.push(root);
  bool isFirst = true;
  while (!qIndex.empty()) {
    int index = qIndex.front();
    qIndex.pop();

    if (tree[index].first != -1) {
      qIndex.push(tree[index].first);
    }
    if (tree[index].second != -1) {
      qIndex.push(tree[index].second);
    }

    // 访问叶子节点
    if (tree[index].first == -1 && tree[index].second == -1) {
      if (isFirst) {
        std::cout << index;
        isFirst = false;
      } else {
        std::cout << " " << index;
      }
    }
  }
  std::cout << std::endl;
}

int main() {
  int root;
  std::vector<std::pair<int, int>> tree;
  InputTree(tree, root);

  LevelorderTraversal(tree, root);

  return 0;
}
