#include <iostream>
#include <conio.h>
#include <random>

using std::cout;
using std::endl;
using std::cin;
using std::random_device;
using std::mt19937;
using std::uniform_int_distribution;

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

template<typename TValue>
void init(TValue* arr, int* size)
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(0, 99);


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
    cout << message;

    for (int i = 0; i < *size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

template<typename TValue>
void sorting(TValue* arr, int* size)
{
    for (int i = 1; i < *size; i++)
    {
        TValue key = arr[i];
        int j = i - 1;

        while (j >= 0 && key < arr[j])
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

int main()
{
    int* size = new int{ 10 };
    int* arr = new int[*size];
    init<int>(arr, size);
    print<int, const char>(arr, size, "Array: ");

    sorting<int>(arr, size);
    print<int, const char>(arr, size, "Result: ");

    delete_value<int>(arr, true);
    delete_value<int>(size, ' ');

    char ch = _getch();
    return 0;
}