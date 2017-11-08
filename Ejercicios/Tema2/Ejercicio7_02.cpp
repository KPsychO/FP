#include <iostream>

using namespace std;

int main()
{	
	int x = 12;
	double sigma = 2.1836;
	int y = 3;
	double lambda = 1.11695;
	double alfa = 328.67;
	double f;

	f = 3 * ( ( x + sigma * y ) / ( x * x - y * y ) ) - lambda * ( alfa - 13.7 );
	
	cout << x << endl;
	cout << sigma << endl;
	cout << y << endl;
	cout << lambda << endl;
	cout << alfa << endl;
	cout << f << endl;
	
	return 0;
}
