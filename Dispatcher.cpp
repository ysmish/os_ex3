#include "Dispatcher.h"
// producer queues and co-editors queues
Dispatcher::Dispatcher(vector<BoundedBuffer*> pq, vector<BoundedBuffer*> coeq) {
    this->pq = pq;
    this->coeq = coeq;
}
// takes from the producers to the matching queue of the co editors
void Dispatcher::redirect() {
    int len = pq.size();
    int n_working_queues = len; // number of working queues
    bool working_queues[len] = {false};
    int i = 0;
    news_data nd;
    while (n_working_queues) {
        if ((*pq[i]).consume(&nd) == -1) {
            i = (i + 1) % len;
            continue;
        }
        switch (nd.type) {
            case DONE:
                if (!working_queues[i]) {
                    n_working_queues --;
                    working_queues[i] = true;
                }
                break;
            default:
                (*coeq[nd.type]).produce(nd);
                break;
        }
        i = (i + 1) % len;
    }
    (*coeq[SPORTS]).produce({DONE, "DONE"});
    (*coeq[NEWS]).produce({DONE, "DONE"});
    (*coeq[WEATHER]).produce({DONE, "DONE"});
}
Dispatcher::~Dispatcher() {
    // I decided that the dispatcher is in charge of free the allocated memory.
    // this is because the dispatcher has access to most bounded buffer need to be free
    for (BoundedBuffer *bb : pq) {
        delete bb;
    }
    for (BoundedBuffer *bb : coeq) {
        delete bb;
    }
}
