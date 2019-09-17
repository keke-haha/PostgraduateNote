// KMP 模板 -- 刘汝佳
#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int n,m;
char p[1000005],T[1000005];
int f[1000005];
void getfail(char *p,int *f){
    int m=strlen(p);
    f[0]=f[1]=0;
    for(int i=1;i<m;i++){
        int j=f[i];
        while(j&&p[i]!=p[j])j=f[j];
        f[i+1]=p[i]==p[j]?j+1:0;
    }
}
void find(char *T,char *p,int *f){
    n=strlen(T),m=strlen(p);
    getfail(p,f);
    int j=0;
    for(int i=0;i<n;i++){
        while(j&&p[j]!=T[i])j=f[j];　　//顺着失配边走，直到可以匹配
        if(p[j]==T[i])j++;
        if(j==m){
            printf("%d\n",i-m+2);　　//输出匹配成功后的第一个字符的位置
        }
    }
}
int main(){
    scanf("%s",T);
    scanf("%s",p);
    find(T,p,f);
    for(int i=1;i<=m;i++){
        printf("%d ",f[i]);
    }
}
