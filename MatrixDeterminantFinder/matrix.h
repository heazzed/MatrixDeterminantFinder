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
	int size;
	double det;
	string path_to_file;
	vector< vector<double> > values;

	void build_structure();
	void calculate_size();
	double calculate_det(vector< vector<double> > matrix, int rank);
public:
	matrix();
	matrix(string path_to_file);

	void set_from_file(string path_to_file);
	void show();
	double get_det();
};