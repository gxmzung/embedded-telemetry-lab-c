#ifndef CRC16_H
#define CRC16_H

unsigned short calculate_crc16(const char *data);
int validate_crc(const char *payload, int expected_crc);

#endif