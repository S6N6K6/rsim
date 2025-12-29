#pragma once

#include "Core.h"
#include "Layer.h"

#include <imgui.h>
#include <imgui_impl_opengl3.h>
#include <imgui_impl_glfw.h>

namespace RSIM {

  class RSIM_API ImGuiLayer : public Layer {

    public:
      ImGuiLayer();
      ~ImGuiLayer();

      void OnAttach();
      void OnDetach();
      void OnUpdate();
      void OnEvent(Event &event);

    private:
    float m_time = 0.0f;
  };

} // namespace RSIM
