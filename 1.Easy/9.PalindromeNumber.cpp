//https://leetcode.com/problems/palindrome-number/description/
class Solution {
    public boolean isPalindrome(int x) {
          String s1 = String.valueOf(x);
		StringBuilder s2 = new StringBuilder(s1);
		String s3 = s2.reverse().toString();
		if (s1.equals(s3)) {
			return true;
		} else
			return false;
    }
}
