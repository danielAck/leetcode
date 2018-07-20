 /**
 * 题目地址： https://leetcode-cn.com/problems/01-matrix/description/
 * 解题思路： 1. 从每一个0开始遍历，不停的更新每一个1的距离
			  2. 使用BFS的思想，采用队列存储坐标对(pair), 并将值为1的点的值赋为无穷大防止碰到1，1的值被修改
 *    		  3. 对队列中的每一个点/坐标遍历周围四个点，如果越界或者周围值比自己小则跳过，否则周围值加一并加入队列
 */

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dirs{{0,-1},{-1,0},{0,1},{1,0}};
        queue<pair<int, int>> q;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == 0) q.push({i, j});
                else matrix[i][j] = INT_MAX;
            }
        }
        while (!q.empty()) {
            auto t = q.front(); q.pop();
            for (auto dir : dirs) {
                int x = t.first + dir[0], y = t.second + dir[1];
                if (x < 0 || x >= m || y < 0 || y >= n ||
                matrix[x][y] <= matrix[t.first][t.second]) continue; 
                matrix[x][y] = matrix[t.first][t.second] + 1;
                q.push({x, y});
            }
        }
        return matrix;
    }
};