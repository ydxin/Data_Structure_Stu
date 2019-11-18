#include "sort.h"
#include <stdbool.h>
#include <stdlib.h>
void InsertSort(int r[], int n)
{
	for (int i = 1; i < n; i++)
	{
		if (r[i] < r[i - 1])
		{
			int tmp = r[i];
			int j = i - 1;
			do
			{
				r[j + 1] = r[j];
				j--;
			} while (j >= 0 && r[j] > tmp);
			r[j + 1] = tmp;
		}		
	}
}


void BinInsertSort(int *r, int n)
{
	int tmp;
	for (int i = 1; i < n; i++)
	{
		if (r[i] < r[i - 1])
		{
			tmp = r[i];
			int low = 0;
			int high = i - 1;
			int mid = 0;
			while (low <= high)
			{
				mid = (low + high) / 2;
				if (tmp < r[mid])
					high = mid - 1;
				else
					low = mid + 1;
			}
			for (int j = i - 1; j >= high + 1; j--)
				r[j + 1] = r[j];
			r[high + 1] = tmp;
		}
	}
}

void ShellSort(int* r, int n)
{
	int tmp = 0;
	int d = n / 2;
	while (d > 0)
	{
		for (int i = d; i < n; i++)
		{
			tmp = r[i];
			int j = i - d;
			while (j >= 0 && tmp < r[j])
			{
				r[j + d] = r[j];
				j = j - d;
			}
			r[j + d] = tmp;
		}
		d = d / 2;
	}
}

void BubbleSort(int* r, int n)
{
	for (int i = 0; i < n - 1; i++)
		for (int j = n - 1; j > i; j--)
			if (r[j] < r[j - 1])
				swap(&r[j], &r[j - 1]);
}

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void BubbleSort1(int* r, int n)
{
	bool exChange;
	for (int i = 0; i < n - 1; i++)
	{
		exChange = false;
		for (int j = n - 1; j > i; j--)
		{
			if (r[j] < r[j - 1])
			{
				swap(&r[j], &r[j - 1]);
				exChange = true;
			}
		}		
		if (!exChange)
			return;
	}
}

int Partition1(int *r,int s,int t)
{
	int i = s;
	int j = t;
	int tmp = r[i];
	while (i < j)
	{
		while (j > i && r[j] >= tmp)
			j--;
		r[i] = r[j];
		while (i < j && r[i] <= tmp)
			i++;
		r[j] = r[i];
	}
	r[i] = tmp;
	return i;
}

void QuickSort(int* r, int s, int t)
{
	int i = 0;
	if (s < t)
	{
		i = Partition1(r, s, t);
		QuickSort(r, s, i - 1);
		QuickSort(r, i + 1, t);
	}
}

void QuickSort1(int* r, int s, int t)
{
	int pivot = (s + t) / 2;
	int i = 0;
	if (s < t)
	{
		if (pivot != s)
			swap(&r[pivot], &r[s]);
		i = Partition1(r, s, t);
		QuickSort(r, s, i - 1);
		QuickSort(r, i + 1, t);
	}
}

void SelectSort(int* r, int n)
{
	int i, j, k;
	for (int i = 0; i < n - 1; i++)
	{
		k = i;
		for (j = i + 1; j < n; j++)
		{
			if (r[j] < r[k])
				k = j;
		}
		if (k != i)
			swap(&r[i], &r[k]);
	}
}

void Sift(int* r, int low, int high)
{
	int i = low;
	int j = 2 * i;
	int tmp = r[i];
	while (j<=high)
	{
		if (j < high && r[j] < r[j + 1])
			j++;
		if (tmp < r[j])
		{
			r[i] = r[j];
			i = j;
			j = 2 * i;
		}
		else
			break;
	}
	r[i] = tmp;
}

void HeapSort(int* r, int n)
{
	int i; 
	for (i = n / 2; i >= 1; i--)
		Sift(r, i, n);
	for (i = n; i >= 2; i--)
	{
		swap(&r[1], &r[i]);
		Sift(r, 1, i - 1);
	}
}


void Merge(int* r, int low, int mid, int high)
{
	int i = low;
	int j = mid + 1;
	int k = 0;
	int* r1 = (int*)malloc((high - low + 1)*sizeof(int));
	while (i <= mid && j <= high)
	{
		if (r[i] < r[j])
		{
			r1[k] = r[i];
			i++;
			k ++ ;

		}
		else
		{
			r1[k] = r[j];
			j++;
			k++;
		}
	}
	
	while (i <= mid)
	{
		r1[k] = r[i];
		i ++ ;
		k++;

	}
	while (j <= high)
	{
		r1[k] = r[j];
		j++;
		k++;
	}

	for (k = 0, i = low; i <= high; k++, i++)
		r[i] = r1[k];
	free(r1);
}

void MergePass(int* r, int length, int n)
{
	int i;
	for (i = 0; i + 2 * length - 1 < n; i = i + 2 * length)
		Merge(r, i, i + length - 1, i + 2 * length - 1);
	if (i + length - 1 < n - 1)
		Merge(r, i, i + length - 1, n - 1);
}

void MergeSort(int* r, int n)
{
	int length;
	for (length = 1; length < n; length = 2 * length)
		MergePass(r, length, n);
}

void MergeSortDC(int* r, int low, int high)
{
	int mid;
	if (low < high)
	{
		mid = (low + high) / 2;
		MergeSortDC(r, low, mid);
		MergeSortDC(r, mid+1,high);
		Merge(r, low, mid, high);
	}
}
void MergeSort1(int* r, int n)
{
	MergeSortDC(r, 0, n - 1);
}

NodeBase* RadixSort(NodeBase* p, int r, int d)
{
	NodeBase* head[MAXR];
	NodeBase* tail	[MAXR];
	NodeBase* t;
	int i, j, k;
	for (i = 0; i < d; i++)
	{
		for (j = 0; j < r; i++)
			head[j] = tail[j] = NULL;
		while (p)
		{
			k = p->data[i] - '0';
			if (head[k] == NULL)
			{
				head[k] = p;
				tail[k] = p;
			}
			else
			{
				tail[k]->next = p;
				tail[k] = p;
			}
			p = p->next;
		}
		p = NULL;
		for (j = 0; j < r; j++)
		{
			if (head[j] != NULL)
			{
				if (!p)
				{
					p = head[j];
					t = tail[j];
				}
				else
				{
					t->next = head[j];
					t = tail[j];
				}
			}
		}
		t->next = NULL;
	}
	return p;
}
