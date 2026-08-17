#include <iostream>
#include <vector>
using namespace std;

    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while (left + 1 < right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target)
                return mid;
            else if (nums[mid] < target)
                left = mid;
            else
                right = mid;
        }

        if (nums[left] == target) return left;
        if (nums[right] == target) return right;

        return -1;
    }
void solve(){
	int size;
	cin>>size;
	vector<int>nums(size);
	for(int i=0;i<size;i++){
		cin>>nums[i];
	}
	int t;
	cin>>t;
	cout<<search(nums,t);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int tc=1;
    while(tc--){
    	solve();
    }
    return 0;
    	
}