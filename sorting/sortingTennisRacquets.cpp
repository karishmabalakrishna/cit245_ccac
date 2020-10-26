#include <iostream>
#include <string>
#include <vector>
#include "tennisRacquets.cpp"

vector<double> unsortedGripSize;

void printArray(string message,vector<double> arr)  
{  
  cout << message << '\n';
  for(auto& it : arr){
   cout << it << '\n';
 } 
}

void bubbleSortGripSizes(vector<double> arr){
  int n = arr.size() - 1;
  bool swap = true;

while(swap){
  swap = false;
  for(int i=0;i< n;i++){
    if(arr[i] > arr[i+1]){
      arr[i] += arr[i+1];
      arr[i+1] = arr[i] - arr[i+1];
      arr[i] -= arr[i+1];
      swap = true;
    }
  }
}
 printArray("Bubble sort: ",arr);
}

void SearchSort(vector<double> arr){
   int n = arr.size() - 1;
   int min;
   int temp;

   for(int i=0;i<n-1;i++){
     min = i;
     for(int j=i+1;j<n;j++){
       if(arr[j] < arr[min]){
         min = j;
       }
     }
    temp = arr[min];
    arr[min] = arr[i];
    arr[i] = temp;
   } 
    printArray("Search sort: ",arr);
}



int partition(vector<double> &arr, int low, int high){
  int pivotIndex = low + (high - low) / 2;
    int pivotValue = arr[pivotIndex];
    int i = low, j = high;
    int temp;
    while(i <= j) {
        while(arr[i] < pivotValue) {
            i++;
        }
        while(arr[j] > pivotValue) {
            j--;
        }
        if(i <= j) {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    }

    return i;
}

void quicksort(vector<double> &values, int left, int right) {
    if(left < right) {
        int pivotIndex = partition(values, left, right);
        quicksort(values, left, pivotIndex - 1);
        quicksort(values, pivotIndex, right);
    }
}

int main() {
  
  racquet t1{"Head",2,300};
  racquet t2{"Wilson",4,300};
  racquet t3{"Dunlop",3,285};
  racquet t4{"Wilson",5,300};

unsortedGripSize.push_back(t1.getDiameter());
unsortedGripSize.push_back(t2.getDiameter());
unsortedGripSize.push_back(t3.getDiameter());
unsortedGripSize.push_back(t4.getDiameter());

bubbleSortGripSizes(unsortedGripSize);
SearchSort(unsortedGripSize);
quicksort(unsortedGripSize,0, unsortedGripSize.size() - 1);
printArray("Quick sort: ",unsortedGripSize);
}
