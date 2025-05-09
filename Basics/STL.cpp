// C++ STL => 1. Algorithms , 2. Containers , 3. Functions , 4. Iterators

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void printName(string name) {
	cout << "Name of the person : " << name << endl;
}

int sum(int a,int b) {
	return a + b;
}

//Pairs
void explainPair() {

	pair<int,int>p = {1,2};
	cout << p.first << " " << p.second << endl;

	pair<int, pair<int, int>> nestedPair = {1,{2,3}};
	cout << nestedPair.first << " " << nestedPair.second.first << " " << nestedPair.second.second << endl;

	pair<int, int> arr[] = { {1,2}, {3,4}, {5,6}, {7,8}, {9,10} };
	cout << arr[0].first << " " << arr[0].second << endl;
}

//Vectors : dynamic in nature
//It's best practice to use vector when we are unaware about the size of the container.

void explainVectors() {

	vector<int> v;

	v.push_back(1);
	v.emplace_back(2); //Faster method than push_back

	vector<pair<int, int>> VecPair;
	VecPair.push_back({1,2});
	// VecPair.emplace_back({3,4});

	vector<int> vec(5, 100);  //5 Instances of 100

	vector <int> vec2(5); //5 Instances of 0

	vector<int> vec3(5,20); //5 Instances of 20

	vector<int> vec4(vec3); //This will create a copy of vec3

	vector<int>vecFive{10,20,30,40,50};

	vector<int>::iterator it = vecFive.begin(); //iterator points towards the memory
	it++;
	cout << "Value at loaction iterator is pointing : " << *(it) << endl;

	vector<int>::iterator it1 = vecFive.end();
	// Iterator points to the memory location just outside the container
	it1--;
	// it1 = (it1 - 1) => Iterator points the last element
	cout << "Value at loaction iterator is pointing : " << *(it1) << endl;

	// vector<int> :: iterator it2 = vecFive.rend();
	// it2--;
	// cout << "Value at locaion iterator is pointing : " << *(it2) << endl;

	// vector<int>::iterator it3 = vecFive.rbegin();

	cout << vecFive[0] << " " << vecFive.at(0) << endl;

// 	for (vector<int>::iterator it = vecFive.begin() ; it!=vecFive.end() ; it++) {
// 		cout << *(it) << " ";
// 	}

// 	cout << endl;

// 	for (auto it = vecFive.begin() ; it!=vecFive.end() ; it++) {
// 	    cout << *(it) << " ";
// 	}

// 	cout << endl;

// 	for(auto it: vecFive){
// 	    cout << it << " ";
// 	}

// 	vecFive.erase(vecFive.begin()+1);

// 	for(auto it: vecFive){
// 	    cout << it << " ";
// 	}

// 	cout << endl;

// 	vecFive.erase(vecFive.begin()+1 , vecFive.begin() + 3);

// 	for(auto it: vecFive){
// 	    cout << it << " ";
// 	}

// 	cout << endl;

// Insert

	vector<int>ExVec(2,100); // {100,100}
	ExVec.insert(ExVec.begin(),300); // {300,100,100}
	ExVec.insert(ExVec.begin(),2,50); // {300,50,50,100,100}

	vector<int>copy{2,50}; // {50,50}
	ExVec.insert(ExVec.begin()+1,copy.begin(),copy.end());
// {300,50,50,50,50,100,100}

	cout << ExVec.size() << endl;

	ExVec.pop_back();
	cout << ExVec.size() << endl;

	vector<int>v1{10,20}; //v1 => {10,20}
	vector<int>v2{30,40}; //v2 => {30,40}
	v1.swap(v2);

	for(auto it : v1) {
		cout << it << " ";
	}
	cout << endl;

	for(auto it : v2) {
		cout << it << " ";
	}

	cout << endl;

	ExVec.clear(); //erases the entire vector

	cout << ExVec.empty();
}

void explainList() {
	list<int> lst{10,30,40,65};

	lst.push_back(90);
	lst.emplace_back(100);

	lst.push_front(15);
// 	lst.emplace.front(99);

	for(auto it: lst) {
		cout << it << " ";
	}

	cout << endl;

	// rest functions are same as vector
	// begin, end, rbegin, rend, clear, insert, size, swap

}

void explainDeque() {

	std::deque<int>dq{1,2,3,4};

	dq.push_back(1);
	dq.push_front(3);

	dq.pop_back();
	dq.pop_front();

	cout << dq.back() << endl;

	cout << dq.front() <<endl;
}

void explainStack() {

	// L I F O => Last In , First Out

	stack<int> st;

	st.push(1);
	st.push(3);
	st.push(4);
	st.push(2);
	st.push(10);
	st.pop();

// => | 1 | 3 | 4 | 2 |

	cout << "Top of the stack : " << st.top() << endl;
	cout << "Size of the stack : " << st.size() << endl;
	cout << "Stack empty or not : " << st.empty() << endl;

	stack<int>st1, st2;
	st1.swap(st2);
}

