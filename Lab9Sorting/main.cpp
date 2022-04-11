#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

int Partition(int numbers[], int i, int k);
void Quicksort_midpoint(int numbers[], int i, int k);
int Partition_medianOfThree(int numbers[], int i, int k, int leftmost, int midpoint, int rightmost);
void Quicksort_medianOfThree(int numbers[], int i, int k);
void InsertionSort(int numbers[], int numbersSize) ;
int genRandInt(int low, int high);
void fillArrays(int arr1[], int arr2[],int arr3[]);
const int NUMBERS_SIZE = 50000;

int main()
{
    int test1[NUMBERS_SIZE];
    int test2[NUMBERS_SIZE];
    int test3[NUMBERS_SIZE];
    fillArrays(test1, test2, test2);
    const int CLOCKS_PER_MS = CLOCKS_PER_SEC/1000; //clock per milliseconds
    clock_t Start = clock();
    Quicksort_medianOfThree(test1, 0, 50000);
    clock_t End = clock();
    int elapsedTime = (End - Start)/CLOCKS_PER_MS; // converts elapsed time from microseconds to milliseconds.
    cout << "Quicksort_medianOfThree: " << elapsedTime << endl;
    
    clock_t Start1 = clock();
    Quicksort_midpoint(test2, 0, 50000);
    clock_t End1 = clock();
    int elapsedTime1 = (End1 - Start1)/CLOCKS_PER_MS; // converts elapsed time from microseconds to milliseconds.
    cout << "Quicksort_midpoint: " << elapsedTime1 << endl;

    clock_t Start2 = clock();
    InsertionSort(test3, 50000);
    clock_t End2 = clock();
    int elapsedTime2 = (End2 - Start2)/CLOCKS_PER_MS; // converts elapsed time from microseconds to milliseconds.
    cout << "InsertionSort: " << elapsedTime2 << endl;

    return 0;
}

//this function sorts the given array in the range from i to k 
//using quicksort method. In this function, pivot is the midpoint 
//element (numbers[(i+k)/2]). (implementation of this function is 
//given in section 21.5)

int Partition(int numbers[], int i, int k)
{
     // Pick middle element as pivot
    int pivot = numbers[(i+k)/2];
    int temp = 0;
    bool done = false;
    while (!done) {
        // Increment i while numbers[i] < pivot
        while (numbers[i] < pivot) {
            i += 1;
        }
        
        // Decrement k while pivot < numbers[k]
        while (pivot < numbers[k]) {
            k -= 1;
        }
        
        // If zero or one elements remain, then all numbers are 
        // partitioned. Return k.
        if (i >= k) {
            done = true;
        }
        else {
            // Swap numbers[i] and numbers[k]
            temp = numbers[i];
            numbers[i] = numbers[k];
            numbers[k] = temp;
            
            // Update i and k
            i += 1;
            k -= 1;
        }
   }
   
   return k;
}

void Quicksort_midpoint(int numbers[], int i, int k) 
{
    if (i >= k) {
        return;
    }

    int lowEndIndex = Partition(numbers, i, k);
    Quicksort_midpoint(numbers, i, lowEndIndex);
    Quicksort_midpoint(numbers, lowEndIndex + 1, k);

}


//this function utilizes different pivot selection technique in 
//quicksort algorithm. The pivot is the median of the following 
//three values: leftmost (numbers[i]), midpoint (numbers[(i+k)/2]) 
//and rightmost (numbers[k]). You should modify the partition 
//function given in section 21.5 to select the pivot using 
//median-of-three technique.
int Partition_medianOfThree(int numbers[], int i, int k, int leftmost, int midpoint, int rightmost)
{
    int tempS[3];
    tempS[0] = leftmost;
    tempS[1] = midpoint;
    tempS[2] = rightmost;
    InsertionSort(tempS, 3);
    int pivot = tempS[1];
    int temp = 0;
    bool done = false;
    while (!done) {
        // Increment i while numbers[i] < pivot
        while (numbers[i] < pivot) {
            i += 1;
        }
        
        // Decrement k while pivot < numbers[k]
        while (pivot < numbers[k]) {
            k -= 1;
        }
        
        // If zero or one elements remain, then all numbers are 
        // partitioned. Return k.
        if (i >= k) {
            done = true;
        }
        else {
            // Swap numbers[i] and numbers[k]
            temp = numbers[i];
            numbers[i] = numbers[k];
            numbers[k] = temp;
            
            // Update i and k
            i += 1;
            k -= 1;
        }
   }
   
   return k;
}
void Quicksort_medianOfThree(int numbers[], int i, int k)
{
    int leftmost = numbers[i];
    int midpoint = numbers[(i+k)/2];
    int rightmost = numbers[k];

    if (i >= k) {
        return;
    }

    int lowEndIndex = Partition_medianOfThree(numbers, i, k, leftmost, midpoint, rightmost);
    Quicksort_midpoint(numbers, i, lowEndIndex);
    Quicksort_midpoint(numbers, lowEndIndex + 1, k);
} 

//this function sorts the given array using InsertionSort method. 
//(implementation of this method is provided in section 21.3).
void InsertionSort(int numbers[], int numbersSize) 
{
    int sort = 0;
    for (int i = 0; i < numbersSize; ++i)
    {
        int temp = i;
        for (int j = i + 1; j < numbersSize; ++j)
        {
            if (numbers[j] < numbers[temp])
            {
                temp = j;
            }
        }
        sort = numbers[i];
        numbers[i] = numbers[temp];
        numbers[temp] = sort;
    }
}


int genRandInt(int low, int high) {
   return low + rand() % (high - low + 1);
}

void fillArrays(int arr1[], int arr2[],int arr3[]){
    for(int i = 0; i < NUMBERS_SIZE; ++i){
        arr1[i] = genRandInt(0,NUMBERS_SIZE);
        arr2[i] = arr1[i];
        arr3[i] = arr1[i];
    }
}
