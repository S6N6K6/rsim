#pragma once

#include "Window.h"

// #include <glad/glad.h>

struct GLFWwindow {};

namespace RSIM {

  class UnixWindow : public Window {
    public:
      UnixWindow(const WindowsProps &props);
      virtual ~UnixWindow();

      void OnUpdate() override;

      inline unsigned int GetWidth() const override { return m_data.Width; }
      inline unsigned int GetHeight() const override { return m_data.Height; }

      // Window Attributes
      inline void SetEventCallback(const EventCallbackFn &callback) override {
        m_data.EventCallback = callback;
      }
      void SetVSync(bool enabled) override;
      bool IsVSync() const override;

    private:
      virtual void Init(const WindowsProps &props);
      virtual void Shutdown();

    private:
      GLFWwindow *m_window;
      struct WindowData {
          std::string Title;
          unsigned int Width, Height;
          bool VSync;

          EventCallbackFn EventCallback;
      };
      WindowData m_data;
  };

} // namespace RSIM
