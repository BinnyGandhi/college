#include <iostream>
#include <sys/time.h>

using namespace std;

double getTime() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return ((tv.tv_sec * 1000000) + tv.tv_usec);
}

void populateWorstCase(int data[], int size) {
    for (int i = 0; i < size; ++i) {
        data[i] = size - i;
    }
}

void populateAverageCase(int data[], int size) {
    srand((unsigned int) time(NULL));
    for (int i = 0; i < size; ++i) {
        data[i] = rand() % size;
    }
}

void populateBestCase(int data[], int size) {
    for (int i = 0; i < size; ++i) {
        data[i] = i;
    }
}

int partition(int a[], int p, int r) {
    int pivot = a[p];
    int low = p;
    int high = r;

    while (low < high) {
        while (a[low] <= pivot && low < r)
            low++;
        while (a[high] > pivot)
            high--;
        if (low < high) {
            int temp = a[low];
            a[low] = a[high];
            a[high] = temp;
        }
    }
    a[p] = a[high];
    a[high] = pivot;
    return high;
}

double quickSort(int a[], int p, int r) {
    double startTime = getTime();
    if (p < r) {
        int q = partition(a, p, r);
        quickSort(a, p, q - 1);
        quickSort(a, q + 1, r);
    }

    double stopTime = getTime();
    return (stopTime - startTime);

}

int main() {
    int data[20], size;

    cout << "enter the number of elements:\t";
    cin >> size;

    double timeWorstCase, timeAverageCase, timeBestCase;

    populateBestCase(data, size);
    timeBestCase = quickSort(data, 0, size);
    for (int i = 0; i < size; i++) {
        cout << "\t" << data[i];
    }

    cout << "\nBest Case: " << timeBestCase << endl;

    populateAverageCase(data, size);
    timeAverageCase = quickSort(data, 0, size);
    for (int i = 0; i < size; i++) {
        cout << "\t" << data[i];
    }
    cout << "\nAverage Case: " << timeAverageCase << endl;

    populateWorstCase(data, size);
    timeWorstCase = quickSort(data, 0, size);
    for (int i = 0; i < size; i++) {
        cout << "\t" << data[i];
    }
    cout << "\nWorst Case: " << timeWorstCase << endl;

    return 0;
}
