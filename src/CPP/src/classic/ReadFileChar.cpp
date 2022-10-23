#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream ifs;

    ifs.open("ReadFileChar.cpp");
    while (ifs.good()) {
        char c = ifs.get();
        cout << c;
    }
    ifs.close();

    return 0;
}
