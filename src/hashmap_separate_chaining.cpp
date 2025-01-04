#include <iostream>

#include <array>
#include <list>
#include <utility>

class HashMap {
public:
    // Core
    void add(int key, int value);
    void remove(int key);
    auto find(int key) -> int;

    // Optional
    auto is_empty() -> bool;

private:
    auto hash(int key) -> int;

private:
    static int constexpr ARRAY_SIZE = 20;
    using Table = std::array<std::list<std::pair<int, int>>, ARRAY_SIZE>;

    Table table;
    int insert_count;
};

void HashMap::add(int key, int value) {
    auto index = hash(key);

    // If key exists, overwrite value
    auto& target_list = table[index];
    for (auto& [target_key, target_value] : target_list) {
        if (target_key == key) {
            target_value = value;
            return;
        }
    }

    // If key doesn't exist, add value
    target_list.emplace_back(key, value);
    insert_count++;

    return;
}

void HashMap::remove(int key) {
    auto index = hash(key);

    // If key exists, remove value
    auto& target_list = table[index];
    for (auto it = std::begin(target_list); it != std::end(target_list); it++) {
        auto& [target_key, target_value] = *it;
        if (target_key == key) {
            // If the node to remove is not the last one
            it = target_list.erase(it);
            insert_count--;
            break;

            // If the node to remove is the last node
            
            // table.erase(it);

            // target_value = value;
            // return;
        }
    }

    // If key doesn't exist, remove nothing
    return;
}

auto HashMap::find(int key) -> int {
    auto index = hash(key);

    // If key exists, return value
    auto& target_list = table[index];
    for (auto& [target_key, target_value] : target_list) {
        if (target_key == key) {
            return target_value;
        }
    }

    // If key doesn't exist, return -1
    return -1;
}

auto HashMap::hash(int key) -> int {
    auto index = key % ARRAY_SIZE;
    return index;
}

auto HashMap::is_empty() -> bool {
    return insert_count == 0;
}

auto main() -> int {
    auto hashmap = HashMap{};

    std::cout << "Is empty: " << hashmap.is_empty() << '\n';
    std::cout << "Has key of 1:" << hashmap.find(1) << '\n';
    hashmap.add(1, 10);
    hashmap.add(2, 10);
    std::cout << "Has key of 1:" << hashmap.find(1) << '\n';
    hashmap.remove(1);
    std::cout << "Has key of 2:" << hashmap.find(2) << '\n';
    hashmap.remove(2);
    std::cout << "Has key of 2:" << hashmap.find(2) << '\n';
    std::cout << "Is empty: " << hashmap.is_empty() << '\n';
}
