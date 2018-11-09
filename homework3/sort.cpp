// Cinkye 2018.11.5 201730684427
// A file with many sorting functions and their testbench       sort.cpp

#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <iomanip>
#include "heap.h"

using namespace std;

void insSort(double* nums,int size)
{
    for (int i = 0;i < size;++i)
    {
        for(int j = i+1;j > 0;--j)
        {
            if(nums[j] < nums[j-1])
            {
                double tmp = nums[j];
                nums[j] = nums[j-1];
                nums[j-1] = tmp;
            }
            else break;
        }
    }
}

void selectionSort(double* nums,int size)
{
    for(int i = 0;i < size;++i)
    {
        int min = i;
        for(int j = i;j < size;++j)
        {
            if(nums[j]<nums[min])
                min = j;
        }
        double tmp = nums[min];
        nums[min] = nums[i];
        nums[i] = tmp;
    }
}

void bubbleSort(double* nums,int size)
{
    for(int i = 0;i < size;++i)
    {
        for(int j = size-1;j > i;--j)
        {
            if(nums[j] < nums[j-1])
            {
                double tmp = nums[j];
                nums[j] = nums[j-1];
                nums[j-1] = tmp;
            }
        }
    }
}

void shellHelp(double* nums,int size,int gap)
{
    for(int i = gap;i < size;i += gap)
    {
        for(int j = i;j >= gap;--j)
        {
            if(nums[j]<nums[j-gap])
            {
                double tmp = nums[j];
                nums[j] = nums[j-gap];
                nums[j-gap] = tmp;
            }
            else break;
        }
    }
}

void ShellSort(double* nums,int size)
{
    for(int i = size / 2;i > 2 ;i /= 2)
    {
        for(int j = 0;j < i;++j)
            shellHelp(&nums[j],size-j,i);
    }
    shellHelp(nums,size,1);
}

void mergeSort(double* nums,double* temp,int left,int right)
{
    if(left == right)   return;
    int mid = (left + right) / 2;
    mergeSort(nums,temp,left,mid);
    mergeSort(nums,temp,mid+1,right);
    for(int i = left;i<=right;++i)
        temp[i] = nums[i];
    int l = left,r = mid + 1;
    for(int curr = left;curr <= right;++curr)
    {
        if(l == mid+1)
            nums[curr] = temp[r++];
        else if(r > right)
            nums[curr] = temp[l++];
        else if(temp[l] < temp[r])
            nums[curr] = temp[l++];
        else
            nums[curr] = temp[r++];
    }
}

void quickSort(double* nums,int left,int right)
{
    if(right <= left)
        return;
    int pivotIndex = (left + right) / 2;
    // Swap pivot to the end
    double tmp = nums[pivotIndex];
    nums[pivotIndex] = nums[right];
    nums[right] = tmp;
    int l = left;
    int r = right - 1;
    while(l < r)
    {
        if(nums[r] < nums[right])
        {
            if(nums[l] > nums[right])
            {
               tmp = nums[r];
               nums[r] = nums[l];
               nums[l] = tmp;
               l++;
               r--;
            }
            else
               l++;
        }
        else
           r--;
   }
    // do
    // {
    //     while(nums[++l]<nums[right]);
    //     while(l < r && nums[right] < nums[--r]);
    //     tmp = nums[l];
    //     nums[l] = nums[r];
    //     nums[r] = tmp;
    // }while(l < r);
    // tmp = nums[right];
    // nums[right] = nums[l];
    // nums[l] = tmp;
    // //insSort(nums,l);
    // quickSort(nums,left,l-1);
    // quickSort(nums,l+1,right);
}

inline int partition(int* A, int l, int r, int& pivot) {
  do {             // Move the bounds inward until they meet
    while (A[++l] < pivot);  // Move l right and
    while ((l < r) && pivot < A[--r]); // r left
    int tmp = A[l];
    A[l] = A[r];
    A[r] = tmp;              // Swap out-of-place values
  } while (l < r);              // Stop when they cross
  return l;      // Return first position in right partition
}

void qsort(int* nums, int i, int j) { // Quicksort
  if (j <= i) 
  {
      return;
  }
  int pivotIndex = (i + j) / 2;
  int tmp = nums[pivotIndex];
  nums[pivotIndex] = nums[j];
  nums[j] = tmp;    // Put pivot at end
  // k will be the first position in the right subarray
  int k = partition(nums, i-1, j, nums[j]);
  tmp = nums[i];
  nums[i] = nums[j];
  nums[j] = tmp;             // Put pivot in place
  qsort(nums, i, k-1);
  qsort(nums, k+1, j);
}

void heapSort(double* nums,int size)
{
    double max;
    heap<double> h(nums,size,size);
    for(int i = 0;i < size;++i)
        max = h.removefirst();
}


void radix(int A[], int B[], int n, int k, int r, int cnt[]) {
  // cnt[i] stores number of records in bin[i]
  int j;

  for (int i=0, rtoi=1; i<k; i++, rtoi*=r) { // For k digits
    for (j=0; j<r; j++) cnt[j] = 0;        // Initialize cnt

    // Count the number of records for each bin on this pass
    for (j=0; j<n; j++) cnt[(A[j]/rtoi)%r]++;

    // // Index B: cnt[j] will be index for last slot of bin j.
    for (j=1; j<r; j++) cnt[j] = cnt[j-1] + cnt[j];

    // // Put records into bins, work from bottom of each bin.
    // // Since bins fill from bottom, j counts downwards
    for (j=n-1; j>=0; j--)
      B[--cnt[A[j]/rtoi%r]] = A[j];

    for (j=0; j<n; j++) A[j] = B[j];    // Copy B back to A
  }
}


int main()
{
    int d[10000];
    srand((int)time(0));
    for(int i = 0;i < 10000;++i)
        d[i] = abs(((int)(rand()*rand()%3000000))/100.0) ;
    clock_t start = clock();
    //ShellSort(d,10000);
    //double temp[10000];
    //mergeSort(d,temp,0,10000);
    //quickSort(d,0,9999);
    qsort(d,0,9999);
    //heapSort(d,10000);
    int tmp[10000];
    int cnt[10];
    radix(d,tmp,9999,5,10,cnt);
    clock_t end = clock();
    int count = 1;
    for(int i = 0;i < 10000;++i)
    {
        cout << fixed << setprecision(2) << setw(8) << d[i] << " ";
        if(count != 10)
            ++count;
        else
        {
            count = 1;
            cout << endl;
        }
    }
    cout << "Time it takes is " << (double)(end - start)/(double)CLOCKS_PER_SEC*1000.0 << " ms." << endl;

}
