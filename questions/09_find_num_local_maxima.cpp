/*
http://www.geeksforgeeks.org/find-the-maximum-element-in-an-array-which-is-first-increasing-and-then-decreasing/
*/

#include <iostream>

using namespace std;

#define REP(i, n) for(int i = 0; i < n; ++i)

int local_maxima(int *a, int size)
{
  for(int i = 1; i < size - 1; ++i)
    if (a[i] > a[i -1] && a[i] > a[i + 1])
      return a[i];

  return -1;
}

int main()
{
  int arr[] = {1, 30, 40, 50, 60, 70, 23, 20};

  int n = sizeof(arr)/sizeof(arr[0]);

  printf("The local maxima is %d. \n", local_maxima(arr, n));
  
  return 0;
}