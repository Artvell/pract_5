#pragma once
#include <iostream>
#include <vector>
using namespace std;


class Generator {
public:
	vector<vector<int>> matrix;
	int max_size = 100;
	void clear();//done
	int create_matrix(); //done
	int has_zero_column(vector<int>* result); //done
	void generate_w_h(int* n, int* m); //done
	int correct_zero_column(vector<int>* column); //done
	int write_to_file(int i);//done
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