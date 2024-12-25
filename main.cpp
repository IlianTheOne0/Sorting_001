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
        cout << "\t" << i << ". " << arr[i] << endl;
    }
    cout << endl;
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
            incorrect();
            continue;
        }
    } while (choice != 4);

    /*print<int, const char>(arr0, size, "Mobile phone numbers: ");
    print<int, const char>(arr1, size, "Home phone numbers: ");*/
    delete_value<int>(arr0, true);
    delete_value<int>(arr1, true);
    delete_value<int>(size, ' ');

    char ch = _getch();
    return 0;
}