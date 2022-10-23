/*
 * [Source] http://www.lintcode.com/en/problem/mini-uber/
 * [Difficulty]: Medium
 * [Tag]: 
 */

#include <iostream>
#include <cfloat>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Trip {
public:
    int id; // trip's id, primary key
    int driver_id, rider_id; // foreign key
    double lat, lng; // pick up location
    Trip(int rider, double lat, double lng):
    rider_id(rider) {
        this->lat = lat;
        this->lng = lng;
        id = 0; // doesn't matter
        driver_id = 0; // doesn't matter
    }
};

class Helper {
public:
    static double  get_distance(double lat1, double lng1,
            double lat2, double lng2) {
        // return the square of distance between (lat1, lng1) and (lat2, lng2)
        return (lat1 - lat2) * (lat1 - lat2) + (lng1 * lng2) * (lng1 * lng2);
    }
};

// [Corner Case]:
// [Solution]:
struct Location {
    Location() {
        lat = 0.0;
        lng = 0.0;
    }

    Location(double latitude, double longitude):
        lat(latitude), lng(longitude) {}

    double lat, lng;
};

class MiniUber {
public:
    MiniUber() {
    }

    // @param driver_id an integer
    // @param lat, lng driver's location
    // return matched trip information if there have matched rider or NULL
    Trip* report(int driver_id, double lat, double lng) {
        if (driverTrip.count(driver_id))
            return driverTrip[driver_id];

        driverLoc[driver_id] = Location(lat, lng);
        return NULL;
    }

    // @param rider_id an integer
    // @param lat, lng rider's location
    // return a trip
    Trip* request(int rider_id, double lat, double lng) {
        int driver_id = 0;
        double minDis = DBL_MAX;
        for (auto it = driverLoc.begin(); it != driverLoc.end(); ++it) {
            int driver = it->first;
            if (driverTrip.count(driver))
                continue;

            Location &loc = it->second;
            double distance = Helper::get_distance(lat, lng, loc.lat, loc.lng);
            if (distance < minDis) {
                driver_id = driver;
                minDis = distance;
            }
        }

        Trip *trip = new Trip(rider_id, lat, lng);
        trip->driver_id = driver_id;
        driverTrip[driver_id] = trip;
        return trip;
    }

private:
    unordered_map<int, Location> driverLoc;
    unordered_map<int, Trip*> driverTrip; // use pointer because trip is access outside the class
};


// [Solution]:

int main() {
    MiniUber mu;

    mu.report(1, 36.1344, 77.5672);
    mu.report(2, 45.1344, 76.5672);
    mu.request(2, 39.1344, 76.5672);
    mu.report(1, 38.1344, 75.5672);
    mu.report(2, 45.1344, 76.5672);

    return 0;
}
