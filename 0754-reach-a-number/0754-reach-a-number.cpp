class Solution {
public:

    /*
    5
    1 2 3 4 5 6 
  0 1 3 6 10 5
    
   2
   1 3 6
 0 1 -1 3 
 0 

   7
   1 2 3 4 5 
   1 3 6 10 15
 0 1 3 6 2 7

   8 -> 4?
   1 2 3 4 5 6 7 8 9 10 11 12 13
 0 1 3 6 10 15 21 28
 0 -1 1 4 8
   1 
    
    4
  0 -1  
    
    */


 

    int reachNumber(int t) {
        if(t<0)t=-t;
        for(long i=1; i<=1e6; i++)
        {
            long sum = (i*(i+1))>>1;
            if(sum >=  t && abs(sum-t)&1^1)return i;
        }
        return -1;
    }
};