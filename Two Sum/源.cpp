#include<unordered_map>
#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> res;
		unordered_map<int, int> map;
		int i = 0;
		for (auto itr = nums.begin(); itr != nums.end(); itr++)
		{
			if (map.find(*itr) != map.end())
			{
				if ((*itr+*itr)==target)
				{
					res.push_back(map.find(*itr)->second);
					res.push_back(i);
					return(res);
				}
				else i++;
			}
			else
			{
               map.insert(pair<int,int>(*itr, i++));
			}
			
		}
		for (auto itr2 = map.begin(); itr2 != map.end(); itr2++)

			if ((map.find(target - itr2->first) != map.end())&& (map.find(target - itr2->first)!=itr2)) {
				if ((itr2->second)<(map.find(target - itr2->first)->second))
				{
					res.push_back(itr2->second);
					res.push_back(map.find(target - itr2->first)->second);
					return res;
				}
				else
				{
					res.push_back(map.find(target - itr2->first)->second);
					res.push_back(itr2->second);
					return res;
				}
				
			}
		}
	} solution;
int main()
{
	vector<int> num = { 3,3,11,15 };
	vector<int> result=solution.twoSum(num, 6);
	cout << result[0] << '\t' << result[1];
}	
