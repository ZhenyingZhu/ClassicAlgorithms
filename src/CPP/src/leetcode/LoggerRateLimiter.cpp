/*
 * [Source] https://leetcode.com/problems/logger-rate-limiter/
 * [Difficulty]: Easy
 * [Tag]: Hash Table
 * [Tag]: Design
 */

#include <iostream>
#include <list>

using namespace std;

// [Solution]:
// [Corner Case]:
class Logger {
public:
    struct MessageTime {
        int timestamp;
        string message;
    };

    Logger() {
    }

    /** Returns true if the message should be printed in the given timestamp, otherwise returns false.
        If this method returns false, the message will not be printed.
        The timestamp is in seconds granularity. */
    bool shouldPrintMessage(int timestamp, string message) {
        int oldTimestamp = timestamp - 10;
        while (!messageList.empty() && messageList.front().timestamp <= oldTimestamp) {
            messageList.pop_front();
        }

        for (auto it = messageList.begin(); it != messageList.end(); ++it) {
            if (it->message == message)
                return false;
        }

        messageList.push_back( {timestamp, message} );
        return true;
    }

    list<MessageTime> messageList;
};

class Solution {
public:
    void test() {
        Logger logger;
        cout << logger.shouldPrintMessage(1, "foo") << endl;
        cout << logger.shouldPrintMessage(2, "bar") << endl;
        cout << logger.shouldPrintMessage(3, "foo") << endl;
        cout << logger.shouldPrintMessage(8, "bar") << endl;
        cout << logger.shouldPrintMessage(10, "foo") << endl;
        cout << logger.shouldPrintMessage(11, "foo") << endl;
    }
};

// [Solution]: Only store the timestamp when the message can print again

int main() {
    Solution sol;
    sol.test();

    return 0;
}
