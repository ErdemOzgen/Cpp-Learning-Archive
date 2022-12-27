#include <iostream>

#include <cstdio>

using std::cout;
using std::string;


int main() {
    string first_name1 = "Joao";
    string last_name1 = "Martins";
    string name1 = first_name1 + " " + last_name1;
    
    cout << "Name1: " << name1 << "\n";
    printf("Name1 (C-style string): %s\n\n", name1.c_str());
    
    
    string first_name2 = "Maria";
    string last_name2 = "Souza";
    string name2 = first_name2 + " " + last_name2;
    
    cout << "Name2: " << name2 << "\n\n";
    
    if (first_name1 == first_name2)
        cout << "First Names are equal\n";
    else if (first_name1 == "Joao")
        cout << "First Name is Joao\n";
    
    
    string last_name1_again = name1.substr(5, 11);
    cout << "last_name1_again = " << last_name1_again;
    
    // there are a lot of other useful functions for strings
    
    
    return 0;
}