#include <initializer_list>
#include <iostream>
#include <cstddef>
#include <iterator>
#include <stdexcept>

template <class DataType, std::size_t Size>
class Array {
public:
    class iterator {
    public:
        using Category = std::forward_iterator_tag;
        using Distance = std::ptrdiff_t;

        using Pointer = DataType*;
        using Reference = DataType&;

        iterator(Pointer data)
            : data{data}
        {}

        Reference operator*() {
            return *data;
        }

        Pointer operator->() {
            return data;
        }

        // ++it
        iterator operator++() {
            ++data;
            return *this;
        }

        // it++
        iterator operator++(DataType) {
            ++data;
            return *this;
        }

        // friend bool operator

        // l-value comparisons
        // friend bool operator==(iterator& a, iterator& b) {
        //     return a.data == b.data;
        // }

        // // r-value comparisons
        // friend bool operator==(iterator&& a, iterator&& b) {
        //     return a.data == b.data;
        // }

        // templated version of L and R value combinations
        template<typename L, typename R>
        friend bool operator==(const L& a, const R& b) {
            return a.data == b.data;
        }

        template<typename L, typename R>
        friend bool operator!=(const L& a, const R& b) {
            return a.data != b.data;
        }

    private:
        Pointer data;
    };

    Array(std::initializer_list<DataType> init_list) {
        std::copy(init_list.begin(), init_list.end(), _data);
    }

    [[nodiscard]] constexpr DataType& at(std::size_t index) {
        std::cout << _size << '\n';
        if (index < 0 || index >= _size) {
            throw std::out_of_range("at() attempted to index out of range");
        }

        return _data[index];
    }

    [[nodiscard]] constexpr DataType& operator[](std::size_t index) {
        return _data[index];
    }

    [[nodiscard]] constexpr DataType& front() {
        return _data[0];
    }

    [[nodiscard]] constexpr DataType& back() {
        return _data[_size - 1];
    }

    [[nodiscard]] constexpr DataType* data() noexcept {
        return &_data[0];
    }

    /// Iterators

    iterator begin() {
        return iterator{&_data[0]};
    }

    iterator end() {
        return iterator{&_data[_size]};
    }

    // Capacity

    bool empty() {
        return _size == 0;
    }

    std::size_t size() {
        return _size;
    }

    std::size_t max_size() {
        return _size;
    }

    // Operations

    void fill(DataType value) {
        for (std::size_t i = 0; i < _size; i++) {
            _data[i] = value;
        }
    }

    void swap(Array& other) {
        for (std::size_t i = 0; i < _size; i++) {
            auto temp = _data[i];
            _data[i] = other[i];
            other[i] = temp;
        }
    }

private:
    DataType _data[Size] = {};
    std::size_t _size = Size;
};

int main() {
    auto array = Array<int, 5>{};
    array[0] = 10;
    array[1] = 9;

    std::cout << array.at(0) << '\n';
    std::cout << array[0] << '\n';
    std::cout << array.front() << '\n';
    std::cout << array.back() << '\n';
    std::cout << array.data() << '\n';
    std::cout << *(array.data()) << '\n';
    std::cout << *(array.data() + 1) << '\n';

    auto it = array.begin();
    std::cout << *it << '\n';
    it++;
    std::cout << *it << '\n';
    it = array.end();
    std::cout << *it << '\n';

    auto it2 = array.begin();
    auto equal = it == it2;
    auto equal2 = array.begin() == array.end();
    auto equal3 = it == array.begin();

    for (auto v : array) {
        std::cout << v << ", ";
    }
    std::cout << '\n';

    auto array2 = Array<int, 5>{1, 2, 3, 4, 5};
    array.swap(array2);

    for (auto v : array) {
        std::cout << v << ", ";
    }
    std::cout << '\n';

    for (auto v : array2) {
        std::cout << v << ", ";
    }
    std::cout << '\n';
}
