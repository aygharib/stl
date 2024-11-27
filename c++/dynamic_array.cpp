#include <iostream>

template <class DataType>
class DynamicArray {
public:
    DynamicArray()
        : _capacity{1}
        , _data{new DataType[_capacity]}
        , _count{0}
    {}

    int get(int i) {
        return _data[i];
    }

    void set(int i, int n) {
        _data[i] = n;
    }

    void pushback(int n) {
        if (_count == _capacity) {
            resize();
        }

        _data[_count] = n;
        _count++;
    }

    int popback() {
        _count--;
        return _data[_count];
    }

    void resize() {
        int* newData = new int[_capacity*2];
        for (int i = 0; i < _capacity; i++) {
            newData[i] = _data[i];
        }
        _capacity = _capacity * 2;
        delete[] _data;
        _data = newData;
    }

    int getSize() {
        return _count;
    }

    int getCapacity() {
        return _capacity;
    }

private:
    using Pointer = DataType*;

    int _capacity;
    Pointer _data;
    int _count;
};

int main() {
    auto dynamic_array = DynamicArray<int>{};
    std::cout << dynamic_array.get(0) << '\n';
}
