#include <cassert>
#include "{PROJECT_NAME}_static_lib.h"

int main(){
    assert(static_lib_function() == 42);

    return 0;
}
