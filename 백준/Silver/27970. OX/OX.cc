#include<iostream>
int m=1e9+7,s=0,g=1;main(){char a;while((a=getchar())!='\n'){s=(s+(a=='O')*g)%m;g=(g*2)%m;}printf("%d",s);}