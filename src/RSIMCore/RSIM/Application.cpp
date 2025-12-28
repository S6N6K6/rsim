#include "Application.h"
#include "Events/ApplicationEvent.h"
#include "Events/Event.h"
#include "Log.h"
#include "Window.h"

// #include <GL/gl.h>
#include <GLFW/glfw3.h>
#include <functional>

#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)
namespace RSIM {
  Application::Application() {
    m_window = std::unique_ptr<Window>(Window::Create());
    m_window->SetEventCallback(BIND_EVENT_FN(OnEvent));
  }
  Application::~Application() {}
  void Application::Run() {
    while (m_running) {
      m_window->OnUpdate();
      glClearColor(1.0f, 0.0f, 1.0f, 1.0f);
      glClear(GL_COLOR_BUFFER_BIT);
    }
  }

  void Application::OnEvent(Event &e) {
    EventDispatcher dispatcher(e);
    dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));
    RSIM_CORE_TRACE(static_cast<Event &>(e));
  }

  bool Application::OnWindowClose(WindowCloseEvent &e) {
    m_running = false;
    return true;
  }
} // namespace RSIM
