#include<iostream>

using namespace std;

void combine(int *a, int high, int low, int mid) {
    int i, j, k, c[high - low + 1];
    i = low;
    j = mid + 1;
    k = 0;

    for (; i < mid, j < high; k++) {
        if (a[i] <= a[j]) {
            c[k] = a[i];
            i++;
        }
        else {
            c[k] = a[j];
            j++;
        }
    }

    if (i == mid) {
        for (; j < high; j++, k++)
            c[k] = a[j];
    }
    else if (j == high) {
        for (; i < mid; i++, k++)
            c[k] = a[i];
    }

    for (k = low; k < high; k++)
        a[k] = c[k];
}

void merge_sort(int *a, int upper, int lower) {
    if (upper < lower) {
        int mid = (upper + lower) / 2;
        merge_sort(a, mid, lower);
        merge_sort(a, upper, mid + 1);
        combine(a, upper, lower, mid);
    }
}

int main() {
    int a[5] = {1, 3, 2, 4, 5};
    merge_sort(a, 5, 0);

    for (int i = 0; i < 5; i++)
        cout << a[i] << "\t";

    return 0;
}
