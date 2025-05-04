#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>

int main(void)
{
    int hour, minute, second;
    time_t now;
    struct tm *current;
    char *ampm;

    while (true)
    {
        // get current system time
        time(&now);
        current = localtime(&now);

        hour = current->tm_hour;
        minute = current->tm_min;
        second = current->tm_sec;

        // determine am pm to convert to 12 hour format

        if (hour >= 12)
        {
            ampm = "PM";
            if (hour > 12)
                hour -= 12;
        }
        else
        {
            ampm = "AM";
            if (hour == 0)
                hour = 12;
        }

        // clear the screen
        system("clear");

        // print formatted time with AM/PM
        printf("%02d : %02d : %02d %s", hour, minute, second, ampm);

        fflush(stdout);
        sleep(1);
    }

    return 0;
}
