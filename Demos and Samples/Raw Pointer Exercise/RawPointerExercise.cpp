#include <iostream>
#include <memory>

void displayArray(int arr[], size_t size) {
    std::cout << "[ ";
    for (size_t i=0; i<size; i++) 
        (i != size - 1) ? std::cout << arr[i] << ", " : std::cout << arr[i] << " ";
    std::cout << "]" << std::endl;
}

int* apply_all(int arr1[], size_t size1, int arr2[], size_t size2) {
    // Initialization:
    int* temp = nullptr;
    size_t total_size = size1 * size2;
    temp = new int[total_size];

    // Apply:
    int count = 0;
    for (size_t i=0; i<size2; i++) {
        for (size_t j=0; j<size1; j++) {
            temp[count] = arr2[i] * arr1[j];
            count++;
        }
    }
    return temp;
}

int main() {
    size_t arr1_size = 5, arr2_size = 3;
    int array1[] { 1, 2, 3, 4, 5 };
    int array2[] { 10, 20, 30 };

    std::cout << "Array 1: ";
    displayArray(array1, arr1_size);

    std::cout << "Array 2: ";
    displayArray(array2, arr2_size);

    int* result = apply_all(array1, arr1_size, array2, arr2_size);
    std::cout << "Output : ";
    displayArray(result, 15);

    delete [] result;
    return 0;
}