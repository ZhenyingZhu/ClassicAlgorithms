/*
 * [Source] http://www.lintcode.com/en/problem/geohash-ii/
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
     * @param geohash a base32 string
     * @return latitude and longitude a location coordinate pair
     */
    vector<double> decode(string geohash) {
        vector<int> seq = getBinary(geohash);
        vector<int> lat(seq.size() / 2), lon(seq.size() - lat.size());
        for (int i = 0; i < (int)seq.size(); ++i) {
            if (i % 2 == 0)
                lon[i / 2] = seq[i];
            else
                lat[i / 2] = seq[i];
        }

        double longtitude = getLoc(lon, -180.0, 180.0);
        double latitude = getLoc(lat, -90.0, 90.0);
        return {latitude, longtitude};
    }

    vector<int> getBinary(string &str) {
        string map = "0123456789bcdefghjkmnpqrstuvwxyz";
        vector<int> seq(str.length() * 5);
        int st = 0;
        for (char &c : str) {
            int idx = map.find(c);
            for (int i = st + 4; i >= st; --i) {
                seq[i] = idx % 2 == 0 ? 0 : 1;
                idx /= 2;
            }
            st += 5;
        }
        return seq;
    }

    double getLoc(vector<int> &vec, double st, double ed) {
        for (int &i : vec) {
            double md = (st + ed) / 2.0;
            if (i == 1)
                st = md;
            else
                ed = md;
        }
        return (st + ed) / 2.0;
    }
};

int main() {
    GeoHash gh;
    for (double &d : gh.decode("wx4g0s"))
        cout << d << " ";
    cout << endl;

    return 0;
}
