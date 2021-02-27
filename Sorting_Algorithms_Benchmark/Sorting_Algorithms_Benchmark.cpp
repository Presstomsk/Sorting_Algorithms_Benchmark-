
#include <iostream>
#include <time.h> 

using namespace std;

void FillRand(int arr[], const int n, int m);// заполнение массива
void Print(int arr[], const int n); // печать массива
void Copy(int arr_1[], int arr_2[], const int n); //создание буфферной копии массива

double quickSortR(int arr[], const int n); // Быстрая сортировка
double ShellSort(int arr[], const int n); // Сортировка Шелла
double BubbleSortR(int arr[], const int n); // Пузырьковая сортировка
double CountingSortR(int arr[], int arr_index[], const int n, const int m);//Сортировка подсчетом

void Sorting_Algorithms_Benchmark(int n, int m); // Сравнение времени сортировок



int main()
{
    setlocale(LC_ALL, "");
    int n = 100; //n-количество элементов в массиве
    int m = 20000;// диапазон значений элементов массива 0-m
    Sorting_Algorithms_Benchmark(n, m);
    for (int n = 200; n <= 1000; n += 200) Sorting_Algorithms_Benchmark(n, m);
    for (int n = 5000; n <= 30000; n += 5000) Sorting_Algorithms_Benchmark(n, m);
    for (int n = 50000; n <= 200000; n *= 2) Sorting_Algorithms_Benchmark(n, m);
    for (int n = 400000; n <= 51200000; n *= 2) Sorting_Algorithms_Benchmark(n, m);

    /* РЕЗУЛЬТАТЫ:
    Пузырьковая сортировка не производительная при сортировке массивов свыше 1000 элементов;
    Сортировка Шелла хоть и лучше по быстродействию, чем пузырьковая, но проигрывает
    быстрой сортировке и сортировке подсчетом.
    Минус сортировки подсчетом - ей не хватает памяти при больших значениях переменных массива.
    При количестве более 6000000 элементов быстрая сортировка начинает тормозить и 
    проигрывает по скорости сортировке подсчетом.*/

}


double quickSortR(int arr[], const int n)
{
    clock_t start = clock();
    int i = 0, j = n - 1;
    int buffer, p;
    p = arr[n / 2];


    do {
        while (arr[i] < p) i++;
        while (arr[j] > p) j--;

        if (i <= j) {
            buffer = arr[i]; arr[i] = arr[j]; arr[j] = buffer;
            i++; j--;
        }
    } while (i <= j);


    if (j > 0) quickSortR(arr, j + 1);
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

double CountingSortR(int arr[], int arr_index[], const int n, const int m)
{
    clock_t start = clock();

    for (int i = 0; i < m; i++) arr_index[i] = 0;

    for (int i = 0; i < n; i++) arr_index[arr[i]] = arr_index[arr[i]] + 1;

    int i = 0;
    for (int j = 0; j < m; j++)
    {
        while (arr_index[j] != 0)
        {
            arr[i] = j;
            arr_index[j] = arr_index[j] - 1;
            i++;
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
    int* arr_index = new int[m];
    FillRand(arr, n, m);
    Copy(arr_buffer, arr, n);
    //Print(arr,n);
    //Print(arr_buffer,n);
    cout << endl;
    cout << "Сравнение скоростей выполнения сортировок массива, состоящего из " << n << " элементов, " << endl;
    cout << "где каждый элемент задается случайным образом в диапазоне от 0 до " << m << endl;
    
    cout << "Быстрая сортировка: " << quickSortR(arr, n) << " сек. " << endl;
    //Print(arr, n);
    Copy(arr, arr_buffer, n);
    //Print(arr, n);
    
    if(n<=100000)
    {cout << "Пузырьковая сортировка: " << BubbleSortR(arr, n) << " сек. " << endl;
    //Print(arr, n);
    Copy(arr, arr_buffer, n);
    //Print(arr, n);
    }
    if (n <= 400000)
    {cout << "Сортировка Шелла: " << ShellSort(arr, n) << " сек. " << endl;
    //Print(arr, n);
    Copy(arr, arr_buffer, n);
    //Print(arr, n);
    }
    
    cout << "Сортировка подсчетом: " << CountingSortR(arr, arr_index, n, m) << " сек. " << endl;
    //Print(arr, n);
    
    delete[] arr;
    delete[] arr_buffer;
    delete[] arr_index;
}

