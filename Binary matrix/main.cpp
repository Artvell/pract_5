#include <iostream>
#include "Generator.h"
#include "Solver.h"
#include <ctime>


using namespace std;

int main() {
	srand(time(NULL));
	int k = 0;
	int n = 1;
	//Generator g;
	//g.generate(n);
	//cout << k << "/" << n;
	Solver s("0.txt");
	s.solve();
	return 0;
}