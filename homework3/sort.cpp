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

void ShellSort(double* nums,int size)
{

}

void mergeSort(double* nums,int size)
{

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
    insSort(d,10000);
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
