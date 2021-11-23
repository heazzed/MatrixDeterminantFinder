#include <iostream>
#include "matrix.h"
#include <fstream>

int main()
{
    //matrix mat("C:\\Users\\User\\Desktop\\matrix.txt");
    matrix mat;
    mat.set_from_file("C:\\Users\\User\\Desktop\\matrix.txt");
    mat.show();
    double det = mat.get_det();
    cout << "det = " << det;
}