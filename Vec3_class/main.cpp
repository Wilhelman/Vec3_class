#include <iostream>

#include "DynArray.h"
#include "LinkedList.h"
#include "Vec3.h"

using namespace std;

int main() {

	Vec3<int> v1(1, 3, 2);
	Vec3<int> v2(1, 3, 2);
	Vec3<int> v3(7, 4, 1);

	Vec3<float> v4(-4.6f, 2.12f, -2.4f);
	Vec3<float> v5(7.0f, 4.25f, -5.98f);

	// Testing gets and sets
	cout << v1.x << endl;
	cout << v5.z << endl;
	v5.z = -6.0f;
	cout << v5.z << endl;
	v1.zero();
	cout << v1.y << endl;

	// Testing operators
	if (v1 == v2)
		cout << "Equals" << endl;
	else
		cout << "Not equals" << endl;

	v1.x = 1;
	v1.y = 3;
	v1.z = 2;

	if (v1 == v2)
		cout << "Equals" << endl;
	else
		cout << "Not equals" << endl;

	v3 -= v2;
	v3.displayVector();

	v5 *= 2;
	v5.displayVector();

	v1.x = 5;
	v1.displayVector();
	v2.displayVector();
	cout << "Distance between v1 and v2: " <<  v1.getDistance(v2) << endl;

	system("pause");

	return 0;
}