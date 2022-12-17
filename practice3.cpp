/*Вариант 1
В текстовом файле input.txt записан русский текст. 
Найти в тексте слова, содержащие не менее четырех 
из пяти наиболее часто встречающихся букв текста, 
записать их заглавными буквами и указать после каждого 
такого слова в скобках найденные буквы. Полученный текст 
записать в файл output.txt. Весь текст, кроме найденных 
слов, должен остаться неизменным, включая и знаки препинания.
*/



#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int mass[100] = { 0 };

int main()
{
	string str;
	string letter;
	char letter1, letter2, letter3, letter4, letter5;
	ifstream fin("meowt.txt");
	ofstream fout("bark.txt");
	string alphabet = "qwertyuiopasdfghjklzxcvbnm";

	while (fin >> str)
	{

			for (int i = 0; i < str.length(); i++)
			{
				str[i] = tolower(str[i]);
			}
			while (ispunct(str[0]))
			{
				str.erase(0, 1);
				if (str.length() == 0)
				{
					break;
				}
			}
			if (str.length() == 0)
			{
				continue;
			}
			while (ispunct(str[str.length() - 1]))
			{
				str.erase(str.length() - 1);
			}

			for (int i = 0; i < str.length(); i++)
			{
				mass[alphabet.find(str[i])]++;
			}
	}

	for (int i = 0; i < alphabet.length() - 1; i++)
		for (int j = i + 1; j < alphabet.length() - 1; j++)
			if (mass[i] < mass[j])
			{
				swap(mass[i], mass[j]);
				swap(alphabet[i], alphabet[j]);
			}
		
	for (int i = 0; i < 5; i++) cout << alphabet[i];
	
	
	ifstream fin2("meowt.txt");
	while (fin2 >> str)
	{
		int count = 0;
		string sc = " (";
		bool fl[10];
		for (int i = 0; i < 5; i++) fl[i] = true;
		for (int i = 0; i < str.length(); i++)
			for (int j = 0; j < 5; j++)
			{
				if ((str[i] == alphabet[j]) && (fl[j]))
				{
					count++;
					//cout << count << endl;
					sc += str[i];
					fl[j] = false;
				}
			}

		if (count >= 4)
		{
			//cout << str << " ";
			//cout << sc << " ";
			for (int i = 0; i < str.length(); i++)
			{
				if ((sc.find(str[i])>=0) && (sc.find(str[i]) < sc.length()))
				{
					str[i] = toupper(str[i]);
				}
			}
			str += sc + ")";
			//cout << str << " ";

		}
		fout << str << " ";
	}
	system("pause");
	return 0;
}


