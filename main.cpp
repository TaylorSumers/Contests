#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>

uint n;
std::vector<int> a;

void SetFastIo() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
}

void Input() {
  std::cin >> n;
  a.reserve(n);
  int ai;
  for (int i = 0; i < n; i++) {
    std::cin >> ai;
    a.push_back(ai);
  }
}

std::vector<int> Merge(const std::vector<int>& l,
                       const std::vector<int>& r) {
  std::vector<int> res;
  size_t l_i = 0, r_i = 0;
  while (l_i < l.size() && r_i < r.size()) {
    if (l[l_i] > r[r_i]) {
      res.push_back(r[r_i]);
      r_i++;
    } else {
      res.push_back(l[l_i]);
      l_i++;
    }
  }

  while (l_i < l.size()) {
    res.push_back(l[l_i]);
    l_i++;
  }
  while (r_i < r.size()) {
    res.push_back(r[r_i]);
    r_i++;
  }

  return res;
}

std::vector<int> MergeSort(const std::vector<int>& arr) {
  uint arr_size = arr.size();
  std::vector l(arr.begin(), arr.begin() + arr_size / 2);
  std::vector r(arr.begin() + arr_size / 2, arr.end());
  if (l.size() <= 1 && r.size() <= 1) {
    return Merge(l, r);
  }
  MergeSort(l);
  MergeSort(r);
  return Merge(l, r);
}

int main() {
  SetFastIo();
  Input();
  MergeSort(a);
}