#include<stdio.h>

typedef struct{
    int year, day;      //value of day ranges from 1 to 365 or 366
    int hour, min, sec;
} dt;       //dt stands for day time

dt input(dt temp){
    scanf(" %d", &temp.year);
    scanf(" %d", &temp.day);
    scanf(" %d", &temp.hour);
    scanf(" %d", &temp.min);
    scanf(" %d", &temp.sec);
    return temp;
}
int calculate(int a, int b, int cons, int *d){
    int res = a - b;
    if(res < 0){
        res+=cons;
        --(*d);
    }
    return res;
}
dt calculate_difference(dt x, dt y){
    dt diff;
    diff.sec = calculate(x.sec, y.sec, 60, &x.min);
    diff.min = calculate(x.min, y.min, 60, &x.hour);
    diff.hour = calculate(x.hour, y.hour, 24, &x.day);

    long daycount=0;
    if(x.year != y.year){
        if(x.year%4==0) daycount = 366 - x.day;
        else            daycount = 365 - x.day;

        daycount += y.day;
    }
    else{
        daycount = x.day - y.day;
    }

    for(int i=x.year+1; i<y.year; ++i){
        if(i%4==0)
            daycount+=366;
        else
            daycount+=365;
    }

    diff.year = daycount / 365;
    diff.day = daycount % 365;
    return diff;
}
int main(){
    dt x = input(x);
    dt y = input(y);
    // printf(" %d %d %d %d %d\n", x.year, x.day, x.hour, x.min, x.sec);
    // printf(" %d %d %d %d %d\n", y.year, y.day, y.hour, y.min, y.sec);
    dt diff = calculate_difference(x, y);
    printf(" %d years %d days %d hours %d minutes %d seconds\n", diff.year, diff.day, diff.hour, diff.min, diff.sec);

    return 0;
}
