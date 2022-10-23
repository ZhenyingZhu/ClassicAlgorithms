/*
 * [Source] https://leetcode.com/problems/powx-n/
 * [Difficulty]: Medium
 * [Tag]: Binary Search
 * [Tag]: Math
 */

#include <iostream>

using namespace std;

// [Solution]: P(x,n)=P(x, n/2)*x^(n%2).
// [Corner Case]: n<=0.
class Solution {
    double myPow(double x, int n) {
        if (n == 0)
            return 1.0;
        if (n == 1)
            return x;
        if (n == -1)
            return 1.0 / x;

        double half = myPow(x, n / 2);
        double tmp = half * half;
        if (n % 2 == 0) {
            return tmp;
        } else if (n > 0) {
            return tmp * x;
        } else {
            return tmp / x;
        }
    }
};

/* Java solution
https://github.com/ZhenyingZhu/ClassicAlgorithms/blob/master/src/algorithms/mathandprob/Pow.java
 */

/* Java solution
public class Solution {
    public double pow(double x, int n) {
        if(n==0) return 1.0;
        if(n==1) return x;
        if(n>0) return power(x, n);
        else return 1.0/power(x, -n);
    }
    
    public double power(double x, int n){
        if(n==0) return 1.0;
        double y=power(x, n/2);
        if(n%2==0) return y*y;
        return y*y*x;
    }
}
 */

int main() {
    Solution sol;
    cout << sol.myPow(1.0, 1) << endl;
    cout << sol.myPow(2.0, 2) << endl;
    cout << sol.myPow(2.0, 3) << endl;
    cout << sol.myPow(2.0, -1) << endl;
    cout << sol.myPow(2.0, -2) << endl;

    return 0;

    return 0;
}
