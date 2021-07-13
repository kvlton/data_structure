#include <algorithm>
#include <iostream>
#include <vector>

int index_inorder;
std::vector<int> Inorder;

// 完全二叉树的中序遍历
void InorderTraversal(std::vector<int>& CBST, int root) {
  if(root >= CBST.size()) return;
  InorderTraversal(CBST, 2*root);
  CBST[root] = Inorder[index_inorder++];
  InorderTraversal(CBST, 2*root+1);
}

int main() {
  size_t N;
  std::cin >> N;
  Inorder.resize(N);
  for (size_t i = 0; i < Inorder.size(); ++i) {
    std::cin >> Inorder[i];
  }
  // 二叉搜索树的中序遍历是有序的
  std::sort(Inorder.begin(), Inorder.end());

  index_inorder = 0;
  std::vector<int> CBST(N+1);
  InorderTraversal(CBST, 1);

  if (CBST.size() >= 2) {
    std::cout << CBST[1];
    for (size_t i = 2; i < CBST.size(); ++i) {
      std::cout << " " << CBST[i];
    }
    std::cout << std::endl;
  }
    
  return 0;
}
