#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include "../MyUtils.h"
#include "TextQuery.h"

using namespace std; 
using namespace myutils;

namespace cppprimer {

int testQuery(int argc, char **argv)
{
    /* Source: Chapter 10.6.3
     * Description: Test TextQuery class.
     */
    ifstream infile;
    if (argc < 2 || !open_file(infile, argv[1])) {
        cerr << "No input file! " << endl;
        return EXIT_FAILURE;
    }

    TextQuery tq;
    tq.read_file(infile);
    while (true) {
        cout << "Enter word to look for, or q to exit: " << endl;
        string s;
        cin >> s;
        if (!cin || s == "q") break;
        set<TextQuery::line_no> locs = tq.run_query(s);
        print_results(locs, s, tq);
    }

    cout << "All queries done. Exiting..." << endl;

    return 0;
}

} // cppprimer

