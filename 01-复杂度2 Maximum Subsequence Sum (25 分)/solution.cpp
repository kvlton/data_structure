#include <iostream>
#include <vector>

int main() {
  size_t K;
  std::cin >> K;
  if (K <= 0) {
    std::cout << "Please input a positive interger." << std::endl;
    return 1;
  }
  std::vector<int> vNums(K);
  for (size_t i = 0; i < vNums.size(); ++i) {
    std::cin >> vNums[i];
  }

  int max_sum = -1, this_sum = 0;
  int start_index = -1, end_index = -1;
  int tmp_start_index = 0;
  for (size_t i = 0; i < vNums.size(); ++i) {
    this_sum += vNums[i];
    if (this_sum > max_sum) {
      max_sum = this_sum;
      start_index = tmp_start_index;
      end_index = i;
    }
    if (this_sum < 0) {
      this_sum = 0;
      tmp_start_index = i+1;
    }
  }

  if (max_sum == -1) {
    std::cout << 0 << " " << vNums.front() << " " << vNums.back() << std::endl;
  } else {
    std::cout << max_sum << " " << vNums[start_index] << " " << vNums[end_index]
              << std::endl;
  }

  return 0;
}
