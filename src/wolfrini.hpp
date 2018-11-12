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
    INISection(const std::string &);
    std::string getValue(const std::string &) const;
    void removeKeyValuePair(const std::string &);
    void setValue(const std::string &, const std::string &);
    std::string getAsINI() const;
    std::string getSectionName() const;
    void addKeyValuePair (std::string&, std::string&);

  private:
    const auto getKeyValuePair(const std::string &key) const;
    auto getKeyValuePair(const std::string &key);
    std::string sectionName;
    std::vector<KeyValuePair> data;
};

class INIFile
{
  public:
    INIFile(std::string &);
    template <class... T>
    INIFile(T... sections)
    {
        sectionUnpacker(sections...);
    }
    const INISection getSection(std::string &) const;
    INISection getSection(std::string &);
    std::string getValue(std::string &, std::string &) const;
    std::string getValue(std::string &, std::string &);
    std::string setValue(std::string &, std::string &, std::string &);
    std::string getAsINI() const;
    void addSection (INISection &);

  private:
    auto getSectionIteratorWithName(std::string &name);
    const auto getSectionIteratorWithName(std::string &name) const;

    template <class A, class... T>
    void sectionUnpacker(A section, T... other)
    {
        typename std::enable_if<std::is_same<A, INISection>::value, int>::type a;
        sections.push_back(section);
        sectionUnpacker(other...);
    }
    void sectionUnpacker()
    {
    }

    std::vector<INISection> sections;
};
} // namespace WINI
#endif