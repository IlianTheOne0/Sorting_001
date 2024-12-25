#include <iostream>
#include <conio.h>
#include <Windows.h>

using std::cout;
using std::endl;
using std::cin;

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
void init(TValue* arr, int* size)
{
    int i = 0;
    int input{};
    
    do
    {
        if (i == *size)
        {
            break;
        }

        cout << "Enter the grade num." << i + 1 << ": ";
        cin >> input;
   
        if (input > 12 || input < 1)
        {
            incorrect();
            continue;
        }
       
        arr[i] = input;
        
        i++;
    } while (i != *size);

    cout << endl;
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
bool scholarship(double gpa)
{
    cout << "Scolarship: ";
    
    if (gpa >= 10.7)
    {
        SetConsoleTextAttribute(hConsole, 2);
        cout << "available" << endl;
        SetConsoleTextAttribute(hConsole, 7);
        return true;
    }

    SetConsoleTextAttribute(hConsole, 4);
    cout << "not available" << endl;
    SetConsoleTextAttribute(hConsole, 7);
    return false;
}

template<typename TValue>
bool GPA(TValue* arr, int* size)
{
    double gpa = 0;

    for (int i = 0; i < *size; i++)
    {
        gpa += arr[i];
    }

    gpa /= *size;

    cout << "GPA: " << gpa << endl;
    
    return scholarship<int>(gpa);
}

template<typename TValue>
void retake(TValue* arr, int* size)
{

    system("cls");

    cout << "num:\t";
    for (int i = 0; i < *size; i++)
    {
        cout << i + 1 << "  ";
    }
    cout << endl;
    print(arr, size, "Grades: ");
    cout << endl << endl;

    int input;
    
    do
    {
        cout << "Enter the number of the grade you want to retake?" << endl << "num.: ";
        cin >> input;

        if (input > 10 || input < 1)
        {
            incorrect();
            continue;
        }
        else
        {
            break;
        }
    } while (true);

    input--;

    do
    {
        cout << "Enter the grade num." << input + 1 << ": ";
        cin >> arr[input];

        if (arr[input] > 12 || arr[input] < 1)
        {
            incorrect();
            continue;
        }
        else
        {
            break;
        }
    } while (true);
}

int main()
{
	int* size = new int{ 10 };

    //int* arr = new int[*size] { 10, 10, 10, 10, 10, 10, 10, 10, 10, 10 };
    //int* arr = new int[*size] { 12, 12, 12, 12, 12, 12, 12, 12, 12, 12 };
    int* arr = new int[*size];
    init<int>(arr, size);

    int choice;
    do
    {
        system("cls");
     
        cout << "Menu:" << endl
            << "1. Display grades" << endl
            << "2. Retake the exam" << endl
            << "3. Is a scholarship available?" << endl
            << "4. Exit" << endl
            << "Option: ";
        cin >> choice;

        if (choice > 4 || choice < 1)
        {
            incorrect();
            continue;
        }
        else
        {
            switch (choice)
            {
                case 1: {
                    system("cls");

                    print(arr, size, "Grades: ");

                    cout << endl << endl << "Press any key to continue..." << endl;
                    char ch = _getch();
                } break;

                case 2: { retake<int>(arr, size); } break;

                case 3: {
                    system("cls");

                    GPA<int>(arr, size);

                    cout << endl << endl << "Press any key to continue..." << endl;
                    char ch = _getch();
                } break;
            }
        }
    } while (choice != 4);
    
    delete_value(arr, true);
    delete_value(size, ' ');

	return 0;
}