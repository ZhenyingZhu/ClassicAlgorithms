#include "AddCredits.hpp"

#include <string>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <stdexcept>
#include <cassert>

using std::string;
using std::map;
using std::unordered_map;
using std::unordered_set;
using std::cout;
using std::endl;

namespace epi {
  namespace chapter15 {
    class AddCredits::ClientsCreditsInfo {
    public:
        bool remove(const string &clientId);

        void insert(const string &clientId, int credit);

        int lookup(const string &clientId) const;

        void increaseCreditsForAll(int c);

        string maxCreditClient() const;

    private:
        int offset_ = 0;
        map<int, unordered_set<string>> creditClients_;
        unordered_map<string, int> clientCredit_;

    };

    bool AddCredits::ClientsCreditsInfo::remove(const string &clientId) {
        unordered_map<string, int>::const_iterator iter = clientCredit_.find(clientId);
        if (iter == clientCredit_.end())
            return false;

        int credit = iter->second;
        unordered_set<string> &clients = creditClients_[credit];
        clients.erase(clientId);
        if (clients.empty())
            creditClients_.erase(credit);

        clientCredit_.erase(iter);
        return true;
    }

    void AddCredits::ClientsCreditsInfo::insert(const string &clientId, int credit) {
        assert(credit >= 0);

        remove(clientId);

        int c = credit - offset_;

        clientCredit_.emplace(clientId, c);

        creditClients_[c].emplace(clientId);
    }

    int AddCredits::ClientsCreditsInfo::lookup(const string &clientId) const {
        unordered_map<string, int>::const_iterator iter = clientCredit_.find(clientId);
        if (iter == clientCredit_.end())
            return -1;

        return iter->second + offset_;
    }

    void AddCredits::ClientsCreditsInfo::increaseCreditsForAll(int c) {
        offset_ += c;
    }

    string AddCredits::ClientsCreditsInfo::maxCreditClient() const {
        if (creditClients_.empty())
            return "";

        map<int, unordered_set<string>>::const_reverse_iterator maxIter = creditClients_.crbegin();
        return *(maxIter->second.cbegin());
    }

    bool AddCredits::test() {
        ClientsCreditsInfo cci;
        cci.insert("a", 1);
        cci.insert("b", 2);
        cci.insert("c", 3);

        int aCredit = cci.lookup("a");
        if (aCredit != 1) {
            cout << "a credit " << aCredit << endl;
            return false;
        }

        string maxClient = cci.maxCreditClient();
        if (maxClient != "c") {
            cout << "max client " << maxClient << endl;
            return false;
        }

        cci.increaseCreditsForAll(2);
        int bCredit = cci.lookup("b");
        if (bCredit != 4) {
            cout << "b credit " << bCredit << endl;
            return false;
        }

        cci.insert("d", 4);
        int dCredit = cci.lookup("d");
        if (dCredit != 4) {
            cout << "d credit " << dCredit << endl;
            return false;
        }

        cci.insert("a", 1);
        aCredit = cci.lookup("a");
        if (aCredit != 1) {
            cout << "a credit " << aCredit << endl;
            return false;
        }

        cci.remove("d");
        dCredit = cci.lookup("d");
        if (dCredit != -1) {
            cout << "d credit " << dCredit << endl;
            return false;
        }

        return true;
    }

  } // chapter15
} // epi
