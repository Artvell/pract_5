#pragma once
#include "Generator.h"

int Generator::create_matrix()
{
	int m = 0, n = 0;
	vector <int> tmp;
	generate_w_h(&n, &m, 100);
	//cout << n << " | " << m << endl;
	for (int j = 0; j < m; j++) {
		for (int i = 0; i < n; i++) {
			tmp.push_back(rand() % 2);
		}
		matrix.push_back(tmp);
		tmp.clear();
	}
	return 0;
}

int Generator::has_zero_column(vector<int>* result)
{
	int f = 0;
	for (int i = 0; i < matrix[0].size(); i++) {
		int k = 0;
		for (int j = 0; j < matrix.size(); j++) {
			k += matrix[j][i];
		}
		if (k > 0) result->push_back(0);
		else { result->push_back(1); f = 1; }
	}
	return f;
}

void Generator::generate_w_h(int* m, int* n, int max_size) {
	*n = (1 + rand() % max_size);
	*m = (1 + rand() % max_size);
}

int Generator::correct_zero_column(vector<int>* column)
{
	return 0;
}

int Generator::write_to_file()
{
	return 0;
}

int Generator::generate(int k)
{
	return 0;
}


