#include "anomaly_detector.h"

int is_voltage_anomaly(const TelemetryPacket *packet) {
    return packet->voltage < 10.5 || packet->voltage > 13.0;
}

int is_temperature_anomaly(const TelemetryPacket *packet) {
    return packet->temperature < -10.0 || packet->temperature > 75.0;
}

int is_signal_anomaly(const TelemetryPacket *packet) {
    return packet->signal_strength < 35.0;
}

int count_packet_anomalies(const TelemetryPacket *packet) {
    int count = 0;

    if (is_voltage_anomaly(packet)) {
        count++;
    }

    if (is_temperature_anomaly(packet)) {
        count++;
    }

    if (is_signal_anomaly(packet)) {
        count++;
    }

    return count;
}