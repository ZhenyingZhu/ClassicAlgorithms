/*
 * [Source] https://leetcode.com/problems/anagrams/
 * [Difficulty]: Medium
 * [Tag]: Hash Talbe
 * [Tag]: String
 */

#include <iostream>

using namespace std;

// [Solution]: Use sorted string as key, insert into hash table.
// [Corner Case]:
class Solution {
};

// [Solution]: For previous leetcode question
/* Java solution
https://github.com/ZhenyingZhu/ClassicAlgorithms/blob/master/src/algorithms/sortandsearch/SortAnagrams.java
 */

/* Java solution
public class Solution {
    public List<String> anagrams(String[] strs) {
		List<String> result=new ArrayList<String>();
        if(strs.length<=1) return result;
		String[] copy=new String[strs.length];
		int[] idxs=new int[strs.length];
		for(int i=0; i<strs.length; i++){
			copy[i]=sortChar(strs[i]);
			idxs[i]=i;
		}
		quickSort(copy, idxs, 0, strs.length-1);
		int pt=0;
		int cnt=0;
		for(int i=1; i<idxs.length; i++){
			if(copy[i].equals(copy[pt])){
				cnt++;
			}else{
				if(cnt>0){
					for(int j=0; j<=cnt; j++){
						result.add(strs[idxs[pt+j]]);
					}
				}
				cnt=0;
				pt=i;
			}
		}
		if(cnt>0){
			for(int j=0; j<=cnt; j++){
				result.add(strs[idxs[pt+j]]);
			}
		}
		return result;
    }
	
	public String sortChar(String str){
		if(str.length()<=1) return str;
		char[] array=str.toCharArray();
		quickSort(array, 0, str.length()-1);
		return new String(array);
	}
	
	public void quickSort(char[] array, int start, int end){
		if(start>end) return;
		int mid=(start+end)/2;
		swap(array, mid, end);
		int pt=start-1;
		for(int i=start; i<end; i++){
			if(array[i]<array[end]){
				pt++;
				swap(array, i, pt);
			}
		}
		pt++;
		swap(array, pt, end);
		quickSort(array, start, pt-1);
		quickSort(array, pt+1, end);
	}
	
	public void quickSort(String[] array, int[] idxs, int start, int end){
		if(start>end) return;
		int mid=(start+end)/2;
		swap(array, mid, end);
		swap(idxs, mid, end);
		int pt=start-1;
		for(int i=start; i<end; i++){
			if(array[i].compareTo(array[end])<0){
				pt++;
				swap(array, i, pt);
				swap(idxs, i, pt);
			}
		}
		pt++;
		swap(array, pt, end);
		swap(idxs, pt, end);
		quickSort(array, idxs, start, pt-1);
		quickSort(array, idxs, pt+1, end);
	}
	
	public void swap(char[] array, int a, int b){
		char tmp=array[a];
		array[a]=array[b];
		array[b]=tmp;
	}
	
	public void swap(String[] array, int a, int b){
		String tmp=array[a];
		array[a]=array[b];
		array[b]=tmp;
	}

	public void swap(int[] array, int a, int b){
		int tmp=array[a];
		array[a]=array[b];
		array[b]=tmp;
    }
}
 */

int main() {
    Solution sol;

    return 0;
}
