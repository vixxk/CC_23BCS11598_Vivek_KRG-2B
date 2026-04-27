// User function template for C++

class Solution {
  public:
    void floydWarshall(vector<vector<int>> &dis) {
        // Code here
        int n = dis.size();
        
            for(int i = 0; i < n; i++) {
            dis[i][i] = 0;
        }
        
        
        for(int k = 0; k<n; k++){
         for(int i = 0;i<n;i++){
                for(int j = 0; j<n; j++){

                 if(dis[i][k] != 1e8 && dis[k][j] != 1e8) {
                        dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
                    }
                }
            }
        }
        
        
    }
};