#include <iostream>
#include "function.hpp"
#include "t_function.hpp"
using namespace std;

int main() {
    int n, m , i, j, q = 1;
    int t_1 = 0, t_2 = 0, t_3 = 0, t_5 = 0, t_6 = 0;
    int T1[20] = { 0 }, T2[20] = { 0 }, T3[20] = { 0 };
    double k_mo_mij = 0;


    cout << "Nermuceq C matrici andamneri qanaky: "; cin >> n;
    cout << "Nermuceq A matrici andamneri qanaky: "; cin >> m; // gagatneri qanak

    /* In the example below A, A1 and sigma depend on graph tops. 
    So if graph tops are 20, the size of matrix must be 20. */

    int  A1[30][30] = { 0 }, A[30][30] = { 0 }, sigma[30][30] = { 0 };

    // In the example below 35 is the lengh of C matrix. This value can be changeable

    int C[2][35];

    getting_C(C, n);
    getting_A(A1, m, C, n);
    for (i = 0; i < m; i++)
        for (j = 0; j < m; j++)
            A[i][j] = A1[i][j];
    
    int r = R(C,n);
    t1(C, n, m, t_1, T1);
    t2(C, n, m, t_2, T2);
    t3(C, n, t_3, T3);
    cout << "T1 = "<< t_1<<" "; print_array(T1, t_1);
    cout << "T2 = "<< t_2<<" "; print_array(T2, t_2);
    cout << "T3 = "<< t_3<<" "; print_array(T3, t_3);

    t5(C, n, T2, t_2, t_5);
    cout << "t5 = " << t_5 << endl;
    t6(C, n, t_6, T3, t_3);
    cout << "t6 = " << t_6 << endl;
    do {
        int t_4, t_7;
        t_4 = t4(A, m);
        t_7 = t4(A, m) - q;
        cout << "t4(" << q << ") = " << t_4 << endl;
        cout << "t7(" << q << ") = " << t_7 << endl;
        cout << "k_mo = " << double(t_7) / t_4 << endl;
        k_mo_mijin(double(t_7) / t_4, &k_mo_mij);
        sum(sigma, A, m);
        cout << "A(" << q << ") = ";
        print_matrix(A, m);
        power_A(A1, A, m);
        q++;
    } while (count(A, m) != 0 && diagonal(A, m) == 0);

    if (diagonal(A, m) != 0)
        cout << "Hamakargy karg chuni" << endl;
    else
        cout << "Hamakargi kargy " << q - 1 << " e" << endl;

    cout << "sigma = ";   print_matrix(sigma, m);
    cout << "k_n_k = " << double(t_5) / r << endl;
    cout << "k_m = " << double(t_2) / m << endl; // popoxutyun n-y m-ov
    cout << "k_mo_mijin = " << k_mo_mij / q << endl;
    cout << "k_krknman = " << 2.0*t_6/(t_3*(t_3-1));
    return (0);
}
