/*
 * [Source] http://www.lintcode.com/en/problem/mini-cassandra/
 * [Difficulty]: Medium
 * [Tag]: 
 */

#include <iostream>
#include <string>
#include <unordered_map>
#include <list>
#include <vector>

using namespace std;

class Column {
public:
    int key;
    string value;
    Column(int key, string value) {
        this->key = key;
        this->value = value;
   }
};

// [Corner Case]:
// [Solution]: Use a hash to map from raw key to a list, where stores sorted column objects.
class MiniCassandra {
public:
    MiniCassandra() {
    }

    /**
     * @param raw_key a string
     * @param column_start an integer
     * @param column_end an integer
     * @return void
     */
    void insert(string raw_key, int column_key, string column_value) {
        Column c(column_key, column_value);
        if (keyListMap_.find(raw_key) == keyListMap_.end()) {
            keyListMap_[raw_key].push_back(c);
        } else {
            list<Column>::iterator it = keyListMap_[raw_key].begin();
            while (it != keyListMap_[raw_key].end() && it->key < column_key)
                ++it;
            if (it->key == column_key) {
                it->value = column_value;
            } else {
                keyListMap_[raw_key].insert(it, c);
            }
        }
    }

    /**
     * @param raw_key a string
     * @param column_start an integer
     * @param column_end an integer
     * @return a list of Columns
     */
    vector<Column> query(string raw_key, int column_start, int column_end) {
        vector<Column> res;
        if (keyListMap_.find(raw_key) == keyListMap_.end())
            return res;
        for (list<Column>::const_iterator it = keyListMap_[raw_key].cbegin(); it != keyListMap_[raw_key].cend(); ++it) {
            if (it->key > column_end)
                break;
            if (it->key >= column_start)
                res.push_back(*it);
        }
        return res;
    }

private:
    unordered_map<string, list<Column>> keyListMap_;
};

// [Solution]:

void printQuery(vector<Column> vec) {
    for (Column& c : vec) {
        cout << c.value << " ";
    }
    cout << endl;
}

int main() {
    MiniCassandra cassandra;
    cassandra.insert("Linkedin", 7, "DGFINL");
    printQuery(cassandra.query("Apple", 7, 8));
    cassandra.insert("Airbnb", 8, "BOKAQP");
    cassandra.insert("Linkedin", 3, "ODAMGH");
    cassandra.insert("Linkedin", 3, "KELFJN");
    cassandra.insert("Facebook", 2, "HJPQEG");
    cassandra.insert("Airbnb", 0, "OFACBI");
    printQuery(cassandra.query("Linkedin", 0, 1));
    cassandra.insert("Facebook", 6, "QHPMCI");
    cassandra.insert("Facebook", 6, "KOPBFL");
    cassandra.insert("Linkedin", 4, "EAKNIF");
    printQuery(cassandra.query("Facebook", 0, 1));
    cassandra.insert("Google", 3, "GNQCEK");
    cassandra.insert("Facebook", 5, "NBEJIQ");
    cassandra.insert("Linkedin", 8, "NOMCAD");
    cassandra.insert("Airbnb", 1, "DPHKNG");
    printQuery(cassandra.query("Linkedin", 2, 7));
    printQuery(cassandra.query("Google", 4, 4));
    printQuery(cassandra.query("Facebook", 2, 2));
    printQuery(cassandra.query("Facebook", 2, 4));
    printQuery(cassandra.query("Linkedin", 3, 7));
    printQuery(cassandra.query("Linkedin", 0, 8));
    cassandra.insert("Apple", 3, "PKJNHF");
    cassandra.insert("Facebook", 3, "OMIJPQ");

    return 0;
}
