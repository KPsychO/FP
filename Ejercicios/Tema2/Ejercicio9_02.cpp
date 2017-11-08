#include <iostream>

using namespace std;

int main() 
{	

	int a = 1;
	double d = 1.0;
	
	a = 1;
	a = 46 % 9 + 4 * 4 - 2;
	cout << "a = 46 % 9 + 4 * 4 - 2" << endl;
	cout << a << endl;
	
	a = 1;
	a = 45 + 43 % 5 * (23 * 3 % 2);
	cout << "a = 45 + 43 % 5 * (23 * 3 % 2)" << endl;
	cout << a << endl;
	
	a = 1;
	a = 45 + 45 * 50 % a--;
	cout << "a = 45 + 45 * 50 % a--" << endl;
	cout << a << endl;
	
	d = 1.0;
	d = 1.5 * 3 + (++d);
	cout << "d = 1.5 * 3 + (++d)" << endl;
	cout << d << endl;
	
	d = 1.0;
	d = 1.5 * 3 + d++;
	cout << "d = 1.5 * 3 + d++" << endl;
	cout << d << endl;
	
	a = 1;
	a %= 3 / a + 3;
	cout << "a %= 3 / a + 3" << endl;
	cout << a << endl;
	
	return 0;
}
