#include "Application.h"
#include "Events/ApplicationEvent.h"
#include "Events/Event.h"
#include "Events/MouseEvent.h"
#include "Log.h"
#include "Window.h"

// #include <GL/gl.h>
#include <GLFW/glfw3.h>

namespace RSIM {
  Application::Application() {
    m_window = std::unique_ptr<Window>(Window::Create());
  }
  Application::~Application() {}
  void Application::Run() {
    while (m_running) {
      m_window->OnUpdate();
      glClearColor(1.0f, 0.0f, 1.0f, 1.0f);
      glClear(GL_COLOR_BUFFER_BIT);
    }
  }
} // namespace RSIM
