// implement a shared_ptr
#include <iostream>

template <class T>
class SharedPtr {
public:
    // default constructor + parameterized
    SharedPtr(T* input = nullptr)
        : resourcePtr{input}
        , counter{new int{1}}
    {}

    // copy constructor
    SharedPtr(const SharedPtr& rhs) {
        resourcePtr = rhs.resourcePtr;
        counter = rhs.counter;
        incrementCounter();
    }

    // copy assignment operator
    SharedPtr& operator=(const SharedPtr& rhs) {
        if (this == &rhs) return *this; // check for self assignment

        // decrement counter
        decrementCounter();
        // point to new resource and counter
        resourcePtr = rhs.resourcePtr;
        counter = rhs.counter;
        // increment counter
        incrementCounter();

        return *this;
    }

    // move constructor
    SharedPtr(SharedPtr&& rhs) {
        resourcePtr = rhs.resourcePtr;
        counter = rhs.counter;
        rhs.resourcePtr = nullptr;
        rhs.counter = nullptr;
    }

    // move assignment operator
    SharedPtr& operator=(SharedPtr&& rhs) {
        if (this == &rhs) return *this; // stop self-move

        // decrement old
        decrementCounter();
        // set to new
        resourcePtr = rhs.resourcePtr;
        counter = rhs.counter;
        rhs.resourcePtr = nullptr;
        rhs.counter = nullptr;
        // don't increment new... not needed
        return *this;
    }

    // destructor
    ~SharedPtr() {
        decrementCounter();
    }

    T& operator*() {
        return *get();
    }

    T* operator->() {
        return get();
    }

    void reset(T* input = nullptr) {
        // there's nothing passed in
        decrementCounter();

        if (input) {
            resourcePtr = input;
            counter = new int{1};
        }
    }

    T* get() const {
        return resourcePtr;
    }

    int getCount() const {
        if (counter) {
            return *counter;
        }

        return -1;
    }

private:

    void incrementCounter() {
        if (counter) {
            (*counter)++;
        }
    }
    void decrementCounter() {
        if (counter) {
            (*counter)--;

            if ((*counter) == 0) {
                delete resourcePtr;
                delete counter;

                resourcePtr = nullptr;
                counter = nullptr;
            }
        }
    }

private:
    T* resourcePtr;
    int* counter;
};

int main() {
    auto ptr1 = SharedPtr<int>{}; // default constructor
    if (ptr1.get() == nullptr) {
        std::cout << "ptr1 is empty\n";
    }
    auto ptr2 = SharedPtr{new int{10}}; // custom constructor
    std::cout << (*ptr2) << '\n';
    auto ptr3 = ptr2; // copy constructor
    std::cout << (*ptr3) << '\n';
    ptr3 = ptr2; // copy assignment operator
    std::cout << (*ptr3) << '\n';
    auto ptr4 = std::move(ptr2); // move constructor
    std::cout << (*ptr4) << '\n';
    ptr4 = std::move(ptr3); // move assignment operator
    std::cout << (*ptr4) << '\n';

    ptr3.reset();
    ptr3.reset(new int{13});
    std::cout << (*ptr3) << '\n';

    ptr3.get();
    ptr3.getCount();

    // destructor
}