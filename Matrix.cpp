// Matrix.cpp : Определяет функции для статической библиотеки.
#include <cmath>
#include "Matrix.h"

double** MatrixLibrary::Matrixx::allocate_mem(int row, int column) {
	//отводит память в оперативке для массива
	double** arr = new double* [row];
	for (int n = 0; n < row; n++) {
		arr[n] = new double[column];
	}
	return arr;
}

double** MatrixLibrary::Matrixx::fill_mat(int row, int column) {
	//отводит память и заполняет рандомными числами массив
	double** arr = allocate_mem(row, column);
	for (int n = 0; n < row; n++) {
		for (int m = 0; m < column; m++) {
			arr[n][m] = rand() % 100;
		}
	}
	return arr;
}

double** MatrixLibrary::Matrixx::fill2_mat(double** arr, int row, int column) {

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			std::cin >> arr[i][j];
		}
	}
	return arr;
}

double** MatrixLibrary::Matrixx::sum(double** arr1, double** arr2, int row1, int column1, int row2, int column2){
	//сложение двух матриц
	if (row1 == row2 and column1 == column2) {
		double** res = allocate_mem(row1, column1);
		for (int n = 0; n < row1; n++) {
			for (int m = 0; m < column1; m++) {
				res[n][m] = arr1[n][m] + arr2[n][m];//ну здесь просто складываем поэлементно
			}
		}
		return res;
		delete_mat(res, row1, column1);
	}
	else {
		double** res = allocate_mem(1,1);
		res[0][0] = -666;
		return res;
	}
}

double** MatrixLibrary::Matrixx::trans(double** arr, int i, int j) {
	double** tarr = allocate_mem(j, i);
	for (int n = 0; n < j; n++) {
		for (int m = 0; m < i; m++) {
			tarr[n][m] = arr[m][n];//здесь транспонирует
		}
	}
	return tarr;
}

double** MatrixLibrary::Matrixx::multiply(double** arr1, double** arr2, int row1, int column1, int row2, int column2) {
	if (column1 == row2) {
		double** res = allocate_mem(row1, column2);
		for (int n = 0; n < row1; n++) {
			for (int m = 0; m < column2; m++) {
				res[n][m] = 0;
				for (int inner = 0; inner < row2; inner++) {
					res[n][m] += arr1[n][inner] * arr2[inner][m];
				}
			}
		}
		return res;
		delete_mat(res, row1, column2);
	}
	else {
		double** res = allocate_mem(1, 1);
		res[0][0] = -666;
		return res;
	}
}

double** MatrixLibrary::Matrixx::scalar_mult(double** arr, int row, int column, int a) {
	double** res = allocate_mem(row, column);
	for (int n = 0; n < row; n++)
		for (int m = 0; m < column; m++) {
			res[n][m] = a*arr[n][m];
		}
	return res;
	delete_mat(res, row, column);
}

double MatrixLibrary::Matrixx::det(double** arr, int row, int column) {
	if (row == column) {
		if (row == 1) return arr[0][0];
		else if (row == 2) return arr[0][0] * arr[1][1] - arr[0][1] * arr[1][0];
		else if (row >= 3) {
			double** narr = allocate_mem(row - 1, row - 1);
			double det = 0;
			int a, b;

			for (int j = 0; j < row; j++) {
				a = 0;
				for (int k = 1; k < row; k++) {
					b = 0;
					for (int s = 0; s < row; s++) {
						if (s != j) {
							narr[a][b] = arr[k][s];
							b++;
						}
					}
					a++;
				}
				det += pow(-1, j + 2) * arr[0][j] * MatrixLibrary::Matrixx::det(narr, row - 1, column - 1);
			}
			return det;
			delete_mat(narr, row - 1, row - 1);
		}
	}
	else return -666;

}

double** MatrixLibrary::Matrixx::invert(double** arr, int row, int column){

	double det1 = det(arr, row, column);
	if (det1 != 0 && row == column) {
		double temp;
		double** res = allocate_mem(row, row);
		for (int i = 0; i < row; i++)
			for (int j = 0; j < row; j++)
				res[i][j] = arr[i][j];

		double** narr = allocate_mem(row, row);

		for (int i = 0; i < row; i++)
			for (int j = 0; j < row; j++) {
				narr[i][j] = 0.0;
				if (i == j)
					narr[i][j] = 1.0;
			}

		for (int k = 0; k < row; k++) {
			temp = res[k][k];
			for (int j = 0; j < row; j++) {
				res[k][j] /= temp;
				narr[k][j] /= temp;
			}
			for (int i = k + 1; i < row; i++) {
				temp = res[i][k];
				for (int j = 0; j < row; j++) {
					res[i][j] -= res[k][j] * temp;
					narr[i][j] -= narr[k][j] * temp;
				}
			}
		}

		for (int k = row - 1; k > 0; k--) {
			for (int i = k - 1; i >= 0; i--) {
				temp = res[i][k];
				for (int j = 0; j < row; j++) {
					res[i][j] -= res[k][j] * temp;
					narr[i][j] -= narr[k][j] * temp;
				}
			}
		}

		for (int i = 0; i < row; i++)
			for (int j = 0; j < row; j++)
				res[i][j] = narr[i][j];

		return res;

		delete_mat(res, row, row);
		delete_mat(narr, row, row);
	}
	else {
		double** res = allocate_mem(1, 1);
		res[0][0] = -666;
		return res;
	}
}

double** MatrixLibrary::Matrixx::left_division(double** arr1, double** arr2, int row1, int column1, int row2, int column2) {


	double** narr1 = invert(arr1, row1, column1);
	//double** res = multiply(narr1, arr2, row1, column1, row2, column2);
	if (column1 == row2 && row1 == column1) {
		double** res = allocate_mem(row1, column2);
		for (int n = 0; n < row1; n++) {
			for (int m = 0; m < column2; m++) {
				res[n][m] = 0;
				for (int inner = 0; inner < row2; inner++) {
					res[n][m] += narr1[n][inner] * arr2[inner][m];
				}
			}
		}
		return res;
		delete_mat(res, row1, column2);
	}
	else {
		double** res = allocate_mem(1, 1);
		res[0][0] = -666;
		return res;
	}
	//return res;


}

double** MatrixLibrary::Matrixx::right_division(double** arr1, double** arr2, int row1, int column1, int row2, int column2) {

	double** narr2 = invert(arr2, row2, column2);
	//double** res = allocate_mem(row1, column2);
	if (column1 == row2 && row2==column2) {
		double** res = allocate_mem(row1, column2);
		for (int n = 0; n < row1; n++) {
			for (int m = 0; m < column2; m++) {
				res[n][m] = 0;
				for (int inner = 0; inner < row2; inner++) {
					res[n][m] += arr1[n][inner] * narr2[inner][m];
				}
			}
		}
		return res;
		delete_mat(res, row1, column2);
	}
	else {
		double** res = allocate_mem(1, 1);
		res[0][0] = -666;
		return res;
	}
	//return res;


}

void MatrixLibrary::Matrixx::print_mat(double** arr, int row, int column){
	for (int i = 0; i < row; i++){
		for (int j = 0; j < column; j++)
			std::cout << arr[i][j] << "\t";
		std::cout << "\n";
	}
}

void MatrixLibrary::Matrixx::delete_mat(double** arr, int row, int column)
{
	for (int n = 0; n < row; n++) {
		delete[] arr[n];
	}
	delete[] arr;
}

