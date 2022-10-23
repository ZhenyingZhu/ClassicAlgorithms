/*
 * [Source] http://www.lintcode.com/en/problem/toy-factory/
 * [Difficulty]: Easy
 * [Tag]: 
 */

#include <iostream>

using namespace std;

// [Corner Case]:
// [Solution]:

// [Solution]:
class Toy {
public:
    virtual void talk() const = 0;
};

class Dog: public Toy {
    void talk() const {
        cout << "Wow" << endl;
    }
};

class Cat: public Toy {
    void talk() const {
        cout << "Meow" << endl;
    }
};

class ToyFactory {
public:
    /**
     * @param type a string
     * @return Get object of the type
     */
    Toy* getToy(string type) {
        if (type == "Dog")
            return new Dog;
        else if (type == "Cat")
            return new Cat;
        return NULL;
    }
};

int main() {
    ToyFactory tf;
    Toy *dog = tf.getToy("Dog");
    dog->talk();
    Toy *cat = tf.getToy("Cat");
    cat->talk();

    return 0;
}
