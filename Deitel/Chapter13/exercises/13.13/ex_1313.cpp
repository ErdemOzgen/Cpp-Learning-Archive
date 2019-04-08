/*
 * =====================================================================================
 *
 *       Filename:  ex_1313.cpp
 *
 *    Description:  Exercise 13.13 - Shape Hierarchy
 *
 *        Version:  1.0
 *        Created:  17/08/16 15:09:52
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Siidney Watson - siidney.watson.work@gmail.com
 *   Organization:  LolaDog Studio
 *
 * =====================================================================================
 */
#include <iostream>
#include <typeinfo>
#include <vector>

#include "Circle.hpp"
#include "Cube.hpp"
#include "Cuboid.hpp"
#include "Rectangle.hpp"
#include "Shape.hpp"
#include "Sphere.hpp"
#include "Square.hpp"
#include "ThreeDimensionalShape.hpp"
#include "Triangle.hpp"
#include "TwoDimensionalShape.hpp"

int main(int argc, const char *argv[]) {
    // 2D shapes
    Square square(2);
    Rectangle rectangle(3, 6);
    Circle circle(10);
    Triangle triangle(15, 4);

    // 3D shapes
    Cube cube(5);
    Cuboid cuboid(5, 4, 10);
    Sphere sphere(10);

    std::vector<Shape *> shapes;

    shapes.push_back(&square);
    shapes.push_back(&rectangle);
    shapes.push_back(&circle);
    shapes.push_back(&triangle);
    shapes.push_back(&cube);
    shapes.push_back(&cuboid);
    shapes.push_back(&sphere);

    for (size_t i = 0; i < shapes.size(); ++i) {
        shapes[i]->print();

        // downcast pointer to TwoDimensionalShape
        TwoDimensionalShape *twoDimDerivedPtr =
            dynamic_cast<TwoDimensionalShape *>(shapes[i]);

        if (twoDimDerivedPtr != 0) {  // 0 if not TwoDimensionalShape
            std::cout << "\nArea: " << twoDimDerivedPtr->getArea() << std::endl;
        } else {
            // three dimensional shape print volume

            // downcast pointer to ThreeDimensionalShape
            ThreeDimensionalShape *threeDimDerivedPtr =
                dynamic_cast<ThreeDimensionalShape *>(shapes[i]);
            if (threeDimDerivedPtr != 0) {  // 0 if not ThreeDimensionalShape
                std::cout << "\nSurface Area: " << threeDimDerivedPtr->getArea()
                          << "\nVolume: " << threeDimDerivedPtr->getVolume()
                          << std::endl;
            }
        }

        std::cout << "==========" << std::endl;
    }

    return 0;
}
