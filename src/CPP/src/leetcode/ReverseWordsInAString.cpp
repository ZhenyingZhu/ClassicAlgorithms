/*
 * [Source] https://leetcode.com/problems/reverse-words-in-a-string/
 * [Difficulty]: Medium
 * [Tag]: String
 */

#include <iostream>

using namespace std;

// [Solution]: Reverse each word, then reverse the whole string
// [Corner Case]: trailing spaces count as one space in the result
class Solution {
};

// [Solution]: split the string by space
/* Java solution
https://github.com/ZhenyingZhu/ClassicAlgorithms/blob/master/src/algorithms/arrandstring/ReverseWordsInAString.java
 */

/* Java solution
public class Solution {
    public String reverseWords(String s) {
        String[] array=s.split(" ");
        StringBuffer result=new StringBuffer();
        if(array.length<1) return result.toString();
        for(int i=array.length-1; i>=0; i--){
            if(!array[i].equals("")){
                result.append(array[i]+" ");
            }
        }
        String answer=result.toString();
        if(answer.equals("")) return answer; 
        return answer.substring(0, answer.length()-1);
    }
}
 */

int main() {
    Solution sol;

    return 0;
}
