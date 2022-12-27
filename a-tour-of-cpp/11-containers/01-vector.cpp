#include <iostream>
#include <vector>


using std::cout;
using std::string;
using std::vector;


// A class with the main purpose of holding objects is commonly called a "container".
// Providing suitable containers for a given task and supporting them with useful fundamental operations
// are important steps in the construction of any program.

// #### STL vector ####
//
// The most useful standard-library container is "vector."
//
// A vector is a sequence of elements of a given type.
// The elements are stored contiguously in memory.


class NamePhone {
private:
    string name_;
    int phone_;

public:
    NamePhone(string name_in, int phone_in) : name_{name_in}, phone_{phone_in} {};
    string name() const { return name_; }
    int phone() const { return phone_; }
};




void print(const vector<NamePhone>& phone_book) {
    int i = 0;
    for (const auto& book : phone_book)
        cout << "[" << i++ << "] = {" << book.name() << ", " << book.phone() << "}\n";
    cout << "\n";
}


int main() {
    vector<NamePhone> phone_book1 = {
            {"Maria Joaquina", 1234},
            {"Joao da Silva", 9999},
            {"Bruno Andrade", 7777}
    };
    
    
    cout << "Phone Book 1\n";
    cout << "Capacity: " << phone_book1.capacity() << "\n\n";
    for (int i = 0; i < phone_book1.size(); i++)
        cout << "[" << i << "] = {" << phone_book1[i].name() << ", " << phone_book1[i].phone() << "}\n";
    cout << "\n";
    
    
    // A vector can be copied in assignments and initializations.
    // Copying and moving of vectors are implemented by constructors and assignment operators
    // Assigning a vector involves copying its elements.
    auto phone_book2 = phone_book1;
    vector<NamePhone> phone_book3;
    phone_book3 = phone_book1;
    
    
    // push_back: adds a new element at the end of a vector, increasing its size by one.
    // The standard-library vector is implemented so that growing a vector by repeated push_back()s is efficient.
    // #### When we insert a new element, its value is copied into the container.
    //
    //
    NamePhone book_jose = {"Jose Antonio", 3333};
    
    // copies the content of book_jose into the container
    phone_book2.push_back(book_jose);
    
    // An emplace operation takes arguments for an element’s constructor and builds the object in a
    // newly allocated space in the container, rather than copying an object into the container.
    phone_book3.emplace_back("Pedro Silva", 6666);
    
    
    // phone_book1 remains intact after push_back in phone_book2 and phone_book3
    cout << "Phone Book 1\n";
    cout << "Capacity: " << phone_book1.capacity() << "\n\n";
    print(phone_book1);
    
    cout << "Phone Book 2\n";
    cout << "Capacity: " << phone_book2.capacity() << "\n\n";
    print(phone_book2);
    
    cout << "Phone Book 3\n";
    cout << "Capacity: " << phone_book3.capacity() << "\n\n";
    print(phone_book3);
    
    
    
    
    
    
    
    
    
    
    
    return 0;
}




