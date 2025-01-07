#include <iostream>
#include <stack>

class Node {
public:
    char val;
    Node* left;
    Node* right;

    Node(char initialVal) {
        val = initialVal;
        left = nullptr;
        right = nullptr;
    }
};

void preorderDFS(Node* root) {
    if (root == nullptr) {
        return;
    }

    std::stack<Node*> stack{};
    stack.push(root);

    while (!stack.empty()) {
        auto current = stack.top();
        stack.pop();

        std::cout << current->val << '\n';

        if (current->right != nullptr) {
            stack.push(current->right);
        }
        if (current->left != nullptr) {
            stack.push(current->left);
        }
    }
}

void inorderDFS(Node* root) {
    if (root == nullptr) {
        return;
    }

    std::stack<Node*> stack{};
    Node* current = root;

    while (current != nullptr || !stack.empty()) {
        while (current != nullptr) {
            stack.push(current);
            current = current->left;
        }
        
        current = stack.top();
        stack.pop();
        
        std::cout << current->val << '\n';
        
        current = current->right;
    }
}

void postorderDFS(Node* root) {
    if (root == nullptr) {
        return;
    }

    std::stack<Node*> stack{};
    Node* current = root;
    Node* lastVisited = nullptr;

    while (current != nullptr || !stack.empty()) {
        if (current != nullptr) {
            stack.push(current);
            current = current->left;
        } else {
            Node* peekNode = stack.top();

            if (peekNode->right != nullptr && lastVisited != peekNode->right) {
                current = peekNode->right;
            } else {
                std::cout << peekNode->val << " ";
                lastVisited = stack.top();
                stack.pop();
            }
        }
    }
    std::cout << '\n';
}

int main() {
    auto* a = new Node('a');
    auto* b = new Node('b');
    auto* c = new Node('c');
    auto* d = new Node('d');
    auto* e = new Node('e');
    auto* f = new Node('f');

    a->left = b;
    a->right = c;
    b->left = d;
    b->right = e;
    c->right = f;

    //      a
    //    /   \
    //   b     c
    //  / \     \
    // d   e     f

    preorderDFS(a);
}