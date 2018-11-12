#ifndef WOLFRINI__HPP
#define WOLFRINI__HPP
#include <string>
#include <fstream>
#include <vector>

namespace WINI
{
struct KeyValuePair
{
    std::string key;
    std::string value;
};

class INISection
{
  public:
    INISection(std::string &);
    std::string getValue(const std::string &) const;
    void removeKeyValuePair(const std::string &);
    void setValue(const std::string &, const std::string &);
    std::string getAsINI() const;
    const std::string getSectionName () const;

  private:
    const auto getKeyValuePair (const std::string& key) const; 
    auto getKeyValuePair (const std::string& key); 
    std::string sectionName;
    std::vector<KeyValuePair> data;
};

class INIFile
{
  public:
    INIFile(std::string &);
    INIFile(INISection &...);
    const INISection getSection (std::string&) const;
    INISection getSection (std::string&);
    const std::string getValue (std::string&, std::string&) const;
    std::string getValue (std::string&, std::string&);
    std::string setValue (std::string&, std::string&, std::string&);
    std::string getAsINI() const;
  private:
    void sectionUnpacker(const INISection&, const INISection &...);
    void sectionUnpacker();
    std::vector<INISection> sections;
};
} // namespace WINI
#endif