void explainQueue() {

	std::queue<int> q;

	q.push(1); // { 1 }
	q.push(2); // { 1 , 2 }
	q.emplace(4); // { 1 , 2 , 4 }
	q.back() += 5;

	cout << "Value of q.back() : " << q.back() << endl;
	// prints 9
	// Q is { 1 , 2 , 9 }

	q.pop(); // { 2 , 9 }
	cout << q.front() << endl; // prints 2

	// size swap and empty same as stack !
}

void explainPQ() {
	// Data is not stored in an linear manner !
	priority_queue<int> pq;

	pq.push(5); // {5}
	pq.push(2); // {5,2}
	pq.push(8); // {8,5,2}
	pq.emplace(10); // {10,8,5,2}

	cout << "Top of the priority_queue is " << pq.top() << endl;

}

void explainSet() {

// unique and sorted !
	std::set<int> st;

	st.insert(1);  // { 1 }
	st.emplace(2); // { 1 , 2 }
	st.insert(2);  // { 1 , 2 }
	st.insert(4);  // { 1 , 2 , 4 }
	st.insert(3);  // { 1 , 2 , 3 , 4 }
	st.insert(5);  // { 1 , 2 , 3 , 4 , 5 }

	// Functionality of insert in vector
	// can be used also, that only increases
	// effeciency

	// begin() , end() , rbegin() , rend() , size() ,
	// empty() and swap() are same as above.

	auto it2 = st.find(1);
	cout << *(it2) << endl;

	auto it = st.find(3);
	cout << *(it) << endl;

	auto it1 = st.find(5);
	cout << *(it1) << endl;

	st.erase(5); // erases 5
	// takes logarithmic time

	bool cnt = st.count(5);
	cout << "Is 5 in the set or not => " << cnt << endl;

	cout << "Values stored in the set => " << endl;
	for(auto it = st.begin() ; it!=st.end() ; it++) {
		cout << *(it) << " ";
	}
	cout << endl;

	auto itr = st.find(3);
	st.erase(itr); // it takes constant time

	cout << "Set Values after removing => " << endl;
	for(auto it : st) {
		cout << it << " ";
	}

	cout << endl;

	// { 1 , 2 , 4 }
	st.insert(3);
	st.insert(5);
	st.insert(9);

	// { 1 , 2 , 3 , 4 , 5 , 9 }  ---
	//          it1               it2

	auto itr1 = st.find(3);
	auto itr2 = st.end();
	st.erase(itr1,itr2);

	cout << "Set after removing multiple elements => " << endl;
	for(auto it : st) {
		cout << it << " ";
	}

	// lower_bound and upper_bound function works in the same way.
}

void explainMultiSet() {
	// everything is same as set
	// only stores duplicate element as well

	// sorted , not unique
	multiset<int> ms;

	ms.insert(1);
	ms.insert(1);
	ms.insert(2);
	ms.insert(2);
	ms.insert(2);
	ms.insert(3);
	ms.insert(4);
	// { 1 , 1 , 2 , 2 , 2 , 3 , 4 }

	ms.erase(1); // all 1's erased

	int cnt = ms.count(1);
	cout << "No of 1's in the multiset =>" << cnt << endl;

	ms.erase(ms.find(1));
	// all 1's erased

// 	ms.erase(ms.find(1) , ms.find(1) + 2);

	// rest all the functions same as set

}

void explainUSet() {

	// unique but not in sorted order
	// O(1) => ALL OPERATIONS

	unordered_set<int> st;
	// lower_bound and upper_bound function
	// doesn't works rest all functions are same
	// as above, it does not stores in any
	// particular order it has better complexity
	// than set in most cases, except some when collision happens
}

void explainMap() {

// Key - Value Pair Exists
// map stores unique keys in sorted order

	map<int, int> mp;
	map<int, pair<int, int>> mpp;
	map<pair<int,int>, int> mapOne;

	mp[1] = 2;
	mp[2] = 3;

	mapOne[ {1,2}] = 5;

	mpp[1] = {1,2};
	mpp[3] = {99,100};
	mpp[2] = {23,24};


// 	for(auto it = mpp.begin() ; it!=mpp.end() ; it++) {
// 		cout << it.first << " " << it.second << endl;
// 	}

    cout << mapOne[{1,2}] << endl;
    cout << mapOne[{3,4}] << endl; // it dne and if something dne it shows 0 as o/p
    
    // auto itr = mpp.find(1);
    // cout << *(itr).second << endl;
    
    auto itr1 = mpp.lower_bound(2);
    
    auto itr2 = mpp.upper_bound(2);
    
    // erase , swap , empty , size is same as above 
    // multiMap same as map but it has multiple keys which are same but in sorted order
    // unordered_map same as unordered_set => keys are unique but in sorted manner 
}

int main() {

	// int a;
	// cin >> a;
	// cout << a << endl;

	// int s = sum(1,2);
	// cout << "The sum of 2 no.s is " << s << endl;

	// printName("Aaryan Wadhawan");

	// explainPair();
	// explainVectors();
	// explainList();
	// explainDeque();
	// explainStack();
	// explainQueue();
	// explainMultiSet();

	// explainUSet();
	// explainMap();
	
	return 0;
}

// Functions => sort , sort with custom-comparator , _builtin_popcount() , _builtin_popcountll() , next_permutation , max_element 
