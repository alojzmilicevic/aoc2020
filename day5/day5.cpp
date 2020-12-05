#include "day5.h"
#include "../util.h"

#include <vector>
#include <iostream>
#include <string>

using std::vector;
using std::string;
using std::pair;
using std::cout;
using std::endl;

#define MAX_ROWS 127
#define MAX_COLS 7
#define OFFSET 7

namespace day5 {
    int do_binary_search(string const &value, int start) {
        int pos = {0};

        for (char c : value) {

            start = floor(start / 2);
            if (c == 'B' || c == 'R') {
                pos += start + 1;

            }
        }
        return pos;
    }

    int part_1(const vector<string> &input) {
        int max_seat_id{0};
        for (auto &line: input) {
            string row{line.substr(0, OFFSET)};
            string col{line.substr(OFFSET, input.size() - OFFSET)};

            int row_id = do_binary_search(row, MAX_ROWS);
            int col_id = do_binary_search(col, MAX_COLS);
            int seat_id{row_id * (MAX_COLS + 1) + col_id};

            if (seat_id > max_seat_id) {
                max_seat_id = seat_id;
            }
        }
        return max_seat_id;
    }

    int part_2(const vector<string> &input) {
        int max_seat_id{part_1(input)};
        vector<bool> taken_seats{};

        taken_seats.reserve(max_seat_id + 1);
        for (int i = 0; i < max_seat_id + 1; ++i) {
            taken_seats.push_back(false);
        }

        for (auto &line: input) {
            string row{line.substr(0, OFFSET)};
            string col{line.substr(OFFSET, input.size() - OFFSET)};

            int row_id = do_binary_search(row, MAX_ROWS);
            int col_id = do_binary_search(col, MAX_COLS);
            int seat_id{row_id * (MAX_COLS + 1) + col_id};

            taken_seats[seat_id] = true;
        }

        for (int i = 0; i < taken_seats.size(); ++i) {
            if (i > 34 && !taken_seats[i]) {
                return i;
            }
        }

        return -1;
    }

    pair<int, int> solve(const vector<string> &input) {
        return pair<int, int>{part_1(input), part_2(input)};
    }
}