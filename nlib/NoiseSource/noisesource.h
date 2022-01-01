#ifndef __NB_NOISESOURCE
#define __NB_NOISESOURCE

#include "nworkbench.h"

class nBlock_NoiseSource: public nBlockSimpleNode<1> {

public:
    nBlock_NoiseSource(float min, float max, uint32_t seed);
    void triggerInput(nBlocks_Message message);
	void endFrame(void);
    uint32_t newValueFLAG;

private:	
	float  _input;
    float  _outvalue;
    float _max;
    float _min;
    uint32_t _seed;
    //srand _srand;
    //rand() _rand;

};
 
#endif