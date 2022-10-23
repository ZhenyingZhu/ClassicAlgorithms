#include <iostream>
#include <string>

using namespace std; 

namespace cppprimer {

extern int stringOperations()
/* Source: Chapter 3.2.3
 * Description: check string max_size()
 */
{
    string s("Hello World! ");
    cout << s.max_size() << endl;

    return 0;
}

}
