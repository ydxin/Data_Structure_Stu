#pragma once
#define MAXD 10
#define MAXR 10
typedef struct NodeBase
{
	char data[MAXD];
	struct NodeBase* next;
}NodeBase;


void swap(int* a, int* b);
void InsertSort(int r[], int n);
void BinInsertSort(int* r, int n);
void ShellSort(int* r, int n);
void BubbleSort(int* r, int n);
void BubbleSort1(int* r, int n);
int Partition1(int* r, int s, int t);
void QuickSort(int* r, int s, int t);
void QuickSort1(int* r, int s, int t);
void SelectSort(int* r, int n);
void Sift(int* r, int low, int high);
void HeapSort(int* r, int n);
void Merge(int* r, int low, int mid, int high);
void MergePass(int* r, int length, int n);
void MergeSort(int* r, int n);
void MergeSortDC(int* r, int low, int high);
void MergeSort1(int* r, int n);