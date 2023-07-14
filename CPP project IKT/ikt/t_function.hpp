#pragma once
#include <iostream>
using namespace std;

void t1(int[][35], int, int, int&, int[]);
void t2(int[][35], int, int, int&, int[]);
void t3(int[][35], int, int&, int[]);
int t4(int[][30], int);
void t5(int[][35], int, int[], int, int&);
void t6(int[][35], int, int&, int[], int);

void t1(int c[][35], int n, int m, int& l1, int T1[]) {
    int i, j;
    for (i = 1; i <= m; i++)
    {
        int q = 0;
        for (j = 0; j < n; j++)
            if (c[1][j] == i)
                q++;
        if (q == 0)
            T1[l1++] = i;
    }
}

void t2(int c[][35], int n, int m, int& l2, int T2[]) {
    int i, j;

    l2 = 0;
    for (i = 1; i <= m; i++) {
        bool a = false, b = false;
        for (j = 0; j < n; j++)
            if (c[0][j] == i && c[1][j] != 0) {
                a = true;
                break;
            }
        for (j = 0; j < n; j++)
            if (c[1][j] == i) {
                b = true;
                break;
            }
        if (a == true && b == true)
            T2[l2++] = i;
    }
}

void t3(int c[][35], int n, int& l3, int T3[]) {
    int j, k, a = 0;
    l3 = 0;
    for (j = 0; j < n; j++)
        if (c[1][j] == 0)
            T3[l3++] = c[0][j];
}

int t4(int a[][30], int m) {
    int i, j, t4 = 0;
    for (i = 0; i < m; i++)
    {
        int q = 0;
        for (j = 0; j < m; j++)
            q += a[j][i];
        if (q == 0)
            t4++;
    }
    return (t4);
}

void t5(int c[][35], int n, int t2[], int l2, int& l5) {
    int i, k, j;
    cout << "T5 = {";
    for (i = 0; i < l2; i++)
        for (j = 0; j < n; j++)
            if (c[0][j] == t2[i] && c[1][j] != 0) {
                for(k = 0; k < l2; k++){
                    if(c[1][j] == t2[k]){
                        l5++;
                        cout << c[0][j] << " - " << c[1][j] << ",";
                    }
                }            
            }
    cout << "}" << endl;
}

void t6(int c[][35], int n, int& l6, int t3[], int l3) {
    int i, k;
    cout << "T6 = {";
    for (i = 0; i < n; i++)
        for (k = 0; k < l3; k++)
            if (c[0][i] == t3[k] && c[1][i] != 0) {
                l6++;
                cout << c[0][i] << " - " << c[1][i] << ",";
            }
    cout << "}" << endl;

}
