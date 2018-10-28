//
//  main.c
//  Simultaneous linear equations
//
//  Created by YoshiharaNaoki on 2018/10/22.
//  Copyright © 2018年 Naoki Yoshihara. All rights reserved.
//

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<math.h>
#define N 4 //計算する問題によって変更してください//
#define EPSILON 1.0E-8

int sweep( double a[ ][N], double b[ ], double x[ ]);
void swap(double *sw1,double *sw2);
int main(void)
{
    int i,j;
    //int sw;
    //sw=1;
    
    //(教科書p16例1.4)//
    //double a[N][N] = {{2.0, 3.0, 1.0},{4.0, 1.0, -3.0},{-1.0, 2.0, 1.0}};
    //double x[N],b[N] = {2.0, 3.0, 4.0};
    
    //(3元連立1次方程式)　途中でピボットが0となり，行を入れ替える必要がある例//
    //double a[N][N] = {{2.0, 4.0, 2.0},{1.0, 2.0, 5.0},{3.0, 3.0, 1.0}};
    //double x[N],b[N] = {8.0, 24.0, 8.0};
    
    //(4元連立1次方程式)//
    double a[N][N] = {{2.0, 1.0, 1.0, 1.0},{1.0, 2.0, 1.0, 1.0},{1.0, 1.0, 2.0, 1.0},{1.0, 1.0, 1.0, 2.0}};
    double x[N],b[N] = {6.0, 7.0, 12.0, 15.0};
    
    
    printf(" ===== 係数行列と定義 =====\n\n");
    for(i=0; i<N; i++)
    {
        for(j=0; j<N; j++)
        {
            printf("%12.6f",a[i][j]);
        }
        printf("%12.6f\n\n",b[i]);
    }
    
    sweep(a,b,x);
    
    printf("\n\n ===== 掃出方による連立一次方程式の解 =====\n\n");
    for(i=0; i<N; i++)
    {
        printf("x[%d] = %12.6f \n", i+1, x[i]);
    }
    
    return 0;
}

void swap(double *sw1,double *sw2)
{
    double sw0;
    
    sw0 = *sw1;
    *sw1 =*sw2;
    *sw2 = sw0;
}

int sweep( double a[ ][N], double b[ ], double x[ ])
{
    int i,j,k,ik;
    double ak,aik;
    
    for(k=0; k<N; k++)
    {
        ak = a[k][k];
        
        if(fabs(ak) <= EPSILON)
        {
            ik = k + 1;
            while((ik<N)&&(fabs(a[ik][k])<EPSILON))
            {
                ik++;
            }
            if(ik<N)
            {
                for(j=k; j<N; j++){swap(&a[k][j],&a[ik][j]);}
                swap(&b[k],&b[ik]);
                ak = a[k][k];
            }
            else
            {
                printf(" ピボットが零です !\n");
                printf("解は求められませんでした。 \n\n");
                return 1;
            }
        }
        
        for(j=k; j<N; j++){a[k][j] = a[k][j] / ak;}
        b[k] = b[k] / ak;
        for(i=0; i<N; i++)
        {
            if(i != k)
            {
                aik = a[i][k];
                for(j=k; j<N; j++){a[i][j] = a[i][j] - aik * a[k][j];}
                b[i] = b[i] - b[k] * aik;
            }
            
        }
    }
    for(k=0; k<N; k++){x[k] =b[k];}
    return 1;
}
