#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>

#include "../MyUtils.h"
#include "TextQuery.h"
#include "Query.h"

using namespace std;
using namespace myutils;

namespace cppprimer {

int testWordQuery(int argc, char **argv) {
    ifstream infile;
    if (argc < 2 || !open_file(infile, argv[1])) {
        cerr << "No input file! " << endl;
        return EXIT_FAILURE;
    }

    TextQuery tq;
    tq.read_file(infile);

    while (true) {
        cout << "Enter word to look for, or n to continue: " << endl;
        string s;
        cin >> s;
        if (!cin || s == "n") break;

        Query q(s);
        set<TextQuery::line_no> locs = q.eval(tq);
        cout << "Query is: " << q << endl;
        print_results(locs, s, tq);
    }

    while (true) {
        cout << "Enter word that not look for, or n to continue: " << endl;
        string s;
        cin >> s;
        if (!cin || s == "n") break;

        Query q = ~Query(s);
        set<TextQuery::line_no> locs = q.eval(tq);
        cout << "Query is: " << q << endl;
        print_results(locs, "no " + s, tq);
    }

    while (true) {
        cout << "Enter two words to look for both, or n to continue: " << endl;
        string s1, s2;
        cin >> s1;
        if (!cin || s1 == "n") break;
        cin >> s2;

        Query q = Query(s1) & Query(s2);
        set<TextQuery::line_no> locs = q.eval(tq);
        cout << "Query is: " << q << endl;
        print_results(locs, s1 + " and " + s2, tq);
    }

    while (true) {
        cout << "Enter two words to look for either, or n to continue: " << endl;
        string s1, s2;
        cin >> s1;
        if (!cin || s1 == "n") break;
        cin >> s2;

        Query q = Query(s1) | Query(s2);
        set<TextQuery::line_no> locs = q.eval(tq);
        cout << "Query is: " << q << endl;
        print_results(locs, s1 + " or " + s2, tq);
    }

    return 0;
}

} // cppprimer
