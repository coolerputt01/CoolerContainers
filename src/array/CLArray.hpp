template <typename T, unsigned int N> 
struct CLArray {
  T items[N];
  bool isDynamic;
  unsigned int length;

  CLArray() = default;
  CLArray(std::initializer_list<T> list, bool dynamic = false)
      : isDynamic(dynamic) {
    length = std::min(list.size(), static_cast<size_t>(N));
    std::copy_n(list.begin(), length, items);
  }

  T at(const unsigned int &index) noexcept {
    if (index < N) {
      return items[index];
    } else {
      std::cerr << "Trying to access an invalid index in an CLArray of " << N
                << " size is seg fault lol.\n";
      return T{};
    }
  }

  void push_back(T data) noexcept {
    if (length < N) {
      items[length] = data;
      length += 1;

    } else {
      std::cerr << "Can't push back on filled CLArray.\n";
    }
  }

  void pop_back() noexcept {
    if (length > 0) {
      items[length - 1] = 0;
      length -= 1;
    } else {
      std::cerr << "Trying to pop from an empty CLArray huh?\n";
    }
  }

  void pop_backs(int count) noexcept {
    if (count > length)
      count = length;

    for (size_t i = 0; i < count; i++) {
      items[length - 1 - i] = 0;
    }

    length -= count;
  }

  
  void print() const {
    for (unsigned int i = 0; i < length; i++) {
      std::cout << items[i] << " ";
    }
    std::cout << std::endl;
  }
  const T& front() const noexcept {
    if(length <= 0)
        assert("Length of CLArray is 0");
    
    return items[0];
  }

  const T& back() const noexcept {
    if(length <= 0)
        assert("Length of CLArray is 0");
    
    return items[length-1];
  }

  bool isEmpty() const noexcept {
    return length > 0 ? false : true;
  }
};