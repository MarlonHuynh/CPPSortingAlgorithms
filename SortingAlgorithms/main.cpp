//Push test

#include <iostream>
#include <cstdlib> // Include for rand()
#include <iomanip> // set(w) 
#include <string> //to_string(s)

using namespace std;

void displayMenu(int*); 
int* randomArray();
void displayArray(int*, int); 
void bubbleSort(int*, int); 
void insertionSort(int*, int); 
void selectionSort(int*, int);
void shellSort(int*, int);
void quickSort(int*, int);
void mergeSort(int*, int);
void radixSort(int*, int);

int main() {
    int* arr = randomArray();
    displayMenu(arr); 
    //delete[] arr;
    return 0;
}
void displayMenu(int* arr) {
    int select;
    cout << "Hello, welcome to Sorting Algorithms!" << endl;
    cout << "-1 - Display current array" << endl; 
    cout << "0 - Randomize Array" << endl;
    cout << "Basic Sorting Algorithms" << endl; 
    cout << "1 - Bubble Sort" << endl;
    cout << "2 - Insertion Sort" << endl;
    cout << "3 - Selection Sort" << endl;
    cout << "Faster sorting Algorithms" << endl; 
    cout << "4 - Shell Sort" << endl;
    cout << "5 - Merge Sort" << endl;
    cout << "6 - Quick Sort" << endl;
    cout << "7 - Radix Sort" << endl;
    cout << "Enter: ";
    cin >> select;
    cout << endl; 

    switch (select) {
    
    case -1: 
        displayArray(arr, 10); 
        break; 
    case 0: 
        arr = randomArray(); 
        displayArray(arr, 10); 
        break;
    case 1: 
        bubbleSort(arr, 10); 
        break; 
    case 2:
        insertionSort(arr, 10); 
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


void displayArray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << right << setw(5) << to_string(arr[i]);
    }
    cout << endl;
}

void bubbleSort(int* arr, int size)
{
    //Display algorithm information 
    cout << "BUBBLE SORT" << endl; 
    cout << "Compares adjacent items and exchanges them if out of order" << endl; 
    cout << "When ordering successive pairs largest item bubbles to end of the array" << endl;
    cout << "Requires several passes over the data until one last pass where no exchange happens" << endl; 
    cout << "Optimization: in successive passes, the largest element of previous pass and beyond can be ignored" << endl;
    cout << "BUBBLE SORT COMPLEXITY" << endl; 
    cout << "Worst case: O(n^2) - array is reverse sorted." << endl; 
    cout << "Best case: O(n) - array is already sorted." << endl; 
    cout << "Average case: O(n^2)" << endl << endl; 

    displayArray(arr, size); 
    int i, j;
    bool atLeastOneSwapped;
    for (i = 0; i < size - 1; i++) {
        atLeastOneSwapped = false;
        for (j = 0; j < size - i - 1; j++) { 
            if (arr[j] > arr[j + 1]) { 
                
                //Display each swapped element
                for (int k = 0; k < size; k++) {
                    if (k == j || k == j+1) {
                        cout << right << setw(5) << "[" + to_string(arr[k]) + "]";
                    }
                    else { cout << right << setw(5) << arr[k]; }
                } 
                cout << endl; // End of display

                swap(arr[j], arr[j + 1]); // Swap
                atLeastOneSwapped = true;
            }
        }//Must be at least one swapped in the entire outer loop, else entire array is sorted
        if (atLeastOneSwapped == false) {
            break;
        }
    }
}

void insertionSort(int* arr, int size) {

    // Display algorithm information
    cout << "INSERTION SORT" << endl; 
    cout << "Take each item from unsorted region and insert it into correct order in sorted region." << endl;
    cout << "Sorted region in the front half of array, unsorted in the back." << endl;
    cout << "Keep moving data from the back half to the front half until it can move no longer, now it's placed in the right position." << endl;
    cout << "Sometimes called \"Reverse Bubble Sort\"." << endl;
    cout << "One pass through the array, multiple passes in the reverse direction." << endl;
    cout << "INSERTION SORT EFFICIENCY" << endl;
    cout << "Worst case: O(n^2) - array is reverse sorted" << endl;
    cout << "Best case: O(n)" << endl;
    cout << "Average case: O(n^2)" << endl;
    displayArray(arr, size);

    for (int i = 1; i < size; i++) {
        int key = arr[i]; // The second element is the first key.
        int j = i - 1; // j is the index left of the first key.

        // Move elements from 0 to j that are greater than key to one position ahead of their current position
        while (j >= 0 && arr[j] > key) { 
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key; // Move the key into the slot left behind

        //Display each step
        for (int k = 0; k < size; k++) {
            if (k == j + 1) {
                cout << right << setw(7) << "[" + to_string(arr[k]) + "]"; 
            }
            else { cout << right << setw(7) << arr[k]; }
        }
        cout << endl; //End of display
    }
}

void selectionSort(int* arr, int size)
{

}

void shellSort(int* arr, int size)
{

}

void mergeSort(int* arr, int size)
{

}

void quickSort(int* arr, int size)
{

}

void radixSort(int* arr, int size)
{

}