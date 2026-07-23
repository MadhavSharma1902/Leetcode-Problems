#include <bit>
class Solution {
public:
   int uniqueXorTriplets(vector<int>& nums) {
       int n = nums.size();
       return n < 3 ? n : pow(2, (bit_width((unsigned int)n)));
   }
};