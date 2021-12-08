class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) 
        int low = 0, high = len-1, len = arr.size();;
        while(low <= high) {
            int mid = low + (high-low)/2;
            
            // Corner Cases
            if(mid == 0)            ++mid;
            if(mid == len-1)        --mid;
            
            if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1]) {
                return mid;
            }
            else if(arr[mid]>arr[mid-1] && arr[mid]<arr[mid+1]) {
                low = mid+1;
            }
            else {
                high = mid-1;
            }
        }
        return -1;
    }
};