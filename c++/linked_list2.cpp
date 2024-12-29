#include <vector>

struct Node {
    int value{0};
    Node* next{nullptr};
};

class LinkedList {
public:
    LinkedList() {
        head->next = tail;
    }

    // int get(int index) {
    //     int count = 0;
    //     Node* current = head;
    //     while (current != nullptr && count < index) {
    //         current = current->next;
    //         count++;
    //     }

    //     if (current == nullptr) {
    //         return -1;
    //     }

    //     return current->value;
    // }

    // void insertHead(int val) {
    //     Node* newHead = new Node{val, head};
    //     head = newHead;
    //     // size++;
    // }

    // void insertTail(int val) {
    //     Node* newTail = new Node{val, nullptr};
    //     tail->next = newTail;
    //     tail = newTail;
    //     // size++;
    // }

    // bool remove(int index) {
    //     int count = 0;
    //     Node* previous = nullptr;
    //     Node* current = head;
    //     while (current != nullptr && count < index) {
    //         previous = current;
    //         current = current->next;
    //         count++;
    //     }

    //     if (current == nullptr) {
    //         return false;
    //     }

    //     // 0 -> 1 -> 2 -> 3 -> N
    //     // remove(2)
    //     previous->next = current->next;

    //     current->next = nullptr;
    //     delete current;
    //     // size--;
    //     return true;
    // }

    // std::vector<int> getValues() {
    //     // int result[size] = {};
    //     std::vector<int> result{};
    //     Node* current = head;
    //     // for (int i = 0; i < size; i++) {
    //     while (current != nullptr) {
    //         // result[i] = current->value;
    //         result.push_back(current->value);
    //         current = current->next;
    //     }
    //     return result;
    // }
private:
    Node* head{};
    Node* tail{};
    // int size{};
};

int main() {
    auto linked_list = LinkedList{};
}
