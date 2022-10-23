#include <vector>
#include <set>
#include <map>
#include <string>

#ifndef TEXTQUERY_H
#define TEXTQUERY_H

namespace cppprimer {

class TextQuery {
    /* Source: Chapter 10.6.2
     * Description: Query which lines are a word in.
     * A simple example of how class works.
     */
public:
    typedef std::vector<std::string>::size_type line_no;
    void read_file(std::ifstream &is) {
        store_file(is);
        build_map();
    }
    std::set<line_no> run_query(const std::string&) const;
    std::string text_line(line_no) const;
    line_no size() const;
private:
    void store_file(std::ifstream&);
    void build_map();
    std::vector<std::string> lines_of_text;
    std::map< std::string, std::set<line_no> > word_map;
};// TextQuery

void print_results(const std::set<TextQuery::line_no>& locs,
        const std::string& sought, const TextQuery &file);

}

#endif
