#include "GroupByAge.hpp"

#include <vector>
#include <string>
#include <utility>
#include <unordered_map>
#include <iostream>
#include <ostream>
#include <stdexcept>
#include <cassert>

using std::vector;
using std::string;
using std::swap;
using std::unordered_map;
using std::cout;
using std::endl;
using std::ostream;

namespace epi {
  namespace chapter14 {
    struct GroupByAge::Person {
        string name;
        unsigned age;
    };

    ostream& operator<<(ostream &os, const GroupByAge::Person &person) {
        os << "(" << person.name << " " << person.age << ")";

        return os;
    }

    void GroupByAge::groupByAge(vector<Person> &persons) {
        if (persons.size() <= 2)
            return;

        unordered_map<unsigned, size_t> ageCnt;
        for (const Person &person : persons) {
            ++ageCnt[person.age];
        }

        size_t offset = 0;
        unordered_map<unsigned, size_t> ageOffset;
        for (const auto &pair : ageCnt) {
            ageOffset[pair.first] = offset;
            offset += pair.second;
        }

        while (!ageOffset.empty()) {
            // This position is the next of the end of the bucket. Need swap this person1 to right place
            auto fromPair = ageOffset.begin();
            Person &curPositionPerson = persons[fromPair->second];

            // This is the right place with person2, place the person1 to here
            auto toPair = ageOffset.find(curPositionPerson.age);
            Person &rightPositionPerson = persons[toPair->second];

            swap(curPositionPerson, rightPositionPerson);

            // so person1 bucket has one right entry
            --ageCnt[curPositionPerson.age];
            if (ageCnt[curPositionPerson.age] == 0)
                ageOffset.erase(curPositionPerson.age);
            else
                ++ageOffset[curPositionPerson.age];
        }
    }

    bool GroupByAge::test() {
        vector<Person> persons = {
                Person{"Greg",14}, Person{"John",12}, Person{"Andy",11}, Person{"Jim",13},
                Person{"Phil",12}, Person{"Bob",13}, Person{"Chip",13}, Person{"Tim",14}
        };

        groupByAge(persons);

        for (Person person : persons) {
            cout << person << endl;
        }

        return true;
    }

  } // chapter14
} // epi
