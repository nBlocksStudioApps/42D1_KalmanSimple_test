#include "adc.h"

/// GPI
nBlock_ADC::nBlock_ADC(PinName pinAdc, nBlocks_OutputType data_type): _adc(pinAdc) {
	outputType[0] = data_type;
    return;
}

void nBlock_ADC::triggerInput(nBlocks_Message message) {
    // Input 0 triggers a read regardless of value
    if (message.inputNumber == 0) {
		// Select a different reading method depending on output type
		if (outputType[0] == OUTPUT_TYPE_FLOAT) {
			// Read as a float and pack as uint32_t for transmission
			output[0] = PackFloat(_adc.read());
			available[0] = 1;
		}
		else if (outputType[0] == OUTPUT_TYPE_INT) {
			// Read as uint16_t and store as uint32_t
			output[0] = _adc.read_u16();
			available[0] = 1;
		}
		else {
			// Unknown data type. Just ignore and fail silently
		}
    }
}

