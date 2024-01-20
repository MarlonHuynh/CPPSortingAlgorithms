/*
Description: Test program used to test and visually display different types of sorting algorithms
Author: Betty Huynh
Date: January 2024
*/

#include <iostream>
#include <cstdlib> // Include for rand()
#include <iomanip> // setw(n) 
#include <string> // to_string(s)

using namespace std;

// Prototypes
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
    cout << "-------------------------------------" << endl;
    cout << "Hello, welcome to Sorting Algorithms!" << endl;
    cout << "-------------------------------------" << endl;
    cout << "Basic Array Functions" << endl;
    cout << setw(5) << left << " " << "-1: Display current array" << endl;
    cout << setw(5) << left << " " << "0: Randomize Array" << endl;
    cout << "Basic Sorting Algorithms" << endl;
    cout << setw(5) << left << " " << "1: Bubble Sort" << endl;
    cout << setw(5) << left << " " << "2: Insertion Sort" << endl;
    cout << setw(5) << left << " " << "3: Selection Sort" << endl;
    cout << "Faster sorting Algorithms" << endl;
    cout << setw(5) << left << " " << "4: Shell Sort" << endl;
    cout << setw(5) << left << " " << "5: Merge Sort" << endl;
    cout << setw(5) << left << " " << "6: Quick Sort" << endl;
    cout << setw(5) << left << " " << "7: Radix Sort" << endl;
    cout << "Enter a number: ";
    cin >> select;
    cout << endl; 

    switch (select) {
    
    case -1: 
        cout << "Displaying current array!" << endl;
        displayArray(arr, 10); 
        break; 
    case 0: 
        cout << "Generating and displaying random array!" << endl;
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
        selectionSort(arr, 10); 
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

// TODO: Dynamic array sizes and max rand integers
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
/*
------THE BUBBLE SORT------
• Compares adjacent items - exchanges them if
out of order
• When ordering successive pairs - largest item
bubbles to end of the array
• Requires several passes over the data – until
one last pass where no exchange happens
• Optimization – in successive passes, the
largest element of previous pass and beyond
can be ignored
------ANALYSIS------
• Analysis – algorithm efficiency
    – Worst case (array is reverse sorted) is O(n^2)
    – Best case (array already in order) is O(n)
    – Average case is O(n2) :
    • n-1, n-2, n-3, ..., 3, 2, 1, 0 comparisons for successive
        passes ➔ (n(n+1))/2 operations
    • Assuming 50% of comparisons resulted in swaps ➔
    (n(n+1))/4 operations
    • Total = add both ➔ (3/4)(n(n+1)) operations
    • Expand, drop multipliers, lower order items ➔ O(n^2)
• Analysis – when to use
    – Average case of bubble sort is O(n2)
    – Appropriate only for small n
    – Or to verify is data is already sorted
    – O(n2) grows rapidly
• Could be a good choice when
    – Both comparisons and swaps are not significant in
    computing power costs
*/
void bubbleSort(int* arr, int size)
{
    cout << "BUBBLE SORT - LOOPS through ARRAY, SWAPPING any ADJACENT elements that are out of order, until sorted. O(n^2) COMPLEXITY\n[] symbol denotes number being swapped" << endl; 
    displayArray(arr, size); 
    int i, j;
    bool atLeastOneSwapped;
    for (i = 0; i < size - 1; i++) {
        atLeastOneSwapped = false;
        for (j = 0; j < size - i - 1; j++) { 
            if (arr[j] > arr[j + 1]) { 
                
                // Display each swapped element
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
        }
        // Must be at least one swapped in the entire outer loop, else entire array is sorted
        if (atLeastOneSwapped == false) {
            break;
        }
    }
}
/* 
------THE INSERTION SORT------
• Take each item from unsorted region
    – Insert it into correct order in sorted region
    – Sorted region in the front half of array, unsorted
    region at the back
    – Keep moving data from the back half to the front
    half until it can move no longer – now placed in
    rightful position
    – Sometimes also called the ‘Reverse Bubble Sort’
    – One pass through the array, multiple passes in the
    reverse direction
------ANALYSIS------
• Analysis – algorithm efficiency
    – Average case is O(n2) : if x comparisons in reverse
    direction, then x-1 swaps
• Assuming 50% of (n-1, n-2, n-3, ..., 3, 2, 1, 0)
    comparisons + swaps for successive passes ➔
    (n(n+1))/2 operations
• Expand, drop multipliers, lower order items ➔ O(n2)
    – Worst case (array is reverse sorted) is O(n2)
• 100% comparisons and swaps = n(n+1) operations
    – Best case (array already in order) is O(n)
• Analysis – when to use
    – Average case of insertion sort is O(n2)
    – Appropriate only for small n
    – Or to verify is data is already sorted
    – O(n2) grows rapidly
• Could be a good choice when
    – Both comparisons and swaps are not significant in
    computing power costs
*/
void insertionSort(int* arr, int size) {

    cout << "INSERTION SORT - LOOPS and SELECTS an element from UNSORTED region (does not need to be the smallest). INSERT it in the SORTED region in CORRECT order. O(n^2) COMPLEXITY\n| represents the division between sorted and unsorted\n The number to the right of | is the next unsorted item to be sorted" << endl;
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

        // Display each step
        for (int k = 0; k < size; k++) {
            cout << right << setw(5) << arr[k];
            if (k == i) {
                cout << right << setw(5) << "|"; 
            }
        }
        cout << endl; // End of display
    }
}


/*
------THE SELECTION SORT------
• Find the smallest or the largest element in the
array and put it in the right position
– Temp var to hold the smallest or largest element
– Update the temp var as needed when compared
to all elements
• When desired element found
– Swap with the element at the first (smallest) or
last (largest) location.
– Repeat process for remaining array
------ANALYSIS------
• Analysis – algorithm efficiency
– Average case is O(n2) :
• n-1, n-2, n-3, ..., 3, 2, 1, 0 comparisons for successive passes ➔
(n(n+1))/2 operations
• One swap per pass, 50% passes swap ➔ n/2 operations
• Total = add both ➔ n/2 + (n(n+1))/2 operations
• Expand, drop multipliers, lower order items ➔ O(n2)
– Worst case (array is reverse sorted) is O(n2)
• Same comparisons as above, every pass has a swap
– Best case (array already in order) is O(n2)
• Same comparisons as above, no swaps
*/
void selectionSort(int* arr, int size) {
    cout << "SELECTION SORT - LOOPS through to SELECT the LOWEST element, then PLACE it in the MINIMUM index, INCREASING the MINIMUM index for every pass. O(n^2) COMPLEXITY" << endl;
    displayArray(arr, size);
    for (int i = 0; i < size - 1; ++i) {
        // Assume the current index is the minimum
        int minIndex = i;
        // Find the index of the minimum element in the unsorted part of the array
        for (int j = i + 1; j < size; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        // Swap the found minimum element with the first element
        swap(arr[i], arr[minIndex]);
        
        // Display each step
        for (int k = 0; k < size; ++k) {
            if (k == minIndex) {
                cout << right << setw(5) << "[" + to_string(arr[k]) + "]";
            } else { cout << right << setw(5) << arr[k]; }
        }
        cout << " The minimum element " << arr[i] << " is getting swapped with the i index element " << arr[minIndex] << endl; // End of display
    }
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