#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

std::map<char, int> map_;  // char weight

typedef struct Node* Tree;
struct Node {
  Node(int _weight) : weight(_weight), left(nullptr), right(nullptr) {}
  int weight;
  Tree left, right;
};

bool compare(const Tree& tree1, const Tree& tree2) {
  return tree1->weight > tree2->weight;
}

// 使用最小堆构造哈夫曼树
Tree Huffman(std::vector<Tree>& min_heap) {
  size_t size = min_heap.size();
  for (size_t i = 1; i < size; ++i) {
    Tree tree = new Node(-1);
      
    tree->left = min_heap.front();
    std::pop_heap(min_heap.begin(), min_heap.end(), compare);
    min_heap.pop_back();
    tree->right = min_heap.front();
    std::pop_heap(min_heap.begin(), min_heap.end(), compare);
    min_heap.pop_back();
      
    tree->weight = tree->left->weight + tree->right->weight;
    min_heap.push_back(tree);
    std::push_heap(min_heap.begin(), min_heap.end(), compare);
  }
  return min_heap.back();
}

// 递归计算二叉树的加权路径长度WPL
int WPL(Tree tree, int depth) {
  if (!tree) return 0;
  if (!tree->left && !tree->right) return depth * tree->weight;
  return WPL(tree->left, depth + 1) + WPL(tree->right, depth + 1);
}

Tree InputHuffman(size_t N) {
  Tree root = new Node(-1);
  for (size_t i = 0; i < N; ++i) {
    char ch;
    std::string str;
    std::cin >> ch >> str;

    Tree tree = root;
    for (size_t i = 0; i < str.size(); ++i) {
      int num = str[i] - '0';
      if (num == 0) {
        if (!tree->left) {
          tree->left = new Node(-1);
        }
        tree = tree->left;
      } else if (num == 1) {
        if (!tree->right) {
          tree->right = new Node(-1);
        }
        tree = tree->right;
      }
    }
    tree->weight = map_[ch];
  }
  return root;
}

bool isHuffman(Tree tree) {
  if (!tree) return true;
  if (!tree->left && !tree->right) return true;
  if (tree->weight != -1) return false;
  return isHuffman(tree->left) && isHuffman(tree->right);
}

int main() {
  size_t N;
  std::cin >> N;
  std::vector<Tree> min_heap;
  min_heap.reserve(N);
  for (size_t i = 0; i < N; ++i) {
    char ch;
    int weight;
    std::cin >> ch >> weight;
    map_[ch] = weight;
    min_heap.push_back(new Node(weight));
  }

  std::make_heap(min_heap.begin(), min_heap.end(), compare);
  Tree tree = Huffman(min_heap);
  int min_wpl = WPL(tree, 0);

  size_t M;
  std::cin >> M;
  for (size_t i = 0; i < M; ++i) {
    Tree tmp_tree = InputHuffman(N);
    if (!isHuffman(tmp_tree)) {
      std::cout << "No" << std::endl;
      continue;
    }
    if (WPL(tmp_tree, 0) == min_wpl) {
      std::cout << "Yes" << std::endl;
    } else {
      std::cout << "No" << std::endl;
    }
  }

  return 0;
}
