#ifndef __NB_STRINGSERIAL
#define __NB_STRINGSERIAL

#include "nworkbench.h"

class nBlock_StringSerial: public nBlockSimpleNode<1> {
public:
    nBlock_StringSerial(PinName pinTX, PinName pinRX);
    void triggerInput(nBlocks_Message message);
    void endFrame(void);
private:
    Serial _ser;
};

#endif
