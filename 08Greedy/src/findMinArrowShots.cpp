#include "../include/leetcode.h"

/**
 * @brief 452. 用最少数量的箭引爆气球
 * @see https://leetcode.cn/problems/minimum-number-of-arrows-to-burst-balloons/
 */
class Solution
{
public:
    int findMinArrowShots(vector<vector<int>> &points)
    {
        if (points.size() == 0)
            return 0;
        sort(points.begin(), points.end(), [](const vector<int> &a, const vector<int> &b)
             { return a[0] < b[0]; });
        int result = 1; // points 不为空至少需要一支箭
        for (int i = 1; i < points.size(); i++)
        {
            if (points[i][0] > points[i - 1][1]) // 气球i和气球i-1不挨着，注意这里不是>=
            {
                result++; // 需要一支箭
            }
            else // 气球i和气球i-1挨着
            {
                points[i][1] = min(points[i - 1][1], points[i][1]); // 更新重叠气球最小右边界
            }
        }
        return result;
    }
};