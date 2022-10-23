#include <map>
#include <iostream>
#include <string>

using namespace std; 

namespace cppprimer {

int mapOperations()
{
    /* Source: Chapter 10.3.2
     * Description: check map::key_type.
     */
    map<string, int>::key_type a("apple");
    cout << a << endl;

    return 0;
}

}

