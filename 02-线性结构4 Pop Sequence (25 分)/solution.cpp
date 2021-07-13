#include <iostream>
#include <stack>
#include <vector>

bool isPopSequence(const std::vector<int>& vInput,
                   const std::vector<int>& vOutput, int stack_size) {
  std::stack<int> stack;
  auto iter_input = vInput.begin();
  auto iter_output = vOutput.begin();
  while (iter_input != vInput.end() && stack.size() < stack_size) {
    stack.push(*iter_input);
    ++iter_input;
    while (!stack.empty() && iter_output != vOutput.end() &&
           stack.top() == *iter_output) {
      stack.pop();
      ++iter_output;
    }
  }
  if (!stack.empty()) {
    return false;
  } else {
    return true;
  }
}

int main() {
  size_t M, N, K;
  std::cin >> M >> N >> K;
  std::vector<int> vInput(N);
  for (size_t i = 0; i < vInput.size(); ++i) {
    vInput[i] = i + 1;
  }
  for (size_t i = 0; i < K; ++i) {
    std::vector<int> vOutput(N);
    for (size_t j = 0; j < vOutput.size(); ++j) {
      std::cin >> vOutput[j];
    }
    if (isPopSequence(vInput, vOutput, M)) {
      std::cout << "YES" << std::endl;
    } else {
      std::cout << "NO" << std::endl;
    }
  }

  return 0;
}
