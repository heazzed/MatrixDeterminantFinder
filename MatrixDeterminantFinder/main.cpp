#include "matrix.h"

int main()
{
    setlocale(LC_ALL, "ru");
    matrix mat("C:\\Users\\User\\Desktop\\matrix.txt");
    //matrix mat;
    //mat.set_from_file("C:\\Users\\User\\Desktop\\matrix.txt");
    mat.show();
    double det = mat.get_det();
    cout << "det = " << det;
}