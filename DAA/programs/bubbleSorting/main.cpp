#include <iostream>

using namespace std;

void bubbleSort(int list[], int size) {
    for (int i = 1; i < size; i++) {
        for (int k = 0; k < size - i; k++) {
            if (list[k] > list[k + 1]) {
                int temp = list[k + 1];
                list[k + 1] = list[k];
                list[k] = temp;
            }
        }
    }
}


int main() {
    int size;
    cout << "enter size:";
    cin >> size;

    int list[size];
    cout << "\nenter elements:\n";
    for (int i = 0; i < size; i++) {
        cin >> list[i];
    }

    bubbleSort(list, size);
    cout << "\nsorted:\n";
    for (int i = 0; i < size; i++) {
        cout << list[i] << "\t";
    }
    return 0;
}