class Solution {
public:
    int maxArea(vector<int>& heights) {
        int wat=0;
        int st=0;
        int end=heights.size()-1;
        while(st<end){
            int area;
            int minheight=min(heights[st],heights[end]);
            int wid=end-st;
            area=minheight*wid;
            wat=max(wat,area);
            if(heights[st]<heights[end]){
                st++;
            }else{
                end--;
            }
        }
        return wat;
    }
};
