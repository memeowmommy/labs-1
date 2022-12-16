#include <iostream>
using namespace std;
int main() {
	int a, b, c = 0;
	cin >> a;
	cin >> b;
	cin >> c;

	if ((a % b == 0) && (b > c))
		cout << a / b + c;
	else if ((a % b == 0) && (b > c))
		cout << a / b - c;
	else
		cout << (a + b) * c;
	system("pause");
	return 0;


}