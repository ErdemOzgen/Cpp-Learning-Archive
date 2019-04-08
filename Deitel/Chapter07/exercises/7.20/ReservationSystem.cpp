/*
 * =====================================================================================
 *
 *       Filename:  
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Thanks to github you know it
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author: Mahmut Erdem ÖZGEN   m.erdemozgen@gmail.com
 *   
 *
 * =====================================================================================
 */
#include "ReservationSystem.hpp"

ReservationSystem::ReservationSystem() : _availability(Availability::BOTH) {}
// entry point
void ReservationSystem::go() {
    while (_availability != Availability::FULL) {
        printMenu();
        checkCapacity();

        //        printSeatingPlan();
    }

    std::cout << "\n*** PLANE'S FULL ***" << std::endl;
}
// prints the menu of choices
void ReservationSystem::printMenu() {
    int choice = 0;
    int bookedSeat;

    std::cout << "\nPlease type 0 for First Class"
              << ((_availability == Availability::SECOND) ? " (full)\n" : "\n")
              << "Please type 1 for Second Class"
              << ((_availability == Availability::FIRST) ? " (full)\n> " : "\n> ");

    std::cin >> choice;

    if (((choice == 0 || choice == 1) &&
         (_availability == Availability::BOTH)) ||
        ((choice == 0) && (_availability == Availability::FIRST)) ||
        ((choice == 1) && (_availability == Availability::SECOND))) {
        bookedSeat = bookSeat(choice);

        // set successfully booked
        if (bookedSeat > -1) { printBoardingPass(bookedSeat); }

        // prevent incorrect values triggering this
    } else if (choice == 0 || choice == 1) {
        char change;

        std::cout << "\n\n ************\n"
                  << "\n"
                  << ((choice == 0) ? "First" : "Second") << " class is full."
                  << "\nWould you like a seat in "
                  << ((choice == 0) ? "Second" : "First") << " class? ";
        std::cin >> change;

        if (change == 'y') {
            choice = 1 - choice;

            bookedSeat = bookSeat(choice);

            printBoardingPass(bookedSeat);
        } else {
            std::cout << "\n\n ***********\n"
                      << "Next Plane Leaves in 3 Hours." << std::endl;
        }
    }
}
// print the seating plan (available/unavailable seats)
void ReservationSystem::printSeatingPlan() {
    for (int i = 0; i < capacity; ++i) {
        std::cout << _plane[i] << std::endl;
    }
}
// check if a seat is available
// return inverse of _plane[seat] as available seats stored as false
bool ReservationSystem::isSeatAvailable(int seat) { return !_plane[seat]; }
// books a seat -returns the booked seat
int ReservationSystem::bookSeat(int cl) {
    // set search limit based upon class
    int seatClass = (cl == 0) ? 5 : 10;

    // check individual seat and assign or not
    for (int seat = ((cl == 0) ? 1 : 6); seat <= seatClass; ++seat) {
        if (isSeatAvailable(seat)) {
            _plane[seat] = !_plane[seat];

            // set availability based upon seatClass limits
            if (seat == 5) { _availability = Availability::SECOND; }

            if (seat == 10) { _availability = Availability::FIRST; }

            return seat;
        }
    }
    return -1;
}
// check plane for empty seats
// sets _availability to full if none found
void ReservationSystem::checkCapacity() {
    for (int seat = 1; seat < capacity; ++seat) {
        if (isSeatAvailable(seat)) { return; }
    }
    _availability = Availability::FULL;
}
// prints the boarding pass on successful booking
void ReservationSystem::printBoardingPass(int seat) {
    std::cout << "\n *** BOARDING PASS ***\n\n"
              << "\nSeat Number: " << seat
              << "\nClass: " << ((seat <= 5) ? "First" : "Second") << " class\n"
              << "\n\n ********************\n"
              << std::endl;
}
