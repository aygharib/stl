#include <iostream>

#include <array>

class HeapBinaryMin {
public:
    // Core
    auto top() -> int;
    void push(int value);
    void pop();

    // Optional
    auto empty() -> bool;
    void print();

    // void swap(int a, int b);

// private:
    static int constexpr CAPACITY = 10;

    std::array<int, CAPACITY> data;
    int size;
};

auto HeapBinaryMin::top() -> int {
    return (size > 0) ? data[0] : -1;
}

auto parent(int value) -> int {
    return (value - 1) / 2;
}

// void HeapBinaryMin::swap(int a, int b) {
//
// }

void HeapBinaryMin::push(int value) {
    auto new_node_index = size;
    auto parent_index = (new_node_index - 1) / 2;
    size++;
    data[new_node_index] = value;

    // If the heap property is violated, reorder until heap property is reestablished
    while (parent_index >= 0 && data[parent_index] > data[new_node_index]) {
        // If parent is larger, swap the parent and child
        auto parent_old = data[parent_index];
        data[parent_index] = data[new_node_index];
        data[new_node_index] = parent_old;

        new_node_index = parent_index;
        parent_index = (new_node_index - 1) / 2;
        print();
    }

    // size++;
    // int i = size - 1;
    // data[i] = value;
    // while (i != 0 && data[parent(i)] > data[i]) {
    //     std::swap(data[i], data[parent(i)]);
    //     i = parent(i);
    // }

    return;
}

void HeapBinaryMin::pop() {

}

auto HeapBinaryMin::empty() -> bool {
    return true;
}

void HeapBinaryMin::print() {
    for (int i = 0; i < size; i++) {
        std::cout << data[i] << ", ";
    }
    std::cout << '\n';
    return;
}

auto main() -> int {
    auto min_heap = HeapBinaryMin{};
    min_heap.push(3);
    min_heap.print();

    min_heap.push(4);
    min_heap.print();

    min_heap.push(6);
    min_heap.print();

    min_heap.push(2);
    min_heap.print();

    min_heap.push(1);
    min_heap.print();

    min_heap.push(7);
    min_heap.print();

    min_heap.push(5);
    min_heap.print();
}
