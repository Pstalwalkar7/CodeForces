#include<stdio.h>
#include<stdlib.h>
typedef long long ll;
ll prod_dig(ll n){
    ll prod=1;
    int a;
    while(n){
        a=n%10;
        if(a){
            prod*=a;
        }
        n/=10;
    }
    // printf("\tprod:%lld\n",prod);
    return prod;
}
int arr[10][1000000+1];
int main(){
    int t;
    // printf("%lld\n",prod_dig(999999));
    for(int i=1;i<=1000000;i++){
        t=i;
        // printf("num:%d\n",t);
        while(t/10){
            t=prod_dig(t);
        }
        for(int j=0;j<10;j++){
            arr[j][i]=arr[j][i-1];
        }
        arr[t][i]++;
    }
    // for(int i=0;i<10;i++){
    //     printf("%d:",i);
    //     for(int j=1;j<20;j++){
    //         printf("  %d : %d  ",j,arr[i][j]);
    //     }
    //     printf("\n");
    // }
    // printf("Done\n");
    int Q,l,r,x,key;
    scanf("%d",&Q);
    while(Q--){
        scanf("%d%d%d",&l,&r,&key);
        printf("%d\n",arr[key][r]-arr[key][l-1]);
    }
}