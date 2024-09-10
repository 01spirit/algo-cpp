#include <iostream>
#include <cstdint>

void merge_sort(int* arr, int left, int right);
void merge(int* arr, int left, int mid, int right);

int main(){
    int arr[10] = {3,7,1,9,5,2,6,8,0,4};
    int left = 0, right = 9;
    merge_sort(arr, 0, 9);
    
    for (int i=0; i < right+1; i++) {
        std::cout<< arr[i] << " ";
    }
    std::cout<<std::endl;

    return 0;
}

void merge_sort(int* arr, int left, int right){
    if(left >= right){
        return;
    }
    int mid = (left + right) / 2;

    merge_sort(arr, left, mid);
    merge_sort(arr, mid+1, right);

    merge(arr, left, mid, right);
}

void merge(int* arr, int left, int mid, int right){
    int len_1 = mid - left + 1;
    int len_2 = right - mid;

    int tmp_arr_1[len_1+1];
    int tmp_arr_2[len_2+1];

    for(int i=0; i < len_1; i++){
        tmp_arr_1[i] = arr[left+i];
    }
    for(int i=0; i < len_2; i++){
        tmp_arr_2[i] = arr[mid+1+i];
    }
    tmp_arr_1[len_1] = 1000;
    tmp_arr_2[len_2] = 1000;

    int i=0, j=0;
    for(int k=left; k <= right; k++){
        if(tmp_arr_1[i] < tmp_arr_2[j]){
            arr[k] = tmp_arr_1[i];
            i++;
        } else {
            arr[k] = tmp_arr_2[j];
            j++;
        }
    }
}