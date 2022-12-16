#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void mass(string s, int mas[1000])
{
	for (int i = 0; i < s.length(); i++)
	{
		mas[i + 1] = s[i] - '0';

	}
	mas[0] = s.length();
	for (int i = 1; i < mas[0] / 2 + 1; i++)
	{
		int k = mas[0] - i + 1;
		swap(mas[i], mas[k]);
	}
}
void addition(int number1[1000], int number2[1000], int sum[1000])
{
	if (number1[0] > number2[0])
	{
		sum[0] = number1[0];
	}
	else
	{
		sum[0] = number2[0];
	}
	int r = 0;
	for (int i = 1; i <= sum[0]; i++)
	{

		sum[i] = number1[i] + number2[i] + r;
		r = sum[i] / 10;
		sum[i] = sum[i] % 10;

	}
	if (r != 0)
	{
		sum[0]++;
		sum[sum[0]] = r;

	}
}

void multiplication(int number1[1000], int number2[1000], int mult[1000])
{
	mult[0] = number1[0] + number2[0];
	for (int i = 1; i <= number1[0]; i++)
	{
		int q = 0;
		for (int j = 1; j <= number2[0]; j++)
		{
			mult[i + j - 1] += number1[i] * number2[j];
			q = mult[i + j - 1] / 10;
			mult[i + j - 1] = mult[i + j - 1] % 10;
			mult[i + j] += q;

		}
	}

}


int main()
{
	string str2;
	string str1;
	int num1[1000] = { 0 };
	int num2[1000] = { 0 };
	int sum[1000] = { 0 };
	int multi[1000] = { 0 };
	ifstream fin("meow.txt");
	ofstream fout("bark.txt");
	fin >> str1;
	fin >> str2;
	mass(str1, num1);
	mass(str2, num2);
	addition(num1, num2, sum);
	multiplication(num1, num2, multi);
	for (int i = sum[0]; i >=1 ; i--)
	{
		fout << sum[i];
	}

	fout << endl;

	if (multi[multi[0]] == 0)
	{
		multi[0]--;
	}
	for (int i = multi[0]; i >= 1; i--)
	{
		fout << multi[i];
	}

	system("pause");
}