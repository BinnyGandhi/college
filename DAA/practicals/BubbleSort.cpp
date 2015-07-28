#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

using namespace std;

double getTime() {
  struct timeval tv;
  gettimeofday(&tv, NULL);
  return ((tv.tv_sec * 1000000) + tv.tv_usec);
}

void populateWorstCase(int *data, int size) {
  for (int i = 0; i < size; ++i) {
    data[i] = size - i;
  }
}

void populateAverageCase(int *data, int size) {
  srand((unsigned int) time(NULL));
  for (int i = 0; i < size; ++i) {
    data[i] = rand() % size;
  }
}

void populateBestCase(int *data, int size) {
  for (int i = 0; i < size; ++i) {
    data[i] = i;
  }
}

double bubbleSort(int *data, int size) {
  double startTime = getTime();
  bool sorted = true;
  for (int i = 0; ((sorted) && (i < size - 1)); ++i) {
    if (data[i] > data[i + 1]) {
      sorted = false;
    }
  }
  if (!sorted) {
    for (int i = 0; i < size - 1; ++i) {
      for (int j = 0; j < size - i - 1; ++j) {
        if (data[j] > data[j + 1]) {
          data[j] = data[j] + data[j + 1];
          data[j + 1] = data[j] - data[j + 1];
          data[j] = data[j] - data[j + 1];
        }
      }
    }
  }
  double stopTime = getTime();
  return (stopTime - startTime);
}

int main() {
  int *data, size;

  cout << "Enter the problem size: ";
  cin >> size;

  data = new int[size];

  double timeWorstCase, timeAverageCase, timeBestCase;

  populateBestCase(data, size);
  timeBestCase = bubbleSort(data, size);
  cout << "Best Case: " << timeBestCase << endl;

  populateAverageCase(data, size);
  timeAverageCase = bubbleSort(data, size);
  cout << "Average Case: " << timeAverageCase << endl;

  populateWorstCase(data, size);
  timeWorstCase = bubbleSort(data, size);
  cout << "Worst Case: " << timeWorstCase << endl;


  return 0;
}
