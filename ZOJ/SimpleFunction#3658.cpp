/*#include <cstdio>
#include <cmath>
#include <iostream>

using namespace std;

inline double sqr(double x){return x*x;}

#define EPS 1e-6

int dcmp(double d)
{
    if (d > EPS)
        return 1;
    else if (d < -EPS)
        return -1;
    else
        return 0;
}

int main(int argc, char const *argv[])
{
    int t;
    scanf("%d", &t);
    while(t--){
        double A,B,C,D,E;
        scanf("%lf%lf%lf%lf%lf", &A, &B, &C, &D, &E);
        //cout << A << ' ' << B << ' ' << C << ' ' << D << ' ' << E << endl;
        double M = B - A*D;
        if(M==0){
            double tmp = C - A*E;
            double minv = E - D*D/4.0;
            if(dcmp(tmp)==0){
                printf("[%.4lf, %.4lf]\n", A, A);
            }
            else if(dcmp(tmp) > 0){
                if(dcmp(minv) > 0){
                    printf("(%.4lf, %.4lf]\n", A, A + tmp/minv);
                }
                else if(dcmp(minv) < 0){
                    printf("(-INF, %.4lf] U (%.4lf, INF)\n", A + tmp/minv, A);
                }
                else{
                    printf("(%.4lf, INF)\n", A);
                }
            }
            else{
                if(dcmp(minv) > 0){
                    printf("[%.4lf, %.4lf)\n", A + tmp/minv, A);
                }
                else if(dcmp(minv) < 0){
                    printf("(-INF, %.4lf) U [%.4lf, INF)\n", A, A + tmp/minv);
                }
                else{
                    printf("(-INF, %.4lf)\n", A);
                }
            }
        }
        else{
            double N =(C - A*E)/M;
            double tmp = E - N*(D - N);
            double tmp2 = D - 2*N;
            if(M > 0){
                if(dcmp(tmp)==0){
                    if(dcmp(tmp2) > 0){
                        if(dcmp(N*N-D*N+E)==0)
                            printf("(-INF, %.4lf) U (%.4lf, %.4lf) U (%.4lf, INF)\n", A, A, A + M/tmp2, A + M/tmp2);
                        else
                            printf("(-INF, %.4lf) U (%.4lf, INF)\n", A + M/tmp2, A + M/tmp2);
                    }
                    else if(dcmp(tmp2) < 0){
                        if(dcmp(N*N-D*N+E)==0)
                            printf("(-INF, %.4lf) U (%.4lf, %.4lf) U (%.4lf, INF)\n", A + M/tmp2, A + M/tmp2, A, A);
                        else
                            printf("(-INF, %.4lf) U (%.4lf, INF)\n", A + M/tmp2, A + M/tmp2);
                    }
                    else{
                        if(dcmp(N*N-D*N+E)==0)
                            printf("(-INF, %.4lf) U (%.4lf, INF)\n", A, A);
                        else
                            printf("(-INF, INF)\n");
                    }
                }
                else if(dcmp(tmp) < 0){
                    if(dcmp(N*N-D*N+E)==0)
                        printf("(-INF, %.4lf) U (%.4lf, INF)\n", A, A);
                    else
                        printf("(-INF, INF)\n");
                }
                else{
                    // E - N(D - N) > 0
                    double v1 = D - 2*N + 2*sqrt(E-N*(D-N)), v2 = tmp2 - 2*sqrt(tmp);
                    double x = sqrt(tmp) - N;
                    if(dcmp(v1) > 0 && dcmp(v2) > 0){
                        if(dcmp(N*N-D*N+E)==0){
                            if(dcmp(x*x+D*x+E)!=0)
                                printf("(-INF, %.4lf) U (%.4lf, %.4lf] U [%.4lf, INF)\n", A, A, A + M/v1, A + M/v2);
                            else
                                printf("(-INF, %.4lf) U (%.4lf, %.4lf) U (%.4lf, INF)\n", A, A, A + M/v1, A + M/v2);
                        }
                        else{
                            if(dcmp(x*x+D*x+E)!=0)
                                printf("(-INF, %.4lf] U [%.4lf, INF)\n", A + M/v1, A + M/v2);
                            else
                                printf("(-INF, %.4lf) U (%.4lf, INF)\n", A + M/v1, A + M/v2);
                        }
                    }
                    else if(dcmp(v1) > 0 && dcmp(v2) == 0){
                        if(dcmp(N*N-D*N+E)==0){
                            if(dcmp(x*x+D*x+E)!=0)
                                printf("(-INF, %.4lf) U (%.4lf, %.4lf]\n", A, A, A + M/v1);
                            else
                                printf("(-INF, %.4lf) U (%.4lf, %.4lf)\n", A, A, A + M/v1);
                        }
                        else{
                            if(dcmp(x*x+D*x+E)!=0)
                                printf("(-INF, %.4lf]\n", A + M/v1);
                            else
                                printf("(-INF, %.4lf)\n", A + M/v1);
                        }
                    }
                    else if(dcmp(v1) > 0 && dcmp(v2) < 0){
                        if(dcmp(N*N-D*N+E)==0){
                            if(dcmp(x*x+D*x+E)!=0)
                                printf("[%.4lf, %.4lf) U (%.4lf, %.4lf]\n", A + M/v2, A, A, A + M/v1);
                            else
                                printf("(%.4lf, %.4lf) U (%.4lf, %.4lf)\n", A + M/v2, A, A, A + M/v1);
                        }
                        else{
                            if(dcmp(x*x+D*x+E)!=0)
                                printf("[%.4lf, %.4lf]\n", A + M/v2, A + M/v1);
                            else
                                printf("(%.4lf, %.4lf)\n", A + M/v2, A + M/v1);
                        }
                    }
                    else if(dcmp(v1) == 0 && dcmp(v2) < 0){
                        if(dcmp(N*N-D*N+E)==0){
                            if(dcmp(x*x+D*x+E)!=0)
                                printf("[%.4lf, %.4lf) U (%.4lf, INF)\n", A + M/v2, A, A);
                            else
                                printf("(%.4lf, %.4lf) U (%.4lf, INF)\n", A + M/v2, A, A);
                        }
                        else{
                            if(dcmp(x*x+D*x+E)!=0)
                                printf("[%.4lf, INF)\n", A + M/v2);
                            else
                                printf("(%.4lf, INF)\n", A + M/v2);
                        }
                    }
                    else if(dcmp(v1) < 0 && dcmp(v2) < 0){
                        if(dcmp(N*N-D*N+E)==0){
                            if(dcmp(x*x+D*x+E)!=0)
                                printf("(-INF, %.4lf] U [%.4lf, %.4lf) U (%.4lf, INF)\n", A + M/v1, A + M/v2, A, A);
                            else
                                printf("(-INF, %.4lf) U (%.4lf, %.4lf) U (%.4lf, INF)\n", A + M/v1, A + M/v2, A, A);
                        }
                        else{
                            if(dcmp(x*x+D*x+E)!=0)
                                printf("(-INF, %.4lf] U [%.4lf, INF)\n", A + M/v1, A + M/v2);
                            else
                                printf("(-INF, %.4lf) U (%.4lf, INF)\n", A + M/v1, A + M/v2);
                        }
                    }
                }
            }
            else{
                // M < 0
                if(dcmp(tmp)==0){
                    if(dcmp(tmp2) > 0){
                        if(dcmp(N*N-D*N+E)==0)
                            printf("(-INF, %.4lf) U (%.4lf, %.4lf) U (%.4lf, INF)\n", A + M/tmp2, A + M/tmp2, A, A);
                        else
                            printf("(-INF, %.4lf) U (%.4lf, INF)\n", A + M/tmp2, A + M/tmp2);
                    }
                    else if(dcmp(tmp2) < 0){
                        if(dcmp(N*N-D*N+E)==0)
                            printf("(-INF, %.4lf) U (%.4lf, %.4lf) U (%.4lf, INF)\n", A, A, A + M/tmp2, A + M/tmp2);
                        else
                            printf("(-INF, %.4lf) U (%.4lf, INF)\n", A + M/tmp2, A + M/tmp2);
                    }
                    else{
                        if(dcmp(N*N-D*N+E)==0)
                            printf("(-INF, %.4lf) U (%.4lf, INF)\n", A, A);
                        else
                            printf("(-INF, INF)\n");
                    }
                }
                else if(dcmp(tmp) < 0){
                    if(dcmp(N*N-D*N+E)==0)
                        printf("(-INF, %.4lf) U (%.4lf, INF)\n", A, A);
                    else
                        printf("(-INF, INF)\n");
                }
                else{
                    double v1 = D - 2*N + 2*sqrt(E-N*(D-N)), v2 = tmp2 - 2*sqrt(tmp);
                    double x = sqrt(tmp) - N;
                    if(dcmp(v1) > 0 && dcmp(v2) > 0){
                        if(dcmp(N*N-D*N+E)==0){
                            if(dcmp(x*x+D*x+E)!=0)
                                printf("(-INF, %.4lf] U [%.4lf, %.4lf) U (%.4lf, INF)\n", A + M/v2, A + M/v1, A, A);
                            else
                                printf("(-INF, %.4lf) U (%.4lf, %.4lf) U (%.4lf, INF)\n", A + M/v2, A + M/v1, A, A);
                        }
                        else{
                            if(dcmp(x*x+D*x+E)!=0)
                                printf("(-INF, %.4lf] U [%.4lf, INF)\n", A + M/v2, A + M/v1);
                            else
                                printf("(-INF, %.4lf) U (%.4lf, INF)\n", A + M/v2, A + M/v1);
                        }
                    }
                    else if(dcmp(v1) > 0 && dcmp(v2) == 0){
                        if(dcmp(N*N-D*N+E)==0){
                            if(dcmp(x*x+D*x+E)!=0)
                                printf("[%.4lf, %.4lf) U (%.4lf, INF)\n", A + M/v1, A, A);
                            else
                                printf("(%.4lf, %.4lf) U (%.4lf, INF)\n", A + M/v1, A, A);
                        }
                        else{
                            if(dcmp(x*x+D*x+E)!=0)
                                printf("[%.4lf, INF)\n", A + M/v1);
                            else
                                printf("(%.4lf, INF)\n", A + M/v1);
                        }
                    }
                    else if(dcmp(v1) > 0 && dcmp(v2) < 0){
                        if(dcmp(N*N-D*N+E)==0){
                            if(dcmp(x*x+D*x+E)!=0)
                                printf("[%.4lf, %.4lf) U (%.4lf, %.4lf]\n", A + M/v1, A, A, A + M/v2);
                            else
                                printf("(%.4lf, %.4lf) U (%.4lf, %.4lf)\n", A + M/v1, A, A, A + M/v2);
                        }
                        else{
                            if(dcmp(x*x+D*x+E)!=0)
                                printf("[%.4lf, %.4lf]\n", A + M/v1, A + M/v2);
                            else
                                printf("(%.4lf, %.4lf)\n", A + M/v1, A + M/v2);
                        }
                    }
                    else if(dcmp(v1) == 0 && dcmp(v2) < 0){
                        if(dcmp(N*N-D*N+E)==0){
                            if(dcmp(x*x+D*x+E)!=0)
                                printf("(-INF, %.4lf) U (%.4lf, %.4lf]\n", A, A, A + M/v2);
                            else
                                printf("(-INF, %.4lf) U (%.4lf, %.4lf)\n", A, A, A + M/v2);
                        }
                        else{
                            if(dcmp(x*x+D*x+E)!=0)
                                printf("(-INF, %.4lf]\n", A + M/v2);
                            else
                                printf("(-INF, %.4lf)\n", A + M/v2);
                        }
                    }
                    else if(dcmp(v1) < 0 && dcmp(v2) < 0){
                        if(dcmp(N*N-D*N+E)==0){
                            if(dcmp(x*x+D*x+E)!=0)
                                printf("(-INF, %.4lf) U (%.4lf, %.4lf] U [%.4lf, INF)\n", A, A, A + M/v2, A + M/v1);
                            else
                                printf("(-INF, %.4lf) U (%.4lf, %.4lf) U (%.4lf, INF)\n", A, A, A + M/v2, A + M/v1);
                        }
                        else{
                            if(dcmp(x*x+D*x+E)!=0)
                                printf("(-INF, %.4lf] U [%.4lf, INF)\n", A + M/v2, A + M/v1);
                            else
                                printf("(-INF, %.4lf) U (%.4lf, INF)\n", A + M/v2, A + M/v1);
                        }
                    }
                }
            }
        }
    }
    return 0;
}
*/
#include <stdio.h>
#include <math.h>
#define EPS 1e-6

