#include "Co_Editor.h"

// co-editors queue and screen manager queue
Co_Editor::Co_Editor(BoundedBuffer& coeq, BoundedBuffer& smq) : coeq(coeq), smq(smq) {}
void Co_Editor::edit() {
    news_data nd;
    do {
        coeq.consume(&nd);
        if (nd.type != DONE) {
            // sleeps 100000 microseconds which is 0.1 seconds
            usleep(100000);
        }
        smq.produce(nd);
    } while (nd.type != DONE);
}
