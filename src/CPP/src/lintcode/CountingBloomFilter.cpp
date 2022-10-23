/*
 * [Source] http://www.lintcode.com/en/problem/counting-bloom-filter/
 * [Difficulty]: Medium
 * [Tag]: 
 */

#include <iostream>
#include <vector>

using namespace std;

// [Corner Case]:
// [Solution]:
const size_t CAP = 100000;

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

class CountingBloomFilter {
public:
    CountingBloomFilter(int k) {
        for (int i = 0; i < k; ++i) {
            hashFuncs.push_back( HashFunc(33 * i + 7) );
        }
        counter.resize(CAP, 0);
    }

    void add(string word) {
        for (HashFunc &hf : hashFuncs) {
            size_t hashcode = hf.hash(word);
            ++counter[hashcode];
        }
        words.push_back(word);
    }

    void remove(string word) {
        if (contains(word)) {
            for (HashFunc &hf : hashFuncs) {
                --counter[ hf.hash(word) ];
            }
        }
    }

    bool contains(string word) {
        for (HashFunc &hf : hashFuncs) {
            size_t hashcode = hf.hash(word);
            if (counter[hashcode] <= 0)
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
    vector<int> counter;
    vector<string> words;
};

// [Solution]:

int main() {
    CountingBloomFilter bf(3);
    bf.add("lint");
    bf.add("code");
    cout << bf.contains("lint") << endl;
    cout << bf.contains("world") << endl;
    bf.remove("lint");
    cout << bf.contains("lint") << endl;

    return 0;
}
