#ifndef DYNAMIC_M_H
#define DYNAMIC_M_H

#include <stdio.h>
#include <stdbool.h>

void VvodVect(int **x, int n, FILE *in);
void VvodMatr(int ***x, int n, int m, FILE *in);
void VivodVect(FILE *out, int *x, int n);
void VivodMatr(FILE *out, int **x, int n, int m);
bool NalVMatr(int **a, int n, int x);
bool NalSovpad(int *p, int **a, int n);
float SrArVect(int *p, int n);
void OchistkaVect(int **x);
void OchistkaMatr(int ***x, int n);

#endif
