#include <iostream>
#include <time.h> 

using namespace std;

void FillRand(double arr[],const double n);
void Print(double arr[], const double n);
void Copy(double arr_1[], double arr_2[],const double n);

double quickSortR(double *arr, const int n);
double BubbleSortR(double arr[],const double n);


int main()
{
    setlocale(LC_ALL,"");
    double n = 100000;
    double* arr = new double[n];
    double* arr_buffer = new double[n];
    FillRand(arr,n);
    Copy(arr_buffer, arr, n);
    //Print(arr,n);
    //Print(arr_buffer,n);
    cout << endl;
    cout<<quickSortR(arr, n)<<endl;
    //Print(arr, n);
    Copy(arr, arr_buffer, n);
    //Print(arr, n);
    //Print(arr, n);
    cout << BubbleSortR(arr, n) << endl;
    delete[] arr;
    delete[] arr_buffer;
}


double quickSortR(double *arr, const int n)
{
    clock_t start = clock();
    int i = 0, j = n - 1; 		
    int buffer, p;
    p = arr[n/2];		

    // процедура разделения
    do {
        while (arr[i] < p) i++;
        while (arr[j] > p) j--;

        if (i <= j) {
            buffer = arr[i]; arr[i] = arr[j]; arr[j] = buffer;
            i++; j--;
        }
    } while (i <= j);

    // рекурсивные вызовы, если есть, что сортировать 
    if (j > 0) quickSortR(arr, j+1);
    if (n > i) quickSortR(&arr[i], n - i);
    clock_t end = clock();
    double seconds = (double)(end - start) / CLOCKS_PER_SEC;
    return seconds;
    
}

double BubbleSortR(double arr[], const double n)
{
    clock_t start = clock();
    
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            if (arr[j] < arr[j + 1])
            {
                // Обмен местами
                double buffer = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = buffer;
            }
        }
    }
    clock_t end = clock();
    double seconds = (double)(end - start) / CLOCKS_PER_SEC;
    return seconds;
}

void FillRand(double arr[], const double n)
{
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 30000;
    }
}

void Print(double arr[], const double n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << '\t';
    }
    cout << endl;
}

void Copy(double arr_1[], double arr_2[], const double n)
{
    for (int i = 0; i < n; i++)
    {
        arr_1[i] = arr_2[i];
    }
}
