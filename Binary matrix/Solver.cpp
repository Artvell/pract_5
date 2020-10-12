#include "Solver.h"
#include <fstream>


int Solver::openWrite()
{
    int n, m, k;
    vector<int> tmp;
    in.open("examples/"+filename);
    if (in.is_open()) {
        in >> strings;
        in >> rows;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < strings; j++) {
                in >> k;
                tmp.push_back(k);
            }
            matrix.push_back(tmp);
            tmp.clear();
        }
        in.close();
        return 0;
    }
    return -1;
    
}

int Solver::maxUnitString()
{
    int ind = 0;
    int max = 0;
    for (int i = 0; i < matrix.size(); i++) {
        int tmp = 0;
        for (int j = 0; j < matrix[i].size(); j++) {
            if (matrix[i][j] == 1) tmp++;
        }
        if (tmp > max) { max = tmp; ind = i; }
    }
    return ind;
}

int Solver::deleteCrossRows()
{
    int ind = maxUnitString();
    vector<vector<int>> tmp;
    vector<int> temp;
    if (!isZerosExists(ind)) {
        matrix.erase(matrix.begin() + ind);
        deleted.push_back(ind);
        return 1;
    }
    for (int i = 0; i < matrix.size(); i++) {
        if (i == ind) continue;
        for (int j = 0; j < matrix[i].size(); j++) {
            if (matrix[ind][j] == 0) {
                temp.push_back(matrix[i][j]);
            }
        }
        tmp.push_back(temp);
        temp.clear();
    }
    matrix = tmp;
    tmp.clear();
    deleted.push_back(ind);
    return 0;
}

bool Solver::isZerosExists(int ind)
{
    for (int i = 0; i < matrix[ind].size(); i++) {
        if (matrix[ind][i] == 0) return true;
    }
    return false;
}

int Solver::writeAnswer()
{
    out.open("answers/" + filename);
    if (out.is_open()) {
        for (int i = 0; i < rows; i++) {
            if (!isExists(i))  out << i + 1 << " ";
        }
        out.close();
        return 0;
    }
    return -1;
}

int Solver::isExists(int n)
{
    for (int i = 0; i < deleted.size(); i++) {
        if (n == deleted[i]) return 1;
    }
    return 0;
}

int Solver::solve()
{
    int res = 0;
    openWrite();
    while (res != 1) {
        res = deleteCrossRows();
    }
    writeAnswer();
    return 0;
}

