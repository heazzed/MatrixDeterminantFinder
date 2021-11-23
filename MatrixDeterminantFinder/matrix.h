#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

class matrix
{
private:
	vector< vector<double> > values;
	int rank;
	double det;
	string path_to_file;

	void build_structure();
	void calculate_rank();
	double calculate_det(vector< vector<double> > matrix, int rank);
public:
	matrix();
	matrix(string path_to_file);

	void set_from_file(string path_to_file);
	void show();
	double get_det();
};