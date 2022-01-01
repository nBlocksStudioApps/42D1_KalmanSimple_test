#include "signalmixer.h"

nBlock_SignalMixer::nBlock_SignalMixer(float ratio1, float ratio2, float ratio3, float ratio4) {
    _ratio1 = ratio1;
    _ratio2 = ratio2;
    _ratio3 = ratio3;
    _ratio4 = ratio4;
    outputType[0] = OUTPUT_TYPE_FLOAT;
}
 
void nBlock_SignalMixer::triggerInput(nBlocks_Message message){
    // Any Input triggers an output regardless of value
    // 
    if (message.inputNumber == 0) { 
        _outvalue =  _outvalue +  _ratio1*(message.floatValue);      
        newValueFLAG = 1;   
    }
    if (message.inputNumber == 1) { 
        _outvalue =  _outvalue +  _ratio2*(message.floatValue);          
        newValueFLAG = 1;   
    }
    if (message.inputNumber == 2) {
        _outvalue =  _outvalue +  _ratio3*(message.floatValue);           
        newValueFLAG = 1;   
    }
    if (message.inputNumber == 3) { 
        _outvalue =  _outvalue +  _ratio4*(message.floatValue);          
        newValueFLAG = 1;   
    }            
}	

void nBlock_SignalMixer::endFrame(void) {
	if(newValueFLAG){
		newValueFLAG = 0;
		
		output[0] = PackFloat(_outvalue);
        _outvalue = 0;
		available[0] = 1;
	}	
}
