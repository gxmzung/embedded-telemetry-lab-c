#include "crc16.h"

unsigned short calculate_crc16(const char *data) {
    unsigned short crc = 0xFFFF;

    while (*data) {
        crc ^= (unsigned char)(*data++);

        for (int i = 0; i < 8; i++) {
            if (crc & 1) {
                crc = (crc >> 1) ^ 0xA001;
            } else {
                crc >>= 1;
            }
        }
    }

    return crc;
}

int validate_crc(const char *payload, int expected_crc) {
    unsigned short calculated = calculate_crc16(payload);
    return calculated == (unsigned short)expected_crc;
}