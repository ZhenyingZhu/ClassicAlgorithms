#include <iostream>
#include <unordered_map>

using namespace std;

// [Source]: http://www.1point3acres.com/bbs/thread-225124-1-1.html

class SSNStorage {
public:
    SSNStorage() {
        root = new TrieNode();
    }

    ~SSNStorage() {
        delete root;
    }

    void insert(string SSN) {
        TrieNode *run = root;
        for (char &c : SSN) {
            if (c == '-')
                continue;

            int num = c - '0';
            if (!run->map.count(num)) {
                run->map[num] = new TrieNode();
            }
            run = run->map[num];
        }
    }

    bool exist(string SSN) {
        TrieNode *run = root;
        for (char &c : SSN) {
            if (c == '-')
                continue;

            int num = c - '0';
            if (!run->map.count(num))
                return false;
            run = run->map[num];
        }
        return true;
    }

private:
    struct TrieNode {
        TrieNode() { }

        ~TrieNode() {
            for (auto it = map.begin(); it != map.end(); ++it) {
                delete it->second;
            }
        }

        unordered_map<int, TrieNode*> map;
    };

    TrieNode *root;
};

int main() {
    SSNStorage s;
    s.insert("12-345");
    s.insert("13-345");
    cout << s.exist("12-345") << endl;
    cout << s.exist("13-345") << endl;
    cout << s.exist("12-343") << endl;

    return 0;
}
