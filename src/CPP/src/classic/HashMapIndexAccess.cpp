#include <iostream>
#include <unordered_map>

using namespace std;

class TryHash {
public:
    char getCharA(unordered_map<int, char> &map) {
        // operator[] is a non-const func, so cannot call when map is const 
        char &c = map[0];
        return c;
    }
};

int main() {
    unordered_map<int, char> map;
    for (int i = 0; i < 26; ++i)
        map[i] = 'A' + i;
    
    char &c = map[0];
    cout << c << endl;

    TryHash t;
    cout << t.getCharA(map) << endl;

    return 0;
}
