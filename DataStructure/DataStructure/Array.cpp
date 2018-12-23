#include<iostream>
#include<map>
#include<stdlib.h>
#include<stack>
#include<algorithm>
#include "Array.h"
using namespace std;
int compAsc(const void* a, const void* b) {	int* _a =(int*) a;	int* _b =(int*) b;	return *_a - *_b;}
int compDesc(const void* a, const void* b) {	int* _a =(int*) a;	int* _b =(int*) b;	return *_b - *_a;}
bool hasArrayTwoCandidates1(int a[], int n, int s)
{
	qsort(a, n, sizeof(a[0]), compAsc);
	int l = 0, h = n - 1;
	while (l <= h)
	{
		if (a[l] + a[h] == s) return true;
		else if (a[l] + a[h] < s)l++;
		else h--;
	}
	return false;
}

bool hasArrayTwoCandidates(int a[], int n, int s)
{
	map<int,bool> m;
	for (int i = 0; i < n; i++)
	{
		int x = s - a[i];
		if (x > 0) {
			if (m.find(x) != m.end()) return true;
			else m[x] = true;
		}
	}
}
int findCondidate(int a[], int n)
{
	int x ;
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		if (count == 0) { x = a[i]; count = 1; }
		if (a[i] == x)count++;
		else count--;
	}
	return x;
}
void printMajorityElement(int a[], int n)
{
	// run two loop and count occureance of each number if any num count reaches n/2+1 return true;
	// create bst(info,count) if same element increment count if count rached n/2+1 return true;
	// Moore voting method
	int x = findCondidate(a, n);
	int c = 0;
	for (int i = 0; i < n; i++)
	{
		if (x == a[i]) c++;
	}
	if (c > (n / 2) + 1) cout << "Majority element is " << x << endl;
	else cout << "Majority element not found !!!" << endl;
}

int LargestSumContiguosArray(int a[], int n)
{
	int s = 0, max = INT_MIN;
	int x = 0, y = 0;
	for (int i = 0; i < n; i++)
	{
		s += a[i];
		if (s < 0) {s = 0; x = i + 1;}
		else if (s > max) {	max = s; y = i;	}
	}
	cout << x << " " << y << endl;
	if (max == 0)
	{
		max = a[0];
		for(int i=1; i<n; i++)
			if (max < a[i]) {
				max = a[i]; x = y = i;
			}
	}
	else
	return max;
}
int binarySearch(int a[], int l, int h, int key)
{
	while (l <= h)
	{
		int m = (h-l)/2+l;
		if (a[m] == key) return m;
		else if (a[m] < key) l = m + 1;
		else h = m - 1;
	}
	return -1;
}
int findPivotPoint(int a[],int l,int h)
{
	while (l <= h)
	{
		int m = (h - l) / 2 + l;
		if (m > 0) { if (a[m] < a[m - 1]) return m; }
		if (m < h) { if (a[m] > a[m + 1]) return m + 1; }
		if (a[m] < a[l]) h = m - 1;
		else l = m + 1;
	}
	return -1;
}

