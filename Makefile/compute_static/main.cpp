#include <iostream>
#include "add.h"
#include "sub.h"
#include "mul.h"

using namespace std;

int main(void)
{
	
	int a = 10, b = 2, c = 0;
	c = add(a, b) + sub(a, b) + mul(a, b);
	cout << "final: " << c << endl;
	return 0;
}