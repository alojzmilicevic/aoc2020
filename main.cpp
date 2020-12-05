#include <iostream>
#include <vector>

#include "util.h"
#include "day1/day1.h"
#include "day2/day2.h"
#include "day3/day3.h"
#include "day4/day4.h"
#include "day5/day5.h"

using namespace std;

int main() {
    pair<int, int> result{};

    int days = 5;

    for (int i{0}; i < days; ++i) {
        switch (i) {
            case 0: {
                //std::vector<int> input{read_num(i + 1)};
                //result = day1::solve(input);
                break;
            }
            case 1: {
                //std::vector<string> input {read_lines(i+1)};
                //result = day2::solve(input);
                break;
            }
            case 2: {
                //std::vector<string> input {read_lines(i+1)};
                //result = day3::solve(input);
                break;
            }
            case 3: {
                //std::vector<string> input{read_chunks(i + 1)};
                //result = day4::solve(input);
                break;
            }
            case 4: {
                std::vector<string> input{read_lines(i + 1)};
                result = day5::solve(input);
                break;
            }
            default: {
                cout << "Day not solved." << endl;
                break;
            }
        }
        cout << "* * [Day " << i + 1 << "] * * " << endl << "Result part 1: " << result.first << endl;
        cout << "Result part 2: " << result.second << endl << endl;
    }


    return 0;

}