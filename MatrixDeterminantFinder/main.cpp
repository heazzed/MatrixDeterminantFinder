#include "matrix.h"

void show_action_list()
{
    cout << "Выберите действие:" << endl
        << "'1' - Заполнить матрицу из файлa" << endl
        << "'2' - Посмотреть матрицу" << endl
        << "'3' - Получить определитель матрицы" << endl;
}

void choose_action(int choice, matrix matrix)
{
    string path;

    int new_choice;

    switch (choice)
    {
    case 1:
    {
        cout << "Введите путь к файлу: ";
        cin >> path;
        matrix.set_from_file(path);
        cout << endl;
        show_action_list();
        cin >> new_choice;
        choose_action(new_choice, matrix);
        break;
    }
    case 2:
    {
        matrix.show();
        cout << endl;
        show_action_list();
        cin >> new_choice;
        choose_action(new_choice, matrix);
        break;
    }
    case 3:
    {
        double det = matrix.get_det();
        cout << endl << "det = " << det << endl;
        cout << endl;
        show_action_list();
        cin >> new_choice;
        choose_action(new_choice, matrix);
        break;
    }
    default:
    {
        cout << endl << "Вы ввели неверную команду!" << endl;
        cout << endl;
        show_action_list();
        cin >> new_choice;
        choose_action(new_choice, matrix);
        break;
    }
    }
}

int main()
{
    setlocale(LC_ALL, "ru");

    cout << "Программа для поиска определителя матрицы." << endl << endl
        << "Пожалуйста, вводите только числовые символы." << endl << endl;

    show_action_list();

    int choice;
    cin >> choice;

    matrix matrix;
    choose_action(choice, matrix);
}
