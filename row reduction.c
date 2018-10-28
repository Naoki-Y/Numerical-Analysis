//
//  main.c
//  row reduction
//
//  Created by YoshiharaNaoki on 2018/10/12.
//  Copyright © 2018年 Naaoki Yoshihara. All rights reserved.
//
#include <stdio.h>
#include <math.h>
#define N 4     //行列の次数//
#define N1 8    //2*N//
#define EPSILON 1.0E-5
#define TRUE 1
#define FALSE 0
//行列設定
float a[N][N1] = {{1.0, 0.75, 0.0, -0.5, 1.0, 0.0, 0.0, 0.0},
    {0.0, -0.25, 0.0, 0.5, 0.0, 1.0, 0.0, 0.0},
    {0.0, 0.75, 0.0, -0.5, 0.0, 0.0, 1.0, 0.0},
    {-2.0, -1.5, -1.0, 1.0, 0.0, 0.0, 0.0, 1.0}};

float det;
int sw;

int main(void)
{
    int i,j;
    void sweep();
    
    printf("\n\n=====元の行列=====\n\n");
    for(i=0; i<N; i++)
    {
        printf(" %d : ",i+1);
        for(j=0; j<N; j++)
        {
            printf(" %10.4f ",a[i][j]);
        }
            printf("\n");
    }
    printf("\n\n");
    sw = TRUE;
    sweep(&sw);
    
    if(sw==TRUE)
    {
        printf("\n\n=====逆行列=====\n\n");
        for(i=0; i<N; i++)
        {
            printf(" %d : ",i+1);
            for(j=0; j<N; j++)
            {
                printf(" %10.4f ",a[i][j]);
                
            }
            printf("\n");
        }
        printf("\n 行列式 = %8.4f \n",det);
    }
    else
    {
        printf("\n 逆行列は求まりませんでした !\n");
    }
}

void swap(sw1,sw2)      //スワップ処理//
float *sw1,*sw2;
{
    float sw0;
    sw0 = *sw1;
    *sw1 = *sw2;
    *sw2 = sw0;
}

void sweep(sw)
int *sw;
{
    int i,j,k,ik;
    float ak = 0.0,aik,p;
    
    det = 1.0;
    p = 1.0;
    for(k=0; k<N; k++)
    {
        ak = a[k][k];
        if(fabs(ak) <= EPSILON)
        {
            ik = k+1;
            while((ik<N) && (fabs(a[ik][k])<EPSILON))
            {
                ik++;
            }
                if(ik < N)
                {
                    for(j=k; j<N1; j++)
                    {
                        swap(&a[k][j],&a[ik][j]);
                    }
                    ak = a[k][k];
                    p = -p;
                }
            if(ik >= N)
            {
                printf("    ピボットが零です    !\n");
                *sw = FALSE;
                goto owari;
            }
        
            
            
            
        }
    
        det = det * ak;
        for(j=k; j<N1; j++)
        {
            a[k][j] = a[k][j] / ak;
        }
            for(i=0; i<N; i++)
            {
                if(i != k)
                {
                    aik = a[i][k];
                    for(j=k; j<N1; j++)
                    {
                        a[i][j] = a[i][j] - aik * a[k][j];
                    }
                }
            }
    }   //forの終わり//
            det = p * det;
            owari:;
}
