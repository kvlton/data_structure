#include <algorithm>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <vector>

#define MAX_SIZE 100001

int main() {
  int first_address;
  size_t N, K;
  std::cin >> first_address >> N >> K;

  std::vector<int> vData(MAX_SIZE);
  std::vector<int> vNext(MAX_SIZE);
  for (size_t i = 0; i < N; ++i) {
    int address, data, next;
    std::cin >> address >> data >> next;
    vData[address] = data;
    vNext[address] = next;
  }

  std::vector<int> vIndex;
  vIndex.reserve(MAX_SIZE);
  int next_address = first_address;
  while (next_address != -1) {
    vIndex.push_back(next_address);
    next_address = vNext[next_address];
  }

  int time = vIndex.size() / K;
  auto iter = vIndex.begin();
  for (size_t i = 0; i < time; ++i) {
    auto next_iter = iter + K;
    std::reverse(iter, next_iter);
    iter = next_iter;
  }

  for (auto iter = vIndex.begin(); iter != vIndex.end(); ++iter) {
    printf("%05d %d ", *iter, vData[*iter]);
    auto next_iter = std::next(iter);
    if (next_iter == vIndex.end()) {
      printf("-1\n");
    } else {
      printf("%05d\n", *next_iter);
    }
  }
}
