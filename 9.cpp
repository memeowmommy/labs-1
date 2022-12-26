#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
using namespace std;

class circle
{
private:
	double pi = M_PI;
	double r = 0;
	long double  S = 0;

public:
	circle(double rad)
	{
		r = rad;
		S = c_area(rad);
	}

	bool radius(double rad)
	{
		if (rad <= 0)
		{
			cout << "Wrong radius." << endl;
			return false;
		}
		r = rad;
	}

	double c_area(double rad)
	{
		if (radius(rad))
		{
			S = (r * r) * pi;
			return S;
		}
		return S;

	}
	void output()
	{
		if (S == 0) { cout << "This circle doesn't exist." << endl; }
		else {cout << S << endl; };
	}
};

int main()
{
	double x;
	cout << "Enter the radius:" << " ";
	cin >> x;
	circle c1(x);
	c1.output();

	system("pause");
	return 0;
}
