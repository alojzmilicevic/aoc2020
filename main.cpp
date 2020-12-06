#include <iostream>
#include <vector>

#include "util.h"
#include "day1/day1.h"
#include "day2/day2.h"
#include "day3/day3.h"
#include "day4/day4.h"
#include "day5/day5.h"
#include "day6/day6.h"
#include "day7/day7.h"
#include "day8/day8.h"
#include "day9/day9.h"
#include "day10/day10.h"
#include "day11/day11.h"
#include "day12/day12.h"
#include "day13/day13.h"
#include "day14/day14.h"
#include "day15/day15.h"
#include "day16/day16.h"
#include "day17/day17.h"
#include "day18/day18.h"
#include "day19/day19.h"
#include "day20/day20.h"
#include "day21/day21.h"
#include "day22/day22.h"
#include "day23/day23.h"
#include "day24/day24.h"
#include "day25/day25.h"

using namespace std;

int main() {
    pair<int, int> result{};

    int start_day{7};
    int end_day{7};

    for (int i{start_day}; i <= end_day; ++i) {
        switch (i) {
            case 1: {
                std::vector<int> input{read_num(i)};
                result = day1::solve(input);
                break;
            }
            case 2: {
                std::vector<string> input{read_lines(i)};
                result = day2::solve(input);
                break;
            }
            case 3: {
                std::vector<string> input{read_lines(i)};
                result = day3::solve(input);
                break;
            }
            case 4: {
                std::vector<string> input{read_chunks(i)};
                result = day4::solve(input);
                break;
            }
            case 5: {
                std::vector<string> input{read_lines(i)};
                result = day5::solve(input);
                break;
            }
            case 6: {
                std::vector<string> input{read_chunks(i)};
                result = day6::solve(input);
                break;
            }
            case 7: {
                std::vector<string> input{read_lines(i)};
                result = day7::solve(input);
                break;
            }
            case 8: {
                std::vector<string> input{read_lines(i)};
                result = day8::solve(input);
                break;
            }
            case 9: {
                std::vector<string> input{read_lines(i)};
                result = day9::solve(input);
                break;
            }
            case 10: {
                std::vector<string> input{read_lines(i)};
                result = day10::solve(input);
                break;
            }
            case 11: {
                std::vector<string> input{read_lines(i)};
                result = day11::solve(input);
                break;
            }
            case 12: {
                std::vector<string> input{read_lines(i)};
                result = day12::solve(input);
                break;
            }
            case 13: {
                std::vector<string> input{read_lines(i)};
                result = day13::solve(input);
                break;
            }
            case 14: {
                std::vector<string> input{read_lines(i)};
                result = day14::solve(input);
                break;
            }
            case 15: {
                std::vector<string> input{read_lines(i)};
                result = day15::solve(input);
                break;
            }
            case 16: {
                std::vector<string> input{read_lines(i)};
                result = day16::solve(input);
                break;
            }
            case 17: {
                std::vector<string> input{read_lines(i)};
                result = day17::solve(input);
                break;
            }
            case 18: {
                std::vector<string> input{read_lines(i)};
                result = day18::solve(input);
                break;
            }
            case 19: {
                std::vector<string> input{read_lines(i)};
                result = day19::solve(input);
                break;
            }
            case 20: {
                std::vector<string> input{read_lines(i)};
                result = day20::solve(input);
                break;
            }
            case 21: {
                std::vector<string> input{read_lines(i)};
                result = day21::solve(input);
                break;
            }
            case 22: {
                std::vector<string> input{read_lines(i)};
                result = day22::solve(input);
                break;
            }
            case 23: {
                std::vector<string> input{read_lines(i)};
                result = day23::solve(input);
                break;
            }
            case 24: {
                std::vector<string> input{read_lines(i)};
                result = day24::solve(input);
                break;
            }
            case 25: {
                std::vector<string> input{read_lines(i)};
                result = day25::solve(input);
                break;
            }
            default: {
                cout << "Day not solved." << endl;
                break;
            }
        }
        cout << "* * [Day " << i << "] * * " << endl << "Result part 1: " << result.first << endl;
        cout << "Result part 2: " << result.second << endl << endl;
    }


    return 0;

}