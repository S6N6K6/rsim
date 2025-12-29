#include "ImGuiLayer.h"
#include "Application.h"
#include "imgui.h"
#include <GLFW/glfw3.h>

namespace RSIM {

  ImGuiLayer::ImGuiLayer() : Layer("ImGuiLayer") {}

  ImGuiLayer::~ImGuiLayer() {}

  void ImGuiLayer::OnAttach() {

    ImGui::CreateContext();
    ImGuiIO &io = ImGui::GetIO();
    ImGui::StyleColorsDark();
    io.BackendFlags |= ImGuiBackendFlags_HasMouseCursors;
    io.BackendFlags |= ImGuiBackendFlags_HasSetMousePos;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;

    ImGui_ImplOpenGL3_Init("#version 410");
  }

  void ImGuiLayer::OnDetach() {}

  void ImGuiLayer::OnUpdate() {
    ImGuiIO &io = ImGui::GetIO();
    Application &app = Application::Get();
    io.DisplaySize =
        ImVec2(app.GetWindow().GetWidth(), app.GetWindow().GetHeight());

    float time = (float)glfwGetTime();
    io.DeltaTime = m_time > 0.0 ? (time - m_time) : (1.0f / 60.0f);
    m_time = time;

    ImGui_ImplOpenGL3_NewFrame();
    ImGui::NewFrame();

    static bool show = true;
    ImGui::ShowDemoWindow(&show);

    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
  }

  void ImGuiLayer::OnEvent(Event &event) {}

} // namespace RSIM
