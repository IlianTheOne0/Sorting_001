#include <iostream>
#include <conio.h>
#include <random>
#include <Windows.h>

using std::cout;
using std::endl;
using std::cin;
using std::random_device;
using std::mt19937;
using std::uniform_int_distribution;

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

template<typename TValueL>
void delete_value(TValueL*& value, char indicator)
{
    delete value;
    value = nullptr;
}
template<typename TValueL>
void delete_value(TValueL*& arr, bool indicator)
{
    delete[] arr;
    arr = nullptr;
}

void incorrect()
{
    SetConsoleTextAttribute(hConsole, 4);
    cout << "Incorrect number" << endl;
    SetConsoleTextAttribute(hConsole, 7);
}

void sorted()
{
    SetConsoleTextAttribute(hConsole, 2);
    cout << "Sorted!" << endl;
    SetConsoleTextAttribute(hConsole, 7);
}


template<typename TValue>
void init(TValue* arr, int* size, int min, int max)
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(min, max);


    for (int i = 0; i < *size; i++)
    {
        arr[i] = dist(gen);
    }
}

template<typename TValueL, typename TValueR>
void print(TValueL* value, TValueR* message)
{
    cout << message << *value << endl;
}
template<typename TValueL, typename TValueR>
void print(TValueL* arr, int* size, TValueR* message)
{
    cout << message << endl;

    for (int i = 0; i < *size; i++)
    {
        cout << "\t" << i + 1 << ". " << arr[i] << endl;
    }
    cout << endl;
}

template<typename TValue>
void sorting(TValue* arr, int* size)
{
    for (int i = 0; i < *size - 2; i += 2)
    {
        for (int j = 0; j < *size - i - 2; j += 2)
        {
            if (arr[j] > arr[j + 2])
            {
                int temp = arr[j];
                arr[j] = arr[j + 2];
                arr[j + 2] = temp;

                temp = arr[j + 1];
                arr[j + 1] = arr[j + 3];
                arr[j + 3] = temp;
            }
        }
    }
}

template<typename TValue>
void compare(TValue* arr0, TValue* arr1, int add0, int add1, int* size)
{
    int* new_size = new int{ *size * 2 };
    int* new_arr = new int[*new_size] {};

    for (int j = 0; j < *size; j++)
    {
        new_arr[j * 2 + add0] = arr0[j];
        new_arr[j * 2 + add1] = arr1[j];
    }

    sorting(new_arr, new_size);

    for (int j = 0; j < *size; j++)
    {
        arr0[j] = new_arr[j * 2 + add0];
        arr1[j] = new_arr[j * 2 + add1];
    }

    delete_value<int>(new_arr, true);
    delete_value<int>(new_size, ' ');
}

int main()
{
    int* size = new int{ 10 };

    int* arr0 = new int[*size];
    init<int>(arr0, size, 38000, 999999);

    int* arr1 = new int[*size];
    init<int>(arr1, size, 1111, 9999);

    int choice;
    do
    {
        cout << "Menu:" << endl
            << "1. Sort by mobile phone numbers" << endl
            << "2. Sort by home phone numbers" << endl
            << "3. Display the list of users" << endl
            << "4. Exit" << endl
            << "Option: ";
        cin >> choice;

        if (choice > 4 || choice < 1)
        {

            system("cls");
            incorrect();
            continue;
        }
        else
        {
            switch (choice)
            {
                case 1:
                {
                    system("cls");

                    compare<int>(arr0, arr1, 0, 1, size);
                    sorted();

                    cout << endl << endl << "Press any key to continue..." << endl;
                    char ch = _getch();
                    system("cls");
                } break;
                

                case 2:
                {
                    system("cls");
                    
                    compare<int>(arr0, arr1, 1, 0, size);
                    sorted();

                    cout << endl << endl << "Press any key to continue..." << endl;
                    char ch = _getch();
                    system("cls");
                } break;

                case 3:
                {
                    system("cls");

                    print<int, const char>(arr0, size, "Mobile phone numbers: ");
                    print<int, const char>(arr1, size, "Home phone numbers: ");

                    cout << endl << endl << "Press any key to continue..." << endl;
                    char ch = _getch();
                    system("cls");
                } break;
            }
        }
    } while (choice != 4);


    delete_value<int>(arr0, true);
    delete_value<int>(arr1, true);
    delete_value<int>(size, ' ');

    //char ch = _getch();
    return 0;
}