#include "matrix.h"
#include <iostream>
#include <fstream>

int main()
{
    //matrix mat("C:\\Users\\User\\Desktop\\matrix.txt");
    setlocale(LC_ALL, "ru");
    matrix mat;
    //mat.set_from_file("C:\\Users\\User\\Desktop\\matrix.txt");
    mat.show();
    double det = mat.get_det();
    cout << "det = " << det;
}