/* Custom C++ array type by Coolerputt  */

#include <algorithm>
#include <initializer_list>
#include <iostream>

template <typename T, unsigned int N> struct Array {
  T items[N];
  bool isDynamic;
  unsigned int length;

  Array() = default;
  Array(std::initializer_list<T> list, bool dynamic = false)
      : isDynamic(dynamic) {
    // NOTE: Always limit the copy to N elements to avoid undefined behaviour
    length = std::min(list.size(), static_cast<size_t>(N));
    std::copy_n(list.begin(), length, items);
  }

  int at(const unsigned int &index) noexcept {
    if (index < N) {
      return items[index];
    } else {
      std::cerr << "Trying to access an invalid index in an array of " << N
                << " size is seg fault lol.\n";
      return T{}; // NOTE: Return the default value of T instead
    }
  }

  void push_back(T data) noexcept {
    if (length < N) {
      items[length] = data;
      length += 1;

    } else {
      std::cerr << "Can't push back on filled array.\n";
    }
  }

  void pop_back() noexcept {
    if (length > 0) {
      items[length - 1] =
          0; // NOTE: Use length and not N, N is the fixed buffer and length is
             // the actuall buffer size with the elements
      length -= 1;
    } else {
      std::cerr << "Trying to pop from an empty array huh?\n";
    }
  }

  void pop_backs(int count) noexcept {
    if (count > length) // NOTE: Use length and not N, N is the fixed buffer and
                        // length is the actuall buffer size with the elements
      count = length;   // prevent underflow

    for (size_t i = 0; i < count; i++) {
      items[length - 1 - i] = 0; // remove from the last added element
    }

    length -= count;
  }

  // Added a simple print method
  void print() const {
    for (unsigned int i = 0; i < length; i++) {
      std::cout << items[i] << " ";
    }
    std::cout << std::endl;
  }
};

int main() {
  Array<int, 4> array = {1, 2};

  int g = 9;
  array.push_back(g);
  // array.pop_backs(6);
  array.print();
  std::cout << array.length << std::endl << std::flush;

  return 0;
}
