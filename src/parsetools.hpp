#ifndef PARSETOOLS_HPP
#define PARSETOOLS_HPP
#include "wolfrini.hpp"
#include <string>
#include <vector>
#include <regex>
#include <algorithm>
namespace WINI {
std::string removeUntil (const std::string &toProcess, char until) {
    auto it = std::find(toProcess.begin(), toProcess.end(), until);
    if (it == toProcess.end()) 
        return "";
    return std::string (++it, toProcess.end());
}

std::string getUntil (const std::string &toProcess, char until) {
    auto it = std::find(toProcess.begin(), toProcess.end(), until);
    return std::string (toProcess.begin(), it);
}

inline std::string findSectionName (const std::string &iniCode) {
    std::string remaining = removeUntil (iniCode, '[');
    return getUntil (remaining, ']');
}

inline std::string removeSectionName (const std::string& iniCode) {
    return removeUntil (iniCode, ']');
}

inline KeyValuePair getKeyValuePair (const std::string &line) {
    KeyValuePair temp;
    temp.key = getUntil (line, '=');
    temp.value = getUntil (removeUntil(line, '='), ';');
    return temp;
}

inline std::vector<KeyValuePair> findKeyValuePairs(const std::string& iniCode) {
    std::vector<KeyValuePair> stored;
    std::string code = removeSectionName(iniCode);
    while (code != "") {
        KeyValuePair t = getKeyValuePair (getUntil (code, '\n'));
        if (t.key != "") 
            stored.push_back(t);
        code = removeUntil(code, '\n');
    }
    return stored;
}
}

#endif