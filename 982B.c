#include<stdio.h>
typedef long long ll;
ll temp[200001][2];
ll Pop(ll arr[],int* top){
    return arr[(*top)--];
}
void Push(ll arr[],int* top,ll val){
    arr[++(*top)]=val;
}
void merge(ll arr[][2],int l,int m,int r){
    for(int i=l;i<=r;i++){
        temp[i][0]=arr[i][0];
        temp[i][1]=arr[i][1];
    }
    int i=l,j=m+1,k=l;
    while(i<=m && j<=r){
        if(temp[i][1]<=temp[j][1]){
            arr[k][0]=temp[i][0];
            arr[k++][1]=temp[i++][1];
        }
        else{
            arr[k][0]=temp[j][0];
            arr[k++][1]=temp[j++][1];
        }
    }
    while(i<=m){
        arr[k][0]=temp[i][0];
        arr[k++][1]=temp[i++][1];
    }
    while(j<=r){
        arr[k][0]=temp[j][0];
        arr[k++][1]=temp[j++][1];
    }
}
void mergesort(ll arr[][2],int l,int r){
    if(l<r){
        int m=(l+r)/2;
        mergesort(arr,l,m);
        mergesort(arr,m+1,r);
        merge(arr,l,m,r);
    }
}
int main(){
    int n;
    scanf("%d",&n);
    ll arr[n][2];
    for(int i=0;i<n;i++){
        arr[i][0]=i;
        scanf("%lld",&arr[i][1]);
    }
    mergesort(arr,0,n-1);
    ll I[n];
    ll E[n];
    int topI=-1;
    int topE=-1;
    for(int i=n-1;i>=0;i--){
        Push(I,&topI,arr[i][0]);
    }
    char Str[2*n +1];
    ll x;
    scanf("%s",Str);
    for(int i=0;i<2*n;i++){
        if(Str[i]=='0'){
            x=Pop(I,&topI);
            Push(E,&topE,x);
        }
        else{
            x=Pop(E,&topE);
        }
        printf("%lld ",x+1);
    }
}