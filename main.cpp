#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

struct Sheep {
  uint id;
  uint a;
};

struct Dog {
  uint id;
  uint b;

  bool operator<(const Dog& other) const {
    return b != other.b ? b < other.b : id < other.id;
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
  if (dogs.size() < 2) {
    return false;
  }

  Dog temp{0, a};
  auto upper = dogs.lower_bound(temp);
  auto lower = std::prev(upper);
  if (upper == dogs.end() || upper == dogs.begin()) {
    return false;
  }
  if (upper != dogs.end() && upper->b == a) {
    ++upper;
  }
  if (lower->b >= a) {
    return false;
  }

  b_j = lower->id;
  b_k = upper->id;

  dogs.erase(upper);
  dogs.erase(lower);

  return true;
}

int main() {
  SetFastIo();
  Input();

  std::sort(sheeps.begin(), sheeps.end(), [](const Sheep& l_sheep, const Sheep& r_sheep) { return l_sheep.a < r_sheep.a; });
  uint count = 0;
  std::vector<std::vector<uint>> res;
  for (Sheep sheep: sheeps) {
    uint b_j;
    uint b_k;
    if (FindDogs(sheep.a, b_j, b_k)) {
      count++;
      res.push_back(std::vector{sheep.id + 1, b_j + 1, b_k + 1});
    }
  }

  std::cout << count << '\n';
  for (std::vector el: res) {
    std::cout << el[0] << ' ' << el[1] << ' ' << el[2] << '\n';
  }
}