#include <algorithm>
#include <iostream>
#include <vector>

void insertion_sort(std::vector<int>& numbers) {
    if (numbers.size() <= 1) return;

    for (int i = 1; i < numbers.size(); i++) {
        auto value = numbers[i];

        int j = i - 1;

        while (j >= 0 && numbers[j] > value) {
            numbers[j + 1] = numbers[j];
            j--;
        }

        numbers[j + 1] = value;
    }
}

auto main() -> int {
    auto numbers = std::vector{5, 1, 2, 9, 10, 3};
    insertion_sort(numbers);

    std::for_each(std::begin(numbers), std::end(numbers), [](int const& n) {
        std::cout << n << '\n';
    });
}
