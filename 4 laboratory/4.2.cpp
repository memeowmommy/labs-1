#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");

	int N;
	cin >> N;

	if (N > 1000)
	{
		cout << "Ошибка" << endl;
		return 0;
	}

	int A[1000][3];

	for (int i = 0; i < N; i++)
	{
		cin >> A[i][0];
		if (A[i][0] < 1)
		{
			cout << "Ошибка" << endl;
			return 0;

		}
		int n = A[i][0];
		int sum = 0;
		while (n > 9)
		{
			sum += n % 10;
			n /= 10;
		}
		A[i][1] = n;
		A[i][2] = sum + A[i][1];
	}
	for (int ii = 0; ii < N - 1; ii++)
	{
		for (int jj = ii + 1; jj < N; jj++)
		{
			if (A[ii][1] > A[jj][1])
			{
				int t0 = A[ii][0];
				int t1 = A[ii][1];
				int t2 = A[ii][2];
				A[ii][0] = A[jj][0];
				A[ii][1] = A[jj][1];
				A[ii][2] = A[jj][2];
				A[jj][0] = t0;
				A[jj][1] = t1;
				A[jj][2] = t2;
			}
			if (A[ii][1] == A[jj][1])
			{
				if (A[ii][2] > A[jj][2])
				{
					int t0 = A[ii][0];
					int t1 = A[ii][1];
					int t2 = A[ii][2];
					A[ii][0] = A[jj][0];
					A[ii][1] = A[jj][1];
					A[ii][2] = A[jj][2];
					A[jj][0] = t0;
					A[jj][1] = t1;
					A[jj][2] = t2;
				}
				if (A[ii][2] == A[jj][2])
				{
					if (A[ii][0] > A[jj][0])
					{
						int t0 = A[ii][0];
						int t1 = A[ii][1];
						int t2 = A[ii][2];
						A[ii][0] = A[jj][0];
						A[ii][1] = A[jj][1];
						A[ii][2] = A[jj][2];
						A[jj][0] = t0;
						A[jj][1] = t1;
						A[jj][2] = t2;
					}
				}
			}
		}
	}
	for (int x = 0; x < N; x++)
	{
		cout << A[x][0] << " ";
	}



	system("pause");
	return 0;

}
