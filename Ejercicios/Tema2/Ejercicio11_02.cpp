#include <iostream>
#include <cmath>

using namespace std;

int main()
{	

	double x;
	double y;
	double fxy;
	double e = 2.718281828459045235360;
	double pi;
	double z;
	pi = 3.141592;
	
	cout << "Introduzca el valor de X: " << endl;
	cin >> x;
	cout << "Introduzca el valor de Y: " << endl;
	cin >> y;
	
	z = (x + y);
	
	fxy = ( sqrt ( pow ( 1.531 , z )) + ( abs ( pow ( e , x ) - pow ( e , y ) ) * ( sin ( x ) - tan ( y ))) / ( log10 ( y ) * pow ( pi , x )));
	cout << "f (x, y) = " << fxy << endl;
	
	return 0;
}
