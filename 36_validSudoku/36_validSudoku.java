class Solution {
    public boolean isValidSudoku(char[][] board) {
        Map row = new HashMap<Character,Integer>();
        Map col = new HashMap<Character,Integer>();
        List<Map<Character,Integer>> pane = new ArrayList<Map<Character,Integer>>();
        for(int i = 0; i < 3; i++) pane.add(new HashMap<Character,Integer>());
        int check_row = 1;
        
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                //边加边判断行和
                if(row.containsKey(board[i][j])){
                    return false;
                }
                if(board[i][j] != '.')  
                    row.put(board[i][j],i+j);//考虑value填什么
                if(pane.get((int)(j/3)).containsKey(board[i][j])){
                    return false;
                }
                if(board[i][j] != '.')
                    pane.get((int)(j/3)).put(board[i][j], i+j);
            }
            //满3行清空 3*3记录HashMap
            if(check_row == 3){
                for(int j = 0; j < 3; j++) pane.get(j).clear();
                check_row = 1;
            }
            else check_row++;
            //清空行HashMap
            row.clear();
        }
        
        //检查列
        for(int i=0; i<9; i++){
            for(int j = 0; j < 9; j++){
                //边加边判断行和
                if(col.containsKey(board[j][i]))
                    return false;
                if(board[j][i] != '.')
                    col.put(board[j][i],i+j);//考虑value填什么
            }
            //清空列HashMap
            col.clear();
        }
        
        return true;
    }
}