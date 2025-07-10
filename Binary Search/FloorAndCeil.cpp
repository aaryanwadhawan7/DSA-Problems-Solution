#include <iostream>
#include <vector>
using namespace std;

/*
Q) We have to look for element present at the floor and ceil of x element

index =>              0     1    2     3      4     5
vector<int> nums = {  3  ,  4  ,  4  ,  7  ,  8  ,  10  }
                     low         mid               high

floor(nums[3]) ==> 4 [largest element in the nums <= x] , 
ceil(nums[3]) ==> 8  [smallest element in the nums >= x]

*/

#include <iostream>
#include <vector>
using namespace std;

int getFloor(vector<int> &nums, int x) {
   int low = 0, high = nums.size() - 1;
   int ans = -1;

   while (low <= high) {
      int mid = low + (high - low) / 2;
      if (nums[mid] == x) {
         return nums[mid];
      } else if (nums[mid] > x) {
         high = mid - 1;
      } else {
         ans = nums[mid];
         low = mid + 1;
      }
   }

   return ans;
}

int getCeil(vector<int> &nums, int x) {
   int low = 0, high = nums.size() - 1;
   int ans = -1;

   while (low <= high) {
      int mid = low + (high - low) / 2;
      if (nums[mid] == x) {
         return nums[mid];
      } else if (nums[mid] < x) {
         low = mid + 1;
      } else {
         ans = nums[mid];
         high = mid - 1;
      }
   }

   return ans;
}

int main () {
     vector<int> nums = {3, 4, 4, 7, 8, 10};
     int x; 
     cin >> x;
     int floorVal = getFloor(nums, x);
     int ceilVal = getCeil(nums, x);

     cout << "Floor of " << x << " is: " << floorVal << endl;
     cout << "Ceil of " << x << " is: " << ceilVal << endl;

     return 0;
}