int searchPivotedArray1(int a[], int n,int key)
{
	int p = findPivotPoint(a,0, n-1);
	if (p == -1) return binarySearch(a, 0, n-1, key);
	else if (a[p] == key) return p;
	else if (key < a[0]) return binarySearch(a, p+1, n-1, key);
	else return binarySearch(a, 0, p-1, key);
}
int searchPivotedArray(int a[], int l, int h, int key)
{
	while (l <= h)
	{
		int m = (h - l) / 2 + l;
		if (a[m] == key) return m;
		else if (a[l] <= a[m]) { if (key >= a[l]&&key<=a[m])h = m - 1; else l = m + 1; }
		else { if (key >= a[m] &&key<=a[h])l = m +1; else h = m - 1; }
	}
	return -1;
}
void MergeArray()
{
	#define NA -1
	/* Initialize arrays */
	int mPlusN[] = { 2, 8, NA, NA, NA, 13, NA, 15, 20 };
	int N[] = { 5, 7, 9, 25 };
	int n = sizeof(N) / sizeof(N[0]);
	int m = sizeof(mPlusN) / sizeof(mPlusN[0]);
	/*Move the m elements at the end of mPlusN*/
	int j = m - 1;
	for (int i = m - 1; i >= 0; i--)
		if (mPlusN[i] != NA) { mPlusN[j] = mPlusN[i]; j--; }
	/*Merge N[] into mPlusN[] */
	int i = 0;
	int k = 0;
	j++;
	while (i < n&&j < m)
	{
		if (mPlusN[j] < N[i]) mPlusN[k] = mPlusN[j++];
		else mPlusN[k] = N[i++];
		k++;
	}
	while (i < n)
		mPlusN[k++] = N[i++];
	while (j < m)
		mPlusN[k++] = mPlusN[j++];

	/* Print the resultant mPlusN */
	for (int i = 0; i < m; i++)
		cout << mPlusN[i] << " ";
	cout << endl;
}
int median()
{
	int ar1[] = { 1, 12, 15, 26, 38 };
	int ar2[] = { 2, 13, 17, 30, 45 };
	int n1 = sizeof(ar1) / sizeof(ar1[0]);
	int n2 = sizeof(ar2) / sizeof(ar2[0]);
	if (n1 != n2)
		printf("Doesn't work for arrays of unequal size");
	int m1 = 0, m2 = 0;
	int i = 0, j = 0;
	int count = 0;
	while (i < n1&&j < n2)
	{
		m1 = m2;
		if (ar1[i] < ar2[j]) m2 = ar1[i++];
		else m2 = ar2[j++];
		if (count++ == n1) break;
	}
	if (i == n1)
		m1 = m2, m2 = ar2[0];
	else if (j == n2)
		m1 = m2, m2 = ar1[0];
	cout << (m1 + m2) / 2;
	return (m1 + m2) / 2;
}
int medianOFArray(int a[], int n)
{
	if (n % 2 == 0) {return  (a[n / 2] + a[n / 2 - 1]) / 2; }
	else return a[n / 2];
}
int getMedian(int a[], int b[], int n)
{
	if (n == 0)return -1;
	if (n == 1) return  (a[0] + b[0]) / 2;
	if (n == 2) return (max(a[0], a[1]) + min(b[0], b[1])) / 2;
	int m1 = medianOFArray(a, n);
	int m2 = medianOFArray(b, n);
	if (m1 == m2) return m1;
	if (m1 > m2)
	{
		if (n % 2 == 0)
			return getMedian(a+n/2-1,b,n-n/2+1);
		else
			return 	 getMedian(a+n/2,b,n-n/2);
	}
	else
	{
		if (n % 2 == 0)
			return getMedian(b+n/2-1,a,n-n/2+1);
		else
			return 	 getMedian(b+n/2,a,n-n/2);
	}
	return 0;
}
int gcd(int a, int b)
{
	if (b == 0) return a;
	return gcd(b, a%b);
}
void RotateArray(int a[], int n, int d)
{
	int g = gcd(n, d);
	for (int i = 0; i < g; i++)
	{
		int t = a[i];
		int j = i;
		int k = 0;
		while (1)
		{
			k = j + d;
			if (k >= n)k = k - n;
			if (k == i) break;
			a[j] = a[k];
			j = k;
		}
		a[j] = t;
	}
}
void printArray(int a[], int n) { for (int i = 0; i < n; i++) cout << a[i] << " "; cout << endl; }
void BlockSwap(int a[], int s,int e,int d) 
{
	int i, temp;
	for (i = 0; i<d; i++)
	{
		temp = a[e + i];
		a[e + i] = a[s + i];
		a[s + i] = temp;
	}
}
void RotateArrayBlockSwap(int a[], int n, int d)
{// devide array in two part A[0..d-1] B[d..n-1] 
	if (d == 0 || n == d) return;
	if (n - d == d) 
		BlockSwap(a, 0, n - d, d);
	if (d < n - d) 
	{
		BlockSwap(a, 0, n - d, d);
		RotateArrayBlockSwap(a, d,n-d);
	}
	else
	{
		BlockSwap(a, 0, d, n - d);
		RotateArrayBlockSwap(a + n - d, 2 * d - n, d);
	}
}
int findMaxSumNoElementAdjecent(int a[], int n)
{
	int inc, excl, excl_new;
	inc = a[0];
	excl = 0;
	for (int i = 1; i < n; ++i)
	{
		excl_new = max(inc, excl);
		inc = excl + a[i];
		excl = excl_new;
	}
	return max(inc, excl);
}
void printLeaders(int a[], int n)
{
	int m = a[n - 1];
	cout << m << " ";
	for (int i = n - 2; i >= 0; i--)
	{
		if (a[i] > m) { m = a[i]; cout << m << " "; }
	}
}
struct info {	int index, count, data;};
void printArray(info* p, int n)
{
	for (int i = 0; i < n; i++) printf("(%d,%d,%d) ", p[i].data, p[i].count, p[i].index);
	cout << endl;
}
int comp11(const void *a, const void *b)
{
	info* aa = (info*)a, *bb =(info*)b;
	if (aa->data != bb->data) return aa->data - bb->data;
	return bb->index - aa->index;
}
int comp12(const void *a, const void *b)
{
	info* aa = (info*)a, *bb =(info*)b;
	if (aa->count != bb->count) return aa->count - bb->count;
	return bb->index - aa->index;
}
void sortByFrequency(int arr[], int n)
{
	info  *e = new info[n];
	for (int i = 0; i < n; i++) {e[i].index = i; e[i].count = 0; e[i].data = arr[i]; }
	qsort(e, n, sizeof info, comp11);
	e[0].count = 1;
	for (int i = 1; i < n; i++)
	{
		if (e[i - 1].data == e[i].data)
		{
			e[i].count = e[i - 1].count + 1;
			e[i-1].count = -1;
			e[i].index = e[i - 1].index;
		}
		else
			e[i].count = 1;
	}
	qsort(e, n, sizeof info, comp12);
	for (int i = n-1,k=0; i>=0; i--)
	{
		if(e[i].count!=-1)
		{
			for (int j = 0; j < e[i].count; j++)
				arr[k++] = e[i].data;
		}
	}
}
int countInversion1(int a[], int n)
{
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
			if (a[j] < a[i])
				count++;
	}
	return count;
}
int mergeSorted(int a[], int l, int m, int r)
{
	int inversion = 0;
	int *b = new int[r];
	int i = l, j = m ;
	int k = l;
	while (i < m&&j <= r)
	{
		if (a[i] <= a[j]) 	b[k++] = a[i++];
		else {	b[k++] = a[j++]; inversion = inversion + (m - i );}
	}
	while (i < m) b[k++] = a[i++];
	while (j <= r) b[k++] = a[j++];
	for (k = l; k <= r; k++)a[k] = b[k];
	return inversion;
}
int countInversion2(int a[], int l,int r)
{
	int inversion = 0;
	if (l >= r) return 0;
	int m = (r + l) / 2;
	inversion = countInversion2(a, l, m);
	inversion += countInversion2(a, m+1, r);
	inversion += mergeSorted(a, l, m+1, r);
	return inversion;
}
void minAbsSumPair1(int a[], int n)
{
	int s=0, m = INT_MAX, ii, jj;
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			s = a[i] + a[j];
			if (abs(s) < m) {
				ii = i; jj = j; m = abs(s);
			}
		}
	}
	cout<<a[ii]<<","<<a[jj]<<" Sum = "<< m;
}
void minAbsSumPair2(int a[], int n)
{
	qsort(a, n, 4, compAsc);
	int l = 0, r = n - 1;
	int i = 0, j = 0, s = 0, m = INT_MAX;
	while (l < r)
	{
		s = a[l] + a[r];
		if (abs(s) < abs(m)) { m = s; i = l; j = r; }
		if (s < 0)l++;
		else r--;
	}
	cout << a[i] << "," << a[j] << "sum " << m;
}
void print2Smallest(int a[], int n)
{
	int f = INT_MAX, s = INT_MAX;
	if (a[0] < a[1])f = a[0], s = a[1];
	else f = a[1], s = a[0];
	for (int i = 2; i < n; i++)
	{
		if (a[i] < f) {	s = f;f = a[i];	}
		else if (a[i] < s && f!=a[i]) s = a[i];
	}
	cout << "first smallest " << f << " 2nd smallest " << s << endl;
}
bool isMajority1(int a[], int n, int x)
{
	int l = n % 2 ? n / 2+1 : n / 2 ;
	for (int i = 0; i < l; i++)
	{
		if (a[i] == x&& a[i + n / 2] == x)
			return true;
	}
	return false;
}
int _binarySearch(int a[], int n, int x)
{
	int l = 0, r = n - 1;
	if (a[0] == x) return 0;
	while (l <= r)
	{
		int m = (l + r) / 2;
		if (m>0&& a[m] == x &&a[m-1]<x) 
			return m;
		if (a[m] < x)
			l = m + 1;
		else 
			r = m - 1;
	}
	return -1;
}
bool isMajority2(int a[], int n, int x)
{
	int i = _binarySearch(a, n, x);
	if (i == -1) return false;
	if (i + n / 2 < n) {
		if (a[i + n / 2] == x) 
			return true;
	}
	return false;
}
int  findKthLargestElement1(int a[], int n, int  k)
{
	// using bubble sort k time
	for(int i=0;i<k;i++)
		for (int j = 0;j < n-i-1; j++)
			if (a[j] > a[j + 1]) swap(a[j], a[j +1]);
	return a[n-k];
}
void heapifyMin(int a[], int, int);
int  findKthLargestElement2(int a[], int n, int  k)
{
	// using heap
	for( int i=k/2-1;i>=0;i--)
	heapifyMin(a, i,k);
	for (int i = k; i < n; i++)
	{
		if (a[0] < a[i]) { swap(a[0], a[i]); heapifyMin(a, 0, k);}
	}
	for (int i = 0; i < k; i++)cout << a[i] << " ";
	return a[0];
}
void heapSort(int a[], int  n);

