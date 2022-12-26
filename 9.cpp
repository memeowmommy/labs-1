#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
using namespace std;

class circle
{
private:
	double m_pi = M_PI;
	double m_r = 0;
	long double m_S = 0;

public:
	circle(double rad)
	{
		m_r = rad;
		m_S = c_area(rad);
	}

	bool radius(double rad)
	{
		if (rad <= 0)
		{
			cout << "Wrong radius." << endl;
			return false;
		}
		m_r = rad;
	}

	double c_area(double rad)
	{
		if (radius(rad))
		{
			m_S = (m_r * m_r) * m_pi;
			return m_S;
		}
		return m_S;

	}
	void output()
	{
		if (m_S == 0) { cout << "This circle doesn't exist." << endl; }
		else {cout << m_S << endl; };
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
}
