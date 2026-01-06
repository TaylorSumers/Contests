#include <algorithm>
#include <iostream>
#include <vector>
#include <cstdint>

struct Test {
  size_t id;
  uint a;
  uint b;
};

size_t n;
std::vector<Test> tests;

void SetFastIo() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
}

void Input() {
  std::cin >> n;
  tests.resize(n);
  uint temp;
  for (size_t i = 0; i < n; i++) {
    std::cin >> temp;
    tests[i].id = i + 1;
    tests[i].a = temp;
  }
  for (size_t i = 0; i < n; i++) {
    std::cin >> temp;
    tests[i].b = temp;
  }
}

int main() {
  SetFastIo();
  Input();


  std::vector<Test> group_1;
  std::vector<Test> group_2;
  for (Test test : tests) {
    test.a <= test.b ? group_1.push_back(test) : group_2.push_back(test);
  }
  std::sort(group_1.begin(), group_1.end(), [](Test t1, Test t2) { return t1.a < t2.a; }); // asc
  std::sort(group_2.begin(), group_2.end(), [](Test t1, Test t2) { return t1.b > t2.b; }); // desc

  std::vector<size_t> permutation;
  permutation.reserve(n);
  uint64_t t1 = 0;
  uint64_t t2 = 0;
  for (size_t i = 0; i < group_1.size(); i++) {
    t1 += group_1[i].a;
    t2 = std::max(t1, t2) + group_1[i].b;
    permutation.push_back(group_1[i].id);
  }
  for (size_t i = 0; i < group_2.size(); i++) {
    t1 += group_2[i].a;
    t2 = std::max(t1, t2) + group_2[i].b;
    permutation.push_back(group_2[i].id);
  }

  std::cout << t2 << '\n';
  for (size_t id : permutation) {
    std::cout << id << ' ';
  }
  std::cout << '\n';
  for (size_t id : permutation) {
    std::cout << id << ' ';
  }
}