void print2Repeating(int a[], int n)
{
	int s = 0, p = 1;
	for (int i = 0; i < n; i++)	{		s += a[i];		p *= a[i];	}
	int nn = n - 2;
	int pp = 1;
	for (int i = 1; i <= nn; i++)pp *= i;
	int ss = nn*(nn + 1) / 2;
	s = s - ss;
	p = p /pp;
	int d = sqrt(s*s - 4*p);
	int x = (s + d) / 2;
	int y = (s - d) / 2;
	cout << x << " " << y << endl;
}

void print2Repeating1(int a[], int n)
{
	int s = a[0];
	for (int i = 1; i < n; i++)	{s ^= a[i];}
	for (int i = 1; i <= n - 2; i++) s ^= i;
	int d = s&~(s-1);
	int x=0, y=0;
	for (int i = 0; i < n; i++) 
	{ 
		if (a[i] & d) 
			x^=a[i]; 
		else 
			y^=a[i]; 
	}
	for (int i = 1; i <= n - 2; i++){ if (i & d) x^=i; else y^=i; }
	printf("\n The two repeating elements are %d & %d ", x, y);
}

void print2Repeating2(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		if (a[abs(a[i])] > 0)  a[abs(a[i])] = -a[abs(a[i])];
		else cout << "repeating is " << abs(a[i]) << endl;
	}
	for (int i = 0; i < n; i++)
	{
		if (a[abs(a[i])] < 0)  a[abs(a[i])] = -a[abs(a[i])];
	}
}
void sort012(int a[], int n)
{
	int l = 0, m = 0, h = n - 1;
	while (m <= h)
	{
		switch (a[m])
		{
		case 0: swap(a[m], a[l]); l++, m++;
			break;
		case 1:m++;
			break;
		case 2:swap(a[m], a[h]); h--;
			break;
		}
	}
}
void printUnsorted(int a[], int n)
{
	int s = 0, e = 0;
	int i = 0;
	for ( i = 0; i < n - 1; i++) if (a[i] > a[i + 1]) break;
	s = i;
	for ( i = n-1; i >=0; i--) 	if (a[i] < a[i - 1]) break;
	e = i;
	int min=INT_MAX, max=INT_MIN;
	for (i = s; i <= e; i++)
	{
		if (a[i] < min)min = a[i];
		else if (a[i] > max) max = a[i];
	}
	for (i = 0; i < s; i++) if (a[i] > min)break;
	s = i ;
	for (i = n - 1; i > e; i--) if (a[i] < max)break;
	e = i ;
	cout << s <<" "<< e;
}
void printRepeating(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		if (a[abs(a[i])] > 0)  a[abs(a[i])] = -a[abs(a[i])];
		else cout << "repeating is " << abs(a[i]) << endl;
	}
}

