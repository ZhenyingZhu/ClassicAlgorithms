/*
 * [Source] http://www.lintcode.com/en/problem/geohash/
 * [Difficulty]: Medium
 * [Tag]: 
 */

#include <iostream>
#include <vector>

using namespace std;

// [Corner Case]:
// [Solution]:
class GeoHash {
public:
    /**
     * @param latitude, longitude a location coordinate pair
     * @param precision an integer between 1 to 12
     * @return a base32 string
     */
    string encode(double latitude, double longitude, int precision) {
        int lat = precision * 5 / 2, lon = precision * 5 - lat; // bits of base32
        vector<int> latBinary = getBinary(latitude, lat, -90.0, 90.0);
        vector<int> lonBinary = getBinary(longitude, lon, -180.0, 180.0);
        vector<int> res(precision * 5);
        for (int i = 0; i < (int)res.size(); ++i) {
            if (i % 2 == 0)
                res[i] = lonBinary[i / 2];
            else
                res[i] = latBinary[i / 2];
        }
        vector<char> charArr = groupChar(res);
        return string(charArr.begin(), charArr.end());
    }

    vector<int> getBinary(double num, int len, double st, double ed) {
        vector<int> seq(len);
        for (int i = 0; i < len; ++i) {
            double md = (st + ed) / 2.0;
            if (num > md) {
                seq[i] = 1;
                st = md;
            } else {
                seq[i] = 0;
                ed = md;
            }
        }
        return seq;
    }

    vector<char> groupChar(vector<int> &seq) {
        string map = "0123456789bcdefghjkmnpqrstuvwxyz";
        vector<char> vec;
        for (int i = 0; i < (int)seq.size(); i += 5) {
            int idx = 0;
            for (int j = 0; j < 5; ++j) {
                idx = idx * 2 + seq[i + j];
            }
            vec.push_back(map[idx]);
        }
        return vec;
    }
};

int main() {
    GeoHash gh;
    cout << gh.encode(39.92816697, 116.38954991, 5) << endl;

    return 0;
}
