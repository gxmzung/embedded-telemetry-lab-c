#include <stdio.h>
#include "telemetry_session.h"

void init_session(TelemetrySession *session) {
    session->total_packets = 0;
    session->anomaly_packets = 0;
    session->average_voltage = 0.0;
    session->average_temperature = 0.0;
}

void update_session(TelemetrySession *session, const TelemetryPacket *packet, int anomaly_count) {
    session->total_packets++;

    session->average_voltage += packet->voltage;
    session->average_temperature += packet->temperature;

    if (anomaly_count > 0) {
        session->anomaly_packets++;
    }
}

void print_session_report(const TelemetrySession *session) {
    if (session->total_packets == 0) {
        printf("No telemetry packets processed.\n");
        return;
    }

    printf("\n=== Telemetry Session Report ===\n");
    printf("Total packets: %d\n", session->total_packets);
    printf("Anomaly packets: %d\n", session->anomaly_packets);
    printf("Average voltage: %.2f V\n", session->average_voltage / session->total_packets);
    printf("Average temperature: %.2f C\n", session->average_temperature / session->total_packets);
}