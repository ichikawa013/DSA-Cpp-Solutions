#include "trim.hpp"
#include <algorithm>
#include <cctype>

std::string trim(const std::string& s) {
    std::string result = s;
    result.erase(result.begin(),
        std::find_if(result.begin(), result.end(),
            [](unsigned char ch) { return !std::isspace(ch); }));
    result.erase(std::find_if(result.rbegin(), result.rend(),
            [](unsigned char ch) { return !std::isspace(ch); }).base(),
        result.end());
    return result;
}
