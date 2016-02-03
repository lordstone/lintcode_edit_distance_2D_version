class Solution {
public:    
    /**
     * @param word1 & word2: Two string.
     * @return: The minimum number of steps.
     */
    int minDistance(string word1, string word2) {
        // write your code here
        if(word1.length() == 0 && word2.length() || word1 == word2){
            return 0;
        }
        if(word1.length() == 0 || word2.length() == 0){
            return max(word1.length(),word2.length());
        }
        vector<vector<int>> res (word1.length() + 1, vector<int> ( word2.length() + 1, 0));
        
        for(int i = 0; i <= word2.length(); i ++) res[0][i] = i;
        for(int i = 0; i <= word1.length(); i ++) res[i][0] = i;
        
        for(int i = 1; i <= word1.length(); i ++){
            for(int j = 1; j <= word2.length(); j ++){
                if(word1[i-1] == word2[j-1]){
                    res[i][j] = res[i-1][j-1];
                }else{
                    int a = res[i-1][j-1] + 1;
                    int b = res[i-1][j] + 1;
                    int c = res[i][j-1] + 1;
                    int tmp = min(min(a,b),c);
                    res[i][j] = tmp;
                }
            }
        }
        return res[word1.length()][word2.length() ];
    }
};
