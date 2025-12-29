#include "Application.h"
#include "Core.h"
#include "Events/ApplicationEvent.h"
#include "Events/Event.h"
#include "Log.h"
#include "Window.h"

// #include <GL/gl.h>
#include <functional>
#include <glad/glad.h>

namespace RSIM {
#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)

  Application *Application::s_Instance = nullptr;

  Application::Application() {
    RSIM_CORE_ASSERT(!s_Instance, "Application already exists")
    s_Instance = this;
    m_window = std::unique_ptr<Window>(Window::Create());
    m_window->SetEventCallback(BIND_EVENT_FN(OnEvent));

    unsigned int VAO;
    glGenVertexArrays(1, &VAO);
  }
  Application::~Application() {}

  void Application::PushLayer(Layer *layer) {
    m_LayerStack.PushLayer(layer);
    layer->OnAttach();
  }

  void Application::PushOverlay(Layer *layer) {
    m_LayerStack.PushOverlay(layer);
    layer->OnAttach();
  }

  void Application::Run() {
    while (m_running) {
      glClearColor(1.0f, 0.0f, 1.0f, 1.0f);
      glClear(GL_COLOR_BUFFER_BIT);

      for (Layer *layer : m_LayerStack)
        layer->OnUpdate();

      m_window->OnUpdate();
    }
  }

  void Application::OnEvent(Event &e) {
    EventDispatcher dispatcher(e);
    dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));
    RSIM_CORE_TRACE(static_cast<Event &>(e));

    for (auto it = m_LayerStack.end(); it != m_LayerStack.begin();) {
      (*--it)->OnEvent(e);
      if (e.IsHandled())
        break;
    }
  }

  bool Application::OnWindowClose(WindowCloseEvent &e) {
    m_running = false;
    return true;
  }
} // namespace RSIM
