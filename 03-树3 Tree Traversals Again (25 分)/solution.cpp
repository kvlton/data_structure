#include <iostream>
#include <stack>
#include <string>
#include <vector>

void Input(std::vector<int>& Preorder, std::vector<int>& Inorder) {
  size_t N;
  std::cin >> N;
  Preorder.reserve(N);
  Inorder.reserve(N);
  std::stack<int> stack;
  for (size_t i = 0; i < 2 * N; ++i) {
    std::string str;
    std::cin >> str;
    if (str == "Push") {
      int num;
      std::cin >> num;
      Preorder.push_back(num);
      stack.push(num);
    }
    if (str == "Pop") {
      Inorder.push_back(stack.top());
      stack.pop();
    }
  }
}

// 通过先序和中序,得到后序
void getPostorder(const std::vector<int>& Preorder, int pre_start,
                  const std::vector<int>& Inorder, int in_start,
                  std::vector<int>& Postorder, int post_start, int length) {
  if (length <= 0) return;
  if (length == 1) {
    Postorder[post_start] = Preorder[pre_start];
    return;
  }

  int root = Preorder[pre_start];
  int root_index_inorder;
  for (int i = in_start; i < in_start + length; ++i) {
    if (Inorder[i] == root) {
      root_index_inorder = i;
      break;
    }
  }

  int left_length = root_index_inorder - in_start;
  int right_length = length - left_length - 1;

  Postorder[post_start + length - 1] = root;
  getPostorder(Preorder, pre_start + 1, Inorder, in_start, Postorder,
               post_start, left_length);
  getPostorder(Preorder, pre_start + left_length + 1, Inorder,
               in_start + left_length + 1, Postorder, post_start + left_length,
               right_length);
}

void Output(const std::vector<int>& order) {
  for (size_t i = 0; i < order.size() - 1; ++i) {
    std::cout << order[i] << " ";
  }
  std::cout << order.back() << std::endl;
}

int main() {
  std::vector<int> Preorder, Inorder;
  Input(Preorder, Inorder);

  std::vector<int> Postorder(Preorder.size());
  getPostorder(Preorder, 0, Inorder, 0, Postorder, 0, Preorder.size());

  Output(Postorder);

  return 0;
}
