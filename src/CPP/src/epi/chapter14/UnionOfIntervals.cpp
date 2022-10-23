#include "UnionOfIntervals.hpp"

#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <ostream>
#include <stdexcept>
#include <cassert>

using std::vector;
using std::string;
using std::sort;
using std::max;
using std::min;
using std::cout;
using std::endl;
using std::ostream;

namespace epi {
  namespace chapter14 {
    struct UnionOfIntervals::Interval {
    private:
        // Even though this struct is private, left and right are still public
        struct Endpoint {
            bool operator<(const Endpoint &other) const {
                if (val < other.val)
                    return true;

                if (val == other.val && isClosed)
                    return true;

                return false;
            }

            int val;
            bool isClosed;
        };

    public:
        Interval(int leftVal, bool leftClosed, int rightVal, bool rightClosed):
            left{leftVal, leftClosed}, right{rightVal, rightClosed} { }

        bool operator<(const Interval &other) const {
            if (left.val < other.left.val)
                return true;

            if (left.val == other.left.val && left.isClosed)
                return true;

            return false;
        }

        bool operator>(const Interval &other) const {
            return !(*this < other);
        }

        Endpoint left, right;
    };

    ostream& operator<<(ostream &os, const UnionOfIntervals::Interval &interval) {
        if (interval.left.isClosed)
            os << "[";
        else
            os << "(";

        os << interval.left.val << "," << interval.right.val;

        if (interval.right.isClosed)
            os << "]";
        else
            os << ")";

        return os;
    }

    bool UnionOfIntervals::isIntersect(const Interval &interval1, const Interval &interval2) {
        assert(interval1 < interval2);

        if (interval1.right.val < interval2.left.val)
            return false;
        else if (interval1.right.val == interval2.left.val && !interval1.right.isClosed && !interval2.left.isClosed)
            return false;
        else
            return true;
    }

    vector<UnionOfIntervals::Interval> UnionOfIntervals::unionOfIntervals(vector<Interval> intervals) {
        vector<Interval> res;

        if (intervals.empty())
            return res;

        sort(intervals.begin(), intervals.end());

        for (Interval interval : intervals) {
            if ( res.empty() || !isIntersect(res.back(), interval) )
                res.push_back(interval);
            else {
                Interval &last = res.back();
                last.left = min(last.left, interval.left);
                last.right = max(last.right, interval.right);
            }
        }

        return res;
    }

    bool UnionOfIntervals::test() {
        vector<Interval> intervals = {
                Interval(0, false, 3, false),
                Interval(1, true, 1, true),
                Interval(2, true, 4, true),
                Interval(3, true, 4, false),
                Interval(5, true, 7, false),
                Interval(7, true, 8, false),
                Interval(8, true, 11, false),
                Interval(9, false, 11, true),
                Interval(12, true, 14, true),
                Interval(12, false, 16, true),
                Interval(13, false, 15, false),
                Interval(16, false, 17, false),
        };

        vector<Interval> res = unionOfIntervals(intervals);

        if (res.size() != 3) {
            cout << "Should be size 4" << endl;
            cout << "Result " << endl;

            for (Interval interval : res) {
                cout << interval << endl;
            }

            return false;
        }

        return true;
    }

  } // chapter14
} // epi
