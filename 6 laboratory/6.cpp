#include <iostream>
#include "fufu.h"
#include <math.h>
using namespace std;
using namespace am;

int main() 
{
	int s, n, mas[100][100];
	cout << "Enter the number of lines: " << "\n";
	cin >> s;
	cout << "Enter the number of columns: " << "\n";
	cin >> n;

	input(s, n, mas);
	int sum[100] = { 0 };
	if (fl1(s, n, mas) && fl2(s, n, mas)) 
	{
		sum_of_lines(s, n, mas, sum);
		sort(s, n, mas, sum);
	}
	output(s, n, mas);

	system("pause");
	return 0;
}

