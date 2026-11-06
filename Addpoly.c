#include<stdio.h>
#include<stdlib.h>
#define MAX_TERMS 100

typedef struct{
    float coeff;
    int exp;
}poly;
int avail=0;
poly p[MAX_TERMS];
int compare(int x,int y){
    if(x>y) return 1;
    else if(x==y) return 0;
    else return -1;
}
void attach(float coeff,int exp){
    if(avail>=MAX_TERMS){
        printf("limit excedd");
        exit(0);
    }
    p[avail].coeff=coeff;
    p[avail].exp=exp;
    avail++;
}
void padd(int sa,int fa,int sb,int fb,int *sd,int *fd){
    *sd=avail;
    float coeff;
    while(sa<=fa && sb<=fb){
        switch(compare(p[sa].exp,p[sb].exp)){
            case 1:
            attach(p[sa].coeff,p[sa].exp);
            sa++;
            break;
            case 0:
            coeff=p[sa].coeff+p[sb].coeff;
            attach(coeff,p[sb].exp);
            sa++,sb++;
            break;
            case -1:
            attach(p[sb].coeff,p[sb].exp);
            sb++;
            break;
        }
    }
while(sa<=fa){
  attach(p[sa].coeff,p[sa].exp);
  sa++;
}
while(sb<=fb){
    attach(p[sb].coeff,p[sb].exp);
    sb++;
}
*fd=avail-1;
}
void display(int start,int finish){
    for(int i=start;i<=finish;i++){
        printf("%fx^%d",p[i].coeff,p[i].exp);
        if(i<finish){
            printf("+");
        }
    }
}
int main(){
    int sa,sb,fa,fb,sd,fd;
    sa=avail;
    int n1,n2;
    printf("enter no. of elements in p1 & p2:");
    scanf("%d %d",&n1,&n2);
    for(int i=0;i<n1;i++){
        printf("enter the coeff and exp:");
        scanf("%f %d",&p[avail].coeff,&p[avail].exp);
        avail++;
    }
    fa=avail-1;
    sb=avail;
    for(int i=0;i<n2;i++){
        printf("enter the coeff and exp:");
        scanf("%f %d",&p[avail].coeff,&p[avail].exp);
        avail++;
    }
    fb=avail-1;
    padd(sa,fa,sb,fb,&sd,&fd);
    display(sd,fd);
}