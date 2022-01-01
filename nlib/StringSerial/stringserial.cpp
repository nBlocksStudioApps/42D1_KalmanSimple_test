#include "stringserial.h"

nBlock_StringSerial::nBlock_StringSerial(PinName pinTX, PinName pinRX): _ser(pinTX, pinRX) {
    return;
}
void nBlock_StringSerial::triggerInput(nBlocks_Message message) {
    if (message.dataType == OUTPUT_TYPE_STRING) {
        _ser.printf(message.stringValue);
    }

    if (message.dataType == OUTPUT_TYPE_ARRAY) {
        char * data_array = (char *)(message.pointerValue);
        for (uint32_t i=0; i<message.dataLength; i++) {
            _ser.putc(data_array[i]);
        }
    }
    
}
void nBlock_StringSerial::endFrame(void) {
    if (_ser.readable()) {
        output[0] = _ser.getc();
        available[0] = 1;
    }
    return;
}

