#pragma once
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;


class Solver {
public:
	vector<vector<int>> matrix;
	int strings, rows;
	vector<int> deleted;
	ifstream in;
	ofstream out;
	string filename;
	Solver(string name) {
		filename = name;
	}
	int openWrite(); //done
	int maxUnitString(); //done
	int deleteCrossRows(); //done
	bool isZerosExists(int ind);
	int writeAnswer();
	int solve();
	int isExists(int n);
	void print() {
		for (int i = 0; i < matrix.size(); i++) {
			for (int j = 0; j < matrix[i].size(); j++) {
				cout << matrix[i][j] << " ";
			}
			cout << "\n";
		}
	}
};