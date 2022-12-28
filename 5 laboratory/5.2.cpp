#include <iostream>
#include <string>
#include <fstream>

using namespace std;
int main() {
	
	fstream fin("meow.txt");
	ofstream fout("bark.txt");
	string str;
	char let;
	string word[1000];
	int N;
	int size = 0;
	int sum = 0;
	int count[1000];

	cin >> N;
	cin >> let;
	while (fin >> str)
	{
		
		for (int i = 0; i < str.length(); i++)
		{
			str[i] = tolower(str[i]);
			cout << str[i] << endl;
		}

		while (ispunct(str[0]))
		{
			str.erase(0, 1);
			break;
		}
		if (str.length() == 0)
			continue;
		while (ispunct(str[str.length()]))
		{
			str.erase(str.length() - 1);
		}
		
		if (str[str.length()-1] == let)
		{
			bool flag = true;
			for (int i = 0; i < size; i++)
			{
				if (str == word[i])
				{
					flag = false;
				}
			}
			if (flag == true)
			{
				word[size] = str;
				size += 1;
			}
		}

			
	}

	
	for (int i = 0; i < size - 1; i++) {
		for (int j = i + 1; j < size; j++) {
			if (word[i].length() < word[j].length()) {
				swap(word[i], word[j]);
			}

		}
	}
	if (N > size)
	{
		cout << size << endl;
		N = size;
	}

	for (int i = 0; i < N; i++)
	{
		cout << str[i] << endl;
		fout << word[i] << endl;
	}

	system("pause");
	return 0;
}