int dcmp(double d)
{
    if (d > EPS)
        return 1;
    else if (d < -EPS)
        return -1;
    else
        return 0;
}

int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        int A, B, C, D, E;
        scanf("%d%d%d%d%d", &A, &B, &C, &D, &E);

        B = B - A*D;
        C = C - A*E;
        double AA = A;

        if (B == 0)
        {// g(x)=C/(x^2+Dx+E)
            if (C == 0)
                printf("[%.4f, %.4f]\n", AA, AA);
            else
            {
                double m = -D*D/4.0 + E;
                if (dcmp(m) > 0)
                {// det<0
                    if (C > 0)
                        printf("(%.4f, %.4f]\n", AA, C / m + AA);
                    else
                        printf("[%.4f, %.4f)\n", C / m + AA, AA);
                }
                else if (dcmp(m) == 0)
                {// det==0
                    if (C > 0)
                        printf("(%.4f, INF)\n", AA);
                    else
                        printf("(-INF, %.4f)\n", AA);
                }
                else
                {// det>0
                    if (C > 0)
                        printf("(-INF, %.4f] U (%.4f, INF)\n", C / m + AA, AA);
                    else
                        printf("(-INF, %.4f) U [%.4f, INF)\n", AA, C / m + AA);
                }
            }
        }
        else
        {//B!=0 -- g(x)=(Bx+C)/(x^2+Dx+E)
            double x1 = -1.0*C/B;
            if (dcmp(x1*x1+D*x1+E) == 0)
            {// 可以分解因式，约分 -- g(x)=B/(x-x2) 注意定义域x!=x1)
                double x2 = -D - x1;
                if (dcmp(x1-x2) == 0)//x1 == x2
                    printf("(-INF, %.4f) U (%.4f, INF)\n", AA, AA);
                else
                {
                    double py = B / (x1 - x2); //挖去一个点
                    if (dcmp(py) < 0)
                        printf("(-INF, %.4f) U (%.4f, %.4f) U (%.4f, INF)\n", py+AA, py+AA, AA, AA);
                    else
                        printf("(-INF, %.4f) U (%.4f, %.4f) U (%.4f, INF)\n", AA, AA, py+AA, py+AA);
                }
            }
            else
            {// 不可以分解 -- 还元，分子变为x  -- g(x) = Bx/(x^2+D2x+E2) = B / (x+E2/x + D2)
                double D2 = D - 2.0*C/B;
                double E2 = 1.0*C*C/B/B - 1.0*C*D/B + E;
                if (dcmp(E2) < 0)
                    printf("(-INF, INF)\n");
                else
                {
                    double p = D2 + 2 * sqrt(E2);
                    double q = D2 - 2 * sqrt(E2);
                    if (B > 0)
                    {
                        if (dcmp(p)>0 && dcmp(q) > 0)
                            printf("(-INF, %.4f] U [%.4f, INF)\n", B/p + AA, B/q + AA);
                        else if (dcmp(q) == 0)
                            printf("(-INF, %.4f]\n", B/p + AA);
                        else if (dcmp(p)>0 && dcmp(q) < 0)
                            printf("[%.4f, %.4f]\n", B/q + AA, B/p + AA);
                        else if (dcmp(p) == 0)
                            printf("[%.4f, INF)\n", B/q + AA);
                        else
                            printf("(-INF, %.4f] U [%.4f, INF)\n", B/p + AA, B/q + AA);
                    }
                    else
                    {
                        if (dcmp(p)>0 && dcmp(q) > 0)
                            printf("(-INF, %.4f] U [%.4f, INF)\n", B/q + AA, B/p + AA);
                        else if (dcmp(q) == 0)
                            printf("[%.4f, INF)\n", B/p + AA);
                        else if (dcmp(p)>0 && dcmp(q) < 0)
                            printf("[%.4f, %.4f]\n", B/p + AA, B/q + AA);
                        else if (dcmp(p) == 0)
                            printf("(-INF, %.4f]\n", B/q + AA);
                        else
                            printf("(-INF, %.4f] U [%.4f, INF)\n", B/q + AA, B/p + AA);
                    }
                }
            }
        }
    }
    return 0;
}
