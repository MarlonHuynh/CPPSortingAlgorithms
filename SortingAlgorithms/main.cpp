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
void bozoSort(int*, int); 

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
    cout << setw(5) << left << " " << "8: Bozo Sort" << endl;
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
        shellSort(arr, 10); 
        break;
    case 5:
        mergeSort(arr, 10); 
        break;
    case 6:
        quickSort(arr, 10); 
        break;
    case 7:
        radixSort(arr, 10); 
        break;
    case 8:
        bozoSort(arr, 10); 
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
/*
------SHELL SORT------
• A variation of the insertion sort
    – But faster than O(n2)
• Done by sorting subarrays of equally spaced
    indices
• Instead of moving to an adjacent location an
    element moves several locations away
    – Results in an almost sorted array
    – This array sorted efficiently with ordinary insertion
    sort
------ANALYSIS------
• Efficiency is O(n2) for worst case
• If n is a power of 2
    – Average-case behavior is O(n1.5)
• Shell sort uses insertion sort repeatedly.
• Initial sorts are much smaller, the later sorts
    are on arrays that are partially sorted, the
    final sort is on an array that is almost
    entirely sorted.
*/
void shellSort(int* arr, int size)
{
    cout << "SHELL SORT - RECURSIVE variation of INSERTION SORT, done by sorting SUBARRAYS of equally spaced GAPS/indices,\nresulting in an almost sorted array that we can use INSERTION sort on. O(n^1.5) COMPLEXITY if n is a power of 2" << endl;
    displayArray(arr, size);
    // Loop over different gap sizes, starting with a big gap and reducing it
    for (int gap = size / 2; gap > 0; gap /= 2)
    {
        cout << "Gap = " << gap << endl; // Display current gap size
        // Loop over the elements with the current gap
        for (int i = gap; i < size; i++)
        {
            int temp = arr[i]; // Store the current element
            int j;
            // Insertion sort within the subarray with the current gap
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
            {
                // Display the current state of the array during the sorting process
                for (int k = 0; k < size; ++k) {
                    if (k == j || k == j - gap) {
                        cout << right << setw(5) << "[" + to_string(arr[k]) + "]";
                    }
                    else { cout << right << setw(5) << arr[k]; }
                }
                cout << endl; // End of display
                arr[j] = arr[j - gap]; // Shift elements to make space for the current element
            }
            arr[j] = temp; // Place the current element in its correct position
        }
    }
}
/*
------MERGE SORT------
• A divide-and-conquer algorithm
• Partitions an array into sub-arrays ➔ until
    sub-array size of 1,
• Then merges two successive sub-arrays by
    comparing items and inserting appropriately
    into a combined array,
• Repeat the process backwards, i.e. merge this
    combined array with its successor
• Well suited for recursion
------ANALYSIS------
• Efficiency is O(n*log2(n)) for any case
    – log2 (n) operations to successively divide into
    sub-arrays for merge
    – n operations to merge for each sub-array
• An extremely fast sort for most situations
*/
void mergeSort(int* arr, int size)
{

}
/*
------QUICK SORT------
• Another divide-and-conquer algorithm
• Partitions an array into items that are
    – Less than or equal to the pivot and
    – Those that are greater than or equal to the pivot
• Partitioning places pivot in its correct position
    within the array
    – Place chosen pivot in either theArray[last] or
    theArray[first] before partitioning
    – Also suited for recursion
------ANALYSIS------
• Analysis
    – Partitioning is an O(n) task
    – There are either log2 n or 1 + log2 n levels of
recursive calls to quickSort.
• We conclude
    – Worst case (either array is sorted or reverse
    sorted) is O(n2)
    – Average case is O(n log n)
*/
void quickSort(int* arr, int size)
{

}
/*
------RADIX SORT------
• Different from other sorts
    – Does not compare entries in an array
• Begins by organizing data (say strings)
    according to least significant letters
    – Then combine the groups
• Next form groups using next least signficant
    letter
------ANALYSIS------
• Analysis
    – Requires n moves each time it forms groups
    – n moves to combine again into one group
    – Performs these 2  n moves d times
    – Thus requires 2  n  d moves
• Radix sort is of order O(n)
    – Useful for limited types of data since data has to
    be same width
• More appropriate for chain of linked lists than
    for an array
*/
void radixSort(int* arr, int size)
{

}

void bozoSort(int* arr, int size)
{
    cout << "BOZO SORT - Randomize and pray." << endl;
    cout << "Array before: " << endl;
    displayArray(arr, size);

    int randIndex; 
    int temp; 
    for (int i = 0; i < size; i++) {
        randIndex = rand() % size; 
        temp = arr[i]; 
        arr[i] = arr[randIndex]; 
        arr[randIndex] = temp;
    }

    cout << "Array after: " << endl;
    displayArray(arr, size);
}