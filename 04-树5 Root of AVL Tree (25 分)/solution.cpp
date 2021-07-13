#include <algorithm>
#include <iostream>

typedef struct Node* Tree;
struct Node {
  Node(int _data) : data(_data), left(nullptr), right(nullptr), height(1) {}
  int data;
  Tree left;
  Tree right;
  int height;
};

int getHeight(Tree tree) {
  if (!tree) return 0;
  return tree->height;
}

// 左单旋
Tree SingleLeftRotation(Tree A) {
  Tree B = A->left;
  A->left = B->right;
  B->right = A;
  A->height = std::max(getHeight(A->left), getHeight(A->right)) + 1;
  B->height = std::max(getHeight(B->left), getHeight(B->right)) + 1;
  return B;
}

// 右单旋
Tree SingleRightRotation(Tree A) {
  Tree B = A->right;
  A->right = B->left;
  B->left = A;
  A->height = std::max(getHeight(A->left), getHeight(A->right)) + 1;
  B->height = std::max(getHeight(B->left), getHeight(B->right)) + 1;
  return B;
}

// 左右双旋
Tree LeftRightRotation(Tree A) {
  A->left = SingleRightRotation(A->left);
  return SingleLeftRotation(A);
}

// 右左双旋
Tree RightLeftRotation(Tree A) {
  A->right = SingleLeftRotation(A->right);
  return SingleRightRotation(A);
}

// 插入节点, 并调整高度
Tree InsertNode(Tree tree, int num) {
  if (!tree) return new Node(num);
  if (num < tree->data) {
    // 插到左边
    tree->left = InsertNode(tree->left, num);
    if (getHeight(tree->left) - getHeight(tree->right) == 2) {
      if (num < tree->left->data) {
        tree = SingleLeftRotation(tree); // 左单旋
      } else {
        tree = LeftRightRotation(tree);  // 左右双旋
      }
    }
  } else if (num > tree->data) {
    // 插到右边
    tree->right = InsertNode(tree->right, num);
    if (getHeight(tree->right) - getHeight(tree->left) == 2) {
      if (num > tree->right->data) {
        tree = SingleRightRotation(tree); // 右单旋
      } else {
        tree = RightLeftRotation(tree);   // 右左双旋
      }
    }
  }
  tree->height = std::max(getHeight(tree->left), getHeight(tree->right)) + 1;
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

void free(Tree tree) {
  if (!tree) return;
  free(tree->left);
  free(tree->right);
  delete tree;
}

int main() {
  int N;
  std::cin >> N;
  Tree tree = InputTree(N);
  std::cout << tree->data << std::endl;
  free(tree);

  return 0;
}
