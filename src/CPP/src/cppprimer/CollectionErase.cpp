#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using std::cout; 
using std::endl; 
using std::vector;
using std::string; 
using std::find; 

namespace cppprimer {

extern int collectionErase()
{
    /* Source: Chapter 3.2.2
     * Description: check if erase() delete from start to the one before end
     */
    string str_arr[] = {"a", "b", "c", "d"};
    vector<string> svec(str_arr, str_arr + sizeof str_arr / sizeof *str_arr);

    string delStart("b"), delEnd("c");
    vector<string>::iterator b = find(svec.begin(), svec.end(), delStart);
    vector<string>::iterator e = find(svec.begin(), svec.end(), delEnd);

    cout << "Deleted: "<<*svec.erase(b, e) << endl;

    cout << "Left: " << endl;
    for (vector<string>::const_iterator iter = svec.begin(); iter != svec.end(); ++iter) {
        cout << *iter << endl;
    }

    return 0;
}


}

