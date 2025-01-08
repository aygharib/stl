#include <iostream>

template <class T>
class UniquePtr {
public:
    explicit UniquePtr(T* ptr = nullptr)
        : ptr{ptr}
    {}

    ~UniquePtr() {
        delete ptr;
    }

    UniquePtr(const UniquePtr& rhs) = delete; // copy constructor doesn't exist
    T& operator=(const UniquePtr& rhs) = delete; // copy assignment operator doesn't exist

    // move constructor
    UniquePtr(UniquePtr&& rhs)
        : ptr(rhs.release())
    {}

    // move assignment operator
    UniquePtr& operator=(UniquePtr&& rhs) {
        reset(rhs.release());
        return *this;
    }

    T* release() {
        auto oldPtr = ptr;
        ptr = nullptr;
        return oldPtr;
    }

    // clears the old pointer and sets to newPtr
    void reset(T* newPtr = nullptr) {
        auto oldPtr = release();
        ptr = newPtr;

        if (oldPtr != nullptr) {
            delete oldPtr;
        }
    }

    T* get() const {
        return ptr;
    }

    T* operator->() const {
        return get();
    }

    T& operator*() const {
        return *get();
    }

    explicit operator bool() {
        return get() != nullptr;
    }

    // below this is advanced implementation

    void swap(UniquePtr& other) {
        std::swap(this->ptr, other.ptr);
    }

    // These 2 below are used for `Base* a = new Derived;` support
    template <class U>
    UniquePtr(UniquePtr<U>&& rhs)
        : ptr(rhs.release())
    {}

    template <class U>
    UniquePtr& operator=(UniquePtr<U>&& rhs) {
        reset(rhs.release());
        return *this;
    }



private:
    T* ptr{nullptr};
};

int main() {
    // Testing the data structure

    // Use the user-defined constructor while passing a pointer
    UniquePtr<int> myPtr1 = UniquePtr<int>{new int{5}};
    // Use dereference operator
    std::cout << *myPtr1 << '\n';
    // Use get() function
    std::cout << myPtr1.get() << '\n';

    // Use move constructor
    UniquePtr<int> myPtr2 = std::move(myPtr1);
    std::cout << *myPtr2 << '\n';

    // Use user-defined constructor without passing a pointer
    UniquePtr<int> myPtr3{};
    // Use move-assignment operator
    myPtr3 = std::move(myPtr2);
    std::cout << *myPtr3 << '\n';

    // Use reset function
    if (myPtr3) {
        std::cout << "myPtr3 contains stuff\n";
    }
    myPtr3.release();
    if (!myPtr3) {
        std::cout << "myPtr3 no longer contains stuff\n";
    }
}