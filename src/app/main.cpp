#include <iostream>
#include "RSIM_static_lib.h"
#include "RSIM_shared_lib.h"

int main() {
    std::cout << "Static lib: " << static_lib_function() << std::endl;
    std::cout << "Shared lib: " << shared_lib_function() << std::endl;

    return 0;
}
