//
// Created by leon on 30.12.16.
//

#ifndef ATARI_STIME_MAIN_H
#define ATARI_STIME_MAIN_H

typedef struct
{
    uint8_t   maxlen;        /* Maximum line length */
    uint8_t   actuallen;     /* Current line length */
    int8_t    buffer[255];   /* Line buffer         */
} LINE;

void printDateTime(uint32_t, uint32_t);
void convertToAtari(uint16_t, uint16_t, uint16_t, uint16_t, uint16_t, uint16_t, uint32_t*, uint32_t*);
void convertFromAtari(uint32_t, uint32_t, uint16_t*, uint16_t*, uint16_t*, uint16_t*, uint16_t*, uint16_t*);

#endif //ATARI_STIME_MAIN_H
