/*
 * =====================================================================================
 *
 *       Filename:  TwoDimensionalShape.cpp
 *
 *    Description:  Exercie 13.13 - Shape Hierarchy
 *
 *        Version:  1.0
 *        Created:  17/08/16 14:28:11
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Siidney Watson - siidney.watson.work@gmail.com
 *   Organization:  LolaDog Studio
 *
 * =====================================================================================
 */
#include "TwoDimensionalShape.hpp"

TwoDimensionalShape::TwoDimensionalShape(int w, int h, int x, int y, char f)
    : Shape(w, h, x, y), fillchar(f) {}
TwoDimensionalShape::~TwoDimensionalShape() {
    if (img != nullptr) { delete img; }
}
