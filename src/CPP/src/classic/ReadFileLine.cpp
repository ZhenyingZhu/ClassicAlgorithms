#include <iostream>
#include <fstream>

using namespace std;

int main() {
    string filename = "ReadFileLine.cpp";
    ifstream file(filename);

    // read line by line
    string line;
    while (file.good()) {
        getline(file, line);
        cout << line << endl;
    }

    return 0;
}
