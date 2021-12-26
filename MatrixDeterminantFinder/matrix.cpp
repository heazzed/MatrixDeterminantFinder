#include "matrix.h"

matrix::matrix() {}

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
			cout << endl << "Некорректная матрица для вычисления определителя." << endl;
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

	double temp = 0.0;
	double default_double = temp;
	int elements_count = 0;
	bool is_alpha = false;

	getline(file, sup_str);

	if (sup_str.size() == 0)
	{
		size = 0;
		return;
	}

	file.seekg(0);

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
			if (isalpha(rows[i][j]))
			{
				size = -2;
				return;
			}
		}
	}

	file.seekg(0);

	if (!is_alpha && sup_str.size() != 0)
	{
		while (!file.eof())
		{
			file >> temp;
			elements_count++;
		}
	}

	file.seekg(0);

	if (rows.size() != 0 && size != -2)
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
	
}

void matrix::build_structure()
{
	if (size == 0)
	{
		cout << endl << "Файл пуст. Матрица не была заполнена." << endl;
		return;
	}

	if (size == -1)
	{
		cout << endl << "Матрица не является квадратной. " << endl
			<< "Нахождение определителя имеет смысл только для квадратной матрицы." << endl
			<< "Исправьте значения в файле или укажите путь к другому файлу." << endl;
		return;
	}

	if (size == -2)
	{
		cout << endl << "Матрица введена неверно. Файл имеет нечисловые символы." << endl;
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

	if(!file.is_open())
	{
		cout << endl << "Не удалось открыть файл." << endl
			<< "Проверьте правильность введенного пути к файлу." << endl;
		return;
	}

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

	if (values.size() == size && size != 0)
	{
		cout << endl << "Матрица успешно заполнена значениями из файла " << path_to_file << endl;
	}
}

void matrix::show()
{
	if (path_to_file == "" || values.size() == 0)
	{
		cout << endl << "Матрица не заполнена значениями." << endl
			<< "Необходимо заполнить матрицу для просмотра." << endl
			<< "Вы можете внести значения из файла, используя функцию '1'" << endl;
	}
	else
	{
		if (size > 0)
		{
			cout << endl << "Матрица:" << endl;
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
