#pragma once
#include <vector>
using namespace std;


class Generator {
public:
	vector<vector<int>> matrix;

	virtual int create_matrix(int n, int m) = 0;
	virtual int has_zero_column() = 0;
	virtual void generate_w_h(int n, int m) = 0;
	virtual int correct_zero_column(vector<int>* column) = 0;
	virtual int write_to_file() = 0;
	virtual int generate(int k) = 0;
};