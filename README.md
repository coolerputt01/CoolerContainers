# Custom C++ Array

A simple fixed-size C++ array template with `push_back`, `pop_back`, and initializer-list support.  
Inspired by Coolerputt’s original version and improved for safety.

## Features

- Fixed-size array with compile-time size `N`
- Type-safe template (`T` can be any type)
- `push_back` / `pop_back` / `pop_backs`
- Safe initializer-list constructor
- Optional print support

## Example

```cpp
#include "array.hpp" // or your Array class file
#include <iostream>

int main() {
    Array<int, 4> arr = {1, 2};
    arr.push_back(9);
    arr.pop_backs(2);

    for (unsigned int i = 0; i < arr.length; i++) {
        std::cout << arr.items[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
