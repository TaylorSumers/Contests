#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>
#include <set>

struct Sheep {
  uint id;
  uint a;
};

struct Dog {
  uint id;
  uint b;

  bool operator<(const Dog& other) const {
    return id < other.id;
  }
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

  for (uint i = 0; i < m; i++) {
    Sheep sheep{i};
    std::cin >> sheep.a;
    sheeps.push_back(sheep);
  }
  for (uint i = 0; i < n; i++) {
    Dog dog{i};
    std::cin >> dog.b;
    dogs.insert(dog);
  }
}

bool FindDogs(uint a, uint& b_j, uint& b_k) {

}

int main() {
  SetFastIo();
  Input();

  std::sort(sheeps.begin(), sheeps.end(), [](const Sheep& l_sheep, const Sheep& r_sheep) { return l_sheep.a < r_sheep.a; });
  uint count = 0;
  std::vector<std::vector<uint>> res;
  for (Sheep sheep : sheeps) {
    uint b_j, b_k;
    if (FindDogs(sheep.a, b_j, b_k)) {
      count++;
      res.push_back(std::vector{sheep.id, b_j, b_k});
    }
  }

  std::cout << count << '\n';
  for (std::vector el : res) {
    std::cout << el[0] << ' ' << el[1] << ' ' << el[2] << '\n';
  }
}