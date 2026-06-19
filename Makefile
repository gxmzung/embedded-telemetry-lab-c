CC=gcc
CFLAGS=-Wall -Wextra -Iinclude

SRC=src/main.c src/packet_parser.c src/crc16.c src/anomaly_detector.c src/telemetry_session.c
OUT=embedded_telemetry_lab

all:
	$(CC) $(CFLAGS) $(SRC) -o $(OUT)

run: all
	./$(OUT)

clean:
	rm -f $(OUT)