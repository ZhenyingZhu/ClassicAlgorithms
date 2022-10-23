#include <iostream>

using std::cout; 
using std::endl; 

/*
 *
 */
namespace cppprimer {

extern int printHello()
/* Source: Chapter 2.4
 * Description: extern means it can be
 * access from other cpp files.
 */
{
    cout << "Hello World! " << endl;

    return 0;
}

}
