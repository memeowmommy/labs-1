#include "fufu.h"
#include <iostream>
using namespace std;

namespace am 
{
	void input(int h, int g, int mas[100][100]) 
	{
		cout << "Enter the matrice: " << "\n";
		for (int i = 0; i < h; i++) 
			for (int j = 0; j < g; j++)
			{
				
				cin >> mas[i][j];
			}
	}

	bool prime(int x) 
	{
		if (x < 2) 
		{
			return false;
		}
		for (int i = 2; i < x; i++)
		{
			if (x % i == 0) 
			{
				return false;
			}
			return true;
		}
	}

	bool columns(int x[100], int y[100], int n) 
	{
		for (int i = 0; i < n; i++) 
		{
			if (x[i] != y[i]) {return false;}
		}
		return true;
	}

	bool fl1(int s, int n, int mas[100][100]) 
	{
		for (int i = 0; i < n - 1; i++) {
			int x[100];
			int y[100];
			for (int j = i + 1; j < n; j++) 
			{
				for (int k = 0; k < s; k++) 
				{
					x[k] = mas[k][i];
					y[k] = mas[k][j];
				}

				if (columns(x, y, s)) 
				{
					return true;
					break;
				}
			}
		}
	}

	bool fl2(int s, int n, int mas[100][100]) 
	{
		for (int i = 0; i < s; i++)
		{
			for (int j = 0; j < n; j++) 
			{
				if (prime(abs(mas[i][j]))) 
				{
					return true;
					break;
				}
			}
		}
	}
	
	void sum_of_lines(int s, int n, int mas[100][100], int sum[100]) 
	{
		for (int k = 0; k < s; k++) 
			for (int i = 0; i < n; i++) 
			{
				sum[k] += abs(mas[k][i]);
			}
	}

	void sort(int s, int n, int mas[100][100], int sum[100]) 
	{
		for (int i = 0; i < s - 1; i++) 
		{
			for (int k = i; k < s; k++) 
			{
				int tmp;
				if (sum[i] > sum[k]) 
				{
					for (int j = 0; j < n; j++) 
					{
						tmp = mas[i][j];
						mas[i][j] = mas[k][j];
						mas[k][j] = tmp;
					}

					tmp = sum[i];
					sum[i] = sum[k];
					sum[k] = tmp;
				}
			}
		}
	}

	void output(int s, int n, int mas[100][100])
	{
		cout << "New matrice:" << "\n";
		for (int i = 0; i < s; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cout << mas[i][j] << ' ';
			}
			cout << endl;
		}
	}
}