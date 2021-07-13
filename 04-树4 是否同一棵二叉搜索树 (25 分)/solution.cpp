#include <iostream>

typedef struct node* Tree;
struct node {
  node(int _data) : data(_data), left(nullptr), right(nullptr) {}
  int data;
  Tree left;
  Tree right;
};

Tree InsertNode(Tree tree, int num) {
  if (!tree) return new node(num);
  if (num < tree->data) {
    tree->left = InsertNode(tree->left, num);
  } else if (num > tree->data) {
    tree->right = InsertNode(tree->right, num);
  }
  return tree;
}

Tree InputTree(size_t N) {
  Tree tree = nullptr;
  for (size_t i = 0; i < N; ++i) {
    int num;
    std::cin >> num;
    tree = InsertNode(tree, num);
  }
  return tree;
}

bool Judge(Tree tree1, Tree tree2) {
  if (!tree1 && !tree2) return true;
  if (!tree1 || !tree2) return false;
  if (tree1->data != tree2->data) return false;
  return Judge(tree1->left, tree2->left) && Judge(tree1->right, tree2->right);
}

void free(Tree tree) {
  if (!tree) return;
  free(tree->left);
  free(tree->right);
  delete tree;
}

int main() {
  size_t N;
  std::cin >> N;
  while (N != 0) {
    size_t L;
    std::cin >> L;
    Tree old_tree = InputTree(N);
    for (size_t i = 0; i < L; ++i) {
      Tree new_tree = InputTree(N);
      if (Judge(old_tree, new_tree)) {
        std::cout << "Yes" << std::endl;
      } else {
        std::cout << "No" << std::endl;
      }
      free(new_tree);
    }
    free(old_tree);
    std::cin >> N;
  }

  return 0;
}
