#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <string>
#include <stdexcept>
#include "../MyUtils.h"

using namespace std; 
using namespace myutils;

namespace cppprimer {

int wordsTransform(int argc, char **argv)
{
    /* Source: Chapter 10.3.9.
     * Description: translate a file based on a translate dict.
     * Also argc and argv are the way to get program args.
     * Input files are under resources/WordsTransform/
     */
    if (argc != 3)
        throw runtime_error("wrong number of arguments");

    map<string, string> trans_map;
    string key, value;

    ifstream map_file;
    if (!open_file(map_file, argv[1]))
        throw runtime_error("no transformation file");
    while (map_file >> key >> value)
        trans_map.insert(make_pair(key, value));

    ifstream input;
    if (!open_file(input, argv[2]))
        throw runtime_error("no input file");

    string line;
    while (getline(input, line)) {
        istringstream stream(line);
        string word;
        bool first_word = true;

        while (stream >> word) {
            map<string, string>::const_iterator map_it = trans_map.find(word);
            if (map_it != trans_map.end())
                word = map_it->second;

            if (first_word)
                first_word = false;
            else
                cout << " ";
            cout << word;
        }

        cout << endl;
    }

    return 0;
} // wordsTransform

} // namespace cppprimer

