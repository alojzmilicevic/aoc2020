#include <vector>
#include <iostream>

namespace day1 {
    int part_1(const std::vector<int> &input) {
        for (int i = 0; i < input.size(); ++i) {
            for (int j = 0; j < input.size(); ++j) {
                int first{input[i]};
                int second{input[j]};
                if ((first + second) == 2020) {
                    return first * second;
                }
            }
        }

        return -1;
    }

    int part_2(const std::vector<int> &input) {
        for (int i = 0; i < input.size(); ++i) {
            for (int j = 0; j < input.size(); ++j) {
                for (int k = 0; k < input.size(); ++k) {
                    int first{input[i]};
                    int second{input[j]};
                    int third{input[k]};
                    if ((first + second + third) == 2020) {
                        return first * second * third;
                    }
                }
            }
        }

        return -1;
    }

    int test(const std::vector<int> &input, int n) {
        for (int i = 0; i < input.size(); ++i) {
            if (n > 1) {
                test(input, n - 1);
            }

        }
        return -1;
    }

    std::pair<int, int> solve(const std::vector<int> &input) {
        return std::pair<int, int>{part_1(input), part_2(input)};
    }
}