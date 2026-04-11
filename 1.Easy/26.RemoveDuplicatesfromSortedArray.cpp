//https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/
class Solution {
    public static int removeDuplicates(int[] nums) {
		 if (nums.length <= 1) {
	        return nums.length;
	    }

	    int x = 0;
	    for (int i = 1; i < nums.length; i++) {
	        if (nums[i] != nums[x]) {
	            x++;
	            nums[x] = nums[i];
	        }
	    }
	    for (int i = 0; i < nums.length; i++) {
			System.out.println(nums[i]);
		}
	    return x + 1;
	}
}
