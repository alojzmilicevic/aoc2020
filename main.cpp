#include <iostream>
#include <vector>

#include "util.h"
#include "day1/day1.h"
#include "day2/day2.h"
#include "day3/day3.h"
#include "day4/day4.h"
#include "day5/day5.h"
#include "day6/day6.h"

using namespace std;

int main() {
    pair<int, int> result{};

    int days = 7;

    for (int i{1}; i <= days; ++i) {
        switch (i) {
            case 1: {
                std::vector<int> input{read_num(i)};
                result = day1::solve(input);
                break;
            }
            case 2: {
                std::vector<string> input {read_lines(i)};
                result = day2::solve(input);
                break;
            }
            case 3: {
                std::vector<string> input {read_lines(i)};
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
                std::vector<string> input {read_chunks(i)};
                result = day6::solve(input);
                break;
            }
            case 7: {
                std::vector<string> input {read_chunks(i)};
                result = day6::solve(input);
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