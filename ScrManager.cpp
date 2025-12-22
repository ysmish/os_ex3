#include "Screen_Manager.h"
// co-editors queue and screen manager queue
Screen_Manager::Screen_Manager(BoundedBuffer& smq) : smq(smq) {}
void Screen_Manager::display() {
    int n_done = 0; // counts the number of DONE
    news_data nd;       
    while (n_done < 3) {
        smq.consume(&nd);
        if (nd.type != DONE) {
            cout << nd.str << endl;
        } else {
            n_done ++;
        }
    }
    cout << DONE_STR << endl;
}
