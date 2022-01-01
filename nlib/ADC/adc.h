#ifndef __NB_ADC
#define __NB_ADC

#include "mbed.h"
#include "nworkbench.h"

class nBlock_ADC: public nBlockSimpleNode<1> {
public:
    nBlock_ADC(PinName pinAdc, nBlocks_OutputType data_type = OUTPUT_TYPE_FLOAT);
    void triggerInput(nBlocks_Message message);
private:
    AnalogIn _adc;
};





#endif
