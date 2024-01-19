#include <iostream>
#include <cstdlib> // Include for rand()

using namespace std;

void displayMenu(int*); 
int* randomArray();
void displayArray(int*, int); 
void displayArray(int*, int, int);
void bubbleSort(int*, int); 

int main() {
    int* arr = randomArray();
    displayMenu(arr); 
    //delete[] arr;
    return 0;
}
void displayMenu(int* arr) {
    int select;
    cout << "Hello, welcome to Sorting Algorithms!" << endl;
    cout << "0 - Display Array" << endl;
    cout << "1 - Bubble Sort" << endl;
    cout << "2 - Selection Sort" << endl;
    cout << "3 - Insertion Sort" << endl;
    cout << "Enter: ";
    cin >> select;

    switch (select) {
    
    case 0: 
        cout << "Array elements: ";
        displayArray(arr, 10); 
        break;
    case 1: 
        bubbleSort(arr, 10); 
        break; 
    case 2:
        break;
    case 3:
        break;
    case 4:
        break;
    case 5:
        break;
    default: 
        cout << "Error! Invalid input." << endl; 

    }
    cout << endl; 
    displayMenu(arr); 
}

int* randomArray() {
    int* arr = new int[10];
    int num;
    for (int i = 0; i < 10; i++) {
        num = rand() % 100;
        arr[i] = num;
    }
    return arr;
}

void displayArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void displayArray(int arr[], int size, int code) {
    cout << "hi!"; 
    cout << endl;
}

void bubbleSort(int arr[], int size)
{
    displayArray(arr, size, 1); 
    int i, j;
    bool atLeastOneSwapped;       
    for (i = 0; i < size - 1; i++) {
        atLeastOneSwapped = false;
        for (j = 0; j < size - i - 1; j++) { 
            if (arr[j] > arr[j + 1]) { 
                swap(arr[j], arr[j + 1]); 
                displayArray(arr, size, 1);
                atLeastOneSwapped = true;
            }
        }//Must be at least one swapped in the entire outer loop, else entire array is sorted
        if (atLeastOneSwapped == false) {
            break;
        }
    }
}