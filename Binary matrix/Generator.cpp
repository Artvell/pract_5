#pragma once
#include "Generator.h"
#include <fstream>
#include <ctime>
#include <string>


void Generator::clear()
{
	for (int i = 0; i < matrix.size(); i++) {
		matrix[i].clear();
	}
	matrix.clear();
}

int Generator::create_matrix()
{
	vector <int> tmp;
	generate_w_h();
	for (int j = 0; j < rows; j++) {
		for (int i = 0; i < strings; i++) {
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

void Generator::generate_w_h() {
	strings = (1 + rand() % max_size);
	rows = (1 + rand() % max_size);
}

int Generator::correct_zero_column(vector<int>* columns)
{
	for (int i = 0; i < columns->size(); i++) {
		if (columns->at(i) == 1) {
			//int k = (1 + rand() % columns->size());
			for (int j = 0; j < matrix.size(); j++) {
				matrix[j][i]=(1 + rand() % max_size);
			}
		}
	}
	return 0;
}

int Generator::write_to_file(int i)
{
	string filename = ("examples/" + to_string(i) + ".txt");
	ofstream out;
	out.open(filename);
	if (out.is_open())
	{
		out << strings << " " << rows << endl;
		for (int i = 0; i < matrix.size(); i++) {
			for (int j = 0; j < matrix[i].size(); j++) {
				out << matrix[i][j] << " ";
			}
			out << "\n";
		}
	}
	out.close();
	return 0;
}

int Generator::generate(int k)
{
	for (int i = 0; i < k; i++) {
		create_matrix();
		vector<int>tmp;
		if (has_zero_column(&tmp)) {
			correct_zero_column(&tmp);
			if (has_zero_column(&tmp)) {
				cout << i + 1 << "FATAL " << endl;
				break;
			}
		}
		write_to_file(i);
		tmp.clear();
		clear();
	}
	return 0;
}


