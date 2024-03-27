#include <iostream>
#include <algorithm>

void reverseArray(int arr[], int start, int end) {
    while (start < end) {
        std::swap(arr[start], arr[end]);
        start++;
        end--;
    }
}

void rotateArray(int arr[], int size, int rotations) {
    rotations = rotations % size; // handle cases where rotations are greater than the size

    // Reverse the first part of the array (0 to rotations - 1)
    reverseArray(arr, 0, rotations - 1);

    // Reverse the second part of the array (rotations to size - 1)
    reverseArray(arr, rotations, size - 1);

    // Reverse the entire array to get the final result
    reverseArray(arr, 0, size - 1);
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int size = sizeof(arr) / sizeof(arr[0]);
    int rotations = 2; // specify the number of rotations

    std::cout << "Original array: ";
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    rotateArray(arr, size, rotations);

    std::cout << "Array after " << rotations << " right rotations: ";
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
