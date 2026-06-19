# Telemetry Protocol Spec

## Packet Format

```text
packet_id,voltage,temperature,signal_strength,crc

Field Description
Field	Type	Description
packet_id	int	Sequential telemetry packet identifier
voltage	double	System voltage
temperature	double	Internal temperature
signal_strength	double	Communication signal quality
crc	int	Expected CRC value
Diagnostic Rules
Rule	Condition
Voltage anomaly	voltage < 10.5 or voltage > 13.0
Temperature anomaly	temperature < -10.0 or temperature > 75.0
Signal anomaly	signal_strength < 35.0