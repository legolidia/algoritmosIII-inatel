#include<iostream>
using namespace std;

void merge(int arr[], int temp[], int left, int mid, int right, int& contador) {
    int i = left;   
    int j = mid + 1; 
    int k = left;   

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];  
        } else {
            temp[k++] = arr[j++];  
            contador += (mid - i + 1);  
        }
    }

    while (i <= mid) temp[k++] = arr[i++];
    while (j <= right) temp[k++] = arr[j++];

    for (i = left; i <= right; i++) arr[i] = temp[i];
}

void mergeSort(int arr[], int temp[], int left, int right, int& contador) {
    if (left < right) {
        int mid = (left + right) / 2;

        mergeSort(arr, temp, left, mid, contador); 
        mergeSort(arr, temp, mid + 1, right, contador);  
        merge(arr, temp, left, mid, right, contador);
    }
}

int main() {
    int n;
    cin >> n;
    int arr[n], temp[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int contador = 0;
    mergeSort(arr, temp, 0, n - 1, contador);

    cout << contador << endl;

    return 0;
}
