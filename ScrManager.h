#ifndef SCRMEN_H
#define SCRMEN_H
#include "ex3.h"
#include "BoundedBuffer.h"
#define DONE_STR "DONE"

class Screen_Manager {
public:
    // co-editors queue and screen manager queue
    Screen_Manager(BoundedBuffer& smq);
    void display();
private:
    BoundedBuffer& smq;
};
#endif