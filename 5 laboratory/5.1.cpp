#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int main() {
	char str[100];
	char vowels[7] = "aeyuio";
	cin >> str;
	for (int i = 0; i < strlen(str); i++) {
		for (int j = 0; j < strlen(vowels); j++) {
			if (str[i] == vowels[j]) {
				str[i] -= 32;
			}
		}
	}
	cout << str<<endl;
	system("pause");
}
