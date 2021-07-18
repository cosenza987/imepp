#include <iostream>
#include <bits/stdc++.h>
#include <stdio.h>
#include <math.h>
#include <cmath>
#include <string>

using namespace std;

void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    for(int i = 0; i < n1; i++) {
        L[i] = arr[l + i];
    }
    for(int i = 0; i < n2; i++) {
        R[i] = arr[m + 1 + i];
    }
    int i = 0, j = 0, k = l;
    while(i < n1 and j < n2) {
        if(L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while(i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while(j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void ms(int arr[], int l, int r) {
    if(l >= r) {
        return;
    }
    int m = l + (r - l) / 2;
    ms(arr, l, m);
    ms(arr, m + 1, r);
    merge(arr, l, m, r);
}

void printar(int A[], int size) {
    for(int i = 0; i < size; i++) {
        printf("%d ", A[i]);
    }
}

int main() {
    int m, i;
    scanf("%d", &m);
    int arr[m];
    for(i = 0; i < m; i++) {
        scanf("%d", &arr[i]);
    }
    ms(arr, 0, m - 1);
    printar(arr, m);
    return 0;
}