#include <cstdio>
#include <cstdlib>
#define Mon 1
#define Tues 2
#define Wed 3
#define Thur 4
#define Fri 5
#define Sat 6
#define Sun 0
FILE *fp = fopen("C:\\Users\\gavin\\Desktop\\Perpetualcalendar.txt", "w+");
int day_count(int month) {
    if (month == 1) return 0;
    if (month == 2) return 31;
    if (month == 3) return 59;
    if (month == 4) return 90;
    if (month == 5) return 120;
    if (month == 6) return 151;
    if (month == 7) return 181;
    if (month == 8) return 212;
    if (month == 9) return 243;
    if (month == 10) return 273;
    if (month == 11) return 304;
    if (month == 12) return 334;
}

void YM_Weekname_Print(int month, int year) {
    fprintf(fp, "%8d年  ", year);
    if (month == 1) fprintf(fp, "一月\n\n");
    if (month == 2) fprintf(fp, "二月\n\n");
    if (month == 3) fprintf(fp, "三月\n\n");
    if (month == 4) fprintf(fp, "四月\n\n");
    if (month == 5) fprintf(fp, "五月\n\n");
    if (month == 6) fprintf(fp, "六月\n\n");
    if (month == 7) fprintf(fp, "七月\n\n");
    if (month == 8) fprintf(fp, "八月\n\n");
    if (month == 9) fprintf(fp, "九月\n\n");
    if (month == 10) fprintf(fp, "十月\n\n");
    if (month == 11) fprintf(fp, "十一月\n\n");
    if (month == 12) fprintf(fp, "十二月\n\n");
    fprintf(fp, "%3s %3s %3s %3s %3s %3s %3s\n", "日", "一", "二", "三", "四",
            "五", "六");
}

bool isleap(int year) {
    if (!(year % 4) && year % 100 || !(year % 400))
        return true;
    else
        return false;
}

__int64 date_distance_count(int month, int year) {
    __int64 leap_year_count = 0;
    if (year > 1900) {
        for (int i = 1900; i < year; i++)
            if (isleap(i)) leap_year_count++;
        if (month > 2)
            if (isleap(year)) leap_year_count++;
    } else if (year == 1900)
        if (month > 2) leap_year_count = 1;
    return (year - 1900) * 365 + leap_year_count + day_count(month);
}

void MainPrint(int month, int firstday, int year) {
    int weekday, m = month;
    if (firstday == Sun)
        ;
    if (firstday == Mon) fprintf(fp, "%- 3s", " ");
    if (firstday == Tues) fprintf(fp, "%- 6s", " ");
    if (firstday == Wed) fprintf(fp, "%- 9s", " ");
    if (firstday == Thur) fprintf(fp, "%-12s", " ");
    if (firstday == Fri) fprintf(fp, "%-15s", " ");
    if (firstday == Sat) fprintf(fp, "%-18s", " ");

    if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
        for (int i = 1; i <= 31; i++) {
            weekday = (firstday + i - 1) % 7;
            fprintf(fp, "%-3d", i);
            if (weekday == Sat) fprintf(fp, "\n");
        }
    if (m == 2) {
        if (isleap(year)) {
            for (int i = 0; i < 29; i++) {
                weekday = (firstday + i) % 7;
                fprintf(fp, "%-3d", i + 1);
                if (weekday == Sat) fprintf(fp, "\n");
            }
        } else
            for (int i = 1; i <= 28; i++) {
                weekday = (firstday + i - 1) % 7;
                fprintf(fp, "%-3d", i);
                if (weekday == Sat) fprintf(fp, "\n");
            }
    }
    if (m == 4 || m == 6 || m == 9 || m == 11)
        for (int i = 1; i <= 30; i++) {
            weekday = (firstday + i - 1) % 7;
            fprintf(fp, "%-3d", i);
            if (weekday == Sat) fprintf(fp, "\n");
        }
    fprintf(fp, "\n");
}

void main_month_print(int year) {
    for (int i = 1, month = 1; i <= 12; i++, month++) {
        int firstday_weekday = (1 + date_distance_count(month, year)) % 7;
        ;
        fprintf(fp, "#####################\n");
        YM_Weekname_Print(month, year);
        MainPrint(month, firstday_weekday, year);
        fprintf(fp, "#####################\n\n\n");
    }
}

int main() {
    int year;
    scanf("%d", &year);
    fprintf(fp, "     %d年日历\n", year);
    main_month_print(year);
    return 0;
}