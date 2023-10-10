#include <iostream>
#include "CustomListeners.h"

int main() {
    std::cout << "Starting CustomListener Subscriber...\n";
    
    CustomListenerSubscriber subscriber;
    if (subscriber.init(1)) {
        subscriber.run();
    } else {
        std::cerr << "Failed to initialize subscriber.\n";
    }

    return 0;
}
