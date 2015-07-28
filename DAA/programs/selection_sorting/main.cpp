#include <iostream>

using namespace std;

void selectionSort(int *data, int size) {
    int j = size;

    for (int i = 0, maximum = 0; i < size; i++, j--, maximum = 0) {
        for (int k = 0; k < j; k++) {
            if (data[maximum] < data[k]) {
                maximum = k;
            }
        }
        int temp=data[maximum];
        data[maximum] = data[j - 1];
        data[j - 1] = temp;
    }
}

int main() {
    int data[20], size;
    cout << "enter size of data:\t";
    cin >> size;

    cout << "\nenter elements:\n";
    for (int i = 0; i < size; i++) {
        cin >> data[i];
    }

    selectionSort(data, size);

    cout << "\nsorted elements:\n";
    for (int i = 0; i < size; i++) {
        cout << data[i] << "\t";
    }

    return 0;
}