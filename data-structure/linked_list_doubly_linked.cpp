#include <iostream>

template <class DataType>
struct Node {
    DataType value;
    Node* previous;
    Node* next;
};

int main() {
    auto* node1 = new Node<int>{1, nullptr, nullptr};
    auto* node2 = new Node<int>{2, nullptr, nullptr};
    auto* node3 = new Node<int>{3, nullptr, nullptr};
    node1->next = node2;
    node2->next = node3;
    node2->previous = node1;
    node3->previous = node2;

    auto* current = node1;
    std::cout << current->value << '\n';
    current = current->next->next;
    std::cout << current->value << '\n';
    current = current->previous;
    std::cout << current->value << '\n';
}
