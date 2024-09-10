#include <iostream>

void insertion_sort(int* arr, int len);

int main(){
    int arr[10] = {3,7,1,9,5,2,6,8,0,4};
    int len = 10;

    insertion_sort(arr, len);

    for (int i=0; i < len; i++) {
        std::cout<< arr[i] << " ";
    }
    std::cout<<std::endl;

    return 0;
}

void insertion_sort(int* arr, int len){
    for (int j = 1; j < len; j++) {
        int key = arr[j];
        int i = j-1;
        while (i >= 0 && arr[i] > key) {
            arr[i+1] = arr[i];
            i--;
        }
        arr[i+1] = key;
    }
}