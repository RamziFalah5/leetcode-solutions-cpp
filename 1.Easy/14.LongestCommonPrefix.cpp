//https://leetcode.com/problems/longest-common-prefix/description/
class Solution {
    public String longestCommonPrefix(String[] strs) {
        String s = "";
		boolean b = true;
		char c = 0;
		int length = strs[0].length();

		for (int i = 0; i < strs.length; i++) {
			if (strs[i].length() < length)
				length = strs[i].length();
		}

		for (int i = 0; i < length; i++) {
			c = strs[0].charAt(i);
			for (int j = 0; j < strs.length; j++) {
				if (strs[j].charAt(i) == c) {
					b = true;
				} else {
					b = false;
					return s;
				}
			}
			if (b == true) {
				s += c;
			}

		}
		return s;
    }
}
