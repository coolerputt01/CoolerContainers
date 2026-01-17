/* Custom C++ array type by Coolerputt  */

#include <initializer_list>
#include <algorithm>
#include <iostream>

template<typename T,unsigned int N>
struct Array {
    T items[N];
    bool isDynamic;
    unsigned int length;


    Array() = default;
    Array(std::initializer_list<T> list,bool dynamic = false) : isDynamic(dynamic){
        length = list.size();
        std::copy(std::begin(list),std::end(list),std::begin(items));
    }

    int at(const unsigned int& index) noexcept {
        if (index < N){
            return items[index];
        }
        else {
            std::cerr<<"Trying to access an invalid index in an array of "<<N<<" size is seg fault lol.\n";
            return -1;
        }
    }
    
    void push_back(T data) noexcept {
        if(length < N ){
            items[length] = data;
            length += 1;
        
        }else {
            std::cerr<<"Can't push back on filled array.\n";
        }
    }

    void pop_back() noexcept {
        if(length > 0){
            items[N-1] = 0;
            length -= 1;
        }else {
            std::cerr<<"Trying to pop from an empty array huh?\n";
        }
    }

    void pop_backs(int count) noexcept {
        for(size_t i = 0;i < count;i++){
            items[N-(i+1)] = 0;
            length -= 1;
        }
    }

};


int main(){
    Array<int,4> array = {1, 2};


    int g = 9;
    array.push_back(g);
    array.pop_backs(6);
    std::cout<<array.length<<std::endl<<std::flush;

    return 0;

}