#ifndef COE_H
#define COE_H
#include "ex4.h"
#include "BoundedBuffer.h"

class Co_Editor {
public:
    // co-editors queue and screen manager queue
    Co_Editor(BoundedBuffer& coeq, BoundedBuffer& smq);
    void edit();
private:
    BoundedBuffer& coeq;
    BoundedBuffer& smq;
};
#endif