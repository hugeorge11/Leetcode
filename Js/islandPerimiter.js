class Solution {
    // 1 -> land
    // 0 -> water
    //public void island
    public int getSide(int[][] grid, int xOffset){

        return 0;
    }
    public int islandPerimeter(int[][] grid) {
        int rv = 0;
        int rowCount = grid.length;
        int colCount = grid[0].length;
        int target = 0;
        for(int x = 0; x < rowCount; x++){
            int prev = 0;
            for(int y = 0; y < colCount ; y++){
                target = grid[x][y];
                if(target != prev){
                    rv++;
                }
                System.out.print(target + " ");
                prev = target;
            }
            if(target == 1){
                rv++;
            }
            System.out.println();
        }
        for(int y = 0; y < colCount ; y++){
            int prev = 0;
            for(int x = 0; x < rowCount; x++){
                target = grid[x][y];
                if(target != prev){
                    rv++;
                }
                prev = target;
            }
            if(target == 1){
                rv++;
            }
            System.out.println();
        }
        return rv;
    }
}
