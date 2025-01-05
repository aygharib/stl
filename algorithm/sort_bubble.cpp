#include <algorithm>
#include <iostream>
#include <vector>

void bubble_sort(std::vector<int>& numbers) {
    for (int i = 0; i < numbers.size() - 1; i++) {
        for (int j = i; j < numbers.size() - 1; j++) {
            if (numbers[j+1] < numbers[j]) {
                auto temp = numbers[j];
                numbers[j] = numbers[j + 1];
                numbers[j + 1] = temp;
            }
        }
    }
}

auto main() -> int {
    auto numbers = std::vector{5, 1, 2, 9, 10, 3};
    bubble_sort(numbers);

    std::for_each(std::begin(numbers), std::end(numbers), [](int const& n) {
        std::cout << n << '\n';
    });
}
