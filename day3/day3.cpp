#include "day3.h"
#include <vector>
#include <string>

using std::vector;
using std::string;
using std::pair;

namespace day3 {
    long long part_1(const vector<string> &input, const vector<pair<int, int>> &translations) {
        int length = input[0].size();
        long long sum = 1;

        for (const auto &translation : translations) {
            int trees = 0;

            int right{translation.first};
            int down{translation.second};

            int x{right};

            for (int i = down; i < input.size(); i += down) {
                if (input[i][x] == '#') {
                    ++trees;
                }

                x = (x + right) % length;
            }

            sum = sum * trees;
        }

        return sum;
    }

    pair<long long, long long> solve(const vector<string> &input) {
        return pair<long long, long long>{part_1(input, {{3, 1}}), part_1(input, {
            {1,1},
            {3,1},
            {5,1},
            {7,1},
            {1,2},
        })};
    }
}