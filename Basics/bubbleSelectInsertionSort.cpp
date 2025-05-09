// Selection Sort -> Find minimum and then swap the elements

#include <bits/stdc++.h>
using namespace std;

void bubbleSort(int arr[],int n) {
	bool swapped = false;
	// no of rounds -> (n - 1)
	// Inner loop -> for iterating over rounds
	for(int i = 0; i<n; i++) {
		for(int j = 0; j < n-i; j++) {
			// Outer loop -> swapping
			// j -> (n - 1)th element , (j + 1) -> nth element
			if(arr[j] > arr[j+1]) {
				swap(arr[j],arr[j+1]);
				swapped = true;
			}
		}
		if(swapped == false) {
			// no swapping
			// already sorted
			break;
		}
	}
}

// TC : O(n^2) , SC : O(1)
void selectionSort(int arr[],int n) {
	for(int i = 0; i < n - 1; i++) {
		// iterator i -> 0 to n - 2
		// n - 1 element is already sorted
		int minIndex = i;
		for(int j = i; j < n; j++) {
			// Step 1 => finding minimum
			if(arr[j] < arr[minIndex]) {
				minIndex = j;
			}
		}
		// Step 2 => Swapping minimum element with ith element
		swap(arr[minIndex],arr[i]);
	}
}

void insertionSort(int arr[], int n) {
	for(int i = 0; i<n; i++) {
		// iterator i -> 0 to (n - 1)
		int j = i;
		while(j > 0 && arr[j-1] > arr[j]) {
			swap(arr[j],arr[j-1]);
			j--;
		}
	}
}

int main () {
	int n;
	cin >> n;
	int arr[n];

	for(int i = 0; i<n; i++) {
		cin >> arr[i];
	}

	// selectionSort(arr,n);
   // bubbleSort(arr,n);
	insertionSort(arr,n);

	for(int num : arr) {
		cout << num << " ";
	}

	return 0;
}