#include <iostream>
#include <bits/stdc++.h>
#include <string>
using namespace std;
#define ll long long
#define loop(n) for(ll i = 0; i < n; i++)
#include <vector>

void Heap(int arr[], int n, int i) {
    int mx = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[mx])
        mx = left;

    if (right < n && arr[right] > arr[mx])
        mx = right;

    if (mx != i) {
        swap(arr[i], arr[mx]);
        Heap(arr, n, mx);
    }
}

void Build_Heap(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        Heap(arr, n, i);
    }
}

void heap_Sort(int arr[], int n) {
    Build_Heap(arr, n);
    for (int i = n - 1; i >= 1; i--) {
        swap(arr[0], arr[i]);
        Heap(arr, i, 0);
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {

        int arr[] = {16, 21, 14, 8, 13, 2};
        int n = sizeof(arr) / sizeof(arr[0]);
        cout << "Unsorted array: ";
        printArray(arr, n);

        heap_Sort(arr, n);

        cout << "Sorted array: ";
        printArray(arr, n);

        return 0;
}