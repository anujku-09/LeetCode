class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0] == 1 || grid[n-1][n-1] == 1){
            return -1;
        }
        if(n == 1) return 1;
        int dRow[] = {-1, -1, -1,  0, 0,  1, 1, 1};
        int dCol[] = {-1,  0,  1, -1, 1, -1, 0, 1};     

        queue<vector<int>> q;
        q.push({0, 0, 1});
        grid[0][0] = 1;  
        while(!q.empty()){
            auto curr = q.front();
            q.pop();

            int r = curr[0];
            int c = curr[1];
            int dist = curr[2];
            if(r == n - 1 && c == n - 1){
                return dist;
            }
            for(int i = 0; i < 8; i++){
                int nr = r + dRow[i];
                int nc = c + dCol[i];
                if(nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] == 0){
                    grid[nr][nc] = 1;
                    q.push({nr, nc, dist + 1});
                }
            }
        }
        return -1;
    }
};