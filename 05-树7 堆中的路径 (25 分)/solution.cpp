#include <algorithm>
#include <iostream>
#include <vector>

void OutputTraj(const std::vector<int>& heap, int index) {
  while (index != 0) {
    std::cout << heap[index] << " ";
    index = (index + 1) / 2 - 1;
  }
  std::cout << heap[index] << std::endl;
}

int main() {
  size_t N, M;
  std::cin >> N >> M;

  std::vector<int> heap;
  heap.reserve(N);
  for (size_t i = 0; i < N; ++i) {
    int data;
    std::cin >> data;
    heap.push_back(data);
    std::push_heap(heap.begin(), heap.end(), std::greater<int>());
  }

  for (size_t i = 0; i < M; ++i) {
    int index;
    std::cin >> index;
    OutputTraj(heap, index-1);
  }

  return 0;
}

