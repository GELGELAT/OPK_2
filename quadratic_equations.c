#include <stdio.h>
#include <stdlib.h>
#include <math.h>
double e = 0.001;
double fing_discr(double first,double second,double third)
{
    return second*second - 4*first*third;
}
void fing_ans_v(double* ans,double discr,double first,double second)
{
    double sqrt_discr = sqrt((double)discr);
    ans[0] = (-1*second + sqrt_discr)/2/first;
    ans[1] =(-1*second - sqrt_discr)/2/first;
}
void fing_ans_c(double* ans,double discr,double first,double second)
{
    double sqrt_discr = sqrt(-1*discr);
    ans[0] = -1*second/2/first;
    ans[1] = sqrt_discr/2/first;

}
void print_ans_c(double* ans)
{
    if ( fabs(ans[0])<e)
    {
        printf("x1=%lfi,x2=-%lfi",ans[1],ans[1]);
    }
    else
    {
        printf("x1=%lf+%lfi,x2=%lf-%lfi",ans[0],ans[1],ans[0],ans[1]);
    }
}
void print_ans_v(double* ans)
{
    if ( fabs(ans[0])<e)
    {
        printf("x=%lf",ans[0]);
    }
    else
    {
        printf("x1=%lf,x2=%lf",ans[0],ans[1]);
    }
}
int main(void)
{
    double first, second,third;
    double discr;
    double ans[2]={0};
    
    scanf("%lf",&first);
    scanf("%lf",&second);
    scanf("%lf",&third);

    if (fabs(first)<e)
    {
        if (fabs(second)<e)
        {
            if (fabs(third)<e)
            {
                printf("x=ever");
            }
            else
            {
                printf("x=never");
            }
            
        }
        else
        {
            if (fabs(third)<e)
            {
                printf("x=0");
            }
            else
            {
                printf("x=%lf",-1*third/second);
            }
            
        }
        
    }
    else
    {
        discr = fing_discr(first, second,third);
        if (discr<0)
        {
            fing_ans_c(ans,discr,first,second);
            print_ans_c(ans);
        }
        else
        {
            fing_ans_v(ans,discr,first,second);
            print_ans_v(ans);
            
        }
    }
}