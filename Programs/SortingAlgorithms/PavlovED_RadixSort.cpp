#include<bits/stdc++.h>
using namespace std;

void radixSortAlgo(int a[], int size_of_a){
    int maximumNumber = a[0]; // находим максимальное значение в массиве
    for(int i=1;i<size_of_a;i++){
        maximumNumber = max(maximumNumber, a[i]);
    }
    int digitsCount = 0;
    while(maximumNumber > 0){ // находим количество цифр в максимальном значении в массиве
        digitsCount++;
        maximumNumber /= 10;
    }
    for(int i=0;i<digitsCount;i++){  // Создание нового массива
        int pwr = pow(10, i);
        int new_a[size_of_a];
        int count_array[10]; // Это массив count_array для сортировки подсчётом цифр от 0 до 9
        memset(count_array, 0, sizeof(count_array)); //заполнение нового массива частотами цифр
        for(int j=0;j<size_of_a;j++){
            int num = (a[j]/pwr) % 10;
            count_array[num]++;
        }
        // This is a cumulative frequency
        for(int j=1;j<10;j++){
            count_array[j] += count_array[j-1];
        }
        // We are mapping the frequency array with each element
        // of the array to find out desired position in the updated array
        for(int j=size_of_a-1;j>=0;j--){
            int num = (a[j]/pwr) % 10;
            new_a[count_array[num]-1] = a[j];
            count_array[num]--;
        }
        // Now, we are updating the array with the new array
        for(int j=0;j<size_of_a;j++)
            a[j] = new_a[j];
    }
    // Finally,we print the sorted array result
    for(int j=0;j<size_of_a;j++)
        cout<<a[j]<<" ";
    cout<<endl;
}
int main(){
    // This array of values will be sorted using the radix sort algorithm.
    int a[] = {150000, 95000, 140000, 200000, 100000, 90000, 100000, 300000, 115000, 80000, 95000, 100000, 200000, 115000, 100000, 105000, 190000, 95000, 90000, 120000};
    // We are calculating size of the array
    int size_of_a = sizeof(a)/sizeof(size_of_a);
    // Calling to Radix Sort Algorithm method
    radixSortAlgo(a, size_of_a);
    return 0;
}
