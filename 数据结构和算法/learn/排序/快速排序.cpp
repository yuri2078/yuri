#include <vector>
#include <yuri.h>

yuri::Yuri init;

int quickSort_check(std::vector<int> &data, int start, int end) {
  init << "进行 " << start << " ---- " << end << " 的快速排序\n";
  init.outData();
  int key = data[start], val = end;
  while (start != end) {
    if (data[val] < key) {
      data[start] = data[val];
      val = ++start;
    } else {
      data[end] = data[val];
      val = --end;
    }
  }

  data[start] = key;
  init.outData();
  return start;
}

void quickSort(std::vector<int> &data, int start, int end) {
  if (start < end) {
    int k = quickSort_check(data, start, end);
    quickSort(data, start, k - 1);
    quickSort(data, k + 1, end);
  }
}

int main() {
  std::vector<int> &data = init.getData(true);
  quickSort(data, 0, data.size() - 1);
  return 0;
}