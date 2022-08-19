package algorithms.arrandstring;

import java.util.*;

public class FourSum {
    /* Function: Find all the unique quadruplets in the array that sum to a target.
     * Solution: Use three sum.
     */

    public List<List<Integer>> fourSum(int[] num, int target) {
        List<List<Integer>> res = new ArrayList<List<Integer>>();
        if (num == null || num.length < 4) {
            return res;
        }

        Arrays.sort(num);
        List<Integer> list = new ArrayList<Integer>();
        for (int i = 0; i <= num.length - 4; ++i) {
            if (i != 0 && num[i] == num[i - 1]) {
                continue;
            }

            list.add(num[i]);
            for (int j = i + 1; j <= num.length -3; ++j) {
                if (j != i + 1 && num[j] == num[j - 1]) {
                    continue;
                }

                list.add(num[j]);
                twoSum(num, target - num[i] - num[j], j + 1, list, res);
                list.remove(list.size() - 1);
            }
            list.remove(list.size() - 1);
        }

        return res;
    }

    private void twoSum(int[] num, int target, int st, List<Integer> list, List<List<Integer>> res) {
        int ed = num.length - 1;
        while (st < ed) {
            int sum = num[st] + num[ed];
            if (sum == target) {
                list.add(num[st]);
                list.add(num[ed]);
                res.add(new ArrayList<Integer>(list));
                list.remove(list.size() - 1);
                list.remove(list.size() - 1);

                --ed;
                do {
                    ++st;
                } while (st <= ed && num[st] == num[st - 1]);
            } else if (sum < target) {
                ++st;
            } else {
                --ed;
            }
        }
    }
}