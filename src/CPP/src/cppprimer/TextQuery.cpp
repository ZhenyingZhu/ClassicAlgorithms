#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>

#include "../MyUtils.h"
#include "TextQuery.h"

using namespace std; 
using namespace myutils;

namespace cppprimer {

void TextQuery::store_file(ifstream &is) {
    // Read a file and store each line to a vector
    string textline;
    while (getline(is, textline)) {
        lines_of_text.push_back(textline);
    }
}

void TextQuery::build_map() {
    // Record which line each word is in
    for (line_no line_num = 0; line_num != lines_of_text.size(); ++line_num) {
        istringstream line(lines_of_text[line_num]);
        string word;
        while (line >> word) {
            word_map[word].insert(line_num);
        }
    }
}

set<TextQuery::line_no> TextQuery::run_query(const string &query_word) const {
    // find all lines of a word
    map<string, set<line_no> >::const_iterator loc = word_map.find(query_word);
    if (loc == word_map.end())
        return set<line_no>();
    else
        return loc->second;
}

string TextQuery::text_line(line_no line) const {
    // Return the line
    if (line < lines_of_text.size())
        return lines_of_text[line];
    throw std::out_of_range("line number out of range");
}

TextQuery::line_no TextQuery::size() const {
    return lines_of_text.size();
}

void print_results(const set<TextQuery::line_no>& locs, const string& sought, const TextQuery &file) {
    // Print how many times a word shows, and all lines it in.
    typedef set<TextQuery::line_no> line_nums;
    line_nums::size_type size = locs.size();
    cout << "\n" << sought << " occurs " << size << " " << make_plural(size, "time", "s") << endl;
    line_nums::const_iterator it = locs.begin();
    for (; it != locs.end(); ++it) {
        cout << "\t(line " << (*it) + 1 << ") " << file.text_line(*it) << endl;
    }
}

} // cppprimer

