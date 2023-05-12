#pragma once
#include <iostream>
#include <ctime>

namespace MatrixLibrary {
	class Matrixx{
	public:

		static double** allocate_mem(int, int);
		static double** fill_mat(int, int);
		static double** fill2_mat(double**, int, int);
		static double** sum(double**, double**, int, int, int, int);
		static double** trans(double**, int, int);
		static double** multiply(double**, double**, int, int, int, int);
		static double** scalar_mult(double**, int, int, int);
		static double det(double**, int, int);
		static double** invert(double** , int, int);
		static double** left_division(double**, double**, int, int, int, int);
		static double** right_division(double**, double**, int, int, int, int);
		static void print_mat(double**, int, int);
		static void delete_mat(double**, int, int);
	};
}
