/*
 * =====================================================================================
 *
 *       Filename:  ex_1314.cpp
 *
 *    Description:  Exercise 13.14 - Project: Polymorphic Screen Manager Using
 *                  Shape Hierarchy
 *
 *                  TODO: Move and remove shape
 *
 *        Version:  1.0
 *        Created:  19/08/16 17:35:20
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Siidney Watson - siidney.watson.work@gmail.com
 *   Organization:  LolaDog Studio
 *
 * =====================================================================================
 */
#include "Circle.hpp"
#include "Rectangle.hpp"
#include "ScreenManager.hpp"
#include "Square.hpp"
#include "Triangle.hpp"

void processMenu(int);

ScreenManager sm;

int main(int argc, const char *argv[]) {
    int choice = 0;

    while (choice != 9) {
        std::cout << "1. Add Shape"
                  << "\n2. Move Shape"
                  << "\n3. Remove Shape"
                  << "\n9. Exit"
                  << "\n> ";

        std::cin >> choice;

        if (choice != 9) {
            processMenu(choice);
            std::cout << std::endl;
            sm.render();
        }
    }

    return 0;
}
void processMenu(int choice) {
    switch (choice) {
        case 1:
            int shape, w, h, x, y;
            char f;

            std::cout << "Add Shape."
                      << "\n1. Square"
                      << "\n2. Rectangle"
                      << "\n3. Triangle"
                      << "\n4. Circle\n> ";
            std::cin >> shape;

            std::cout << "Enter width and height: ";
            std::cin >> w >> h;
            std::cout << "Enter x y location: ";
            std::cin >> x >> y;
            std::cout << "Enter a fill char: ";
            std::cin >> f;

            switch (shape) {
                case 1:
                    sm.add(new Square(w, h, x, y, f));
                    break;
                case 2:
                    sm.add(new Rectangle(w, h, x, y, f));
                    break;
                case 3:
                    sm.add(new Triangle(w, h, x, y, f));
                    break;
                case 4:
                    sm.add(new Circle(w, h, x, y, f));
                    break;
                default:
                    break;
            }
            break;
        case 2:
            std::cout << "Move Shape" << std::endl;
            break;
        case 3:
            std::cout << "Remove Shape" << std::endl;
            break;
        default:
            break;
    }
}
