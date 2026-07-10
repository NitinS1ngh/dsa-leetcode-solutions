class Solution {
public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        int n1 = a.size();
        int n2 = b.size();
        
        // Ensure binary search is on the smaller array
        if (n1 > n2) {
            return findMedianSortedArrays(b, a);
        }

        int totalSize = n1 + n2;
        int left = (totalSize + 1) / 2;  // Left half contains half of total elements
        int low = 0, high = n1;

        while (low <= high) {
            int mid1 = (low + high) >> 1;
            int mid2 = left - mid1;

            // Initialize boundary values
            int l1 = INT_MIN, l2 = INT_MIN;
            int r1 = INT_MAX, r2 = INT_MAX;

            if (mid1 < n1) {
                r1 = a[mid1];
            }
            if (mid2 < n2) {
                r2 = b[mid2];
            }
            if (mid1 - 1 >= 0) {
                l1 = a[mid1 - 1];
            }
            if (mid2 - 1 >= 0) {
                l2 = b[mid2 - 1];
            }

            // Correct partition found
            if (l1 <= r2 && l2 <= r1) {
                if (totalSize % 2 == 1) {
                    return max(l1, l2);
                } else {
                    return (max(l1, l2) + min(r1, r2)) / 2.0;
                }
            }
            // Move left
            else if (l1 > r2) {
                high = mid1 - 1;
            }
            // Move right
            else {
                low = mid1 + 1;
            }
        }
        return -1; // This should never be reached
    }
};

