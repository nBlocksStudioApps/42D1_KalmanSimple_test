#include "noisesource.h"

nBlock_NoiseSource::nBlock_NoiseSource(float min, float max, uint32_t seed) {
    _max=max;
    _min=min;
    srand(seed);
    outputType[0] = OUTPUT_TYPE_FLOAT;
}
 
void nBlock_NoiseSource::triggerInput(nBlocks_Message message){
    // Input 0 triggers an output regardless of value
    if (message.inputNumber == 0) {         
        newValueFLAG = 1;   
    }
}	

void nBlock_NoiseSource::endFrame(void) {
	if(newValueFLAG){
		newValueFLAG = 0;
		_outvalue = ((float)rand()/RAND_MAX) * (_max - _min)-(_max - _min)/2;
		output[0] = PackFloat(_outvalue);
		available[0] = 1;
	}	
}
