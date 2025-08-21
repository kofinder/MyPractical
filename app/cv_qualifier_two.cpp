#include <iostream>
#include <vector>

struct ResourceHandle {
    int id;
};

// observe without modifying
void observe_resource(ResourceHandle const* h) {
    std::cout << "Observing resource " << h->id << "\n";
}

class ResourceManager {
    std::vector<ResourceHandle*> resources;

public:

    void add(ResourceHandle* r) {
        resources.push_back(r);
    }

    // note: const member function
    void observe_resources() const {
        for (const ResourceHandle* h : resources) {
            observe_resource(h); // safe, no cast
        }
    }
};

int main() {
    
    ResourceHandle r1{1}, r2{2}, r3{3};
    ResourceManager rm;

    rm.add(&r1);
    rm.add(&r2);
    rm.add(&r3);

    // call const function
    rm.observe_resources();

    return 0;
}
