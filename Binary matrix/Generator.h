#pragma once
#include <iostream>
#include <vector>
using namespace std;


class Generator {
public:
	vector<vector<int>> matrix;
	~Generator() {
		for (int i = 0; i < matrix.size(); i++) {
			matrix[i].clear();
		}
		matrix.clear();
	}
	int create_matrix();
	int has_zero_column(vector<int>* result);
	void generate_w_h(int* n, int* m, int max_size);
	int correct_zero_column(vector<int>* column);
	int write_to_file();
	int generate(int k);
	void print() {
		for (int i = 0; i < matrix.size(); i++) {
			for (int j = 0; j < matrix[i].size(); j++) {
				cout << matrix[i][j] << " ";
			}
			cout << "\n";
		}
	}
};