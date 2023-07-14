#pragma once
#include <iostream>
using namespace std;

int R(int[][35], int);
void getting_C(int[][35], int);
void getting_A(int[][30], int, int[][35], int);
int count(int[][30], int);
int diagonal(int[][30], int);
void power_A(int[][30], int[][30], int);
void sum(int[][30], int[][30], int);
void print_matrix(int[][30], int);
void print_array(int[], int);
void k_mo_mijin(double, double*);

void getting_C(int c[][35], int n) {
    int i, j;
    for (j = 0; j < n; j++)
    {
        cout << "c[0][" << j << "] = ";
        cin >> c[0][j];
        cout << "c[1][" << j << "] = ";
        cin >> c[1][j];
    }
}

void getting_A(int a[][30], int m, int c[][35], int n) {
    int i, j, k;
    for (i = 0; i < m; i++)
        for (k = 0; k < n; k++)
            for (j = 0; j < m; j++)
                if (i == c[0][k] - 1 && j == c[1][k] - 1) {
                    a[i][j] += 1;
                    break;
                }
}

int count(int a[][30], int m) {
    int s = 0, i, j;
    for (i = 0; i < m; i++)
        for (j = 0; j < m; j++)
            s += a[i][j];
    return (s);
}

int diagonal(int a[][30], int m) {
    int s = 0;
    for (int i = 0; i < m; i++)
        s += a[i][i];
    return (s);
}

void sum(int s[][30], int a[][30], int m) {
    int i, j;
    for (i = 0; i < m; i++)
        for (j = 0; j < m; j++)
            s[i][j] = s[i][j] + a[i][j];
}

void power_A(int a1[][30], int a[][30], int m)
{
    int z[30][30], i, j, k;
    for (i = 0; i < m; i++)
        for (k = 0; k < m; k++)
        {
            z[i][k] = 0;
            for (j = 0; j < m; j++)
                z[i][k] += a1[i][j] * a[j][k];
        }
    for (i = 0; i < m; i++)
        for (k = 0; k < m; k++)
            a[i][k] = z[i][k];
}

void print_matrix(int matrix[][30], int m) {
    int i, j;
    cout << "[" << endl;
    for (i = 0; i < m; i++) {
        for (j = 0; j < m; j++)
        {
            cout << matrix[i][j];
            if (j != m - 1)
                cout << ", ";
            else
                cout << endl;
        }
    }
    cout << "]" << endl;
}

void print_array(int T[], int t) {
    cout << "{";
    for (int i = 0; i < t; i++) {
        cout << *(T + i);
        if (i != t - 1)
            cout << ", ";
    }
    cout << "}" << endl;
}

void k_mo_mijin(double k_mo, double* k_mo_mijin) {
    *k_mo_mijin += k_mo;
}

int R(int C[][35], int n){
    int i, r = 0;
    for(i = 0; i < n; i++ )
        if(C[1][i] != 0)
            r++ ;
    
    return r;
}
