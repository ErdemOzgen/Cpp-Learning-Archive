#include <iostream>
#include <vector>

using std::cout;
using std::string;
using std::vector;



class NamePhone {
private:
    string name_;
    int phone_;

public:
    NamePhone(string name_in, int phone_in) : name_{name_in}, phone_{phone_in} {};
    string name() const { return name_; }
    int phone() const { return phone_; }
};


// We can use std::sort to sort our own Classes.
// For this, we must define the operations less than (<), greater than (<), and equal (==)
//
// We must define these functions out of the Class, because std::sort expects these functions with
// two arguments.
// When defining these functions inside the class, they only have one parameter and this is not work.
bool operator<(const NamePhone& x, const NamePhone& y) {// less than
    return x.name() < y.name(); // order NamePhones by their names
}

bool operator==(const NamePhone& x, const NamePhone& y) {// less than
    return x.name() == y.name(); // order NamePhones by their names
}

bool operator>(const NamePhone& x, const NamePhone& y) {// less than
    return x.name() > y.name(); // order NamePhones by their names
}



void print(const vector<NamePhone>& phone_book) {
    int i = 0;
    for (const auto& book : phone_book)
        cout << "[" << i++ << "] = {" << book.name() << ", " << book.phone() << "}\n";
    cout << "\n";
}



int main() {
    vector<NamePhone> phone_book = {
            {"Maria Joaquina", 1234},
            {"Carla da Silva", 5677},
            {"Joao da Silva", 9999},
            {"Bruno Andrade", 7777}
    };
    
    cout << "phone book\n";
    print(phone_book);
    cout << "\n";
    
    cout << "ascending book\n";
    std::sort(phone_book.begin(), phone_book.end());
    print(phone_book);
    cout << "\n";
    
    cout << "descending book\n";
    std::sort(phone_book.begin(), phone_book.end(), std::greater<>());
    print(phone_book);
    cout << "\n";
    
    
    return 0;
}