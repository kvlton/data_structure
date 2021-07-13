#include <iostream>
#include <vector>

int main() {
  size_t K;
  std::cin >> K;
  if (K <= 0) {
    std::cout << 0 << std::endl;
    return 1;
  }
  std::vector<int> vNums(K);
  for (size_t i = 0; i < vNums.size(); ++i) {
    std::cin >> vNums[i];
  }

  int max_sum = 0, this_sum = 0;
  for (auto value : vNums) {
    this_sum += value;
    if (this_sum > max_sum) {
      max_sum = this_sum;
    }
    if (this_sum < 0) {
      this_sum = 0;
    }
  }
  std::cout << max_sum << std::endl;

  return 0;
}
