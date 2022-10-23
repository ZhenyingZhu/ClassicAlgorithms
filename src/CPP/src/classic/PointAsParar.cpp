#include <iostream>

using namespace std;

void plusOne(int *p) {
    (*p)++;
}

int main() {
    int var = 1;
    plusOne(&var);

    cout << var << endl;
}
