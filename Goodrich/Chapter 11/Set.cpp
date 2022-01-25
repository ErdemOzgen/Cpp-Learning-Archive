/*
 * =====================================================================================
 *
 *       Filename:  Set.cpp
 *
 *    Description:  Implementing an example of a set
 *
 *        Version:  1.0
 *        Created:  January 24th, 2022
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author: Sebastian W. Tirado-Vélez   sebastianwtirado@gmail.com
 *   
 *
 * =====================================================================================
 */

#include <iostream>
#include <set> // include from standard container library
using namespace std;

int main() {

    /* Background: Sets are an abstact data type (ADT) that do not contain duplicate elements
        Sets:
            - are not indexed
            - do allow membership testing through the find / insert / remove functions
            - do allow removal of elements

        Common Application(s):
            - finding the intersecting elements between two arrays
    */

   set<int> set1; // declare the set container(s) and specify type to hold

   // insert elements using 'insert' function
   // NOTE: char or string sets require single or double quotes, respectively, when inserting elements
   set1.insert(5);
   set1.insert(14);
   set1.insert(27);
   set1.insert(3);
   set1.insert(80);
   set1.insert(5); // NOTE: repeated values will be ignored during runtime

   // alternative population of set using an array
   int someNumbers[] = {5,10,15,20,25};

   // specifying beginning and end allows for choice of certain amount of consecutive elements
   set<int> set2 (someNumbers,someNumbers+4); // ignore 25

   // delete elements using 'erase' function
   set2.erase(15);
   
   // swap the elements between two sets of the same type
   set1.swap(set2);

   // find an element in a set
   auto certainNumber = set1.find(10); // returns an iterator to the element if it exists, otherwise points to the end of the structure

   /*
        OTHER COMMON FUNCTIONS:
            - set.clear(); // which clears the content within the set
            - set.empty(); // returns a boolean on whether or not the set has no elements
   */

  // Test Output
  for(auto currentNumber: set1) {

      cout << currentNumber << + " "; // Expected Output: 5 10 20

  }

}

// see pg. 533 of Goodrich for more information