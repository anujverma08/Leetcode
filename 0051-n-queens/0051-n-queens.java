public class Solution {
    public List<List<String>> solveNQueens(int n) {
        List<List<String>> ans = new ArrayList<>();
        String res = "";
        for (int i = 0; i < n; i++) {
            res += ".";
        }
        List<String> board = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            board.add(res);
        }
        
        nQueens(board, 0, ans);
        return ans;
    }

    private void nQueens(List<String> board, int row, List<List<String>> ans) {
        if (row == board.size()) {
            ans.add(new ArrayList<>(board));
            return;
        }

        for (int j = 0; j < board.size(); j++) {
            if (isSafe(board, row, j)) {
                char[] rowArray = board.get(row).toCharArray();
                rowArray[j] = 'Q';
                board.set(row, new String(rowArray));
                nQueens(board, row + 1, ans);
                rowArray[j] = '.';
                board.set(row, new String(rowArray));
            }
        }
    }

    private boolean isSafe(List<String> board, int row, int j) {
        // up
        for (int i = row; i >= 0; i--) {
            if (board.get(i).charAt(j) == 'Q') return false;
        }
        // diagonal up left
        int r = row - 1, c = j - 1;
        while (r >= 0 && c >= 0) {
            if (board.get(r).charAt(c) == 'Q') return false;
            r--;
            c--;
        }
        // diagonal up right
         r = row - 1; c = j + 1;
        while (r >= 0 && c < board.size()) {
            if (board.get(r).charAt(c) == 'Q') return false;
            r--;
            c++;
        }

        return true;
    }
}