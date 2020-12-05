#include "day2.h"
#include "../util.h"

#include <vector>
#include <iostream>
#include <string>

using std::vector;
using std::string;
using std::pair;
using std::cout;
using std::endl;

namespace day2 {
    int part_1(const vector<string> &input) {
        int matches = 0;

        for (int i = 0; i < input.size(); i += 3) {
            vector<string>minMax = split(input[i], '-');
            int min = stoi(minMax[0]);
            int max = stoi(minMax[1]);
            char match = input[i+1][0];
            string password = input[i+2];

            size_t n = std::count(password.begin(), password.end(), match);

            if (n >= min && n <= max) {
                ++matches;
            }
        }

        return matches;
    }

    int part_2(const vector<string> &input) {
        int matches = 0;

        for (int i = 0; i < input.size(); i += 3) {
            vector<string>minMax = split(input[i], '-');
            int min = stoi(minMax[0]) - 1;
            int max = stoi(minMax[1]) - 1;
            char match = input[i+1][0];
            string password = input[i+2];

            if (password[min] == match ^ password[max] == match) {
                ++matches;
            }

        }

        return matches;
    }

    pair<int, int> solve(const vector<string> &input) {
        return pair<int, int>{part_1(input), part_2(input)};
    }
}