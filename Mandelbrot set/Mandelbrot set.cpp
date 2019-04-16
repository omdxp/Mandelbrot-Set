// Mandelbrot set.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <fstream>
#include <complex>

using namespace std;
int value(int x, int y);
// Image dimension
constexpr float width = 600;
constexpr float height = 600;

int main()
{
	ofstream image("mandelbrot.ppm");
	if (image.is_open()) {
		image << "P3\n" << width << " " << height << " 255\n";
		for (int i = 0; i < width; i++) {
			for (int j = 0; j < height; j++) {
				int val = value(i, j);
				image << val << ' ' << 0 << ' ' << 0 << "\n";
			}
		}
		image.close();
	}
	else cout << "Could not open file";
	return EXIT_SUCCESS;
}

int value(int x, int y) {
	complex<float> point((float)x / width - 1.5, (float)y / height - 0.5);
	// we divide by the image dimensions to get values smaller than 1 then apply a translation
	complex<float> z(0, 0);
	unsigned int nb_iter = 0;
	while (abs(z) < 2 && nb_iter <= 42) { // Answer of everything
		z = z * z + point;
		nb_iter++;
	}
	if (nb_iter < 42) return (255 * nb_iter) / 42; // Some sort of gradient color
	else return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
