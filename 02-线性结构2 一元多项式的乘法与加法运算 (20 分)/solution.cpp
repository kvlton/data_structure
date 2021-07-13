#include <iostream>
#include <vector>

#define MAX_NUM 1000

std::vector<int> InputPoly() {
  size_t N;
  std::cin >> N;
  std::vector<int> poly(MAX_NUM + 1, 0);
  for (size_t i = 0; i < N; ++i) {
    int coef, exp;
    std::cin >> coef >> exp;
    poly[exp] = coef;
  }
  return poly;
}

void OutputPoly(const std::vector<int>& poly) {
  bool bFirst = true;
  for (int i = poly.size() - 1; i >= 0; --i) {
    if (poly[i] != 0) {
      if (bFirst == true) {
        bFirst = false;
      } else {
        std::cout << " ";
      }
      std::cout << poly[i] << " " << i;
    }
  }
  if (bFirst) {
    std::cout << 0 << " " << 0;
  }
  std::cout << std::endl;
}

std::vector<int> Add(const std::vector<int>& poly1,
                     const std::vector<int>& poly2) {
  std::vector<int> poly_add(MAX_NUM + 1);
  for (size_t i = 0; i < poly1.size(); ++i) {
    poly_add[i] = poly1[i] + poly2[i];
  }
  return poly_add;
}

std::vector<int> Multi(const std::vector<int>& poly1,
                       const std::vector<int>& poly2) {
  std::vector<int> poly_multi(2 * MAX_NUM + 1, 0);
  for (size_t i = 0; i < poly1.size(); ++i) {
    if (poly1[i] == 0) continue;
    for (size_t j = 0; j < poly2.size(); ++j) {
      poly_multi[i + j] += poly1[i] * poly2[j];
    }
  }
  return poly_multi;
}

int main() {
  std::vector<int> poly1 = InputPoly();
  std::vector<int> poly2 = InputPoly();

  OutputPoly(Multi(poly1, poly2));
  OutputPoly(Add(poly1, poly2));

  return 0;
}
