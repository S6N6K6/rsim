#pragma once

#include "Core.h"
#include "Events/Event.h"
#include "Log.h"

struct GLFWwindow {
}; // Forward Declare a GLFWwindow struct to be able to access it;

namespace RSIM {

  struct WindowsProps {
      std::string Title;
      unsigned int Width;
      unsigned int Height;

      WindowsProps(const std::string &title = "RSIM Engine",
                   unsigned int width = 1280, unsigned int height = 720)
          : Title(title), Width(width), Height(height) {}
  };

  // Interface representing a desktop system based Window
  class RSIM_API Window {
    public:
      using EventCallbackFn = std::function<void(Event &)>;

      virtual ~Window() {}

      virtual void OnUpdate() = 0;

      virtual unsigned int GetWidth() const = 0;
      virtual unsigned int GetHeight() const = 0;

      // Window attributes
      virtual void SetEventCallback(const EventCallbackFn &callback) = 0;
      virtual void SetVSync(bool enabled) = 0;
      virtual bool IsVSync() const = 0;
      virtual GLFWwindow *GetNativeWindow() const = 0;

      static Window *Create(const WindowsProps &props = WindowsProps());

    protected:
      GLFWwindow *m_nativeWindow;
  };

} // namespace RSIM
