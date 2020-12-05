#include "day4.h"
#include "../util.h"

#include <vector>
#include <string>
#include <map>

using std::vector;
using std::string;
using std::pair;
using std::cout;
using std::endl;
using std::map;

namespace day4 {
    bool year_validator(string const &val, int min, int max) {
        int int_val = stoi(val);

        return val.size() == 4 && (int_val >= min && int_val <= max);
    }

    bool is_height_valid(string const &val) {
        int size = val.size();
        int height = 0;
        string unit = val.substr(size - 2, size);
        try {
            height = stoi(val.substr(0, size - 2));
        } catch (const std::exception &e) {

        }

        if (unit == "cm") {
            return height >= 150 && height <= 193;
        } else if (unit == "in") {
            return height >= 59 && height <= 76;
        }

        return false;
    }

    bool is_hair_color_valid(string const &val) {
        string value = val.substr(1, val.size());
        if (val[0] == '#' && value.size() == 6) {
            return true;
        }
        return false;
    }

    bool is_eye_color_valid(string const &eye_color) {
        return (eye_color == "amb" || eye_color == "blu" || eye_color == "brn" || eye_color == "gry"
                || eye_color == "grn" || eye_color == "hzl" || eye_color == "oth");
    }

    bool is_passport_id_valid(string const &passport_id) {
        return passport_id.size() == 9;
    }

    bool validator(string const &key, string const &val) {
        if (key == "byr") {
            return year_validator(val, 1920, 2002);
        } else if (key == "iyr") {
            return year_validator(val, 2010, 2020);
        } else if (key == "eyr") {
            return year_validator(val, 2020, 2030);
        } else if (key == "hgt") {
            return is_height_valid(val);
        } else if (key == "hcl") {
            return is_hair_color_valid(val);
        } else if (key == "ecl") {
            return is_eye_color_valid(val);
        } else if (key == "pid") {
            return is_passport_id_valid(val);
        }

        return false;
    }

    int part_1(const vector<string> &input) {
        int valid = 0;
        for (int i = 0; i < input.size(); ++i) {
            std::map<string, bool> data{{"byr", false},
                                        {"iyr", false},
                                        {"eyr", false},
                                        {"hgt", false},
                                        {"hcl", false},
                                        {"ecl", false},
                                        {"pid", false},
                                        {"cid", false}};

            vector<string> tokens{split(input[i], ' ')};

            int total_keys = tokens.size();
            if (total_keys >= 7) {
                for (int j = 0; j < tokens.size(); ++j) {
                    vector<string> keys_and_values{split(tokens[j], ':')};
                    string key{keys_and_values[0]};


                    string value{keys_and_values[1]};


                    data[key] = true;

                }

                // om vi har 7 nycklar men inte cid, då har vi allt som är required
                if ((total_keys == 7 && !data["cid"]) || total_keys == 8) {
                    ++valid;
                }
            }

        }

        return valid;
    }

    int part_2(const vector<string> &input) {
        int valid = 0;
        for (int i = 0; i < input.size(); ++i) {
            std::map<string, bool> data{{"byr", false},
                                        {"iyr", false},
                                        {"eyr", false},
                                        {"hgt", false},
                                        {"hcl", false},
                                        {"ecl", false},
                                        {"pid", false},
                                        {"cid", false}};

            vector<string> tokens{split(input[i], ' ')};

            int total_keys = tokens.size();
            int total_valid = 0;
            if (total_keys >= 7) {
                for (int j = 0; j < tokens.size(); ++j) {
                    vector<string> keys_and_values{split(tokens[j], ':')};
                    string key{keys_and_values[0]};


                    string value{keys_and_values[1]};

                    if (validator(key, value)) {
                        ++total_valid;
                        data[key] = true;
                    }
                }

                // om vi har 7 nycklar men inte cid, då har vi allt som är required
                if ((total_valid == 7 && !data["cid"]) || total_valid == 8) {
                    ++valid;
                }
            }

        }
        return valid;
    }

    pair<int, int> solve(const vector<string> &input) {
        return pair<int, int>{part_1(input), part_2(input)};
    }
}