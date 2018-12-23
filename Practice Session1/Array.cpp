#include<iostream>
#include<string>
#include<stack>
#include<queue>
#include<map>
#include"test.h"
#include<stdlib.h>
//#include"sorting.cpp"
using namespace std;
/*
http://www.geeksforgeeks.org/maximum-difference-between-two-elements/	
http://www.geeksforgeeks.org/maximum-sum-such-that-no-two-elements-are-adjacent/
http://www.geeksforgeeks.org/median-of-two-sorted-arrays/
http://www.geeksforgeeks.org/block-swap-algorithm-for-array-rotation/
http://www.geeksforgeeks.org/counting-inversions/
*/
namespace Array
{
	int compAsc(const void *a, const  void *b) { return (*(int*)a) - (*(int*)b); }
	int compDes(const void *a, const  void *b) { return (*(int*)b) - (*(int*)a); }
	void printPairsSort(int a[], int n, int s)
	{
		qsort(a, n , 4, compAsc);
		int i = 0, j = n - 1;
		while (i < j)
		{
			if (a[i] + a[j] == s) {
				cout << a[i] << " " << a[j] << endl; return;
			}
			else if (a[i] + a[j] < s)i++;
			else j--;
		}
		cout << "no such pair";
	}
	void printPairsHashMap(int a[], int n, int s)
	{
		bool Hmap[1000] = { false };
		for (int i = 0; i < n; i++)
		{
			int t = s - a[i];
			if (t > 0) {
				if (Hmap[t]) { cout << a[i] << " " << t << endl; }
				else Hmap[a[i]] = true;
			}
		}
	}
	void printMajority(int a[], int n)
	{// find condidate element then check if it is majority 
		int x = a[0];
		int c = 1;
		for (int i = 1; i < n; i++)
		{
			if (a[i] == x)c++;
			else c--;
			if (c == 0)x = a[i];
		}
		c = 0;
		for (int i = 0; i < n; i++)
			if (a[i] == x)c++;
		if (c > n / 2) cout << "majority element is " << x<<endl;
		else cout << "No majority element found" << endl;
	}
	int getOddOccurrence(int a[], int n)
	{
		int s = 0;
		for (int i = 0; i < n; i++)
		{
			s = s^a[i];
		}
		return s;
	}
	int maxSubArraySum(int a[], int n)
	{ // if all number are -ve return max no.

		int max = 0, m = 0;
		int maxs, maxe;
		int ms=0, me=0;
		int negMax=INT_MIN;
		bool allNeg = true;
		for (int i = 0; i < n; i++)
		{
			m += a[i];
			if (m < 0) { m = 0; ms = i+1; }
			else if (max < m) { max = m; maxs = ms; maxe = i; allNeg = false; }
			
			if (a[i]<0 && negMax<a[i]) { negMax = a[i]; me = i; }//  case to handle all negative
		}
		if (!allNeg)
			cout << "[ " << maxs << "," << maxe << "] sum = " << max; \
		else cout << negMax << me;
		return max;
	}
	int findPivot(int a[], int l, int h) 
	{
		while (l < h)
		{
			int m = (l + h) / 2;
			if (m > 0 && a[m] < a[m - 1]) return m - 1;
			else if (m<h&&a[m]>a[m + 1]) return m;

			if (a[m] > a[0]) { l = m + 1; }
			else { h = m - 1; }
		}
		return - 1;
	}
	int binerarySearch(int a[], int l, int h, int k)
	{
		while (l < h)
		{
			int m = (l + h) / 2;
			if (a[m] == k) return m;
			else if (a[m] < k) l = m + 1;
			else h = m - 1;
		}
		return -1;
	}
	int searchSortedPivot(int a[], int l, int h, int k)
	{
		int i = findPivot(a, l, h);
		if (i <= 0)return -1;
		if (a[i] == k) return i;
		else if (a[l] < k)  return binerarySearch(a, 0, i, k); 
		else return  binerarySearch(a, i + 1, h,k);
	}
	int searchSortedPivotRec(int a[], int l, int h, int k)
	{
		if (l < h)
		{
			int m = (l + h) / 2;
			if (a[m] == k) return m;
		
			if (a[l] < a[m])
			{
				if (k > a[l] && k < a[m]) return searchSortedPivotRec(a, l, m - 1, k);
				else return searchSortedPivotRec(a, m + 1, h, k);
			}
			if (k > a[m] && k < a[h]) return searchSortedPivotRec(a, m + 1, h, k);
			else searchSortedPivotRec(a, l, m - 1, k);
		}
	}
	void printArray(int a[], int n) { for (int i = 0; i < n; i++)cout << a[i] << " "; cout << endl;}
	void moveAtend(int a[], int n)
	{
		for (int i=n-1,j=n-1; i >= 0; i--)
		{
			if (a[i] != -1)
			{
				a[j] = a[i];
				j--;
			}
		}
	}
	void mergeSortedArray(int ab[], int b[], int m, int n)
	{
		moveAtend(ab, m+n);
		int i = 0;
		int j = n;
		int k = 0;
		while (k < m + n)
		{
			if (ab[j] < b[i]) ab[k++] = ab[j++];
			else ab[k++] = b[i++];
		}

	}
	void rotateByOne(int a[], int n)
	{
		int t = a[0];
		for (int i = 0; i < n - 1; i++)
			a[i] = a[i + 1];
		a[n - 1] = t;
	}
	void leftRotate1(int a[], int n, int d)
	{
		for (int i = 0; i < d; i++)rotateByOne(a, n);
	}
	int gcd(int a, int b)
	{
		if (!b) return a;
		return gcd(b, a%b);
	}
	void leftRotate(int a[], int n, int d)
	{
	// reversal algo reverse both part and then fulll aray
	// copy in temp array move and copy back
	// juggling algo take gcd and copy on interval
		int g = gcd(n, d);

		int j,k;
		for (int i = 0; i < g; i++)
		{
			int t = a[i];
			j = i;
			while (1)
			{
				k = j + d;
				if (k >= n)k = k - n;
				if (k == i)break;
				a[j] = a[k];
				j = k;
			}
			a[j] = t;

		}
	}
	int max(int a, int b) { return a > b ? a : b; }
	int FindMaxSumExclusive(int a[], int n)
	{
		int inc = a[0];
		int excl = 0;
		int exclNew = 0;
		for (int i = 1; i < n; i++)
		{
			exclNew = max(inc, excl);
			inc =excl+ a[i];
			excl = exclNew;
		}
		return max(inc, excl);
	}
	void printLeaders(int a[], int n)
	{
		int m = 0;
		for (int i = n - 1; i >= 0; i--)
			if (a[i] > m) { m = a[i]; cout << m << "is leader at index " << i << endl; }
	}

