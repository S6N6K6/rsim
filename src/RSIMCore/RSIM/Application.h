#pragma once
#include <iostream>

#include "Core.h"

namespace RSIM {
  class RSIM_API Application {
    public:
      Application();
      virtual ~Application();

      virtual void Run();
  };

  // To be define in CLIENT
  Application *CreateApplication();

} // namespace RSIM
