#include <iostream>
#include "CustomListeners.h"

int main() {
    std::cout << "Starting CustomListener Publisher...\n";
    
    CustomListenerPublisher publisher;
    if (publisher.init(1)) {
        publisher.run();
    } else {
        std::cerr << "Failed to initialize publisher.\n";
    }

    return 0;
}
