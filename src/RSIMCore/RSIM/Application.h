#pragma once
#include <memory>

#include "Core.h"
#include "Window.h"

namespace RSIM {
  class RSIM_API Application {
    public:
      Application();
      virtual ~Application();

      virtual void Run();
private:
  std::unique_ptr<Window> m_window;
  bool m_running = true;

  };

  // To be define in CLIENT
  Application *CreateApplication();

} // namespace RSIM
