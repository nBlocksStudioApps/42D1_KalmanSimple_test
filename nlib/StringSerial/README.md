# nblocks_stringserial
StringSerial node for nBlocksStudio

This node implements a serial port, where characters received from the external world (RX pin) are sent one by one to the node's output, but the node's input expects a full string object as input (sent entirely within one frame to the TX pin).

DO NOT CONNECT integer data into this node, as it will definitely lead to incorrect behaviour, sending random bytes in unpredicted amount to the serial port. This can be harmful depending on your design.
