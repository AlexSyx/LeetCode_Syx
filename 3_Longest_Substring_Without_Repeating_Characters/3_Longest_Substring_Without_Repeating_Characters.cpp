
#include<string>
#include<iostream>
#include<unordered_map>
using namespace std;

class Solution {
public:
	int lengthOfLongestSubstring_Force(string s) {
		unordered_map<char,int> map;
		int max = 0;

		for (int i = 0; (i < s.length()) && (s.length() - i > max); i++)
		{
			bool norepeat = true;
			int j = i;
			while (norepeat && (j < s.length()))
			{
				if (map.find(s[j])!=map.end())
				{
					max = max > (j-i) ?  max : (j-i);	
					norepeat = false;
				}
				else if (j == s.length() - 1)
				{
					max = max > (j - i+1) ? max : (j - i+1);
				}
				map.insert(pair<char, int>(s[j], j));
				j++;
			}
			map.clear();
		}

		return max;
	};

	int lengthOfLongestSubstring(string s) {
		unordered_map<char, int> map;
		int max = 0;
		int former_max=0;
		int i = 0;
		int j = 0;
		int m;
		while ((i < s.length()) && (s.length() - i > max))
		{
			while (j < s.length())
			{
				if (map.find(s[j]) != map.end())     //if repeat
				{
					m = map.find(s[j])->second;
					former_max = j - i;
					max = max >(j - i) ? max : (j - i);
					break;
				}
				else if (j == s.length() - 1)        //not repeat but reach the end
				{
					max = max > (j - i + 1) ? max : (j - i + 1);
					
					return max;

				}
				map.insert(pair<char, int>(s[j], j));
				j++;
			}
			
			for (int temp = i; temp <= m; temp++)
			{
				map.erase(s[temp]);
			}
			map.insert(pair<char, int>(s[j], j));
			j++;
			i = m + 1;
			

			

		}

		return max;
	}
}solution;
int main()
{
	string str("abcabcbb");
	cout<<solution.lengthOfLongestSubstring(str);
}