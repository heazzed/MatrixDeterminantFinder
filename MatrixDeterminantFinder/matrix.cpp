#include "matrix.h"

matrix::matrix(){}

matrix::matrix(string path_to_file)
{
	set_from_file(path_to_file);
}

double matrix::calculate_det(vector< vector<double> > matrix, int size)
{
	switch (size)
	{
	case 1:
		return det = matrix[0][0];
	case 2:
		return det = matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
	default:
		if (size < 1) 
		{
			cout << "Некорректная матрица для вычисления определителя!\n";
			return 0;
		}
		double sup_det = 0;
		for (int k = 0; k < size; k++)
		{		
			vector< vector<double> > sub_matrix;
			sub_matrix.resize(size - 1);
			for (int i = 0; i < sub_matrix.size(); i++)
			{
				sub_matrix[i].resize(size - 1);
			}
			for (int i = 1; i < size; i++)
			{
				int t = 0;
				for (int j = 0; j < size; j++)
				{
					if (k == j)
					{
						continue;
					}
					sub_matrix[i - 1][t] = matrix[i][j];
					t++;
				}
			}
			sup_det += pow(-1, k + 2) * matrix[0][k] * calculate_det(sub_matrix, size - 1);
		}
		return det = sup_det;
	}
}

void matrix::calculate_size()
{
	vector<string> rows;
	string sup_str;
	ifstream file;

	file.open(path_to_file);
	int elements_count = 0;

	while (!file.eof())
	{
		getline(file, sup_str);
		if (sup_str == "")
		{
			continue;
		}
		rows.push_back(sup_str);
	}

	for (int i = 0; i < rows.size(); i++)
	{
		for (int j = 0; j < rows[i].length(); j++)
		{
			if (rows[i][j] == char(32))
			{
				continue;
			}
			if (rows[i][j] == char(44) || rows[i][j] == char(46))
			{
				elements_count--;
				continue;
			}
			elements_count++;
		}
	}

	if (rows.size() != 0)
	{
		if ((double)rows.size() != (double)elements_count / (double)rows.size())
		{
			size = -1;
		}
		else
		{
			size = rows.size();
		}
	}
	else
	{
		size = 0;
	}
}

void matrix::build_structure() 
{
	if(size == 0)
	{
		cout << "Матрица не введена. Файл пуст. \n";
		return;
	}

	if (size == -1)
	{
		cout << "Матрица не является квадратной. Возможно, файл имеет не числовые значения.\n";
		return;
	}

	this->values.resize(size);

	for (int i = 0; i < size; i++)
	{
		this->values[i].resize(size);
	}
}

void matrix::set_from_file(string path_to_file)
{
	this->path_to_file = path_to_file;
	ifstream file;

	file.open(path_to_file);
	
	calculate_size();
	build_structure();
	
	if (size > 0)
	{
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				file >> this->values[i][j];
			}
		}
	}
}

void matrix::show() 
{
	if (path_to_file == "")
	{
		cout << "Вы создали матрицу, но не заполнили ее значениями.\n"
			"Вы можете внести значения из файла, используя метод \'set_from_file()\'.\n"
			"Вы также можете передать путь к файлу в качестве параметра конструктора класса \'matrix\'.\n";
	}
	else
	{
		if (size > 0)
		{
			cout << "Матрица:" << endl;
			for (int i = 0; i < size; i++)
			{
				for (int j = 0; j < size; j++)
				{
					cout << setw(5) << this->values[i][j];
				}
				cout << endl;
			}
		}
	}
}

double matrix::get_det()
{
	calculate_det(values, size);
	return det;
}
