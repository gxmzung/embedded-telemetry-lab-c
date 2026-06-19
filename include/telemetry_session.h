#ifndef TELEMETRY_SESSION_H
#define TELEMETRY_SESSION_H

#include "packet_parser.h"

typedef struct {
    int total_packets;
    int anomaly_packets;
    double average_voltage;
    double average_temperature;
} TelemetrySession;

void init_session(TelemetrySession *session);
void update_session(TelemetrySession *session, const TelemetryPacket *packet, int anomaly_count);
void print_session_report(const TelemetrySession *session);

#endif