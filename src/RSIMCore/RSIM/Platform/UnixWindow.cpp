#include "UnixWindow.h"
#include "Core.h"
#include "GLFW/glfw3.h"
#include "Window.h"

namespace RSIM {

  static bool s_GLFWInitialized = false;

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
      s_GLFWInitialized = true;
    }
    m_window = glfwCreateWindow((int)m_data.Width, (int)m_data.Height,
                                m_data.Title.c_str(), nullptr, nullptr);
    glfwMakeContextCurrent(m_window);
    glfwSetWindowUserPointer(m_window, &m_data);
    SetVSync(true);
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
