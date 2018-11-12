#include "wolfrini.hpp"
#include <iostream>

int testnum;
void test (bool worked, std::string comment = "") {
    testnum++;
    if (! worked)
        std::cout << "TEST "<< testnum << " FAILED. " << comment << "\n";
}

int main () {
    WINI::INIFile myIniFile(
        ";somecmment\n"
        "[thatguy]\n"
        "name=andrew\n"
        "surname=batman\n"
        "[me]\n"
        "name=maxi;somecommet\n"
        "surname=norris\n"
    );
    test (myIniFile.getValue("thatguy", "name") == "andrew");
    test (myIniFile.getValue("me", "name") == "maxi");
    WINI::INIFile myIniFile2 (myIniFile.getAsINI());
    test (myIniFile2.getValue("thatguy", "surname") == "batman");
    WINI::INISection &sec = myIniFile2.getSection("thatguy");
    sec.addKeyValuePair("hobby", "being cool");
    test (myIniFile2.getValue("thatguy", "hobby") == "being cool");
    std::cout << myIniFile2.getAsINI();
    std::cout << testnum << " tests performed\n";
}