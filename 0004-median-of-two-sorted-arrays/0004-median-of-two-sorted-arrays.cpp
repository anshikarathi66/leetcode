class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        nums1.insert(nums1.end(), nums2.begin(), nums2.end());
        sort(nums1.begin(),nums1.end());

        int nsize=nums1.size()/2;
        double median=0.00;

        if(nums1.size()%2==0){
            median = (double(nums1[nsize]) + double(nums1[nsize-1]))/2;
            return  median;
        }
        else{
            median = nums1[nsize];
        }

        return median;
    }
};