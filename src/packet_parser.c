#include <stdio.h>
#include <stdlib.h>
#include "packet_parser.h"

int parse_packet_line(const char *line, TelemetryPacket *packet) {
    if (line == NULL || packet == NULL) {
        return 0;
    }

    int parsed = sscanf(
        line,
        "%d,%lf,%lf,%lf,%d",
        &packet->packet_id,
        &packet->voltage,
        &packet->temperature,
        &packet->signal_strength,
        &packet->crc
    );

    return parsed == 5;
}

void print_packet(const TelemetryPacket *packet) {
    if (packet == NULL) {
        return;
    }

    printf(
        "Packet %d | Voltage: %.2f V | Temp: %.2f C | Signal: %.2f | CRC: %d\n",
        packet->packet_id,
        packet->voltage,
        packet->temperature,
        packet->signal_strength,
        packet->crc
    );
}