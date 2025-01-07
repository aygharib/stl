#include <iostream>

namespace aygharib {
template <class DataType>
class ArrayDynamicSize {
public:
    ~ArrayDynamicSize(); // destructor
    ArrayDynamicSize(ArrayDynamicSize const& other); // copy constructor
    ArrayDynamicSize& operator=(ArrayDynamicSize const& other); // copy assignment operator
    ArrayDynamicSize(ArrayDynamicSize const&& other); // move constructor
    ArrayDynamicSize& operator=(ArrayDynamicSize const&& other); // move assignment operator

    int get(int i);
    void set(int i, int n);
    void pushback(int n);
    int popback();
    void resize();
    int getSize();
    int getCapacity();

private:
    using Pointer = DataType*;

    int _count{0};
    int _capacity{1};
    Pointer _data{new DataType[_capacity]};
};

template <class DataType>
ArrayDynamicSize<DataType>::~ArrayDynamicSize() {
    delete[] _data;
    _data = nullptr;
}

template <class DataType>
ArrayDynamicSize<DataType>::ArrayDynamicSize(ArrayDynamicSize const& other) {

}

template <class DataType>
ArrayDynamicSize<DataType>& ArrayDynamicSize<DataType>::operator=(ArrayDynamicSize<DataType> const& other) {

}

template <class DataType>
ArrayDynamicSize<DataType>::ArrayDynamicSize(ArrayDynamicSize const&& other) {

}

template <class DataType>
ArrayDynamicSize<DataType>& ArrayDynamicSize<DataType>::operator=(ArrayDynamicSize<DataType> const&& other) {

}

template <class DataType>
int ArrayDynamicSize<DataType>::get(int i) {
    return _data[i];
}

template <class DataType>
void ArrayDynamicSize<DataType>::set(int i, int n) {
    _data[i] = n;
}

template <class DataType>
void ArrayDynamicSize<DataType>::pushback(int n) {
    if (_count == _capacity) {
        resize();
    }

    _data[_count] = n;
    _count++;
}

template <class DataType>
int ArrayDynamicSize<DataType>::popback() {
    _count--;
    return _data[_count];
}

template <class DataType>
void ArrayDynamicSize<DataType>::resize() {
    int* newData = new int[_capacity*2];
    for (int i = 0; i < _capacity; i++) {
        newData[i] = _data[i];
    }
    _capacity = _capacity * 2;
    delete[] _data;
    _data = newData;
}

template <class DataType>
int ArrayDynamicSize<DataType>::getSize() {
    return _count;
}

template <class DataType>
int ArrayDynamicSize<DataType>::getCapacity() {
    return _capacity;
}
}

int main() {
    auto dynamic_array = aygharib::ArrayDynamicSize<int>{};
    std::cout << dynamic_array.get(0) << '\n';

    auto dyn_array_2 = dynamic_array;
}
