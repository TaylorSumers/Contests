#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>
#include <set>

struct Sheep {
  size_t id;
  uint a;
};

struct Dog {
  size_t id;
  uint b;
};

size_t m, n;
std::vector<Sheep> sheeps;
std::set<Dog> dogs;

void SetFastIo() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
}

void Input() {
  std::cin >> m >> n;
  sheeps.reserve(m);

  for (size_t i = 0; i < m; i++) {
    Sheep sheep{i};
    std::cin >> sheep.a;
    sheeps.push_back(sheep);
  }
  for (size_t i = 0; i < n; i++) {
    Dog dog{i};
    std::cin >> dog.b;
    dogs.insert(dog);
  }
}

int main() {
  SetFastIo();
  Input();

  std::sort(sheeps.begin(), sheeps.end(), [](const Sheep& l_sheep, const Sheep& r_sheep) { return l_sheep.a < r_sheep.a; });
}