int equilibrium(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		int l = 0, h = 0;
		for (int j = 0; j < n; j++) {
			if (j < i)l += a[j];
			else if(j>i) h += a[j];
		}
		if (l == h) cout<<i << " " ;
	}
	return -1;
}
int equilibrium1(int a[], int n)
{
	int s = 0;
	int l = 0;
	for (int i = 0; i < n; i++) s += a[i];
	for (int i = 0; i < n; i++)
	{
		s -= a[i];
		if (l == s ) cout << i << " ";
		l += a[i];
	}
	return -1;
}
void displayMatrix(unsigned int* m, int r, int c)
{
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
			printf("%2d ", *(m + i*c + j) );
		cout << endl;
	}
}
void rotate1(unsigned int *s, unsigned int* d, int r, int c)
{
	//m[i][j] = m+i*c+j
	//d[j][n-i-1] = d+j*r+i
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
			*(d + j*r + r - i - 1) = *(s + i*c + j);
	}
}
void rotate2(unsigned int *m, int r, int c)
{
	//Inplace rotation 
	// this method work for square matrix
	// do transpose of matrix
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			unsigned int t = *(m + i*c + j);
			*(m + i*c + j) = *(m + j*c + i);
			*(m + j*c + i) = t;
		}
	}
	//reverse by row/ col to  rotate 90c clocl/counter clock wise
	for (int i = 0; i < r; i++)
		reverse(m + i*c, m + i*c + c);
}
unsigned int* fun(unsigned int * m, int i, int j) { return (m + i * 4 + j); }
void rotate3(unsigned  int *m, int r, int c)
{
	//	unsigned int image[][4] = { 
	//	{ 1,2,3,4 },
	//	{ 5,6,7,8 },
	//	{ 9,10,11,12},
	//	{13,14,15,16}
	//};
	//unsigned int m=4, n=4;
	//unsigned int *pSource = (unsigned int*)image;
	//unsigned int *pDestination  =  new unsigned int[m*n];
	//displayMatrix(pSource, m, n);
	//rotate3(pSource, m, n);
	//displayMatrix(pSource, m, n);// rotoate inplace
	for (int i = 0; i <= r / 2; i++)
	{
		for (int j = i; j <= r/ 2; j++)
		{
			unsigned int* t = fun(m,i,j);
			*(fun(m, i, j)) = *(fun(m, j,r- i-1));
			*(fun(m, j,r- i-1)) = *(fun(m, r-i, r-j-1));
			*(fun(m, r-i-1, r-j-1)) = *(fun(m, r-j-1, i));
			*(fun(m, r-j-1, i)) = *t;
		}
	}
}

