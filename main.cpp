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
void reverse(TValue* arr, int end)
{
    int start = 0;

    while (start < end)
    {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;

        start++;
        end--;
    }
}

template<typename TValue>
void sorting(TValue* arr, int* size)
{
    for (int i = *size; i > 1; i--)
    {
        int max_ = 0;

        for (int j = 1; j < i; j++)
        {
            if (arr[j] > arr[max_])
            {
                max_ = j;
            }
        }

        if (max_ != i - 1)
        {
            reverse<TValue>(arr, max_);
            reverse<TValue>(arr, i - 1);
        }
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