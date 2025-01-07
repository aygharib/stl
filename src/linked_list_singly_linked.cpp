#include <iostream>

template <class DataType>
struct Node {
    DataType value;
    Node* next;
};

int main() {
    auto* node3 = new Node<int>{3, nullptr};
    auto* node2 = new Node<int>{2, node3};
    auto* node1 = new Node<int>{1, node2};

    auto* current = node1;
    std::cout << current->value << '\n';
    current = current->next;
    std::cout << current->value << '\n';
    current = current->next;
    std::cout << current->value << '\n';
}
