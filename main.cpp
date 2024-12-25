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
    uniform_int_distribution<int> dist(-99, 99);


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
void sorting(TValue* arr, int left, int right)
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

    if (left < j) { sorting<TValue>(arr, left, j); }
    if (i < right) { sorting<TValue>(arr, i, right); }
}

template<typename TValue>
int _mean(TValue* arr, int* size)
{
    int result{};

    for (int i = 0; i < *size; i++)
    {
        result += arr[i];
    }

    return result / *size;
}

template<typename TValue>
void reverse(TValue* arr, int start, int end)
{
    TValue* new_arr = new TValue[end - start]{};
    for (int i = 0; i < end - start; i++)
    {
        new_arr[i] = arr[end - i - 1];
    }

    for (int i = 0; i < end - start; i++)
    {
        arr[start + i] = new_arr[i];
    }

    delete_value(new_arr, true);
}

int main()
{
    int* size = new int{ 15 };
    int* arr = new int[*size];
    init<int>(arr, size);
    print<int, const char>(arr, size, "Array: ");

    int mean = _mean<int>(arr, size);
    cout << endl << endl << "Arithmetic mean: " << mean << endl;

    if (mean > 0)
    {
        cout << "2/3";
        sorting<int>(arr, 0, (*size * (2.0 / 3.0)) - 1);
        reverse<int>(arr, (*size * (2.0 / 3.0)), *size);
    }
    else
    {
        cout << "1/3";
        sorting<int>(arr, 0, (*size * (1.0/3.0)) - 1);
        reverse<int>(arr, (*size * (1.0 / 3.0)), *size);
    }

    cout << " of the array will be sorted. The remaining part is reversed" << endl << endl;
    
    print<int, const char>(arr, size, "Result: ");

    delete_value<int>(arr, true);
    delete_value<int>(size, ' ');

    char ch = _getch();
    return 0;
}