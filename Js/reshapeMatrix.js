class Solution {
    public int[][] matrixReshape(int[][] mat, int r, int c) {
        int[][] rv = new int[r][c];
        int m = mat.length;
        int n = mat[0].length;

        if( (m*n != r*c) ){
            return mat;
        }

        int target = 0;
        int x = 0;
        int y = 0;

        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                rv[i][j] = mat[y][x];
                x++;
                if(x==n){
                    y++;
                    x = 0;
                }
            }
        }

        return rv;
    }
}
