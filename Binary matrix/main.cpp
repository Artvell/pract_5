#include <iostream>
#include "Generator.h"
#include <ctime>
using namespace std;

int main() {
	srand(time(NULL));
	int k = 0;
	int n = 100000;
	for (int i = 0; i < n; i++) {
		Generator g;
		g.create_matrix();
		//g.print();
		vector<int>tmp;
		if (g.has_zero_column(&tmp)) {
			cout << i + 1 << " YES " << endl;
			k++;
		}
		tmp.clear();
		g.~Generator();
		///for (int i = 0; i < tmp.size(); i++) { cout << tmp[i] << " "; }
	}
	cout << k << "/" << n;
	return 0;
}