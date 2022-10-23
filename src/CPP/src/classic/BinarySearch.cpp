#include <iostream>
#include <cmath>

using namespace std;

double DELTA = 0.01;

class BinarySearch {
public:
    enum Cmp {SMALLER, EQUAL, LARGER};

    BinarySearch(double t): target(t) { }

    Cmp compare(double value) {
        //if ( abs(value - target) < DELTA )
        if (value == target) // looks like C++ also implement this
            return EQUAL;
        if (value > target)
            return LARGER;
        return SMALLER;
    }

    double binarySearch(double lower, double upper) {
        while (lower < upper - DELTA) {
            double middle = (lower + upper) / 2.0;
            Cmp code = compare(middle);
            if (code == EQUAL)
                return middle;
            else if (code == SMALLER)
                lower = middle;
            else
                upper = middle;
        }

        if (compare(lower) == EQUAL)
            return lower;
        return upper;
    }

    double target;
};

int main() {
    for (double i = -2.0; i <= 2.0; i += 0.1) {
        BinarySearch bs(i);
        cout << i << ": " << bs.binarySearch(-2.0, 2.0) << endl;
    }
    
    return 0;
}
