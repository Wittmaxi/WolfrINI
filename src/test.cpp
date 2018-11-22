#include "wolfrini.hpp"
#include <iostream>

int testnum;
void test (bool worked) {
    ++testnum;
    if (! worked)
        std::cout << "TEST "<< testnum << " FAILED. \n";
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
    WINI::INIFile myIniFile3 (
        WINI::INISection (
            "[hello]\n"
            "greeter=hi\n"
            "ungeeter=bye\n"
        ),
        WINI::INISection (
            "[thanks]\n"
            "thankies=yaay\n"
        )
    );
    test(myIniFile3.getValue("thanks", "thankies") == "yaay");
    myIniFile3.addSection("section3");
    myIniFile3.addKeyValuePair("section3", "value", "value2");
    test (myIniFile3.getValue("section3", "value") == "value2");

    std::cout << myIniFile.getAsINI();
    std::cout << myIniFile2.getAsINI();
    std::cout << myIniFile3.getAsINI();
    std::cout << testnum << " tests performed\n";
}