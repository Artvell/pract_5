#include <iostream>
#include "Generator.h"
#include <ctime>


using namespace std;

int main() {
	srand(time(NULL));
	int k = 0;
	int n = 10000;
	Generator g;
	g.generate(n);
	//cout << k << "/" << n;
	return 0;
}