void printNGE(int a[], int n)
{
	stack<int> s;
	for (int i = 0; i < n; i++)
	{
		while (!s.empty() && s.top() < a[i])
		{
			cout << s.top() << " NGE-> " << a[i]<<endl;
			s.pop();
		}
		s.push(a[i]);
	}
	while (!s.empty())
	{
		cout << s.top() << " NGE-> " << -1 << endl;
		s.pop();
	}
}
bool areConsecutive(int a[], int n)
{
	int min=INT_MAX, max=INT_MIN;
	for (int i = 0; i < n; i++)
	{
		if (a[i] < min)min = a[i];
		else if (a[i] > max)max = a[i];
	}
	if (max - min + 1 != n) return false;
	
	for (int i = 0; i < n; i++)
	{
		if (a[abs(a[i]) - min] > 0)
			a[abs(a[i]) - min] = -a[abs(a[i]) - min];
		else
			return false;
	}
	return true ;
}
int maxIndexDiff(int a[], int n)
{
	int m = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = n - 1; j >= i; j--)
		{
			if (a[j] > a[i]&& m<j-i)m = j - i;
		}
	}
	return m;
}
void printKMax(int a[], int n, int k)
{
	// max heap, insert firdt k item
	// print top of heap, now replace i-k th element from heap with ith element
	// do reheapify and repeat the same till n
	int *h = new int[k];
	for (int i = 0; i < k; i++) h[i] = a[i];
	for(int i=k/2-1;i>=0;i--)
	heapifyMin(h,i, k);
	cout << h[0]<<" ";
	for (int i = k; i < n; i++)
	{
		for (int j = 0; j < k; j++)
			if (a[k - i] == h[j])
			{
				h[j] = a[i]; break;
			}

		heapifyMin(h, 0, k);
		
		cout << h[0]<<" ";
	}
}
//
//int main()
//{
//	int arr[] = { 12, 1, 78, 90, 57, 89, 56 };
//	int n = sizeof(arr) / sizeof(arr[0]);
//	int k = 3;
//	printKMax(arr, n, k);
//
//	system("pause");
//}
/*
http://www.geeksforgeeks.org/maximum-difference-between-two-elements/
http://www.geeksforgeeks.org/a-product-array-puzzle/
http://www.geeksforgeeks.org/check-if-array-elements-are-consecutive/

*/