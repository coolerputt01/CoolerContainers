#include <initializer_list>
#include <algorithm>
#include <iostream>

template<typename T,unsigned int N>
struct Array {
    T items[N];


    Array() = default;
    Array(std::initializer_list<T> list){
        std::copy(std::begin(list),std::end(list),std::begin(items));
    }

    int at(unsigned int index){
        if (index < N)
            return items[index];
        else
            return -1;
            std::cerr<<"Trying to access an invalid index in an array of "<<N<<" size is seg fault lol.\n";
    }
};


int main(){
    Array<int,4> array = {1, 2, 3, 4};

    std::cout<<array.at(3);

    return 0;

}