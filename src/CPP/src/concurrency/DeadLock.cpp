#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

using namespace std;

// [Source]: EPI Chapter 20.5
class Account {
public:
    Account(int id, int balance):
        id_(id), balance_(balance) { }

    static void transfer(Account &from, Account &to, int amount) {
        cout << "Put to a thread" << endl;
        thread(&Account::move, &from, ref(to), amount).detach();
    }

private:
    bool move(Account &to, int amount) {
        cout << "Transfer " << amount << " from " << id_ << " to " << to.id_ << endl;
        /* to create a dead lock
        lock_guard<recursive_mutex> lock1(mx_);
        {
            this_thread::sleep_for(chrono::seconds(1)); // create a dead lock here
            lock_guard<recursive_mutex> lock2(to.mx_);
        */

        // to solve dead lock, make sure lock in the same order use id order
        recursive_mutex &mx1 = id_ < to.id_ ? mx_ : to.mx_;
        recursive_mutex &mx2 = id_ < to.id_ ? to.mx_ : mx_;
        lock_guard<recursive_mutex> lock1(mx1);
        {
            this_thread::sleep_for(chrono::seconds(1));
            lock_guard<recursive_mutex> lock2(mx2);
            balance_ -= amount;
            to.balance_ += amount;
            cout << "Transfer complete. " << id_ << " now has " << balance_ << endl;
            return true;
        }
    }

private:
    int id_;
    int balance_;
    recursive_mutex mx_;
};

int main() {
    Account a1(1, 10);
    Account a2(2, 0);

    Account::transfer(a1, a2, 10);
    Account::transfer(a2, a1, 10);
    this_thread::sleep_for(chrono::seconds(5));

    return 0;
}
