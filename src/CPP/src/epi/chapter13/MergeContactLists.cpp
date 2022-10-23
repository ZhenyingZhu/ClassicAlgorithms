#include "MergeContactLists.hpp"

#include <vector>
#include <string>
#include <unordered_set>
#include <functional>
#include <cassert>
#include <iostream>
#include <stdexcept>
#include "../../MyUtils.h"

using std::vector;
using std::string;
using std::unordered_set;
using std::hash;
using std::invalid_argument;
using myutils::vec_to_string;
using std::cout;
using std::endl;

namespace epi {
  namespace chapter13 {
    struct MergeContactLists::ContactList {
        bool operator==(const ContactList &that) const {
            return unordered_set<string>(names.begin(), names.end())
                    == unordered_set<string>(that.names.begin(), that.names.end());
        }

        vector<string> names;

    };

    struct MergeContactLists::HashContactList {
        size_t operator()(const ContactList &contacts) const {
            size_t hashCode = 0;

            for (const string &name : unordered_set<string>(contacts.names.begin(), contacts.names.end())) {
                hashCode ^= hash<string>()(name);
            }

            return hashCode;
        }

    };

    vector<MergeContactLists::ContactList> MergeContactLists::mergeContactLists
            (const vector<MergeContactLists::ContactList> &contacts) {
        unordered_set<ContactList, HashContactList> uniqueContacts(contacts.begin(), contacts.end());

        return {uniqueContacts.begin(), uniqueContacts.end()};
    }

    bool MergeContactLists::test() {
        vector<string> names1 = {"a", "b", "c"};
        vector<string> names2 = {"d", "e", "c"};
        vector<string> names3 = {"c", "b", "a", "a"};

        ContactList cl1{names1};
        ContactList cl2{names2};
        ContactList cl3{names3};

        vector<ContactList> vec = {cl3, cl2, cl1};

        vector<ContactList> res = mergeContactLists(vec);

        for (ContactList cl : res) {
            for (string s : cl.names) {
                cout << s << " ";
            }
            cout << endl;
        }

        return true;
    }

  } // chapter13
} // epi
