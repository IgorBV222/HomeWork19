#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;

//Задача 19.1. Наибольший общий делитель 2-х чисел.
int nod(int num1, int num2) {
	int max{}, end; //не понял, почему компилятор затребовал {} после max???
	end = num1 <= num2 ? num1 : num2;	
	for (int i = 1; i <= end; i++) {
		if (num1 % i == 0 && num2 % i == 0) {
			max = i;
		}		
	}
	return max;
}

//Задача 19.2.Принимает число и возвращает его в отражённом виде.
int mirror_number(int num1) {
	int new_num = 0;	
	do {
		new_num = new_num * 10 + num1 % 10;
		num1 /= 10;
	} while (num1 != 0);
	return new_num;
} 

//Задача 19.3. Возвращает первую позицию числа N в массиве, а также сортирует все элементы, которые находятся справа от N.
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
// Задача 19.4.
//Заполняет массив случайными числами из диапазона от A до B
template <typename T>
void fill_arr(T arr[], const int length, int begin, int end) {
	srand(time(NULL));
	for (int i = 0; i < length; i++)
		arr[i] = rand() % (end - begin) + begin;
}
//Вывод массива в консоль.
template <typename T>
void show_arr(T arr[], const int length) {
	cout << '[';
	for (int i = 0; i < length; i++)
		cout << arr[i] << ", ";
	cout << "\b\b]\n";
}




int main() {
	setlocale(LC_ALL, "Russian");

	//Задача 19.1. Создайте функцию, которая принимает два числа и возвращает их наибольший общий делитель.
	cout << "Задача 19.1.\nВведите два числа: \n";
	int n, m;
	cin >> n >> m;
	cout << "Наибольший общий делитель чисел: " << n << " и " << m << " = " << nod(n, m) << "\n\n";


	//Задача 19.2. Напишите функцию mirror_number, которая принимает число и возвращает его в отражённом виде.
	cout << "Задача 19.2.\nВведите число: \n";
	int X;
	cin >> X;
	cout << "Отраженное число: " << mirror_number(X) << "\n\n";


	//Задача 19.3. Создайте функцию, которая принимает массив, его длину и число N. Функция возвращает первую позицию числа N в массиве, а также сортирует все элементы, которые находятся справа от N.
	cout << "Задача 19.3.\nВведите число N: \n";
	int N;
	cin >> N;
	const int size = 10;
	int arr[size]{ 6, 4, 1, 7, -6, 1, 0, 1, 11, 9 };	
	cout << "Позиция числа " << N << " в массиве = " << middel_sort(arr, size, N) << '\n';
	
	
	//Задача 19.4. Создайте функцию, которая принимает пустой массив, его длину и два числа A и B, которые являются началом и концом диапазона.
	//Функция должна заполнять массив случайными числами из указанного диапазона.
	cout << "Задача 19.4.\nВведите число A и B: \n";
	int A, B;
	cin >> A;
	cin >> B;
	const int size4 = 20;
	int arr4[size4];
	fill_arr(arr4, size4, A, B);
	show_arr(arr4, size4);

	return 0;
}