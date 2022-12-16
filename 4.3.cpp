#include <iostream>
using namespace std;
int main() 
{
	int n;
	cin >> n;
	int m;
	cin >> m;
	int matrix[100][100];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> matrix[i][j];

		}
	}
	int min = 1000;
	int s = 0;
	for (int i = 0; i < n; i++) {
		int sum = 0;
		for (int j = 0; j < m; j++) {
			sum += matrix[i][j];
		}
		if (abs(sum) < min) {
				min = abs(sum);
				s = i;
			}
	}
	for (int j = 0; j < m; j++) {
		matrix[s][j] = 0;
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << matrix[i][j] << " ";

		}
		cout << endl;
	}
	system("pause");
	return 0;
}
