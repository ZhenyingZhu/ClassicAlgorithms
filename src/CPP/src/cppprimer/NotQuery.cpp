#include <set>
#include <algorithm>
#include <iterator>

#include "TextQuery.h"
#include "Query.h"
#include "NotQuery.h"

using std::set;
using std::set_intersection;
using std::inserter;

namespace cppprimer {

std::set<TextQuery::line_no> NotQuery::eval(const TextQuery &file) const {
    /* Source: Chapter 15.9.6
     * Description: Not query implement
     */
    set<line_no> ret_lines;

    set<line_no> has_val = query.eval(file);
    for (line_no n = 0; n != file.size(); ++n) {
        if (has_val.find(n) == has_val.end())
            ret_lines.insert(n);
    }
    return ret_lines;
}

} // cppprimer
