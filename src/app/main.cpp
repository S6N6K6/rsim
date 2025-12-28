#include <iostream>

#include "RSIM.h"

class RSIM_API Sandbox : public RSIM::Application {
  public:
    Sandbox() {}
    ~Sandbox() {}
};

RSIM::Application *RSIM::CreateApplication() { return new Sandbox(); }
