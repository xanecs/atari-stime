#include <stdio.h>
#include <osbind.h>
#include <stdint.h>
#include <malloc.h>
#include "main.h"


int main() {
    LINE *input = malloc(sizeof(LINE));
    input->maxlen = 100;

    printDateTime(Tgetdate(), Tgettime());
    printf("Enter date (YYYY-MM-DD):\n");
    uint16_t year, month, day;
    Cconrs(input);
    sscanf(input->buffer, "%hu-%hu-%hu", &year, &month, &day);

    free(input);
    input = malloc(sizeof(LINE));
    input->maxlen = 100;

    printf("Enter time (HH:MM:SS)\n");
    uint16_t hour, minute, second;

    Cconrs(input);
    sscanf(input->buffer, "%hu:%hu:%hu", &hour, &minute, &second);

    free(input);

    uint32_t atdate, attime;
    convertToAtari(year, month, day, hour, minute, second, &atdate, &attime);

    printf("%hu ", second / 2);
    printf("%#04x\n", attime);

    Tsetdate(atdate);
    Tsettime(attime);

    printDateTime(Tgetdate(), Tgettime());
    Cconin();
    return 0;
}

void printDateTime(uint32_t date, uint32_t time) {
    uint16_t year, month, day, hour, minute, second;
    convertFromAtari(date, time, &year, &month, &day, &hour, &minute, &second);
    printf("%hu-%hu-%huT%hu:%hu:%hu\n", year, month, day, hour, minute, second);
}

void convertToAtari(uint16_t year, uint16_t month, uint16_t day, uint16_t hour, uint16_t minute, uint16_t second, uint32_t *atdate, uint32_t *attime) {
    *atdate = ((uint16_t)(year - 1980) << 9) | (month << 5) | (day);
    *attime = (hour << 11) | (minute << 5) | (uint16_t)(second / 2);
}

void convertFromAtari(uint32_t atdate, uint32_t attime, uint16_t *year, uint16_t *month, uint16_t *day, uint16_t *hour, uint16_t *minute, uint16_t *second) {
    *year = (uint16_t)(((atdate & 0xFE00) >> 9) + 1980);
    *month = (uint16_t)(atdate & 0x01E0) >> 5;
    *day = (uint16_t)(atdate & 0x001F);

    *hour = (uint16_t)(attime & 0xF800) >> 11;
    *minute = (uint16_t)(attime & 0x07E0) >> 5;
    *second = (uint16_t)((attime & 0x001F) * 2);
}