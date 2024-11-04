/*
    You are given an array of integers nums containing n + 1 integers. Each integer in nums is in the
    range [1, n] inclusive.

    Every integer appears exactly once, except for one integer which appears two or more times.
    Return the integer that appears more than once.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

/* T.C: O(n*log(n)), S.C: O(n) or O(1) */
int findDuplicateSorting(std::vector<int>& nums)
{
    std::sort(nums.begin(), nums.end());    
    
    for(int i = 0; i < nums.size() - 1; ++i)
    {
        if(nums[i] == nums[i + 1])
        {
            return nums[i];
        }
    }

    return -1;
}

/* T.C: O(n), S.C: O(n)*/
int findDuplicateHashSet(std::vector<int>& nums)
{
    std::unordered_set<int> seen;

    for(auto const& num : nums)
    {
        if(seen.find(num) != seen.end())
        {
            return num;
        }
        seen.insert(num);
    }

    return -1;
}

/* T.C: O(n), S.C: O(n)*/
int findDuplicateArray(std::vector<int>& nums)
{
    std::vector<int> seen (nums.size(), 0);

    for(auto const& num : nums)
    {
        if(seen[num - 1]  == 1)
        {
            return num;
        }
        seen[num - 1] = 1;
    }

    return -1;
}

/* T.C: O(n) S.C: O(1)*/
int findDuplicateNegativeMarking(std::vector<int>& nums)
{
    for(auto const& num : nums)
    {
        int idx = abs(num) - 1;
        
        if(nums[idx] < 0)
        {
            return abs(num);
        }

        nums[idx] *= - 1;
    }

    return -1;
}

/* T.C: O(n) S.C: O(1)*/
int findDuplicate(std::vector<int>& nums)
{
    int slow = 0, fast = 0;
    
    while(true)
    {
        slow = nums[slow];
        fast = nums[nums[fast]];

        if(slow == fast){break;}
    }
    
    int slow2 = 0;

    while (true)
    {
        slow = nums[slow];
        slow2 = nums[slow2];

        if(slow == slow2){return slow;}
    }
    
    return -1;
}

int main()
{
    std::vector<int> nums = {1, 2, 3, 4, 2};
    std::cout << findDuplicateSorting(nums) << std::endl;
    std::cout << findDuplicateHashSet(nums) << std::endl;
    std::cout << findDuplicateArray(nums) << std::endl;
    std::cout << findDuplicateNegativeMarking(nums) << std::endl;

    return 0;
}