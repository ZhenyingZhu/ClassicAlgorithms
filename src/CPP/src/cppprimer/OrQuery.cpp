#include <set>
#include <algorithm>
#include <iterator>

#include "TextQuery.h"
#include "OrQuery.h"

using std::set;
using std::set_intersection;
using std::inserter;

namespace cppprimer {

std::set<TextQuery::line_no> OrQuery::eval(const TextQuery &file) const {
    /* Source: Chapter 15.9.6
     * Description: Or query implement
     */
    set<line_no> ret_lines = lhs.eval(file);

    set<line_no> right = rhs.eval(file);
    ret_lines.insert(right.begin(), right.end());

    return ret_lines;
}

} // cpprimer
