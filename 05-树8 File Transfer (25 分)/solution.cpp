#include <iostream>
#include <iostream>
#include <vector>

// 寻找集合
int Find(std::vector<int>& set, int value) {
  if (set[value] < 0) {
      return value;
  } else {
      return set[value] = Find(set, set[value]); // 路径压缩
  }
}

// 集合归并
void Union(std::vector<int>& set, int value1, int value2) {
  int root1 = Find(set, value1);
  int root2 = Find(set, value2);
  if (root1 != root2) {
    if (set[root1] < set[root2]) {
      set[root1] = set[root1] + set[root2];
      set[root2] = root1;
    } else {
      set[root2] = set[root1] + set[root2];
      set[root1] = root2;
    }
  }
}

// 是否连通
bool Check(std::vector<int>& set, int value1, int value2) {
  int root1 = Find(set, value1);
  int root2 = Find(set, value2);
  return root1 == root2;
}

// 集合数量
int Count(const std::vector<int>& set) {
  int count = 0;
  for (size_t i = 0; i < set.size(); ++i) {
    if (set[i] < 0) ++count;
  }
  return count;
}

int main() {
  size_t N;
  std::cin >> N;
  std::vector<int> set(N, -1);  // 负数表示根节点, 绝对值表示数量

  char ch;
  std::cin >> ch;
  while (ch != 'S') {
    int num1, num2;
    std::cin >> num1 >> num2;
    if (ch == 'I') {
      Union(set, num1 - 1, num2 - 1);
    } else if (ch == 'C') {
      if (Check(set, num1 - 1, num2 - 1)) {
        std::cout << "yes" << std::endl;
      } else {
        std::cout << "no" << std::endl;
      }
    }
    std::cin >> ch;
  }

  int count = Count(set);
  if (count == 1) {
    std::cout << "The network is connected." << std::endl;
  } else {
    std::cout << "There are " << count << " components." << std::endl;
  }

  return 0;
}
