#include "UnixWindow.h"
#include "Core.h"
#include "Events/ApplicationEvent.h"
#include "Events/KeyEvent.h"
#include "Events/MouseEvent.h"
#include "Window.h"
#include "glad/glad.h"
#include "GLFW/glfw3.h"

namespace RSIM {

  static bool s_GLFWInitialized = false;

  static void GLFWErrorCallback(int error_code, const char *description) {
    RSIM_CORE_ERROR("GLFW Error: ({0}): {1}", error_code, description);
  }

  Window *Window::Create(const WindowsProps &props) {
    return new UnixWindow(props);
  }

  UnixWindow::UnixWindow(const WindowsProps &props) { Init(props); }

  UnixWindow::~UnixWindow() {}

  void UnixWindow::OnUpdate() {
    glfwPollEvents();
    glfwSwapBuffers(m_window);
  }

  void UnixWindow::Init(const WindowsProps &props) {
    m_data.Title = props.Title;
    m_data.Height = props.Height;
    m_data.Width = props.Width;

    RSIM_CORE_INFO("Creating window {0} ({1}, {2})", props.Title, props.Width,
                   props.Height);

    if (!s_GLFWInitialized) {
      int success = glfwInit();
      RSIM_CORE_ASSERT(success, "Could not initialize GLFW!")
      glfwSetErrorCallback(GLFWErrorCallback);
      s_GLFWInitialized = true;
    }
    m_window = glfwCreateWindow((int)m_data.Width, (int)m_data.Height,
                                m_data.Title.c_str(), nullptr, nullptr);
    glfwMakeContextCurrent(m_window);
    int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
    RSIM_CORE_ASSERT(status, "Could no initialize GLAD!")
    glfwSetWindowUserPointer(m_window, &m_data);
    SetVSync(true);

    // Set GLFW callbacks

    glfwSetWindowSizeCallback(
        m_window, [](GLFWwindow *window, int width, int height) {
          WindowData &data = *(WindowData *)glfwGetWindowUserPointer(window);
          data.Width = width;
          data.Height = height;

          WindowResizeEvent event(width, height);
          data.EventCallback(event);
        });

    glfwSetWindowCloseCallback(m_window, [](GLFWwindow *window) {
      WindowData &data = *(WindowData *)glfwGetWindowUserPointer(window);
      WindowCloseEvent event;
      data.EventCallback(event);
    });

    glfwSetKeyCallback(m_window, [](GLFWwindow *window, int key, int scancode,
                                    int action, int mods) {
      WindowData &data = *(WindowData *)glfwGetWindowUserPointer(window);
      switch (action) {
      case GLFW_PRESS: {
        KeyPressedEvent event(key, 0);
        data.EventCallback(event);
        break;
      }
      case GLFW_RELEASE: {
        KeyReleasedEvent event(key);
        data.EventCallback(event);
        break;
      }
      case GLFW_REPEAT: {
        KeyPressedEvent event(key, 1);
        data.EventCallback(event);
        break;
      }
      }
    });

    glfwSetMouseButtonCallback(
        m_window, [](GLFWwindow *window, int button, int action, int mods) {
          WindowData &data = *(WindowData *)glfwGetWindowUserPointer(window);
          switch (action) {
          case GLFW_PRESS: {
            MouseButtonPressedEvent event(button);
            data.EventCallback(event);
          }
          case GLFW_RELEASE: {
            MouseButtonReleasedEvent event(button);
            data.EventCallback(event);
            break;
          }
          }
        });

    glfwSetScrollCallback(
        m_window, [](GLFWwindow *window, double xoffset, double yoffset) {
          WindowData &data = *(WindowData *)glfwGetWindowUserPointer(window);
          MouseScrolledEvent event((float)xoffset, (float)yoffset);
          data.EventCallback(event);
        });

    glfwSetCursorPosCallback(
        m_window, [](GLFWwindow *window, double xpos, double ypos) {
          WindowData &data = *(WindowData *)glfwGetWindowUserPointer(window);
          MouseMovedEvent event((float)xpos, (float)ypos);
          data.EventCallback(event);
        });
  }

  void UnixWindow::Shutdown() { glfwDestroyWindow(m_window); }

  void UnixWindow::SetVSync(bool enabled) {
    if (enabled)
      glfwSwapInterval(1);
    else
      glfwSwapInterval(0);

    m_data.VSync = enabled;
  }

  bool UnixWindow::IsVSync() const { return m_data.VSync; }

} // namespace RSIM
