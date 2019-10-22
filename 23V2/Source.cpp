#include <iostream>
#include "Header.h"

using namespace std;

int main()
{
	cout << "Gavryliuk Oksana\n" << "Program will delete line and column which contain abs(max) element in bottom segment\n";

	Matrix mat;
	const int N = 500;

	if (mat.get_matrix(N))
	{
		mat.max();
		mat.out_matrix();
	}

	system("pause");

	return 0;
}