/*
 * [Source] http://www.lintcode.com/en/problem/
 * [Difficulty]: 
 * [Tag]: 
 */

#include <iostream>
#include <vector>

using namespace std;

// [Corner Case]:
// [Solution]:

// enum type for Vehicle
enum class VehicleSize {
    Motorcycle,
    Compact,
    Large
};

class ParkingSpot {
public:
    ParkingSpot(VehicleSize s): size(s), vehicleName(""), available(true) { }
    VehicleSize size;
    string vehicleName;
    bool available;
};

class Row {
public:
    Row(int spotsNum) {
        int i = 0;
        for (; i < spotsNum / 4; ++i)
            spots.push_back(ParkingSpot(VehicleSize::Motorcycle));
        for (; i < spotsNum / 4 * 3; ++i)
            spots.push_back(ParkingSpot(VehicleSize::Compact));
        for (; i < spotsNum; ++i)
            spots.push_back(ParkingSpot(VehicleSize::Large));
    }
    vector<ParkingSpot> spots;
};

class Vehicle {
public:
    virtual bool park(Row&) = 0;
    void unpark() {
        if (parkedRow == NULL)
            return;
        vector<ParkingSpot> &spots = parkedRow->spots;
        for (ParkingSpot &spot : spots) {
            if (spot.vehicleName == name) {
                spot.available = true;
                spot.vehicleName = "";
            }
        }
    }
    string name;
    Row *parkedRow;
};

class Bus: public Vehicle {
public:
    Bus(string n) {
        name = n;
        parkedRow = NULL;
    }

    bool park(Row &row) {
        vector<ParkingSpot> &spots = row.spots;
        int cont = 0;
        for (int i = 0; i  < (int)spots.size(); ++i) {
cout << "spot available " << spots[i].available << " size " << (spots[i].size == VehicleSize::Large) << endl;
            if (spots[i].size == VehicleSize::Large && spots[i].available) {
                ++cont;
cout << "cont " << cont << endl;
                if (cont == 5) {
                    for (int p = i - 4; p <= i; ++p) {
                        spots[p].available = false;
                        spots[p].vehicleName = name;
                    }

                    parkedRow = &row;
                    return true;
                }
            } else {
                cont = 0;
            }
        }
        return false;
    }
};

class Car: public Vehicle {
public:
    Car(string n) {
        name = n;
        parkedRow = NULL;
    }

    bool park(Row &row) {
        vector<ParkingSpot> &spots = row.spots;
        for (ParkingSpot &spot : spots) {
cout << "spot available " << spot.available << endl;
            if (spot.available && (spot.size == VehicleSize::Compact || spot.size == VehicleSize::Large)) {
                spot.available = false;
                spot.vehicleName = name;
                parkedRow = &row;
                return true;
            }
        }
        return false;
    }
};

class Motorcycle: public Vehicle {
public:
    Motorcycle(string n) {
        name = n;
        parkedRow = NULL;
    }

    bool park(Row &row) {
        vector<ParkingSpot> &spots = row.spots;
        for (ParkingSpot &spot : spots) {
cout << "spot available " << spot.available << endl;
            if (spot.available && (spot.size == VehicleSize::Motorcycle || spot.size == VehicleSize::Compact || spot.size == VehicleSize::Large)) {
                spot.available = false;
                spot.vehicleName = name;
                parkedRow = &row;
                return true;
            }
        }
        return false;
    }
};

class Level {
public:
    Level(int rowNum, int spotsNum) {
        for (int i = 0; i < rowNum; ++i) {
            rows.push_back(Row(spotsNum));
        }
    }

    bool park(Vehicle &v) {
        for (int i = 0; i < (int)rows.size(); ++i) {
            if (v.park(rows[i]))
                return true;
        }
        return false;
    }

    vector<Row> rows;
};

class ParkingLot {
public:
    // @param n number of leves
    // @param num_rows  each level has num_rows rows of spots
    // @param spots_per_row each row has spots_per_row spots
    ParkingLot(int n, int num_rows, int spots_per_row) {
        for (int i = 0; i < n; ++i) {
            levels.push_back(Level(num_rows, spots_per_row));
        }
    }

    // Park the vehicle in a spot (or multiple spots)
    // Return false if failed
    bool parkVehicle(Vehicle &vehicle) {
        for (Level &level : levels) {
            if (level.park(vehicle))
                return true;
        }
        return false;
    }

    // unPark the vehicle
    void unParkVehicle(Vehicle &vehicle) {
        vehicle.unpark();
    }

    vector<Level> levels;
};

int main() {
    ParkingLot pl(1, 1, 11);
    Motorcycle m1("Motorcycle_1");
    cout << pl.parkVehicle(m1) << endl;
    Car c1("Car_1");
    cout << pl.parkVehicle(c1) << endl;
    Car c2("Car_2");
    cout << pl.parkVehicle(c2) << endl;
    Car c3("Car_3");
    cout << pl.parkVehicle(c3) << endl;
    Car c4("Car_4");
    cout << pl.parkVehicle(c4) << endl;
    Car c5("Car_5");
    cout << pl.parkVehicle(c5) << endl;
    Bus b1("Bus_1");
    cout << pl.parkVehicle(b1) << endl;
    pl.unParkVehicle(c5);
    cout << pl.parkVehicle(b1) << endl;

    return 0;
}
