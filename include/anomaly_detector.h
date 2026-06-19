#ifndef ANOMALY_DETECTOR_H
#define ANOMALY_DETECTOR_H

#include "packet_parser.h"

int is_voltage_anomaly(const TelemetryPacket *packet);
int is_temperature_anomaly(const TelemetryPacket *packet);
int is_signal_anomaly(const TelemetryPacket *packet);
int count_packet_anomalies(const TelemetryPacket *packet);

#endif