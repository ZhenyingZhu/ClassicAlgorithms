#include <iostream>
#include <map>

using namespace std;

int main() {
    map<int, int> map;
    map[1] = 1;
    map[3] = 3;

    cout << "0 " << map.lower_bound(0)->first << endl;
    cout << "2 " << map.lower_bound(2)->first << endl;
    cout << "3 " << map.lower_bound(3)->first << endl;
    if (map.lower_bound(4) == map.end())
        cout << "4 end" << endl;
    else
        cout << "4 " << map.lower_bound(4)->first << endl;
    cout << "0 " << map.upper_bound(0)->first << endl;
    cout << "2 " << map.upper_bound(2)->first << endl;
    if (map.upper_bound(3) == map.end())
        cout << "3 end" << endl;
    else
        cout << "3 " << map.upper_bound(3)->first << endl;
    if (map.upper_bound(4) == map.end())
        cout << "4 end" << endl;
    else
        cout << "4 " << map.upper_bound(4)->first << endl;
}
