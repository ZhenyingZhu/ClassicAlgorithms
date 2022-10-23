/*
 * [Source] https://leetcode.com/problems/insert-interval/
 * [Difficulty]: Hard
 * [Tag]: Array
 * [Tag]: Sort
 */

#include <iostream>
#include <vector>
#include <functional>
#include <climits>

using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

// [Solution]: Recursive the array. If not overlap, copy to new array. Otherwise compute the new interval.
// [Corner Case]: The newInterval is the last interval, so need a special way to insert it.
class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> res;
        int len = intervals.size();
        if (len == 0) {
            res.push_back(newInterval);
            return res;
        }

        int st = newInterval.start, ed = newInterval.end;
        for (int i = 0; i < len; ++i) {
            const Interval& cur = intervals[i];
            if (cur.end < newInterval.start) {
                res.push_back(cur);
            } else if (cur.start > newInterval.end) {
                if (ed < cur.start) {
                    res.push_back(Interval(st, ed));
                    ed = INT_MAX;
                }
                res.push_back(cur);
            } else {
                st = min(cur.start, st);
                ed = max(cur.end, ed);
            }
        }

        if (ed != INT_MAX)
            res.push_back(Interval(st, ed));

        return res;
    }
};

// helper
void printIntervalVec(const vector<Interval>& vec) {
    for (const Interval& interval : vec) {
        cout << "{" << interval.start << "," << interval.end << "} ";
    }
    cout << endl;
}

// [Solution]: break to three parts
/* Java solution
https://github.com/ZhenyingZhu/ClassicAlgorithms/blob/master/src/algorithms/arrandstring/InsertInterval.java
 */

/* Java solution
public class Solution {
    public List<Interval> insert(List<Interval> intervals, Interval newInterval) {
        List<Interval> result=new ArrayList<Interval>();
		if(intervals.size()==0){
			result.add(newInterval);
			return result;
		}
		if(intervals.get(0).start>newInterval.end){ // Before
			result.add(newInterval);
			result.addAll(intervals);
			return result;
		}
		int i=0;
		while(i<intervals.size()){
			if(intervals.get(i).end<newInterval.start){ // Equal need merge
				result.add(intervals.get(i));
				i++;
			}else{ // Insert before or merge
				break;
			}
		}
		if(i==intervals.size()){ // insert to tail
			result.add(newInterval);
			return result;
		}
		if(intervals.get(i).start>newInterval.end){	// insert not merge
			result.add(newInterval);
			for(; i<intervals.size(); i++){
				result.add(intervals.get(i));
			}
			return result;
		}
		// i.end>=n.start, i.start<=n.end, Merge
		int newStart=(intervals.get(i).start<newInterval.start)?intervals.get(i).start:newInterval.start;
		int j=i+1;
		while(j<intervals.size()){
			if(intervals.get(j).start<newInterval.end){ // equal need merge
				j++;
			}else{
				break;
			}
		}
		if(j==intervals.size()){
			int newEnd=(intervals.get(j-1).end>newInterval.end)?intervals.get(j-1).end:newInterval.end;
			result.add(new Interval(newStart, newEnd));
			return result;
		}
		if(intervals.get(j).start==newInterval.end){ // merge
			int newEnd=intervals.get(j).end;
			result.add(new Interval(newStart, newEnd));
			j++;
		}else if(intervals.get(j-1).end>newInterval.end){ // j.start>n.end && j-1.start<n.end && j-1.end>n.end
			int newEnd=intervals.get(j-1).end;
			result.add(new Interval(newStart, newEnd));
		}else{ // j-1.start<n.end && j-1.end<=n.end
			int newEnd=newInterval.end;
			result.add(new Interval(newStart, newEnd));
		}
		for(; j<intervals.size(); j++){
			result.add(intervals.get(j));
		}
		return result;
    }
}
 */

int main() {
    Solution sol;

    //vector<Interval> vec = {{1,3},{6,9}};
    //printIntervalVec(sol.insert(vec, {2, 5}));

    //vector<Interval> vec = {{1,2},{3,5},{6,7},{8,10},{12,16}};
    //printIntervalVec(sol.insert(vec, {4, 9}));

    vector<Interval> vec = {{1,5}};
    printIntervalVec(sol.insert(vec, {2, 3}));

    return 0;
}
