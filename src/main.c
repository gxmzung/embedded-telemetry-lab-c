#include <stdio.h>
#include <string.h>
#include "packet_parser.h"
#include "anomaly_detector.h"
#include "telemetry_session.h"

int main(void) {
    FILE *file = fopen("data/sample_packets.csv", "r");

    if (file == NULL) {
        printf("Failed to open telemetry data file.\n");
        return 1;
    }

    char line[256];
    TelemetryPacket packet;
    TelemetrySession session;

    init_session(&session);

    fgets(line, sizeof(line), file);

    while (fgets(line, sizeof(line), file)) {
        if (parse_packet_line(line, &packet)) {
            int anomaly_count = count_packet_anomalies(&packet);

            print_packet(&packet);

            if (anomaly_count > 0) {
                printf("  Warning: %d anomaly signal(s) detected.\n", anomaly_count);
            }

            update_session(&session, &packet, anomaly_count);
        }
    }

    fclose(file);
    print_session_report(&session);

    return 0;
}