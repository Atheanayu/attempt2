#include <stdio.h>
#include <stdlib.h>

void print_yanghui_triangle(int layer);/* print yang hui triangle */
long long factorial_num(int n);/* calculate the factorial number which is n! */
long long combinatorial_num(int n,int k);/* calculate the combinatorial number which is the number of the ways that choose k things from n identical things*/
int get_num_length(long long num);/* get the length of numbers ,for instance, the length of 123 is 3 */
void standard_output(long long charactor,int length);/* to make sure that when the number is very long ,the output is still beautiful enough */
int main(){
    print_yanghui_triangle(10);
    return 0;
}
print_yanghui_triangle(int layer){
    int temp = 0,count = 0,length = get_num_length(combinatorial_num(layer,layer/2));/* get the length of the longest number */
    for(int i = layer;i>0;i--){
        /* print the triangle, the triangle can be described by |x|+|y| < layer+2 */
        for(int j= -layer;j<layer+1;j++)
            /* use the short statement if ((temp = abs(i) + abs(j)) < layer + 2) && (temp % 2) is wrong ,++count can not execute */
            if(((temp = abs(i) + abs(j)) < layer + 2) && (temp % 2) && (++count))
                standard_output(combinatorial_num(layer-i+1,count-1),length);
            else
                standard_output(' ',length);
        printf("\n");
        count = 0;
    }
}
long factorial_num(int n){
    long long num=1;
    while(n)
        num*=(n--);
    return num;
}
long combinatorial_num(int n,int k){
    return factorial_num(n)/(factorial_num(k)*factorial_num(n-k));
}
void standard_output(long long charactor,int length){
    int len = get_num_length(charactor);
    if(charactor!=' ') {
        for (int i = 0; i < length - len; i++)
            printf(" ");
        printf("%lld", charactor);
    }else
        for(int i = 0;i<length;i++)
            printf(" ");
}
int get_num_length(long long num){
    int count = 0;
    do
        count++;
    while(num/=10);
    return count;
}
