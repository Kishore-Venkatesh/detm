# detm
DETM - Distributed Edge Telemetry Mesh

Distributed
→ Multiple nodes communicating (your N ↔ N goal)

Edge
→ Runs on devices (Raspberry Pi, embedded systems later if you extend)

Telemetry
→ Real-time data (sensor + system metrics)

Mesh
→ Not client-server
→ Fully connected, decentralized communication

### System Architechure

+-------------------+        DDS (Cyclone DDS)       +-------------------+
|   Node A          |  <---------------------------> |   Node B          |
| (Publisher/Sub)   |                                | (Publisher/Sub)   |
+-------------------+                                +-------------------+
        ↑                                                    ↑
        |                                                    |
        | REST API (CrowCpp)                                 | REST API
        ↓                                                    ↓
+---------------------------------------------------------------+
|                   Control Plane (CrowCpp)                    |
|   - QoS Updates                                              |
|   - Dynamic Topic Subscription                               |
|   - Filtering (by node, data type, priority)                 |
+---------------------------------------------------------------+

