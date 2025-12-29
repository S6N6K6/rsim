#pragma once
#include <memory>

#include "Core.h"
#include "Events/ApplicationEvent.h"
#include "LayerStack.h"
#include "Window.h"

namespace RSIM {
  class RSIM_API Application {
    public:
      Application();
      virtual ~Application();

      virtual void Run();
      void OnEvent(Event &e);
      void PushLayer(Layer *layer);
      void PushOveray(Layer *layer);

    private:
      bool OnWindowClose(WindowCloseEvent &e);
      std::unique_ptr<Window> m_window;
      bool m_running = true;
      LayerStack m_LayerStack;
  };

  // To be define in CLIENT
  Application *CreateApplication();

} // namespace RSIM
