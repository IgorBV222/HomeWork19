#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;

//������ 19.1. ���������� ����� �������� 2-� �����.
int nod(int num1, int num2) {
	int max{}, end; //�� �����, ������ ���������� ���������� {} ����� max???
	end = num1 <= num2 ? num1 : num2;	
	for (int i = 1; i <= end; i++) {
		if (num1 % i == 0 && num2 % i == 0) {
			max = i;
		}		
	}
	return max;
}

//������ 19.2.��������� ����� � ���������� ��� � ��������� ����.
int mirror_number(int num1) {
	int new_num = 0;	
	do {
		new_num = new_num * 10 + num1 % 10;
		num1 /= 10;
	} while (num1 != 0);
	return new_num;
} 

//������ 19.3. ���������� ������ ������� ����� N � �������, � ����� ��������� ��� ��������, ������� ��������� ������ �� N.
template <typename T>
int middel_sort(T arr[], const int length, T value) {
	int first_index = 0;
	for (int i = 0; i < length; i++)
		if (arr[i] == value) {
			first_index = i;			
			return first_index;
			break;
		}
	return -1;	

	for (int i = length - 1; i > first_index; i--) {
		for (int j = first_index + 1; j < i; j++)
			if (arr[j] > arr[j + 1]) {
				swap(arr[j], arr[j + 1]);				
			}
	}	
}
// ������ 19.4.
//��������� ������ ���������� ������� �� ��������� �� A �� B
template <typename T>
void fill_arr(T arr[], const int length, int begin, int end) {
	srand(time(NULL));
	for (int i = 0; i < length; i++)
		arr[i] = rand() % (end - begin) + begin;
}
//����� ������� � �������.
template <typename T>
void show_arr(T arr[], const int length) {
	cout << '[';
	for (int i = 0; i < length; i++)
		cout << arr[i] << ", ";
	cout << "\b\b]\n";
}




int main() {
	setlocale(LC_ALL, "Russian");

	//������ 19.1. �������� �������, ������� ��������� ��� ����� � ���������� �� ���������� ����� ��������.
	cout << "������ 19.1.\n������� ��� �����: \n";
	int n, m;
	cin >> n >> m;
	cout << "���������� ����� �������� �����: " << n << " � " << m << " = " << nod(n, m) << "\n\n";


	//������ 19.2. �������� ������� mirror_number, ������� ��������� ����� � ���������� ��� � ��������� ����.
	cout << "������ 19.2.\n������� �����: \n";
	int X;
	cin >> X;
	cout << "���������� �����: " << mirror_number(X) << "\n\n";


	//������ 19.3. �������� �������, ������� ��������� ������, ��� ����� � ����� N. ������� ���������� ������ ������� ����� N � �������, � ����� ��������� ��� ��������, ������� ��������� ������ �� N.
	cout << "������ 19.3.\n������� ����� N: \n";
	int N;
	cin >> N;
	const int size = 10;
	int arr[size]{ 6, 4, 1, 7, -6, 1, 0, 1, 11, 9 };	
	cout << "������� ����� " << N << " � ������� = " << middel_sort(arr, size, N) << '\n';
	
	
	//������ 19.4. �������� �������, ������� ��������� ������ ������, ��� ����� � ��� ����� A � B, ������� �������� ������� � ������ ���������.
	//������� ������ ��������� ������ ���������� ������� �� ���������� ���������.
	cout << "������ 19.4.\n������� ����� A � B: \n";
	int A, B;
	cin >> A;
	cin >> B;
	const int size4 = 20;
	int arr4[size4];
	fill_arr(arr4, size4, A, B);
	show_arr(arr4, size4);

	return 0;
}