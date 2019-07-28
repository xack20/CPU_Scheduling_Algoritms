#include <bits/stdc++.h>
using namespace std;

struct
{
    char p[10];
    int arrival_time;
    int burst_time;

}typedef pro;



bool sort_sjf(const pro &a , const pro &b)
{
    if(a.arrival_time == b.arrival_time)return (a.burst_time < b.burst_time);
    else return (a.arrival_time < b.arrival_time);
}



int main()
{

    printf("Enter the number of process : ");

    int n ; scanf("%d",&n);

    printf("\n");


    pro name[n];

    printf("Insert your processes \n");
    for(int i = 0 ; i < n ;i ++){

        scanf("%s",name[i].p);
        scanf("%d",&name[i].arrival_time);
        scanf("%d",&name[i].burst_time);
    }
    printf("\n\n");


    sort(name,name+n,sort_sjf);



    char pro_list[n*2][10];
    int times[n*2 + 1];

    int rt = 0;
    int ti=0,pi=0;

    times[ti++] = rt;

    for(int i = 0 ; i < n ; i++)
    {
        if(name[i].arrival_time > rt)
        {

            strcpy(pro_list[pi++], "IDLE");

            rt=name[i].arrival_time;

            times[ti++] = rt;
            strcpy(pro_list[pi++], name[i].p);

            rt+= name[i].burst_time;
            times[ti++] = rt;

        }
        else
        {
            strcpy(pro_list[pi++], name[i].p);
            rt+= name[i].burst_time;
            times[ti++] = rt;
        }
    }




    for(int i = 0 ; i < pi ; i ++)printf("-------");
    printf("\n");

    for(int i = 0 ; i < pi ; i ++){
        if(tolower(pro_list[i][0])=='p')printf("|  %s  ",pro_list[i]);
        else printf("| %s ",pro_list[i]);
    }
    printf("|\n");

    for(int i = 0 ; i < pi ; i ++)printf("-------");
    printf("\n");



    for(int i = 0 ; i < ti ; i ++){
        if((int)(log10(times[i])+1) == 1 || !times[i])printf("%d      ",times[i]);
        else printf("%d     ",times[i]);
    }
    printf("\n\n");



    printf("\n\n*****************     Waiting times    *****************\n\n");

    int wt = 0 ;

    int ind = 0;

    for(int i = 0 ; i < pi ; i ++)
    {
        if(tolower(pro_list[i][0])=='p'){
            printf("%s : %d\n", pro_list[i] ,(times[i]-name[ind++].arrival_time) );
            wt+=(times[i]-name[ind-1].arrival_time);
        }
    }
    printf("\n");


    printf("Average Waiting time : %.2lf\n\n\n",( double(wt)/(double)n));




    printf("\n\n*****************     Turnaround times    *****************\n\n");

    int tt = 0 ;

    ind = 0;

    for(int i = 0 ; i < pi ; i ++)
    {
        if(tolower(pro_list[i][0])=='p'){
            printf("%s : %d\n", pro_list[i] ,(times[i+1]-name[ind++].arrival_time) );
            tt+=(times[i+1]-name[ind-1].arrival_time);
        }
    }
    printf("\n");


    printf("Average TT : %.2lf\n",( double(tt)/(double)n));
    printf("\n\n");


    return 0;
}







