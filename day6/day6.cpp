#include "day6.h"
#include "../util.h"

#include <vector>
#include <string>

using std::vector;
using std::string;
using std::pair;
using std::cout;
using std::endl;

namespace day6 {
    int part_1(const vector<string> &input) {
        int total = 0;

        for (auto &line : input) total += count_unique(line);

        return total;
    }

    int part_2(const vector<string> &input) {
        int total{0};

        for (auto &line : input) {
            std::map<char, int> found{};
            int tokens{0};
            for (char c : line) {
                if (c != ' ') {
                    found[c]++;
                } else {
                    ++tokens;
                }
            }

            for(auto const &[key, val] : found) {
                if (val == tokens) {
                    ++total;
                }
            }
        }

        return total;
    }

    pair<int, int> solve(const vector<string> &input) {
        return pair<int, int>{part_1(input), part_2(input)};
    }
}