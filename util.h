#pragma once

#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <iostream>
#include <algorithm>

#define in_med_dig inline

using std::string;
using std::vector;
using std::ifstream;
using std::cout;
using std::endl;
using std::stringstream;
using std::getline;
using std::fstream;
using std::sort;

in_med_dig void print_file(const string &file_name) {
    ifstream file{file_name};
    string line{};

    while (getline(file, line)) {
        cout << line << endl;
    }
}

template<typename T>
in_med_dig void print(const vector<T> &arr) {
    cout << "[";

    for (int i{}; i < arr.size(); ++i) {
        cout << arr[i];

        if (i < arr.size() - 1) {
            cout << ", ";
        }
    }

    cout << "]" << endl;
}

template<class T>
in_med_dig int len(T number) {
    int digits = 0;
    if (number < 0) digits = 1; // remove this line if '-' counts as a digit
    while (number) {
        number /= 10;
        digits++;
    }
    return digits;
}

in_med_dig int pow(int x, int p) {
    if (p == 0) return 1;
    if (p == 1) return x;

    int tmp = pow(x, p / 2);
    if (p % 2 == 0) return tmp * tmp;
    else return x * tmp * tmp;
}

//TODO: num < 0, num > int
in_med_dig int number_at(int const k, int const num) {
    int length{len(num)};

    if (k < 0 || k > length) throw std::logic_error("Index out of bounds");

    int base{pow(10, length - 1)};

    return num / (base / pow(10, k)) % 10;
}

// Count the number of times num occurs in target.
in_med_dig int count(int digit, int target) {
    int total = 0;

    int length{len(target)};

    for (int i{0}; i < length; ++i) {
        if (number_at(i, target) == digit) total++;
    }

    return total;
}

// https://github.com/andreasjhkarlsson/aoc-2019/blob/master/src/util.h
in_med_dig vector<string> split(const string &s, char delim) {
    vector<string> result;
    stringstream ss(s);
    string item;

    while (getline(ss, item, delim)) {
        result.push_back(item);
    }

    return result;
}

in_med_dig fstream get_file(int const day) {
    return fstream{"../data/in" + std::to_string(day) + ".txt"};
}

in_med_dig vector<string> read_lines(int const day) {
    vector<string> input{};

    fstream my_file{get_file(day)};

    string line{};

    while (my_file >> line) {
        input.push_back(line);
    }

    return input;
}

in_med_dig vector<string> read_chunks(int const day) {
    vector<string> input{};
    stringstream ss{};

    fstream my_file{get_file(day)};
    string line{};

    while (getline(my_file, line)) {
        if (line.size() == 0) {
            input.push_back(ss.str());
            ss.str(string{});
        } else {
            ss << line << " ";
        }
    }

    return input;
}

in_med_dig string read_line(int const day) {
    string line{};
    getline(get_file(day), line);
    return line;
}

in_med_dig vector<int> read_num(int const day) {
    vector<int> input{};

    fstream my_file{get_file(day)};

    int a{0};


    while (my_file >> a) input.push_back(a);

    return input;
}

in_med_dig vector<int> read_num(int day, char split_token) {
    vector<int> input{};

    string line{};
    getline(get_file(day), line);
    vector<string> clean{split(line, split_token)};

    input.reserve(clean.size());

    for (auto &e : clean) {
        input.push_back(std::stoi(e));
    }

    return input;
}

// https://github.com/andreasjhkarlsson/aoc-2019/blob/master/src/util.h
in_med_dig vector<vector<int>> permuteUnique(vector<int> num) {
    sort(num.begin(), num.end());
    vector<vector<int>> res;
    if (num.empty()) {
        return res;
    }
    do {
        res.push_back(num);
    } while (next_permutation(num.begin(), num.end()));
    return res;
}


in_med_dig vector<int> range(const int start, const int end) {
    vector<int> set{};
    set.reserve(end - start);

    for (int i{start}; i < end; ++i) set.push_back(i);

    return set;
}

in_med_dig vector<int> range(const int end) {
    vector<int> set{};
    set.reserve(end);

    for (int i{0}; i < end; ++i) set.push_back(i);

    return set;
}