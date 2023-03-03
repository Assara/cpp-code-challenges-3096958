// C++ Code Challenges, LinkedIn Learning

// Challenge #2: Sorting an Array
// Sort the elements in an array in ascending order.
// Implement the algorithm of your choice.
// Don't use STL vectors.
// Don't use a sorting function from a library.

#include <iostream>

// sort_array()
// Summary: This function receives an array of integers and sorts it in ascending order.
// Arguments:
//           arr: A pointer acting as the array to sort.
//           n: The size of the array.
// Returns: A boolean value: True on success, false otherwise.

void swap(int *arr, int i, int j) {
    int tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
}



bool sort_array(int *arr, int n){
    if (n <= 1) {
        return true;
    }
    if (n == 2) {
        if (arr[0] > arr[1]) {
            swap(arr, 0,1);
        }
        return true;
    }
    int up = n-1;
    int down = 1;
    swap(arr, 0, n/2);
    std::cout<<std::endl;

    while (down < up){
        while(down < n && arr[down] < arr[0]) {
            down++;
        }
        while(up > 0 && arr[up] >= arr[0]) {
            up--;
        } 
        if (down < up) {
            swap(arr, up, down);
        }
    }
    swap(arr, 0, up);
    std::cout<<std::endl;
    sort_array(arr, up);
    sort_array(arr+down, n-down);


    // Write your code here

    return true;
}

// Main function
int main(){
    // The following array will be treated as an array of length len. 
    const int len = 4; // Don't exceed the length of the array below!
    int array[] = {1, 0, 2, 3 };

    // Print the original array
    std::cout << "Original Array: [ ";
    for (int i = 0; i < len; i++)
        std::cout << array[i] << " ";
    std::cout << "]" << std::endl << std::endl << std::flush;

    sort_array(array, len); // Sort the array

    // Print the sorted array
    std::cout << "  Sorted Array: [ ";
    for (int i = 0; i < len; i++)
        std::cout << array[i] << " ";
    std::cout << "]" << std::endl << std::endl << std::flush;

    return 0;
}
