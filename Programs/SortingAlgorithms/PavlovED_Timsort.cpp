#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int getminrun(int n){//���������� ������� ����������� ���������������������
    int r = 0;
        while (n >= 64) { //������� ������� 6 ��� �� N � ����������� �������, ���� � ���������� ������� ����� ���� ���� �� ���� ���������
            r |= (n & 1);
            n >>= 1;
        }
        return n + r;
}

// ������� ���������� ��������������������� ������� ���������
void insertionSort(int arr[], int left, int right)
{
	for (int i = left + 1; i <= right; i++)
	{
		int temp = arr[i];
		int j = i - 1;
		while (j >= left && arr[j] > temp)
		{
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = temp;
	}
}

// ������� ��������������� ����������������������
void merge(int arr[], int l, int m, int r)
{
	// ������� ������ �������� �� "�����" � "������"
	int len1 = m - l + 1, len2 = r - m;
	int left[len1], right[len2];
	for (int i = 0; i < len1; i++)
		left[i] = arr[l + i];
	for (int i = 0; i < len2; i++)
		right[i] = arr[m + 1 + i];
	int i = 0;
	int j = 0;
	int k = l;
	// ����� �� ��������� �� ���������� �� � ����� ������
	while (i < len1 && j < len2){
		if (left[i] <= right[j]){
			arr[k] = left[i];
			i++;
		}
		else{
			arr[k] = right[j];
			j++;
		}
		k++;
	}
	// ����������� ���������� �������� ������ �������, ���� ��� ��������
	while (i < len1){
		arr[k] = left[i];
		k++;
		i++;
	}

	// ����������� ���������� �������� ������ �������, ���� ��� ��������
	while (j < len2){
		arr[k] = right[j];
		k++;
		j++;
	}
}

// ������� ���������� �������� timsort
void timSort(int arr[], int n)
{
    int RUN=getminrun(n);//���������� ����������� ���������������������
	//��������� ����������� ����� ���������� ���������
	for (int i = 0; i < n; i+=RUN)
		insertionSort(arr, i, min((i+RUN-1),(n-1)));

	//������������� ������� ����������� �������� run,����� 2*run,� �.�.
	for (int size = RUN; size < n; size = 2*size){
		for (int left = 0; left < n;left += 2*size)
		{
			// ������� ������� ����� � ������ ���������������������� ��� �������
			int mid = left + size - 1;
			int right = min((left + 2*size - 1),(n-1));

			// ������� ���������������������� � ��������� [left,mid] � [mid+1,right]
			if(mid < right)
				merge(arr, left, mid, right);
		}
	}
}

// ������� ������ �������
void printArray(int arr[], int n)//������� ������ �������
{
    for (int i = 0; i < n; i++)
        cout<<arr[i]<<" ";
}
int main()
{
	int arr[] = {-3,12,32,56,21,-6,-78,-47,64,6,0,-11,-2,13,17,2,5,8,54,61,53,23,56,89,225,7,23,67,2,6,2,424,62,36,236,24,63,457,3,1,53,6843,20,79,46,57,-67,39,-9,77,56,59,30,17,8,62,42,95,26,44,6,10,38,73,43,90,36,-7,85,97,34,23,-89,1,5,78,14,-93,4,76,69,-49,64,27,12,65,94,-31,21,-705,84,-29,16,96,92,15,-88,37,48,-72,50,74,11,-18,40,61,25,-58,83,66,87,63,100,13,99,45,86,24,28,82,47,41,81,52,60,53,91,33,32,80};
	int n = sizeof(arr)/sizeof(arr[0]); //������ �������
	cout<<"Starting array: "<<endl;
	printArray(arr, n); //����� ������������ �������
	timSort(arr, n); //����� ������� ����������
    cout<<endl;
    cout<<"End result: "<<endl;
	printArray(arr, n);//����� ����������
	return 0;
}
