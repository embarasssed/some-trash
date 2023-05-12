/*Реализовать библиотеку функций для работы с матрицами,
размером до 128x128. Библиотека должна включать в себя функции сложения++,
умножения матриц++, скалярного умножения++, инвертирования+-, определения детерминанта++,
левостороннего+- и правостороннего деления+-. Также необходимо реализовать функцию,
отображающую на экран содержимое матрицы.*/

#include <iostream>
#include "Matrix.h"

int main()
{
	setlocale(LC_ALL, "Russian");
	using namespace std;
	using namespace MatrixLibrary;
	srand(time(NULL));

	int row1, row2, column1, column2, row3, column3;
	cout << "Размерность матрицы 1 (два положительных числа):\n";
	cin >> row1 >> column1;
	cout << "Размерность матрицы 2:\n";
	cin >> row2 >> column2;
	cout << "Размерность матрицы 3:\n";
	cin >> row3 >> column3;
	cout<<endl<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl << endl;

	//проверка на ошибки
	if (row1 <= 0 || row2 <= 0 || column1 <= 0 || column2 <= 0 || row3 <= 0 || column3 <= 0)
		cout << "Ошибочка вышла. Размерность матриц - два положительных числа." << endl;
	else {
		double** error = Matrixx::allocate_mem(1, 1);
		error[0][0] = -666;

		//отводит память для динамического массива
		//и
		//задает массив рандомными числами
		double** arr1 = Matrixx::fill_mat(row1, column1);
		double** arr2 = Matrixx::fill_mat(row2, column2);
		double** arr3 = Matrixx::fill_mat(row3, column3);

		//выводит матрицу на консоль
		cout << "Матрица 1:\n";
		Matrixx::print_mat(arr1, row1, column1);
		cout << endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl;

		cout << "Матрица 2:\n";
		MatrixLibrary::Matrixx::print_mat(arr2, row2, column2);
		cout << endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl;

		//Сложение
		cout << "Матрица 1 + Матрица 2:\n";
		//double** sum = Matrixx::allocate_mem(row1, column1);
		double** sum = Matrixx::sum(arr1, arr2, row1, column1, row2, column2);
		if (sum[0][0] != error[0][0]) {
			Matrixx::print_mat(sum, row1, column1);
			cout << endl;
		}
		else cout << "Произошли технические шоколадки. Размеры матриц не совпадают. Сложение невозможно." << endl;
		cout << endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl;

		//Произведение
		cout << "Матрица 1 * Матрица 2:\n";
		double** mult = Matrixx::multiply(arr1, arr2, row1, column1, row2, column2);
		if (mult[0][0] != error[0][0]) {
			Matrixx::print_mat(mult, row1, column2);
			cout << endl;
		}
		else cout << "Технические шоколадки. Операция умножения невозможна." << endl;
		cout << endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl;

		//псевдоделение левостороннее
		cout << "A^(-1) * B = \n";
		double** left_div = Matrixx::left_division(arr1, arr2, row1, column1, row2, column2);
		if (left_div[0][0] != error[0][0]) {
			Matrixx::print_mat(left_div, row1, column2);
			cout << endl;
		}
		else { cout << "Операция псевдоделения недоступна. Несоответствующие размеры матриц."; }
		cout << endl << endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl;

		//правостороннеее
		cout << "A * B^(-1) = \n";
		//Matrixx::right_division(arr1, arr2, row1, column1, row2, column2);
		double** right_div = Matrixx::right_division(arr1, arr2, row1, column1, row2, column2);
		if (right_div[0][0] != error[0][0]) {
			Matrixx::print_mat(right_div, row1, column2);
			cout << endl;
		}
		else { cout << "Операция псевдоделения недоступна. Несоответствующие размеры матриц."; }
		cout << endl << endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl;

		/*cout << "Выбор способа задания матрицы. 1(ввод с клавиатуры) или 2(рандом) : ";
		int sp;
		cin >> sp;
		if (sp != 1 && sp != 2) {
			cout << "\nОшибочка вышла. Тебе просто надо было выбрать 1 или 2. Я разочарована. ";
		}
		else {
			if (sp == 1) {
				double** arr3 = Matrixx::allocate_mem(row3, column3);
				cout << "Введите матрицу 3(ручками): \n";
				arr3 = Matrixx::fill2_mat(arr3, row3, column3);
			}
			else {
				arr3 = Matrixx::fill_mat(row3, column3);
			}*/

		cout << "Матрица 3:\n";
		arr3 = Matrixx::fill_mat(row3, column3);
		Matrixx::print_mat(arr3, row3, column3);
		cout << endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl;

		cout << "Транс-Матрица 3:\n";
		double** trans3 = Matrixx::trans(arr3, row3, column3);
		Matrixx::print_mat(trans3, column3, row3);
		cout << endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl;

		//Скалярное произведение матрицы на число
		cout << "Скалярное произведение матрицы на число a." << endl;
		int a;
		cout << "Введите a: ";
		cin >> a;
		cout << "(матрица) A(3) * a(конст) = " << endl;
		double** scalar_mult = Matrixx::scalar_mult(arr3, row3, column3, a);
		Matrixx::print_mat(scalar_mult, row3, column3);
		cout << endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl;

		//детерминант
		cout << "Определитель Матрицы 3 = ";
		double det = Matrixx::det(arr3, row3, column3);
		if (det != error[0][0])
			cout << det;
		else cout << "не существует...........";
		cout << endl << endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl;

		//обратная
		cout << "Обратная матрица 3:";
		double** inv = Matrixx::invert(arr3, row3, column3);
		if (inv[0][0] != error[0][0]) {
			cout << endl;
			Matrixx::print_mat(inv, row3, row3);
		}
		else cout << " не существует.";
		cout << endl << endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl;

		//очищает оперативку
		Matrixx::delete_mat(arr1, row1, column1);
		Matrixx::delete_mat(arr2, row2, column2);
		Matrixx::delete_mat(arr3, row3, column3);
		cout << "Конец(!)"<<endl;

	}
	return 0;
}




