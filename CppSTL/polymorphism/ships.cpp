/*
 *  Author              : Dimos Kacimardos
 *  Date                : 2/23/2020
 *  Project Difficulty  : Minor
 * 
*/

#include <iostream>
#include <string>

using namespace std;

/////////////////////////////////////////////////////////////////////////////////////////////////////
// make coordinate of type 'int', just for brevity (qoc)
//
typedef int coordinate;
/////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////
// A class for a Point of an Area
// Every Point has next fields/information
/////////////////////////////////////////////////////////////////////////////////////////////////////
class Point {
public:
    /* explicit */ 
    Point(coordinate latitude, coordinate longtitude,
                   int weatherIntensity, bool isPort, 
                   bool hasTreasure)
        : latitude(latitude), longtitude(longtitude) , weatherIntensity(weatherIntensity), 
          isPort(isPort), hasTreasure(hasTreasure) 
    {}
    coordinate getLatitude() const { return latitude; }
    coordinate getLongtitude() const { return longtitude; }
    friend ostream& operator<<(ostream & os, const Point & p) {
        os << "***********************************************************************************\n";
        os << "This Area is at Coordinates: (" << p.latitude << ", " << p.longtitude << ")\n"
           << "Has Wather condition index: " << p.weatherIntensity << endl
           << (p.isPort ? "Is a Port\n" : "Is NOT a Port\n")
           << (p.hasTreasure ? "Has Treasure\n" : "Has NOT Treasure\n")
           << "***********************************************************************************\n";
        return os;
    }
private:
    // the Coordinates of every Point --> for the respective Ship
    coordinate latitude, longtitude;
    // [1-10] : How bad weather conditions this Point in our map has 
    int weatherIntensity;
    // Is this Point a Port or NOT
    bool isPort;
    // Has this Point treasure or NOT
    bool hasTreasure;
};

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Interface class for a Ship ~ You shall not instantiate such an object | Compiler error otherwise
// This is essentially an abstract class
/////////////////////////////////////////////////////////////////////////////////////////////////////
class Ship {
public:    
    enum class MoveType {
        FRIENDLY,   // 0
        HOSTILE,    // 1
        NEUTRAL     // 2
    };
    // every abstract class (interface) should have a default constructor
    virtual ~Ship() = default;
    void move(const Point & to) const {
        cout << "Ship is moving ... ";
    };
    virtual void mode(const MoveType &) = 0;
protected:
    // Every ship has current stamina and max stamina, speed, is near to a Port, and has or not treasure
    int currentStamina;
    int maxStamina = 1000;
    int speed;
    bool isPort;
    bool hasTreasure;
};

// Piratic Ship is of type Ship
//
class Piratic : public Ship {
public:
    Piratic(const Point & position, int power)
        : position(position), power(power)
    {}
    void move(const Point & to) const {
        Ship::move(to);
        cout << " from Point (" << position.getLatitude() << ", " << position.getLongtitude() << ") ... "
             << "to Point (" << to.getLatitude() << ", " << to.getLongtitude() << "). \n";
    }
    void mode(const MoveType & action) override {
        switch(action) {
            case Ship::MoveType::FRIENDLY:
                cout << "This Piratic ship is a friendly one ...\n";
                break;
            case Ship::MoveType::HOSTILE:
                cout << "This Piratic ship is a Hostile one ... Inntension to attack ... \n";
                break;
            case Ship::MoveType::NEUTRAL:
                cout << "No attack is scheduled for now ... Neutral Piratic Ship ...\n";
                break;
            default:
                cout << "ERROR?\n";
                break;
        }
    }
private:
    // Every Piratic ship has a Position (of type Point) inside the World
    Point position;
    int power;
};



/* #########  */
/*   main    */
/* ######## */
int main() {

    //cout << "Project dapost playing with c++ for fun ... [ Start ]\n";
    Point patra(2, 3, 1, false, false);
    cout << patra << endl;

    Piratic piratiko(patra, 7);
    piratiko.move(Point(5, 6, 5, true, false));
    piratiko.mode(Ship::MoveType::HOSTILE);

    return 0;
}