// Cinkye 2018.11.5 201730684427
// A file with many sorting functions and their testbench       sort.cpp

#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <iomanip>

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

void quickSort()
{

}

void heapSort()
{

}

void radixSort()
{

}

int main()
{
    double d[10000];
    srand((int)time(0));
    for(int i = 0;i < 10000;++i)
        d[i] = ((int)(rand()*rand()%3000000))/100.0 ;
    clock_t start = clock();
    //ShellSort(d,10000);
    double temp[10000];
    mergeSort(d,temp,0,10000);
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
