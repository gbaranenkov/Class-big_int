// Class Big Int
// Класс позволяет складывать целые числа больших разрядов
#include <iostream>


class big_int
{

public:
	big_int (const char data[]) //конструктор принимает строку из цифр
	{
		ch = data;
		for (size_t i = 0; ch[i] != '\0'; ++i) //получение размера массива
		{
			arr_size++;
		}

		arr = new int[arr_size];
		for (size_t i = 0; i < arr_size; ++i) //заполнение массива значениями
		{
			arr[i] = ch[i] - 48;
		}
	}

	big_int( int* arr_input, int arr_input_size)
	{
		arr_size = arr_input_size;
		arr = new int[arr_size];
		for (size_t i = 0; i < arr_size; ++i) //заполнение массива значениями
		{
			arr[i] = arr_input[i];
		}
	}

	big_int(const big_int& copy_b) //конструктор копирования
	{
		arr_size = copy_b.arr_size;
		arr = new int[arr_size];
		for (size_t i = 0; i < arr_size; ++i) //заполнение массива значениями
		{
			arr[i] = copy_b.arr[i];
		}
	}

	~big_int()
	{
		delete[] arr;
	}

	int get_arr_size() const//длина созданного массива для числа
	{
		return arr_size;
	}

	int* get_arr() const//указатель на созданный массив
	{
		return arr;
	}

private:
	const char* ch = 0; // получаемое число big int  
	int* arr = 0;	//указатель на массив чисел 
	size_t arr_size = 0; //размер массива
};

//big_int operator+(const big_int& number1, const big_int& number2)
//{
//	int result_arr_size; //размер массива после сложения
//	int* result_arr; //указатель на результирующий массив 
//	if (number1.get_arr_size() > number2.get_arr_size())
//	{
//		result_arr_size = number1.get_arr_size() + 1;
//	}
//	else
//	{
//		result_arr_size = number2.get_arr_size() + 1;
//	}
//
//	result_arr = new int[result_arr_size]; //создаем массив нужного размера
//
//	int tmp = 0; //переменная хранит доп разряд при сложении ячеек массива в столбик
//	int k = 1;
//	int i = result_arr_size;
//	for (; i >=0;  --i)
//	{
//		int size1 = number1.get_arr_size();
//		int size2 = number2.get_arr_size();
//		int num1 = number1.get_arr()[size1 - k];
//		int num2 = number2.get_arr()[size2 - k];
//
//
//		if (k > size1)
//		{
//			num1 = 0;
//		}
//
//		if (k > size2)
//		{
//			num2 = 0;
//		}
//
//
//		result_arr[i] = num1 + num2 + tmp;
//		if (result_arr[i] >= 10)
//		{
//			result_arr[i] %= 10;
//			tmp = 1;
//			k++;
//		}
//		else
//		{
//			tmp = 0;
//			k++;
//		}
//	}
//	
//	for (int i = 0; i < result_arr_size; ++i)
//	{
//		std::cout << result_arr[i];
//	}
//	
//	char ch[256];
//
//	big_int result (ch);
//
//
//	delete[] result_arr;
//	return result;
//}

int* summ_array(const int *arr1, const int *arr2, int size1, int size2)
{
	int new_size;

	(size1 > size2) ? new_size = size1 : new_size = size2; //определяем новый размер массива

	int* new_arr = new int[new_size]; //новый массив


	int tmp = 0; //доп разряд (0 - нет, 1 - есть)
	for (int i = 1; i <= new_size; ++i)
	{

		int num1 = arr1[size1 - i];
		int num2 = arr2[size2 - i];

		if (arr1[size1 - i] <= 0)
		{
			num1 = 0;
		}

		if (arr2[size2 - i] <= 0)
		{
			num2 = 0;
		}

		new_arr[new_size - i] = num1 + num2 + tmp;
		if ((new_arr[new_size - i] > 9) && (new_size - i != 0))
		{
			tmp = 1;
			new_arr[new_size - i] %= 10;
		}
		else 
		{
			tmp = 0;
		}
	}

	//for (size_t i = 0; i < new_size; i++)
	//{
	//	std::cout << new_arr[i];
	//}

	return new_arr;
}


big_int operator+(const big_int& number1, const big_int& number2)
{
	int* arr1 = number1.get_arr();
	int* arr2 = number2.get_arr();
	int size1 = number1.get_arr_size();
	int size2 = number2.get_arr_size();
	
	int* res;
	res = summ_array(arr1, arr2, size1, size2);
	
	int res_size;
	if (size1 > size2)
	{
		res_size = size1;
	}
	else
	{
		res_size = size2;
	}

	big_int result(res, res_size);
	return result;
}




int main()
{
	char ch [256]; // получаемое число big int  
	int* arr;	//указатель на массив чисел 
	size_t arr_size = 0; //размер массива
//	std::cin >> ch;
	
	big_int a ("12345");
	big_int b (a);

	//a + b;
	//int arr1[3] = { 9, 9, 7 };
	//int arr2[4] = { 9, 9, 9, 4};

	//summ_array(arr1, arr2, 3, 4);


	return 0;
}
