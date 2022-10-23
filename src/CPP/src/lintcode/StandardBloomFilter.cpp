/*
 * [Source] http://www.lintcode.com/en/problem/standard-bloom-filter/
 * [Difficulty]: Medium
 * [Tag]: 
 */

#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

// [Corner Case]:
// [Solution]:
const size_t CAP = 10000;

class HashFunc {
public:
    HashFunc():
        seed_(0) { }
    
    HashFunc(int seed):
        seed_(seed) { }

    size_t hash(const string &str) const {
        size_t ret = 0;
        for (const char &c : str) {
            ret = ret * seed_ + c;
            ret %= CAP;
        }
        return ret;
    }

private:
    int seed_;
};

class StandardBloomFilter {
public:
    StandardBloomFilter(int k) {
        for (int i = 0; i < k; ++i) {
            hashFuncs.push_back( HashFunc(33 * i) );
        }
    }

    void add(string word) {
        for (HashFunc &hf : hashFuncs) {
            size_t hashcode = hf.hash(word);
            filter.set(hashcode);
        }
        words.push_back(word);
    }

    bool contains(string word) {
        for (HashFunc &hf : hashFuncs) {
            size_t hashcode = hf.hash(word);
            if (!filter[hashcode])
                return false;
        }

        for (string &w : words) {
            if (w == word)
                return true;
        }
        return false;
    }

private:
    vector<HashFunc> hashFuncs;
    bitset<CAP> filter;
    vector<string> words;
};

// [Solution]:

int main() {
    StandardBloomFilter bf(3);
    bf.add("lint");
    bf.add("code");
    cout << bf.contains("lint") << endl;
    cout << bf.contains("world") << endl;

    return 0;
}
