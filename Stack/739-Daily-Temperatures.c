/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* dailyTemperatures(int* temp, int size, int* returnSize) {

    int *stack=calloc(size,sizeof(int));
     int *res=calloc(size ,sizeof(int));
     int top=-1;
    for(int i=0;i<size;i++)
    {
     while(top>=0 && temp[i]>temp[stack[top]])
     {
        
      res[stack[top]]=i-stack[top];
      top--;
     
     }
      stack[++top]=i;

    }
    *returnSize=size;
    free(stack);
   
    return res;


}