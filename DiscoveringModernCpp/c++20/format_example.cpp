// Example program for Discovering Modern C++
//
// File: format_example.cpp
// Date: 2020-02-14
// https://fmt.dev/latest/index.html

#include <iostream>
#include <fstream>
#include <cstdio>
#include <string>
#include <typeinfo>

#ifdef DMC2_WITH_FMT

#include <fmt/format.h>
#include <fmt/ostream.h>

using namespace std;

namespace dmc
{
    
void print_average(float v1, float v2, int language)
{    
    using namespace fmt;
    string formats[]= {"The average of {v1} and {v2} is {result}.\n",
                       "{result:.6f} ist der Durchschnitt von {v1} und {v2}.\n",
                       "La moyenne de {v1} et {v2} est {result}.\n",
                       "El promedio de {v1} y {v2} es {result}.\n",
                       "{result} corrisponde alla media di {v1} e {v2}.\n"};
    print (formats[language], "v1"_a= v1, "v2"_a= v2, "result"_a= (v1+v2)/2.0f);
}    

// void wprint_average(float v1, float v2, int language)
// {    
//     using namespace fmt;
//     wstring formats[]= {L"The average of {v1} and {v2} is {result}.\n",
//                        L"{result} beträgt der Durchschnitt von {v1} und {v2}.\n",
//                        L"La moyenne de {v1} et {v2} est {result}.\n",
//                        L"El promedio de {v1} y {v2} es {result}.\n",
//                        L"La media di {v1} e {v2} è {result}.\n"};
//     print (formats[language], L"v1"_a= v1, L"v2"_a= v2, L"result"_a= (v1+v2)/2.0f);
// }    



} // namespace dmc

#endif



int main()
{

#ifdef DMC2_WITH_FMT
    using namespace dmc;
    using namespace fmt;

    // Examples from cppreference
    std::printf("Integers\n");
    std::printf("Decimal:\t%i %d %.6i %i %.0i %+i %u\n", 1, 2, 3, 0, 0, 4, -1);
    std::printf("Hexadecimal:\t%x %x %X %#x\n", 5, 10, 10, 6);
    std::printf("Octal:\t\t%o %#o %#o\n", 10, 10, 4);
 
    std::printf("Floating point\n");
    std::printf("Rounding:\t%f %.0f %.22f\n", 1.5, 1.5, 1.3);
    std::printf("Padding:\t%05.2f %.2f %5.2f\n", 1.5, 1.5, 1.5);
    std::printf("Scientific:\t%E %e\n", 1.5, 1.5);
    std::printf("Hexadecimal:\t%a %A\n\n", 1.5, 1.5);

    // same with format lib
    print("Integers\n");
    // no equivalent to %u, 
    print("Decimal:\t{:d} {:d} {:06d} {:d} {:0d} {:+d} {:d}\n", 1, 2, 3, 0, 0, 4, -1);
    print("Decimal:\t{} {} {:06} {} {:0} {:+} {:d}\n", 1, 2, 3, 0, 0, 4, -1);
    print("Hexadecimal:\t{:x} {:x} {:X} {:#x}\n", 5, 10, 10, 6);
    print("Octal:\t\t{:o} {:#o} {:#o}\n", 10, 10, 4);
    print("Binary:\t\t{:b} {:#b} {:#b}\n", 10, 10, 4);
 
    print("Floating point\n");
    print("Default:\t{} {:g} {:g}\n", 1.5, 1.5, 1e20);
    print("Rounding:\t{:f} {:.0f} {:.22f}\n", 1.5, 1.5, 1.3);
    print("Padding:\t{:05.2f} {:.2f} {:5.2f}\n", 1.5, 1.5, 1.5);
    print("Scientific:\t{:E} {:e}\n", 1.5, 1.5);
    print("Hexadecimal:\t{:a} {:A}\n\n", 1.5, 1.3);
    
    double third{1.0 / 3.0};
    print("One third:\t{} {:f} {:9.4f} {:+09.4f}\n", third, third, third, third);
    
    // from tutorial, they should explain how to use it ;-)
//     fmt::memory_buffer out;
//     format_to(out, "For a moment, {} happened.", "nothing");
//     out.data(); // returns a pointer to the formatted data

    print(stderr, "System error code = {}\n", 7);
    print(std::cerr, "System error code = {}\n", 7);
    
    ofstream error_file("error_file.txt");
    print(error_file, "System error code = {}\n", 7);
    
    print("I'd rather be {1} than {0}.\n", "right", "happy");
    
    string name{"World"};
    int number{42};
    
    print("Hello, {name}! The answer is {number}. Goodbye, {name}.\n",
           arg("name", name), arg("number", number));
    
    print("Hello, {name}! The answer is {number}. Goodbye, {name}.\n",
           "name"_a=name, "number"_a=number);
    print("Hallo {name}! Die Antwort ist {number}. Auf Wiedersehen, {name}.\n",
           "name"_a=name, "number"_a=number);
    
    cout << endl;
    for (int i= 0; i < 5; ++i)
        print_average(3.5, 7.3, i);
    cout << endl;
//     for (int i= 0; i < 5; ++i)
//         wprint_average(3.5, 7.3, i);
//     cout << endl;
    
    // format("The answer is {:d}", "forty-two"); // throws format_error
    
    // static assertion failed: mixing character types is disallowed
    // fmt::format("Cyrillic letter {}", L'\x42e'); 
    
    auto cyrillic= format(L"Cyrillic letter {}\n", L'\x42e');
    cout << "Type of cyrillic is " << typeid(cyrillic).name() << endl;
    wcout << cyrillic;
    
    cout << format("{:{}}---\n", "foo", 10); // prints "foo       ---"
    printf("%*s\n", 10, "foo---");           // prints "       foo---"
    
    cout << format("{:*^30}\n", "centered"); // prints "***********centered***********"

#else    
    std::cout << "format_example: fmt library not enabled. :-(\n";
#endif

    return 0;
}
