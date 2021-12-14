#include <iostream>
#include <string>

using namespace std;


class Person 
{
public:
    static Person newPerson(string name, int age) {
        return {name, age};
    }
    void sayHello() {
        cout << "Hello, my name is " << this->name << " and I am " << this->age << " y.o." << endl;
    }
    string getName() const { return name; }
    int getAge() const { return age; }
private:
    string name;
    int age;
    Person(string name, int age)
        : name(name), age(age)
    {}
};


int main()
{
    Person diman = Person::newPerson("Zizou", 47);
    Person *str_ptr = &diman;

    //str_ptr -> sayHello();

    cout << "Hello, my name is " << str_ptr->getName() << " and I am " << str_ptr->getAge() << " y.o." << endl;

    // deallocate memory used by str_ptr in Heap memomry
    //
    delete str_ptr;

    return 0;
}

