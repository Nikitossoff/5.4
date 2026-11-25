#include "dynamic_m.h"
#include <malloc.h>

void VvodVect(int **x, int n, FILE *in) {
    *x = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        fscanf(in, "%i", &(*x)[i]);
    }
    return;
}

void VvodMatr(int ***x, int n, int m, FILE *in) {
    *x = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        (*x)[i] = (int *)malloc(m * sizeof(int));
        for (int j = 0; j < m; j++) {
            fscanf(in, "%i", &(*x)[i][j]);
        }
    }
    return;
}

void VivodVect(FILE *out, int *x, int n) {
    for (int i = 0; i < n; i++) {
        fprintf(out, "%4i ", x[i]);
    }
    fprintf(out, "\n\n");
    return;
}

void VivodMatr(FILE *out, int **x, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            fprintf(out, "%4i ", x[i][j]);
        }
        fprintf(out, "\n");
    }
    fprintf(out, "\n");
    return;
}

bool NalVMatr(int **a, int n, int x) {
    bool fl = false;
    int i = 0;
    while (i < n && !fl) {
        int j = 0;
        while (j < n && !fl) {
            if (a[i][j] == x) {
                fl = true;
            } else {
                j++;
            }
        }
        if (!fl) {
            i++;
        }
    }
    return fl;
}

bool NalSovpad(int *p, int **a, int n) {
    bool fl = false;
    int k = 0;
    while (k < n && !fl) {
        if (NalVMatr(a, n, p[k])) {
            fl = true;
        } else {
            k++;
        }
    }
    return fl;
}

float SrArVect(int *p, int n) {
    int s = 0;
    for (int i = 0; i < n; i++) {
        s += p[i];
    }
    float sr = (float)s / n;
    return sr;
}

void OchistkaVect(int **x) {
    free(*x);
    return;
}

void OchistkaMatr(int ***x, int n) {
    for (int i = 0; i < n; i++) {
        free((*x)[i]);
    }
    free(*x);
    return;
}
