#include<stdio.h>
#include<math.h>

int main(){

    double a[3], n[3], d[3];
    a[0]= 1;
    a[1]= 1.750669631150892e-5;
    a[2]= 2.22044604925031e-16;


    for (int i=0; i<3; i++){
        n[i]=7*a[i]*a[i]*a[i]*a[i]*a[i]*a[i]*(a[i]*a[i]*a[i]+24*a[i]*a[i]+80*a[i]+64);
        d[i]= 7*a[i]*a[i]*a[i]+56*a[i]*a[i]+112*a[i]+64;
        printf("El valor de c_%d = %.16G\n", i, n[i]/(d[i]*d[i]*d[i]));
    }



}
