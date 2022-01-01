#ifndef __NB_SIGNALMIXER
#define __NB_SIGNALMIXER

#include "nworkbench.h"

class nBlock_SignalMixer: public nBlockSimpleNode<4> {

public:
    nBlock_SignalMixer(float ratio1, float ratio2, float ratio3, float ratio4);
    void triggerInput(nBlocks_Message message);
	void endFrame(void);
    uint32_t newValueFLAG;

private:	
    float _ratio1;
    float _ratio2;
    float _ratio3;
    float _ratio4; 
    float _outvalue;

};
 
#endif