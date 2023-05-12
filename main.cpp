/*����������� ���������� ������� ��� ������ � ���������,
�������� �� 128x128. ���������� ������ �������� � ���� ������� ��������++,
��������� ������++, ���������� ���������++, ��������������+-, ����������� ������������++,
��������������+- � ��������������� �������+-. ����� ���������� ����������� �������,
������������ �� ����� ���������� �������.*/

#include <iostream>
#include "Matrix.h"

int main()
{
	setlocale(LC_ALL, "Russian");
	using namespace std;
	using namespace MatrixLibrary;
	srand(time(NULL));

	int row1, row2, column1, column2, row3, column3;
	cout << "����������� ������� 1 (��� ������������� �����):\n";
	cin >> row1 >> column1;
	cout << "����������� ������� 2:\n";
	cin >> row2 >> column2;
	cout << "����������� ������� 3:\n";
	cin >> row3 >> column3;
	cout<<endl<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl << endl;

	//�������� �� ������
	if (row1 <= 0 || row2 <= 0 || column1 <= 0 || column2 <= 0 || row3 <= 0 || column3 <= 0)
		cout << "�������� �����. ����������� ������ - ��� ������������� �����." << endl;
	else {
		double** error = Matrixx::allocate_mem(1, 1);
		error[0][0] = -666;

		//������� ������ ��� ������������� �������
		//�
		//������ ������ ���������� �������
		double** arr1 = Matrixx::fill_mat(row1, column1);
		double** arr2 = Matrixx::fill_mat(row2, column2);
		double** arr3 = Matrixx::fill_mat(row3, column3);

		//������� ������� �� �������
		cout << "������� 1:\n";
		Matrixx::print_mat(arr1, row1, column1);
		cout << endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl;

		cout << "������� 2:\n";
		MatrixLibrary::Matrixx::print_mat(arr2, row2, column2);
		cout << endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl;

		//��������
		cout << "������� 1 + ������� 2:\n";
		//double** sum = Matrixx::allocate_mem(row1, column1);
		double** sum = Matrixx::sum(arr1, arr2, row1, column1, row2, column2);
		if (sum[0][0] != error[0][0]) {
			Matrixx::print_mat(sum, row1, column1);
			cout << endl;
		}
		else cout << "��������� ����������� ���������. ������� ������ �� ���������. �������� ����������." << endl;
		cout << endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl;

		//������������
		cout << "������� 1 * ������� 2:\n";
		double** mult = Matrixx::multiply(arr1, arr2, row1, column1, row2, column2);
		if (mult[0][0] != error[0][0]) {
			Matrixx::print_mat(mult, row1, column2);
			cout << endl;
		}
		else cout << "����������� ���������. �������� ��������� ����������." << endl;
		cout << endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl;

		//������������� �������������
		cout << "A^(-1) * B = \n";
		double** left_div = Matrixx::left_division(arr1, arr2, row1, column1, row2, column2);
		if (left_div[0][0] != error[0][0]) {
			Matrixx::print_mat(left_div, row1, column2);
			cout << endl;
		}
		else { cout << "�������� ������������� ����������. ����������������� ������� ������."; }
		cout << endl << endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl;

		//���������������
		cout << "A * B^(-1) = \n";
		//Matrixx::right_division(arr1, arr2, row1, column1, row2, column2);
		double** right_div = Matrixx::right_division(arr1, arr2, row1, column1, row2, column2);
		if (right_div[0][0] != error[0][0]) {
			Matrixx::print_mat(right_div, row1, column2);
			cout << endl;
		}
		else { cout << "�������� ������������� ����������. ����������������� ������� ������."; }
		cout << endl << endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl;

		/*cout << "����� ������� ������� �������. 1(���� � ����������) ��� 2(������) : ";
		int sp;
		cin >> sp;
		if (sp != 1 && sp != 2) {
			cout << "\n�������� �����. ���� ������ ���� ���� ������� 1 ��� 2. � ������������. ";
		}
		else {
			if (sp == 1) {
				double** arr3 = Matrixx::allocate_mem(row3, column3);
				cout << "������� ������� 3(�������): \n";
				arr3 = Matrixx::fill2_mat(arr3, row3, column3);
			}
			else {
				arr3 = Matrixx::fill_mat(row3, column3);
			}*/

		cout << "������� 3:\n";
		arr3 = Matrixx::fill_mat(row3, column3);
		Matrixx::print_mat(arr3, row3, column3);
		cout << endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl;

		cout << "�����-������� 3:\n";
		double** trans3 = Matrixx::trans(arr3, row3, column3);
		Matrixx::print_mat(trans3, column3, row3);
		cout << endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl;

		//��������� ������������ ������� �� �����
		cout << "��������� ������������ ������� �� ����� a." << endl;
		int a;
		cout << "������� a: ";
		cin >> a;
		cout << "(�������) A(3) * a(�����) = " << endl;
		double** scalar_mult = Matrixx::scalar_mult(arr3, row3, column3, a);
		Matrixx::print_mat(scalar_mult, row3, column3);
		cout << endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl;

		//�����������
		cout << "������������ ������� 3 = ";
		double det = Matrixx::det(arr3, row3, column3);
		if (det != error[0][0])
			cout << det;
		else cout << "�� ����������...........";
		cout << endl << endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl;

		//��������
		cout << "�������� ������� 3:";
		double** inv = Matrixx::invert(arr3, row3, column3);
		if (inv[0][0] != error[0][0]) {
			cout << endl;
			Matrixx::print_mat(inv, row3, row3);
		}
		else cout << " �� ����������.";
		cout << endl << endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl;

		//������� ����������
		Matrixx::delete_mat(arr1, row1, column1);
		Matrixx::delete_mat(arr2, row2, column2);
		Matrixx::delete_mat(arr3, row3, column3);
		cout << "�����(!)"<<endl;

	}
	return 0;
}




