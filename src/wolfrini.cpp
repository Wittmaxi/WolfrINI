#include "wolfrini.hpp"
#include <algorithm>
#include <iostream>
#include "parsetools.hpp"

namespace WINI
{
INISection::INISection(std::string &iniCode) {
    sectionName = findSectionName (iniCode);
}
std::string INISection::getValue(const std::string &keyName) const {
    return getKeyValuePair(keyName)->value;
}
void INISection::removeKeyValuePair(const std::string &keyName) {
    data.erase(getKeyValuePair(keyName));
}
void INISection::setValue(const std::string &keyName, const std::string &newValue) {
    getKeyValuePair(keyName)->value = newValue;
}
std::string INISection::getAsINI() const {
    std::string temporary = "[" + sectionName + "]\n";
    for (const auto &i : data)
        std::cout << i.key << "=" << i.value << "\n";
}
const std::string INISection::getSectionName() const {
    return sectionName;
}
auto INISection::getKeyValuePair (const std::string& keyName) {
    return std::find_if (data.begin(), data.end(),
        [&keyName](const auto &kv) -> bool {
            if (kv.key == keyName)
                return true;
            return false;
        });
}
const auto INISection::getKeyValuePair (const std::string& keyName) const {
    return std::find_if (data.begin(), data.end(),
        [&keyName](const auto &kv) -> bool {
            if (kv.key == keyName)
                return true;
            return false;
        });
}
} // namespace WINI