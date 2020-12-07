#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
void swap(int*a, int*b)
{
    int t=*a ;
    *a=*b ;
    *b=t ;
}

int p1, s1 ;
void qs(int* a, int l, int r)
{

    int i = l, j = r, x = a[(l + r) / 2] ;

    do
    {
        while (a[i] < x) {
                i++ ;
                s1+=1 ;
        }s1+=1 ;
        while (a[j] > x) {
                j-- ;
                s1+=1 ;
        }s1+=1 ;

        if(i <= j)
        {

            if (a[i] > a[j])
            {
                p1=p1+1 ;


                swap(&a[i], &a[j]) ;
            }
            i++ ;
            j-- ;
            s1 =s1+1 ;
        }
    }
    while (i <= j) ;

    if (i < r)
        qs(a, i, r) ;
    if (l < j)
        qs(a, l, j) ;
}


void Sort1(int* m, int n)
{
    for(int i = n - 1 ; i >= 1 ; i--)
        for(int j = 0 ; j < i ; j++)
        {
            if(m[j] > m[j+1])
            {
                p1 = p1+1 ;
                swap(&m[j], &m[j+1]) ;
            }
            s1=s1+1 ;
        }
}
int main()
{
    setlocale(LC_ALL,"Rus");



    while (1)
    {
        int N;
        printf("Ââåäèòå íîìåð ñîðòèðîâêè: 1. Ïóçûðüêîì 2. QuickSort  \n") ;
        scanf("%d", &N) ;

        int n, i ;
        p1=0 ;
        s1=0 ;
        printf("Ââåäèòå êîëè÷åñòâî ýëåìåíòîâ\n ") ;
        scanf("%d", &n) ;
        int* a ;
        a = (int*) malloc(n*sizeof(int)) ;
        printf("Ââåäèòå ìàññèâ\n ") ;
        for (i=0 ; i<n ; i++)
        {
            scanf("%d", a+i) ;
        }
        if (N==1)
        {
            Sort1(a, n) ;
        }
        if (N==2)
        {
            qs(a, 0, n-1) ;
        }

        for (i=0 ; i<n ; i++)
        {
            printf("%3d ", a[i]) ;
        }
        printf("\nñðàâíåíèé   %4d ïåðåñòàíîâîê  %4d\n", s1, p1) ;

    }
}
