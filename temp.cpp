#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>

const uint32_t cEight = 8;
uint32_t n, a, b;
uint32_t cur = 0;
std::vector<uint32_t> x;

uint32_t nextRand24() {
  cur = cur * a + b;
  return cur >> 8;
}

uint32_t nextRand32() {
  uint32_t x, y;
  x = nextRand24();
  y = nextRand24();
  return (x << cEight) ^  y;
}

void SetFastIo() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
}

void Input() {
  std::cin >> n;
  std::cin >> a >> b;
}

void FillX() {
  for (size_t i = 0; i < n; i++) {
    x.push_back(nextRand32());
  }
}


int main() {
  SetFastIo();
  Input();
  FillX();

}
