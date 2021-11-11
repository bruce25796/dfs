//
// dft.c - Simple brute force DFT
// Written by 
// Last updated 11-11-2021
//
// To compile:
//    gcc dft.c -lm -o dft.exe
// 
// To run:
//    ./dft_v1.exe
//
// To run octave:
//   run("dftplots.m")
//
 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
 
//#define N   4    
#define N   16

#define PI2 6.2832




void dft(double xre[N], double xim[N], int nd, double Xre[N], double Xim[N])
{
    
    int k, n;
    
    for (k=0 ; k<=nd-1 ; ++k)
    {
        // Real part of X[k]
        Xre[k] = 0.0;
        for (n=0 ; n<=nd-1 ; n++) Xre[k] += (     xre[n] * cos(n * k * PI2 / nd)
                                               +  xim[n] * sin(n * k * PI2 / nd)
                                           );
         
        // Imaginary part of X[k]
        Xim[k] = 0.0;
        for (n=0 ; n<=nd-1 ; n++) Xim[k] += (  -  xre[n] * sin(n * k * PI2 / nd)
                                               +  xim[n] * cos(n * k * PI2 / nd)
                                           );
         
        // Power at kth frequency bin
        //P[k] = Xre[k]*Xre[k] + Xim[k]*Xim[k];
    }
    //
}

//-------------------------
 
int main()
{
    // time and frequency domain data arrays
    int n, k;              // indices for time and frequency domains
    double x[N];           // discrete-time signal, x
    double Xre[N], Xim[N]; // DFT of x (real and imaginary parts)
    double P[N];           // power spectrum of x
    //
    //
    double xre[N],  xim[N];
    //
    double Fre[N],  Fim[N];
    double xre1[N],  xim1[N];

    // Generate random discrete-time signal x in range (-1,+1)
    //
    // 
    //
    //
    srand(time(0));
    for (n=0 ; n<=N-1 ; ++n) { 
        x[n] = ((2.0 * rand()) / RAND_MAX) - 1.0;
        xre[n] = x[n];
        xim[n] =  0.0;
    }
    //
    //
    //
    //
    //
    //
    //
    //
    // 
    //
    for (n=0 ; n<=N-1 ; ++n) { 
        xre[n] = x[n];
        xim[n] = 0.0;
    }
    //
    //
    //
    //
    dft( xre,  xim,  N, Xre,  Xim);
    //
    //=====================================
    // inverse 
    for (k = 0; k <= N - 1; ++k)
    {
           Fre[k] = Xre[k];
           Fim[k] = Xim[k];
    }
    //
    //
    for (k = 0; k <= N - 1; k++)
    {
        Fim[k] *= -1.0;
    }
    //
    dft( Fre,  Fim,  N, xre1,  xim1);
    //
    for (k = 0; k <= N - 1; k++)
    {
        xre1[k] /= N;
        xim1[k] /= N;
    }
    //
    //
    //
    //
    // Output results to MATLAB / Octave M-file for plotting
    FILE *f = fopen("dftplots.m", "w");
    fprintf(f, "n = [0:%d];\n", N-1);
    fprintf(f, "x = [ ");
    for (n=0 ; n<N ; ++n) fprintf(f, "%f ", x[n]);
    fprintf(f, "];\n");
    //
    fprintf(f, "xre = [ ");
    for (k = 0; k <=N-1; ++k) fprintf(f, "%f ", xre[k]);
    fprintf(f, "];\n");
    fprintf(f, "xim = [ ");
    for (k = 0; k <=N-1; ++k) fprintf(f, "%f ", xim[k]);
    fprintf(f, "];\n");
    //
    fprintf(f, "\n");
    //
    fprintf(f, "Xre = [ ");
    for (k=0 ; k<N ; ++k) fprintf(f, "%f ", Xre[k]);
    fprintf(f, "];\n");
    fprintf(f, "Xim = [ ");
    for (k=0 ; k<N ; ++k) fprintf(f, "%f ", Xim[k]);
    fprintf(f, "];\n");
    fprintf(f, "P = [ ");
    for (k=0 ; k<N ; ++k) fprintf(f, "%f ", P[k]);
    fprintf(f, "];\n");
    //
    fprintf(f, "\n");
    //
    fprintf(f, "xre1 = [ ");
    for (k = 0; k <=N-1; ++k) fprintf(f, "%f ", xre1[k]);
    fprintf(f, "];\n");
    fprintf(f, "xim1 = [ ");
    for (k = 0; k <=N-1; ++k) fprintf(f, "%f ", xim1[k]);
    fprintf(f, "];\n");
    //
    //
    //
    // 
    // 
    fprintf(f, "subplot(4,1,1)\nplot(n,xre,n,xim,n,xre1,n,xim1)\n");
    fprintf(f, "title(\" time/ in-time \") \n");
    fprintf(f, "xlim([0 %d])\n", N - 1);
    //
    fprintf(f, "subplot(4,1,2)\nplot(n,Xre,n,Xim)\n");
    fprintf(f, "xlim([0 %d])\n", N - 1);
    fprintf(f, "title(\" Freq \") \n");
    //
    fprintf(f, "subplot(4,1,3)\nstem(n,P)\n");
    fprintf(f, "xlim([0 %d])\n", N - 1);
    fprintf(f, "title(\" Freq Magnitude \") \n");
    //
    fprintf(f, "subplot(4,1,4)\nplot(n,xre1,n,xim1)\n");
    fprintf(f, "xlim([0 %d])\n", N - 1);
    fprintf(f, "title(\" back in-time \") \n");
    //
    //
    //
    fclose(f);
     
    // exit normally
    return 0;
}