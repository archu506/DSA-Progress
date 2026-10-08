/*
Problem: Valid Perfect Square
LeetCode: 367
Topic: Binary Search
Time: O(log n)
Space: O(1)
*/
bool isPerfectSquare(int num) {
    
   int left=1;
   int right =num;
   while(left<=right)
   {

   int mid=left+(right-left)/2;
   long long prod=1LL *mid*mid;
   if(prod==num)
   {
    return true;
   }
   else  if(prod>num)
   {
    right=mid-1;
   }
   else
   {
    left=mid+1;
   }

   }
   return 0;

}