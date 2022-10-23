#include <iostream>
#include <set>
#include <map>
#include <list>

using namespace std;

// [Source]: http://www.1point3acres.com/bbs/thread-225703-1-1.html
// http://www.1point3acres.com/bbs/thread-229745-1-1.html

class PriceSystem {
public:
    void priceUpdate(int timestamp, double price) {
        if (timePriceMap.count(timestamp))
            return; // already exist

        auto mapIt = timePriceMap.upper_bound(timestamp);
        if (mapIt == timePriceMap.end()) {
            timeline.push_back(price);
            timePriceMap[timestamp] = --timeline.end();
            prices.insert(price);
        } else {
            auto listIt = mapIt->second;
            timeline.insert(listIt, price);
            timePriceMap[timestamp] = --listIt;
            prices.insert(price);
        }
    }

    void correction(int timestamp, double newPrice) {
        if (!timePriceMap.count(timestamp)) {
            priceUpdate(timestamp, newPrice);
            return;
        }

        list<double>::iterator listIt = timePriceMap[timestamp];
        double oldPrice = *listIt;
        prices.erase(prices.find(oldPrice));

        *listIt = newPrice;
        prices.insert(newPrice);
    }

    bool remove(int timestamp) {
        if (!timePriceMap.count(timestamp)) {
            return false;
        }

        list<double>::iterator listIt = timePriceMap[timestamp];
        double oldPrice = *listIt;
        prices.erase(prices.find(oldPrice));
        timePriceMap.erase(timestamp);
        timeline.erase(listIt);
        return true;
    }

    double getLow() {
        if (timeline.empty())
            return -1.0;

        return *prices.begin();
    }

    double getHigh() {
        if (timeline.empty())
            return -1.0;

        return *(--prices.end());
    }

    double getLast() {
        if (timeline.empty())
            return -1.0;

        return timeline.back();
    }

    void display() {
        for (auto it = timeline.begin(); it != timeline.end(); ++it)
            cout << *it << "->";
        cout << endl;
    }

private:
    list<double> timeline;
    map<int, list<double>::iterator> timePriceMap;
    multiset<double> prices;
};

int main() {
    PriceSystem ps;
    ps.priceUpdate(10100,850.50); ps.display(); cout << ps.getHigh() << " " << ps.getLow() << " " << ps.getLast() << endl;
    ps.priceUpdate(10200,852.25); ps.display(); cout << ps.getHigh() << " " << ps.getLow() << " " << ps.getLast() << endl;
    ps.priceUpdate(10300,848.00); ps.display(); cout << ps.getHigh() << " " << ps.getLow() << " " << ps.getLast() << endl;
    ps.correction(10200, 849.00); ps.display(); cout << ps.getHigh() << " " << ps.getLow() << " " << ps.getLast() << endl;
    ps.priceUpdate(10400,855.00); ps.display(); cout << ps.getHigh() << " " << ps.getLow() << " " << ps.getLast() << endl;
    ps.correction(10300, 853.00); ps.display(); cout << ps.getHigh() << " " << ps.getLow() << " " << ps.getLast() << endl;
    ps.priceUpdate(10500,854.00); ps.display(); cout << ps.getHigh() << " " << ps.getLow() << " " << ps.getLast() << endl;
    ps.correction(10500,853.25); ps.display(); cout << ps.getHigh() << " " << ps.getLow() << " " << ps.getLast() << endl;
    ps.remove(10300); ps.display(); cout << ps.getHigh() << " " << ps.getLow() << " " << ps.getLast() << endl;


    return 0;
}
