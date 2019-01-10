//
//  main.c
//  kubun
//
//  Created by YoshiharaNaoki on 2019/01/10.
//  Copyright © 2019年 Naoki Yoshihara. All rights reserved.
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#define TRUE 1
#define FALSE 0
double kubun(double a, double b, int n);
double f(double x);
int main(void)
{
    
    double a,b;
    double kekka = 0;
    double original =   1.107148718;       //めんどくさいのでそのまま入れました
    int n;
    a = 0; b=2; //今回は固定なので入れておく
    
    printf("区間の分割数を入力してください\n");
    scanf("%d", &n);
    kekka = kubun(a,b,n);
    printf("理論値 = %lf\n", original);
    printf("\n積分の値 = %lf\n", kekka);
    printf("誤差　= %lf\n", original - kekka);
    return 0;
}

double f(double x){
    return 1 / (1 +(x * x));
}

double kubun(double a, double b, int n){
    
    double s=0.0;
    double x,h;
    int i;
    
    h=((b-a)/n);
    for(i = 0; i < n; i++){
        x = a + h * i;
        s = s + f(x)+f(x + h);
    }
    return (s * h/2);
}
