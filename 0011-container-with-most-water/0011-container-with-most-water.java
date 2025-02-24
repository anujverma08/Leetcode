class Solution {
    public int maxArea(int[] height) {
        int a = 0;
        int b = height.length - 1;
        int ans = 0;
        while(a<b){
            int temp = Math.min(height[a],height[b]);
            int area = Math.abs(a-b)*temp;

            ans = Math.max(area,ans);

            if(height[a]<height[b]){
                a++;
            }
            else{
                b--;
            }
        
        }
        return ans;
    
    }
}