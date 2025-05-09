#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;

struct Point {
	int x,y;
};

bool myComparator(Point p1, Point p2) {
	return p1.x < p2.x;
	// this will return the pair first with lower x value...
}

int main() {
	// Case 1 : Array
	int arr[] = {10,20,5,7};
	int n = sizeof(arr)/sizeof(arr[0]);

	// sort in ascending order
	sort(arr,arr+n);
	cout << "STL func for array : " << endl;
	for(int x : arr) {
		cout << x << " ";
	}

	sort(arr,arr+n,greater<int>());
	cout << endl;
	cout << "STL func for array in desc order : " << endl;
	for(int x : arr) {
		cout << x << " ";
	}
	cout << endl;

	// Case 2 : Vector
	vector<int>v = {5,7,10,20};
	int vecSize = sizeof(v)/sizeof(v[0]);

	sort(v.begin(),v.end());
	cout << "STL func for sorting vector : " << endl;
	for(int x : v) {
		cout << x << " ";
	}
	cout << endl;

	sort(v.begin(),v.end(),greater<int>());
	cout << "STL func for sorting vector desc order : " << endl;
	for(int x : v) {
		cout << x << " ";
	}
	cout << endl;

	// Case 3 : Custom sorting
	Point brr[] = { {3,10}, {2,4}, {4,5} };
	int size = sizeof(brr)/sizeof(brr[0]);
	sort( brr, brr + size, myComparator);
	for(auto it : brr) {
		cout << "{" <<  it.x << "," << it.y << "}";
	}
	cout << endl;

	return 0;
}