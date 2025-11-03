class Solution {
    public int lengthOfLongestSubstring(String s) {
        if(s.length()==0){
            return 0;
        }
      int res=0;
       int i=0;
        HashMap<Character,Integer>map=new HashMap<>();
        for(int j=0;j<s.length();j++){
                if(map.containsKey(s.charAt(j))){
                    i=Math.max(i,map.get(s.charAt(j))+1);
                }
                res=Math.max(res,j-i+1);
             map.put(s.charAt(j),j); 
           
        }
        // if(i==0){
        //     res++;
        // }
       // res=Math.max(res,set.size());
        return res;
    }
}