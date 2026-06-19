# Embedded Telemetry Lab C

C-based telemetry packet parsing and field diagnostics lab.

This project focuses on low-level packet parsing, CRC validation, anomaly detection, and mission-session reporting for embedded and field-operation systems.

## Goals

- Parse telemetry packets from CSV or binary-like records
- Validate packet structure
- Detect abnormal voltage, temperature, and signal values
- Generate mission session summaries
- Practice C-based embedded diagnostic logic

## Project Structure

```text
src/
  main.c
  packet_parser.c
  crc16.c
  anomaly_detector.c
  telemetry_session.c

include/
  packet_parser.h
  crc16.h
  anomaly_detector.h
  telemetry_session.h

data/
  sample_packets.csv

docs/
  protocol_spec.md
  test_log.md

Target Position

This repository is built for embedded systems, telemetry diagnostics, mission operations, and field engineering practice.

Tech Stack
C
Makefile
CSV telemetry records
CRC16 validation
Embedded-style diagnostic logic
Status

Early implementation scaffold.