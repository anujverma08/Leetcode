import java.util.*;

class Solution {
    public  Map<Character, String> m = new HashMap<>();
    public  List<String> ans = new ArrayList<>();
    public void backtracking(String digits,int index,StringBuilder sb){
        if(digits.length() == sb.length()){
            ans.add(sb.toString());
            return;
        }
        String s = m.get(digits.charAt(index));
        for(int i = 0;i < s.length() ; i++){
            sb.append(s.charAt(i));
            backtracking(digits,index+1,sb);
            sb.deleteCharAt(sb.length()-1);
        }

    }
    public List<String> letterCombinations(String digits) {
        if (digits.isEmpty()) {
            return new ArrayList<>();
        }
        
        // Map<Character, String> m = new HashMap<>();
        m.put('2', "abc");
        m.put('3', "def");
        m.put('4', "ghi");
        m.put('5', "jkl");
        m.put('6', "mno");
        m.put('7', "pqrs");
        m.put('8', "tuv");
        m.put('9', "wxyz");
        StringBuilder sb = new StringBuilder();
        backtracking(digits,0,sb);
        return ans;
        
    //     List<String> res = new ArrayList<>();
    //     res.add("");
        
    //     for (char digit : digits.toCharArray()) {
    //         List<String> temp = new ArrayList<>();
    //         String chars = m.get(digit);
    //         for (char c : chars.toCharArray()) {
    //             for (String s : res) {
    //                 temp.add(s + c);
    //             }
    //         }
            
    //         res = temp;
    //         System.out.println(res);
    //     }
        
    //     return res;
    }
}