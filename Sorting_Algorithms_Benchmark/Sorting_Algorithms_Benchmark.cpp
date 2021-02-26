#include <iostream>
#include <time.h> 

using namespace std;

void FillRand(int arr[],const int n, int m);// заполнение массива
void Print(int arr[], const int n); // печать массива
void Copy(int arr_1[], int arr_2[],const int n); //создание буфферной копии массива

double quickSortR(int *arr, const int n); // Быстрая сортировка
double ShellSort(int arr[],const int n); // Сортировка Шелла
double BubbleSortR(int arr[],const int n); // Пузырьковая сортировка

void Sorting_Algorithms_Benchmark(int n, int m); // Сравнение времени сортировок



int main()
{
    setlocale(LC_ALL,"");
    int n = 10; //n-количество элементов в массиве
    int m = 100;// диапазон значений элементов массива 0-m
    Sorting_Algorithms_Benchmark(n, m);
}


double quickSortR(int *arr, const int n)
{
    clock_t start = clock();
    int i = 0, j = n - 1; 		
    int buffer, p;
    p = arr[n/2];		

  
    do {
        while (arr[i] < p) i++;
        while (arr[j] > p) j--;

        if (i <= j) {
            buffer = arr[i]; arr[i] = arr[j]; arr[j] = buffer;
            i++; j--;
        }
    } while (i <= j);

   
    if (j > 0) quickSortR(arr, j+1);
    if (n > i) quickSortR(&arr[i], n - i);
    clock_t end = clock();
    double seconds = (double)(end - start) / CLOCKS_PER_SEC;
    return seconds;
    
}

double ShellSort(int arr[], const int n)
{
    clock_t start = clock();
    int itr = n;
    itr = itr / 2;
    while (itr > 0)
    {
        for (int i = 0; i < n - itr; i++)
        {
            for (int j = i; (j >= 0) && (arr[j] > arr[j + itr]); j--)
            {
                int buffer = arr[j];
                arr[j] = arr[j + itr];
                arr[j + itr] = buffer;
            }
        }
        itr = itr / 2;
    }

    clock_t end = clock();
    double seconds = (double)(end - start) / CLOCKS_PER_SEC;
    return seconds;
}

double BubbleSortR(int arr[], const int n)
{
    clock_t start = clock();
    
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                
                int buffer = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = buffer;
            }
        }
    }
    clock_t end = clock();
    double seconds = (double)(end - start) / CLOCKS_PER_SEC;
    return seconds;
}

void FillRand(int arr[], const int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % m;
    }
}

void Print(int arr[], const int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << '\t';
    }
    cout << endl;
}

void Copy(int arr_1[], int arr_2[], const int n)
{
    for (int i = 0; i < n; i++)
    {
        arr_1[i] = arr_2[i];
    }
}

void Sorting_Algorithms_Benchmark(int n, int m)
{
    int* arr = new int[n];
    int* arr_buffer = new int[n];
    FillRand(arr, n, m);
    Copy(arr_buffer, arr, n);
    //Print(arr,n);
    //Print(arr_buffer,n);
    cout << endl;
    cout << quickSortR(arr, n) << endl;
    //Print(arr, n);
    Copy(arr, arr_buffer, n);
    //Print(arr, n);
    cout << BubbleSortR(arr, n) << endl;
   // Print(arr, n);
    Copy(arr, arr_buffer, n);
    //Print(arr, n);
    cout << ShellSort(arr, n) << endl;
    //Print(arr, n);
    delete[] arr;
    delete[] arr_buffer;
}
