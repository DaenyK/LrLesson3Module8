#include <stdio.h>
#include <locale.h>
#include <iostream>
#include <stdint.h>
#include <time.h>
#include <windows.h>
#include <string.h>
#include "Header.h"

using namespace std;

unsigned short int q;

void main()

{
	setlocale(LC_ALL, "Russian");
	//SetConsoleCP(1251);
	//SetConsoleOutputCP(1251);

	srand(time(NULL));

	unsigned short int nz;

	do
	{
		cout << "введите номер задания: ";
		cin >> nz;
		switch (nz)
		{
		case 1:
		{
			cout << "Дана строка из нескольких слов. Слова отделяются друг от друга пробелами или запятыми. Вывести слова, " << endl
				<< "начинающиеся и заканчивающиеся одной и той же буквой.\n\n";
			char str[] = "Автотрасса Москва - Алма-ата, как я по ней ехал";
			printf("%s\n", str);
			sameStartEnd(str, strlen(str));
		}break;

		case 2:
		{

			char str[] = "</i><body><hr><ul><i>Чебурашка</i><i>Крокодил Гена</i><i>Шапокляк</i><i>Крыса Лариса</i></ul><hr></body>";
			printf("%s\n\n", str);
			char newstr[] = "";
			int count = 0;
			for (int i = 0; i <= strlen(str); i++)
			{
				if (str[i] == '<'&&str[i + 1] == 'i')
				{
					newstr[count] = str[i];
					newstr[count + 1] = '/';
					count = count + 2;
				}
				else if (str[i] == '<'&&str[i + 1] == '/'&&str[i + 2] == 'i')
				{
					newstr[count] = str[i];
					newstr[count + 1] = '#';
					count = count + 2;
					i = i + 2;
				}
				else
				{
					newstr[count] = str[i];
					count++;
				}
			}
			printf("%s\n\n", newstr);

		}break;

		//case 2:
		//{
		//	//доделаю-------------------------------
		//	cout << "Дан массив символов, в котором встречаются структуры <i> и < / i>.Заменить каждое вхождение <i> на < / i>," << endl
		//		<< "а каждое вхождение < / i> на <#>.Замечание: в программе следует учесть, что буква i может быть, как строчной," << endl
		//		<< "так и прописной.\n\n";
		//	char * a = "<i>", *b = "<#>";
		//	char * m = "<i><body><hr><ul><i>Чебурашка</i><i>Крокодил Гена</i><i>Шапокляк</i><i>Крыса Лариса</i></ul><hr></body>";
		//	printf("Before replace: %s\n", m);
		//	replacestr(m, a, b);

		//	printf("After replace: %s\n\n", m);
		//}break;

		case 3:
		{
			cout << "Дан массив символов, содержащий число в двоичной системе счисления. Проверить правильность ввода этого числа" << endl
				<< "(в его записи должны быть только символы 0 и 1). Если число введено неверно, повторить ввод. При правильном вводе" << endl
				<< "перевести число в десятичную систему счисления\n\n";
			char mas[10];
			int count = 0;
			do
			{
				count = 0;
				cout << "введите число в двоичном виде: ";
				scanf("%s", mas);
				for (int i = 0; i < strlen(mas); i++)
				{
					if (mas[i] != '0' && mas[i] != '1')
						count++;
				}
			} while (count != 0);

			int c = strlen(mas) - 1, sum = 0, temp;

			for (int i = 0; i < strlen(mas); i++)
			{
				if (mas[i] == '1')
				{
					temp = pow(2, c);
					sum += temp;
					c--;
					temp = 0;
				}
				else
					c--;
			}
			cout << sum << endl;
		}break;

		case 4:
		{
			cout << "Дан массив символов, содержащий текст. Определить длину содержащейся в нем максимальной серии символов," << endl
				<< "отличных от букв.\n\n";
			char * mas = "Дан массив 1 1 символов, содержащий текст.111 Определить 111111 длину содержащейся 1111 в нем максимальной ";
			int count = 0, max = 0;
			for (int i = 0; i < strlen(mas); i++)
			{
				//printf("%d - %c\n", (int)mas[i], mas[i]);
				if ((int)mas[i] >= 48 && (int)mas[i] <= 57)
					count++;
				else
				{
					if (max < count)
						max = count;
					count = 0;
				}

			}
			printf("%s \n", mas);
			printf("Max = %d \n", max);
		}break;

		case 5:
		{
			cout << "Дан массив символов. Преобразовать его, заменив точками все двоеточия (:), встречающиеся среди первой половины " << endl
				<< "символов, и заменив точками все восклицательные знаки, встречающиеся среди символов, стоящих во второй половине " << endl
				<< "исходного массива\n\n";

			char masSymbol[] = "пр!и:вет: чт!о сег!!!одня де:лае!ш:ь?";
			printf("%s\n\n", masSymbol);
			int b = strlen(masSymbol);
			cout << b << endl;
			for (int i = 0; i < strlen(masSymbol); i++)
			{
				if (i < (strlen(masSymbol)) / 2)
				{
					if (masSymbol[i] == ':')
						masSymbol[i] = '.';
				}
				else
				{
					if (masSymbol[i] == '!')
						masSymbol[i] = '.';
				}
			}
			printf("ПОСЛЕ: %s\n\n", masSymbol);
		}break;

		case 6:
		{
			cout << "Дан массив символов. Указать те слова, которые содержат хотя бы одну букву k.\n\n";
			char *str = "You know nothing, Jon Snow";
			printf("%s\n\n", str);
			char * word = (char*)calloc(50, sizeof(char));

			int n = 0, kon = 0, ws = 0;
			while (kon < strlen(str))
			{

				while (str[kon] != ' '&&str[kon] != ',')
				{
					if (kon != strlen(str))
						kon++;
					else break;

				}
				for (int i = n; i < kon; i++)
				{
					word[ws] = str[i];
					ws++;
				}
				word[ws] = '\0';

				for (int i = 0; i < strlen(word); i++)
				{
					if (word[i] == 'k')
					{
						printf("%s \n", word);
						break;
					}
				}
				n = kon + 1;
				if (str[kon] != ' ' || str[kon] != ',') kon++;
				ws = 0;
			}
		}break;

		case 7:
		{
			cout << "Дан массив символов, содержащий текст. В строке между словами вставить вместо пробела запятую и пробел\n\n";
			char str[] = "hello! how are you?";
			printf("%s\n\n", str);

			char newStr[] = "";
			int mas[100], j = 0;
			for (int i = 0; i <= strlen(str); i++)
			{
				if (str[i] == ' ')
				{
					newStr[j] = ',';
					newStr[j + 1] = ' ';
					j = j + 2;
				}
				else
				{
					newStr[j] = str[i];
					j++;
				}

			}
			printf("%s\n\n", newStr);

		}break;

		case 8:
		{
			cout << "Дан массив символов, содержащий текст, заканчивающийся точкой.Вывести на экран слова, содержащие три буквы.\n\n";
			char str[] = "Привет, Аня! как дела? что делаешь?";
			printf("%s\n\n", str);

			int mas[100], j = 0;
			for (int i = 0; i < strlen(str); i++)
			{
				if (str[i] == ' ' || str[i] == ',' || str[i] == '!')//и так далее можно условие дополнять, на сопутствующие знаки
				{
					mas[j] = i;
					//cout << mas[j] << "\t";
					j++;
				}
			}
			int startWord[10], s = 0;

			for (int i = 0; i < j; i++)
			{
				if ((mas[i + 1] - mas[i]) == 4)
				{
					startWord[s] = (mas[i]) + 1;
					//	cout << startWord[s] << "\t";
					s++;
				}
			}

			s = 0;
			printf("слова, содержащие 3 буквы: ");
			for (int i = 0; i < strlen(str); i++)
			{
				if (i == startWord[s])
				{
					do {
						cout << str[i];
						i++;
					} while (str[i] != ' '&&str[i] != ',' && str[i] != '!'); // и так далее можно условие дополнять, на сопутствующие знаки
					cout << " ";
					s++;
				}
			}
			printf("\n\n");
		}break;

		}


		cout << "хотите продолжить 1/0?";
		cin >> q;


		switch (q)
		{
		case 1:
			system("cls");
			break;
		default:
			cout << "ошибка" << endl;
		}
	} while (nz > 0);


}