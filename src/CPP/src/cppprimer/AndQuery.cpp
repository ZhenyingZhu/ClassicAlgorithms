#include <set>
#include <algorithm>
#include <iterator>

#include "TextQuery.h"
#include "AndQuery.h"

using std::set;
using std::set_intersection;
using std::inserter;

namespace cppprimer {

std::set<TextQuery::line_no> AndQuery::eval(const TextQuery &file) const {
    /* Source: Chapter 15.9.6
     * Description: And query implement
     */
    set<line_no> ret_lines;
    set<line_no> left = lhs.eval(file), right = rhs.eval(file);

    // Find lines both in left and in right.
    set_intersection(
            left.begin(), left.end(),
            right.begin(), right.end(),
            inserter(ret_lines, ret_lines.begin())
            );

    return ret_lines;
}

} // cpprimer
