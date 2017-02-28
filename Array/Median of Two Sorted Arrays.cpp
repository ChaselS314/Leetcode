// O(log(m+n))
// 相当于在两个sorted序列l1, l2中第K大的元素
// --> 判断两个序列中的第K/2个元素，若相等，即满足条件
// --> 若l1[k/2](伪代码)较小，则删除l1前K/2个元素，在剩余的两个序列中查找第K/2大的元素
// --> 反之亦然
class Solution {
public:
    double findK(vector<int>::iterator iter1, int m, vector<int>::iterator iter2, int n, int k){
        if(m > n) return findK(iter2, n, iter1, m, k);
        if(m == 0) return *(iter2 + k - 1);
        if(k == 1) return min(*iter1, *iter2);
        
        int k1 = min(k/2, m);
        int k2 = k - k1;

        if(*(iter1 + k1 - 1) == *(iter2 + k2 - 1)) return *(iter1 + k1 - 1);
        else if(*(iter1 + k1 - 1) < *(iter2 + k2 - 1)) return findK(iter1 + k1, m-k1, iter2, n, k-k1);
        else return findK(iter1, m, iter2+k2, n-k2, k-k2);
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int targetindex = (nums1.size() + nums2.size() + 1)/2;
        if((nums1.size() + nums2.size()) % 2 == 0)
            return (findK(nums1.begin(), nums1.size(), nums2.begin(), nums2.size(), targetindex) + 
                    findK(nums1.begin(), nums1.size(), nums2.begin(), nums2.size(), targetindex+1)) / 2.0;
        else
            return findK(nums1.begin(), nums1.size(), nums2.begin(), nums2.size(), targetindex);
    }
};

// O(log(min(m, n)))
// l1长度为m, l2长度为n，假设m < n, 查找两个序列中第K大的元素
// 以l1作为基础，寻找一个i属于(0, m), j = k - i，使得l1[i-1] <= l2[j] and l2[j-1] <= l1[i]即可
// 以下为别人的Python代码(https://discuss.leetcode.com/topic/4996/share-my-o-log-min-m-n-solution-with-explanation)
def median(A, B):
    m, n = len(A), len(B)
    if m > n:
        A, B, m, n = B, A, n, m
    if n == 0:
        raise ValueError

    imin, imax, half_len = 0, m, (m + n + 1) / 2
    while imin <= imax:
        i = (imin + imax) / 2
        j = half_len - i
        if i < m and B[j-1] > A[i]:
            # i is too small, must increase it
            imin = i + 1
        elif i > 0 and A[i-1] > B[j]:
            # i is too big, must decrease it
            imax = i - 1
        else:
            # i is perfect

            if i == 0: max_of_left = B[j-1]
            elif j == 0: max_of_left = A[i-1]
            else: max_of_left = max(A[i-1], B[j-1])

            if (m + n) % 2 == 1:
                return max_of_left

            if i == m: min_of_right = B[j]
            elif j == n: min_of_right = A[i]
            else: min_of_right = min(A[i], B[j])

            return (max_of_left + min_of_right) / 2.0
// 我写的C++代码，有错，先不管了
class Solution
{
public:
    double findK(std::vector<int>::iterator iter1, std::vector<int>::iterator iter2, int ileft, int iright, int total){
        int i = (iright - ileft)/2 + 1;
        int j = (total+1)/2-i;
        if(*(iter1+i-1) <= *(iter2+j) && *(iter2+j-1) <= *(iter1+i)){
            // 找到满足条件的i
            if(total % 2 == 0) return (max(*(iter1+i-1), *(iter2+j-1)) + min(*(iter1+i), *(iter2+j))) / 2.0;
            else return max(*(iter1+i-1),  *(iter2+j-1));
        }
        else if(*(iter1+i-1) > *(iter2+j)){
            return findK(iter1, iter2, ileft, i+1, total);
        }
        else if(*(iter2+j-1) > *(iter1+i)){
            return findK(iter1, iter2, i-1, iright, total);
        }
    }
    double findMedianSortedArrays(vector<int>& nums1, std::vector<int>& nums2){
        if(nums1.size() > nums2.size()){
            auto temp = nums1;
            nums1 = nums2;
            nums2 = nums1;
        }
        if(nums1.size() == 0){
            if(nums2.size() % 2 == 0) return (nums2[(nums2.size()-1)/2] + nums2[(nums2.size()+1)/2]) / 2.0;
            else return nums2[(nums2.size()-1)/2];
        }
        int ileft = 1, iright = nums1.size();
        int total = nums1.size() + nums2.size();

        return findK(nums1.begin(), nums2.begin(), ileft, iright, total);
    }
    
};