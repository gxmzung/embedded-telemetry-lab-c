#ifndef PACKET_PARSER_H
#define PACKET_PARSER_H

typedef struct {
    int packet_id;
    double voltage;
    double temperature;
    double signal_strength;
    int crc;
} TelemetryPacket;

int parse_packet_line(const char *line, TelemetryPacket *packet);
void print_packet(const TelemetryPacket *packet);

#endif