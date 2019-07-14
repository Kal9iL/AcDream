//题目链接：https://code.google.com/codejam/contest/204113/dashboard#s=p0&a=0

#include <cstdio>
#include <iostream>

using namespace std;


int main(){
    int t;
    int n;
    char data[50][50];
    int pos[50];
    scanf("%d",&t);
    for(int ics = 1; ics <= t; ics ++){
        scanf("%d",&n);
        for(int i = 0;i < n; i ++){
            scanf("%s",data[i]);
            pos[i] = 0;
            for(int j = n - 1;j >= 0 ;j --){
                if(data[i][j] == '1'){
                    pos[i] = j;
                    break;
                }
            }
        }
        int ans = 0;
        for(int i = 0;i < n ; i ++){
            for(int j = i; j < n; j ++){
                if(pos[j] <= i){
                    int k = j;
                    while(k > i){
                        swap(pos[k],pos[k - 1]);
                        k --;
                        ans ++;
                    }
                    break;
                }
            }
        }
        printf("Case #%d: %d\n",ics,ans);
    }
    return 0;
    
}