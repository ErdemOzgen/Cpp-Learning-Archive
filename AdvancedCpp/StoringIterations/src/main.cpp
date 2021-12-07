//============================================================================
// Name        : Fractal.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstdint>
#include <memory>
#include "Mandelbrot.h"
#include "Bitmap.h"

using namespace std;
using namespace caveofprogramming;

int main() {

	int const WIDTH = 800;
	int const HEIGHT = 600;

	Bitmap bitmap(WIDTH, HEIGHT);

	double min = 999999;
	double max = -999999;

	unique_ptr<int[]> histogram(new int[Mandelbrot::MAX_ITERATIONS]);
	unique_ptr<int[]> fractal(new int[WIDTH*HEIGHT]);

	// fill arrays with 0
	fill(histogram.get(), histogram.get() + Mandelbrot::MAX_ITERATIONS, 0);
	fill(fractal.get(), fractal.get() + WIDTH*HEIGHT, 0);

	for (int y = 0; y < HEIGHT; y++) {
		for (int x = 0; x < WIDTH; x++) {
			double xFractal = (x - WIDTH / 2 - 200) * 2.0 / HEIGHT;
			double yFractal = (y - HEIGHT / 2) * 2.0 / HEIGHT;

			int iterations = Mandelbrot::getIterations(xFractal, yFractal);

			fractal[y*WIDTH+x] = iterations;

			if (iterations != Mandelbrot::MAX_ITERATIONS) {
				histogram[iterations]++;
			}

			uint8_t color = (uint8_t) (256 * (double) iterations
					/ Mandelbrot::MAX_ITERATIONS);

			color = color * color * color;

			bitmap.setPixel(x, y, 0, color, 0);
			if (color < min)
				min = color;
			if (color > max)
				max = color;
		}
	}


	bitmap.write("test.bmp");

	cout << "Finished." << endl;
	return 0;
}