	struct Freq {
		int index, data, freq;
	};
	/*int compData(const void *a, const void* b)
	{
		return ((Freq*)b)->data - ((Freq*)a)->data;
	}*/

	bool compData(Freq a, Freq b)
	{
		return a.data < b.data;
	}
	/*int compFreq(const void *a,const void* b)
	{
		if(((Freq*)b)->freq != ((Freq*)a)->freq)
		  return ((Freq*)b)->freq - ((Freq*)a)->freq;
		else return ((Freq*)b)->index - ((Freq*)a)->index;
	}*/
	bool compFreq(Freq a, Freq b)
	{
		if (a.freq == b.freq)
			return a.index < b.index;
		else
			return a.freq < b.freq;
			
	}
	void bubbleSort(int a[], int n)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n - i - 1; j++)
				if (a[j] > a[j + 1]) swap(a[j], a[j + 1]);
		}

	}
	void printFreqArray(Freq a[], int n) {
		for (int i = 0; i < n; i++)
			cout << "[ " << a[i].data << " , " << a[i].freq<<" ] ";
	}
	void sortByFrequency(int a[],  int n)
	{
		//qsort(a, n,4,compAsc);
	//	bubbleSort(a, n);
	//	printArray(a, n);
		Freq *f = new Freq[n];
		int x = 0;
		int j = -1;
		for (int i = 0; i<n; i++)
		{
			f[i].data = a[i];
			f[i].index = i;
			f[i].freq = 1;
		}

		stable_sort(f, f + n, compData);
		//qsort(f, n, sizeof(Freq), compData);
		cout << endl;
		printFreqArray(f, n);
		for(int i=0;i<n;i++)
		{ 
			if(x== f[i].data)
				f[j].freq++;
			else
			{
				x = f[i].data;
				f[++j].data = f[i].data;
				f[j].index = i;
				//f[j].freq = 1;
			}
		}
		cout << endl;
		printFreqArray(f, j+1);
		cout << endl;
		stable_sort(f, f + j+1 , compFreq);
		printFreqArray(f, j + 1);
		cout << endl;
		//	qsort(f, j + 1,sizeof(Freq),compFreq);
		int k = 0;
		for (int i = 0; i <= j &&k<n; i++) 
		{
			int l = 0;
			while (l++ < f[i].freq)
				a[k++] = f[i].data;
		}
	}
	void print2Smallest(int a[], int n)
	{
		int f = INT_MAX, s = INT_MAX;
		for (int i = 0; i < n; i++)
		{
			if (f > a[i])
			{
				s = f;
				f = a[i];
			}
			else if (a[i] < s && a[i]!=f) s = a[i];
		}
		cout << f<<" "  << s;
	}
	void productArray(int a[], int n)
	{
		int *p = new int [n];
		memset(p, 1, n);
		int t = 1;
		for (int i = 0; i < n; i++)
		{
			p[i] = t;
			t = t*a[i];
		}
		t = 1;
		for (int i = n - 1; i >= 0; i--)
		{
			p[i] *= t;
			t *= a[i];
		}
		for (int i = 0; i < n; i++)cout << p[i] << " ";
	}
	void printRepeating(int a[], int n)
	{
		int x = 0;
		for (int i = 0; i < n; i++)
			x = x^a[i];
		for (int i = 1; i <= n - 2; i++)x ^= i;
		x = x&-x;
		int l = 0, m = 0;
		for (int i = 0; i < n; i++)
		{
			if (a[i] & x) l = l^a[i];
			else m = m^a[i];
		}
		for (int i = 1; i <= n - 2; i++)
		{
			if (i&x) l ^= i;
			else m ^= i;
		}
		cout << l << " " << m;
	}
	void printRepeating1(int a[], int n)
	{
		for (int i = 0; i < n; i++)
		{
			if (a[abs(a[i])] > 0)
				a[abs(a[i])] = -a[abs(a[i])];
			else {
				cout << abs(a[i]) << " ";
			}
		}
		for (int i = 0; i < n; i++)
		{
			if (a[abs(a[i])] < 0)
				a[abs(a[i])] = -a[abs(a[i])];
		}
	}
	int equilibrium(int a[], int n)
	{
		int sum = 0,s=0;
		for (int i = 0; i < n; i++)
			sum += a[i];

		for (int i = 0; i < n; i++)
		{
			sum -= a[i];
			if (s == sum) return i;
			s += a[i];
		}
	}
	void displayMatrix(unsigned int const *p,
		unsigned int r,
		unsigned int c)
	{
		unsigned int row, col;
		printf("\n\n");

		for (row = 0; row < r; row++)
		{
			for (col = 0; col < c; col++)
				printf("%d\t", *(p + row * c + col));
			printf("\n");
		}

		printf("\n\n");
	}
	void rotateMatrix(unsigned int *s, unsigned int *d, int r, int c)
	{
		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
				//d[j][c-i-1] = s[i][j];
				*(d +j*r+(r-i -1)) = *(s + i*c + j);
		}
	}
	void printNGE(int a[], int n)
	{
		stack<int> s;
		s.push(a[0]);
		int t = 0;
		for (int i = 1; i < n; i++)
		{
			t = a[i];
			while(!s.empty() && t>s.top())
			{
				cout << s.top() << " -> " << t<<endl;
				s.pop();
			}
			s.push(t);
		}
		while (!s.empty()) {
			cout << s.top() << "-> -1 " << endl; s.pop();
		}
	}
}
using namespace Array;
// Uses the MCI_OPEN, MCI_RECORD, and MCI_SAVE commands to record and
// save a waveform-audio file. Returns 0L if successful; otherwise,
// it returns an MCI error code.
#include<stdlib.h>
#include <windows.h>
DWORD recordWAVEFile(DWORD dwMilliSeconds)
{
	UINT wDeviceID;
	DWORD dwReturn;
	MCI_OPEN_PARMS mciOpenParms;
	MCI_RECORD_PARMS mciRecordParms;
	MCI_SAVE_PARMS mciSaveParms;
	MCI_PLAY_PARMS mciPlayParms;

	// Open a waveform-audio device with a new file for recording.
	mciOpenParms.lpstrDeviceType = "waveaudio";
	mciOpenParms.lpstrElementName = "";
	if (dwReturn = mciSendCommand(0, MCI_OPEN,
		MCI_OPEN_ELEMENT | MCI_OPEN_TYPE,
		(DWORD)(LPVOID)&mciOpenParms))
	{
		// Failed to open device; don't close it, just return error.
		return (dwReturn);
	}

	// The device opened successfully; get the device ID.
	wDeviceID = mciOpenParms.wDeviceID;

	// Begin recording and record for the specified number of 
	// milliseconds. Wait for recording to complete before continuing. 
	// Assume the default time format for the waveform-audio device 
	// (milliseconds).
	mciRecordParms.dwTo = dwMilliSeconds;
	if (dwReturn = mciSendCommand(wDeviceID, MCI_RECORD,
		MCI_TO | MCI_WAIT, (DWORD)(LPVOID)&mciRecordParms))
	{
		mciSendCommand(wDeviceID, MCI_CLOSE, 0, NULL);
		return (dwReturn);
	}

	// Play the recording and query user to save the file.
	mciPlayParms.dwFrom = 0L;
	if (dwReturn = mciSendCommand(wDeviceID, MCI_PLAY,
		MCI_FROM | MCI_WAIT, (DWORD)(LPVOID)&mciPlayParms))
	{
		mciSendCommand(wDeviceID, MCI_CLOSE, 0, NULL);
		return (dwReturn);
	}
	if (MessageBox(hMainWnd, "Do you want to save this recording?",
		"", MB_YESNO) == IDNO)
	{
		mciSendCommand(wDeviceID, MCI_CLOSE, 0, NULL);
		return (0L);
	}

	// Save the recording to a file named TEMPFILE.WAV. Wait for
	// the operation to complete before continuing.
	mciSaveParms.lpfilename = "tempfile.wav";
	if (dwReturn = mciSendCommand(wDeviceID, MCI_SAVE,
		MCI_SAVE_FILE | MCI_WAIT, (DWORD)(LPVOID)&mciSaveParms))
	{
		mciSendCommand(wDeviceID, MCI_CLOSE, 0, NULL);
		return (dwReturn);
	}

	return (0L);
}

int main()
{
	int arr[] = { 11, 13, 21, 3 };
	int n = sizeof(arr) / sizeof(arr[0]);
	printNGE(arr, n);
	system("pause");
}
/*
http://www.geeksforgeeks.org/check-if-array-elements-are-consecutive/
http://www.geeksforgeeks.org/turn-an-image-by-90-degree/ Do in place 
http://www.geeksforgeeks.org/a-product-array-puzzle/
http://www.geeksforgeeks.org/find-the-two-repeating-elements-in-a-given-array/
*/