#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

// [Source]: http://www.1point3acres.com/bbs/thread-229745-1-1.html

struct User {
    string name;
    vector<string> emails;
    User(string n): name(n) { }
};

class Solution {
public:
    int findUniqueUsers(vector<User*> &users) {
        int size = users.size();
        vector<bool> isUnique(size, true);
        for (int i = 0; i < size; ++i) {
            if (!isUnique[i])
                continue;

            for (int j = 0; j < size; ++j) {
                if (j == i || !isUnique[j])
                    continue;

                if (isSubset(users[j], users[i])) {
                    isUnique[j] = false;
                }
            }
        }

        int cnt = 0;
        for (int i = 0; i < size; ++i) {
            if (isUnique[i])
                ++cnt;
        }
        return cnt;
    }

private:
    bool isSubset(User *subset, User *superset) {
        if (subset->emails.size() > superset->emails.size())
            return false;

        unordered_set<string> superEmails(superset->emails.begin(), superset->emails.end());
        for (string &email : subset->emails) {
            if (!superEmails.count(email))
                return false;
        }
        return true;
    }
};

int main() {
    Solution sol;

    User u1("A"), u2("B"), u3("C"), u4("D");
    u1.emails = {"a", "b", "c"};
    u2.emails = {"b", "c"};
    u3.emails = {"a"};
    u4.emails = {"d"};
    vector<User*> users = {&u1, &u2, &u3, &u4};
    cout << sol.findUniqueUsers(users) << endl;

    return 0;
}
