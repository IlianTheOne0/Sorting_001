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
void sorting(TValue* arr, int* size, int left, int right)
{
    int i = left;
    int j = right;

    int key = arr[(left + right) / 2];

    do
    {
        while (arr[i] < key) { i++; }

        while (arr[j] > key) { j--; }

        if (i <= j)
        {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;

            i++;
            j--;
        }
    } while (i <= j);

    if (left < j) { sorting<TValue>(arr, size, left, j); }
    if (i < right) { sorting<TValue>(arr, size, i, right); }
}

int main()
{
    int* size = new int{ 10 };
    int* arr = new int[*size];
    init<int>(arr, size);
    print<int, const char>(arr, size, "Array: ");

    sorting<int>(arr, size, 0, *size - 1);
    print<int, const char>(arr, size, "Result: ");

    delete_value<int>(arr, true);
    delete_value<int>(size, ' ');

    char ch = _getch();
    return 0;
}