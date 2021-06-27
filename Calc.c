//*********************************************Калькулятор*********************************************//
// File with optimization 

#include <stdio.h> // библиотека ввода/вывода
#include <string.h> // библиотека для функции strlen - длина строки

#define SIZE 100 // максимальный размер строки

int main()
{
	char str[SIZE] = { 0 }; // входная строка
	int values[SIZE / 2] = { 0 }; // хранение всех чисел
	int count_values = 0; // количество чисел
	int i = 0; 
	int j;
	int result = 0; // результат
	char sign = '\0'; // хранение арифметического знака

	fgets(str, SIZE, stdin); // считывание строки

	if (str[0] == '-') // перепрыгиваем через первый минус, если он есть
		i++;

	for (; i < strlen(str); i++) // цикл до конца строки
	{
		j = i; // получение текущей позиции

		while ((str[j] >= '0' && str[j] <= '9') && j < strlen(str)) // перевод из char в int и сохранение чисел в массив values 
		{
			values[count_values] *= 10;
			values[count_values] += ((int)str[j] - '0'); // преобразование из char в int
			j++;
		}

		if (str[i - 1] == '-') // умножение на -1, если стоит знак минус
			values[count_values] *= -1;

		i = j; // восстановление позиции с учётом рассмотренного числа в цикле while

		if (values[count_values] != 0) // обработка счётчика количества чисел
			count_values++;

	}

	for (int k = 0; k < count_values; k++) // суммирование по всем слагаемым
		result += values[k];


	printf("Result: %d", result); // вывод результата
	 
	return 0;
}