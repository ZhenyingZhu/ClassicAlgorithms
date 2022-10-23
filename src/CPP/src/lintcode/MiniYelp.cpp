/*
 * [Source] http://www.lintcode.com/en/problem/mini-yelp/
 * [Difficulty]: Hard
 * [Tag]: 
 */

#include <iostream>

using namespace std;

class Location {
public:
    double latitude, longitude;
    static Location create(double lati, double longi) {
        // This will create a new location object
    }
};

class Restaurant {
public:
    int id;
    string name;
    Location location;
    static Restaurant create(string &name, Location &location) {
        // This will create a new restaurant object,
        // and auto fill id
    }
};

class Helper {
public:
    static double get_distance(Location &location1, Location &location2) {
        // return distance between location1 and location2.
    }
};

class GeoHash {
public:
    static string encode(Location &location) {
        // return convert location to a GeoHash string
    }
    static Location decode(string &hashcode) {
         // return convert a GeoHash string to location
    }
};

// [Corner Case]:
// [Solution]:
int getGeohashPrefixLen(double distance) {
    vector<double> ERROR = {2500, 630, 78, 20, 2.4, 0.61, 0.076, 0.01911, 0.00478, 0.0005971, 0.0001492, 0.0000186};
    for (int len = 0; len < ERROR.size(); ++len)
        if (distance > ERROR[len])
            return len;
    return ERROR.size();
}

class MiniYelp {
public:
    MiniYelp() {
    }

    // @param name a string
    // @param location a Location
    // @return an integer, restaurant's id
    int addRestaurant(string name, Location &location) {
        Restaurant rest = Restaurant::create(name, location);
        string hashcode = GeoHash::encode(location) + "." + to_string(rest.id);
        geohashRestMap[hashcode] = rest;
        restIdGeohashMap[rest.id] = hashcode;
        return rest.id;
    }

    // @param restaurant_id an integer
    void removeRestaurant(int restaurant_id) {
        auto hashcodeIt = restIdGeohashMap.find(restaurant_id);
        if (hashcodeIt != restIdGeohashMap.end()) {
            geohashRestMap.erase(hashcodeIt->second);
            restIdGeohashMap.erase(hashcodeIt);
        }
    }

    // @param location a Location
    // @param k an integer, distance smaller than k miles
    // @return a list of restaurant's name and sort by 
    // distance from near to far.
    vector<string> neighbors(Location &location, double k) {
        string targetHash = GeoHash::encode(location);
        int len = getGeohashPrefixLen(k);
        string prefix = targetHash.substr(0, len);

        vector<RestDist> restList;
        auto stIt = geohashRestMap.lower_bound(prefix);
        for (auto it = stIt; it != geohashRestMap.end(); ++it) {
            if (it->first.substr(0, len) != prefix)
                break;

            Restaurant &rest = it->second;
            double distance = Helper::get_distance(rest.location, location);
            if (distance < k)
                restList.push_back( {distance, rest} );
        }

        sort(restList.begin(), restList.end());
        vector<string> res;
        for (RestDist &rd : restList)
            res.push_back(rd.restaurant.name);
        return res;
    }

private:
    struct RestDist {
        double distance;
        Restaurant restaurant;

        bool operator<(const RestDist &other) const {
            return distance < other.distance;
        }
    };

    map<string, Restaurant> geohashRestMap;
    unordered_map<int, string> restIdGeohashMap;
};

// [Solution]:

int main() {

    return 0;
}
