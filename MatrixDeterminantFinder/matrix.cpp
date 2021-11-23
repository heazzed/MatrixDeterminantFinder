#include "matrix.h"
matrix::matrix(){}

matrix::matrix(string path_to_file)
{
	set_from_file(path_to_file);
}

double matrix::calculate_det(vector< vector<double> > matrix, int rank)
{
	switch (rank)
	{
	case 1:
		return det = matrix[0][0];
	case 2:
		return det = matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
	default:
		if (rank < 1) 
		{
			cout << "Incorrect matrix!\n";
			return 0;
		}
		double sup_det = 0;
		for (int k = 0; k < rank; k++)
		{		
			vector< vector<double> > sub_matrix;
			sub_matrix.resize(rank - 1);
			for (int i = 0; i < sub_matrix.size(); i++)
			{
				sub_matrix[i].resize(rank - 1);
			}
			for (int i = 1; i < rank; i++)
			{
				int t = 0;
				for (int j = 0; j < rank; j++)
				{
					if (k == j)
					{
						continue;
					}
					sub_matrix[i - 1][t] = matrix[i][j];
					t++;
				}
			}
			sup_det += pow(-1, k + 2) * matrix[0][k] * calculate_det(sub_matrix, rank - 1);
		}
		return det = sup_det;
	}
}

void matrix::calculate_rank()
{
	vector<string> rows;
	string sup_str;
	ifstream file;
	file.open(path_to_file);
	int elements_in_row_count = 0;
	while (!file.eof())
	{
		getline(file, sup_str);
		if (sup_str == "")
		{
			continue;
		}
		rows.push_back(sup_str);
	}
	for (int i = 0; i < rows[0].length(); i++)
	{
		if (rows[0][i] == char(32))
		{
			continue;
		}
		elements_in_row_count++;
	}
	if(rows.size() != elements_in_row_count)
	{
		rank = 0;
	}
	else
	{
		rank = rows.size();
	}
}

void matrix::build_structure() 
{
	this->values.resize(rank);
	for (int i = 0; i < rank; i++)
	{
		this->values[i].resize(rank);
	}
}

void matrix::set_from_file(string path_to_file)
{
	this->path_to_file = path_to_file;
	ifstream file;
	file.open(path_to_file);
	
	calculate_rank();
	build_structure();

	for (int i = 0; i < rank; i++)
	{
		for (int j = 0; j < rank; j++)
		{
			file >> this->values[i][j];
		}
	}
}

void matrix::show() 
{
	if (path_to_file == "")
	{
		cout << "You created matrix but not set values.\n"
			"You can read it from file using method \'set_from_file\'\n";
	}
	else
	{
		cout << "Matrix is:" << endl;
		for (int i = 0; i < rank; i++)
		{
			for (int j = 0; j < rank; j++)
			{
				cout << setw(5) << this->values[i][j];
			}
			cout << endl;
		}
	}
}

double matrix::get_det()
{
	calculate_det(values, rank);
	return det;
}
