#include "ImGuiLayer.h"
#include "Application.h"
#include "Core.h"
#include "Events/Event.h"
#include "Events/KeyEvent.h"
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include <GLFW/glfw3.h>
#include <glad/glad.h>

std::unordered_map<int, ImGuiKey> glfwKeyToImGuiKey = {
    {GLFW_KEY_SPACE, RSIM_KEY_SPACE},
    {GLFW_KEY_APOSTROPHE, RSIM_KEY_APOSTROPHE},
    {GLFW_KEY_COMMA, RSIM_KEY_COMMA},
    {GLFW_KEY_MINUS, RSIM_KEY_MINUS},
    {GLFW_KEY_PERIOD, RSIM_KEY_PERIOD},
    {GLFW_KEY_SLASH, RSIM_KEY_SLASH},
    {GLFW_KEY_0, RSIM_KEY_0},
    {GLFW_KEY_1, RSIM_KEY_1},
    {GLFW_KEY_2, RSIM_KEY_2},
    {GLFW_KEY_3, RSIM_KEY_3},
    {GLFW_KEY_4, RSIM_KEY_4},
    {GLFW_KEY_5, RSIM_KEY_5},
    {GLFW_KEY_6, RSIM_KEY_6},
    {GLFW_KEY_7, RSIM_KEY_7},
    {GLFW_KEY_8, RSIM_KEY_8},
    {GLFW_KEY_9, RSIM_KEY_9},
    {GLFW_KEY_SEMICOLON, RSIM_KEY_SEMICOLON},
    {GLFW_KEY_EQUAL, RSIM_KEY_EQUAL},
    {GLFW_KEY_A, RSIM_KEY_A},
    {GLFW_KEY_B, RSIM_KEY_B},
    {GLFW_KEY_C, RSIM_KEY_C},
    {GLFW_KEY_D, RSIM_KEY_D},
    {GLFW_KEY_E, RSIM_KEY_E},
    {GLFW_KEY_F, RSIM_KEY_F},
    {GLFW_KEY_G, RSIM_KEY_G},
    {GLFW_KEY_H, RSIM_KEY_H},
    {GLFW_KEY_I, RSIM_KEY_I},
    {GLFW_KEY_J, RSIM_KEY_J},
    {GLFW_KEY_K, RSIM_KEY_K},
    {GLFW_KEY_L, RSIM_KEY_L},
    {GLFW_KEY_M, RSIM_KEY_M},
    {GLFW_KEY_N, RSIM_KEY_N},
    {GLFW_KEY_O, RSIM_KEY_O},
    {GLFW_KEY_P, RSIM_KEY_P},
    {GLFW_KEY_Q, RSIM_KEY_Q},
    {GLFW_KEY_R, RSIM_KEY_R},
    {GLFW_KEY_S, RSIM_KEY_S},
    {GLFW_KEY_T, RSIM_KEY_T},
    {GLFW_KEY_U, RSIM_KEY_U},
    {GLFW_KEY_V, RSIM_KEY_V},
    {GLFW_KEY_W, RSIM_KEY_W},
    {GLFW_KEY_X, RSIM_KEY_X},
    {GLFW_KEY_Y, RSIM_KEY_Y},
    {GLFW_KEY_Z, RSIM_KEY_Z},
    {GLFW_KEY_LEFT_BRACKET, RSIM_KEY_LEFT_BRACKET},
    {GLFW_KEY_BACKSLASH, RSIM_KEY_BACKSLASH},
    {GLFW_KEY_RIGHT_BRACKET, RSIM_KEY_RIGHT_BRACKET},
    {GLFW_KEY_GRAVE_ACCENT, RSIM_KEY_GRAVE_ACCENT},

    /* Function keys */
    {GLFW_KEY_ESCAPE, RSIM_KEY_ESCAPE},
    {GLFW_KEY_ENTER, RSIM_KEY_ENTER},
    {GLFW_KEY_TAB, RSIM_KEY_TAB},
    {GLFW_KEY_BACKSPACE, RSIM_KEY_BACKSPACE},
    {GLFW_KEY_INSERT, RSIM_KEY_INSERT},
    {GLFW_KEY_DELETE, RSIM_KEY_DELETE},
    {GLFW_KEY_RIGHT, RSIM_KEY_RIGHT},
    {GLFW_KEY_LEFT, RSIM_KEY_LEFT},
    {GLFW_KEY_DOWN, RSIM_KEY_DOWN},
    {GLFW_KEY_UP, RSIM_KEY_UP},
    {GLFW_KEY_PAGE_UP, RSIM_KEY_PAGE_UP},
    {GLFW_KEY_PAGE_DOWN, RSIM_KEY_PAGE_DOWN},
    {GLFW_KEY_HOME, RSIM_KEY_HOME},
    {GLFW_KEY_END, RSIM_KEY_END},
    {GLFW_KEY_CAPS_LOCK, RSIM_KEY_CAPS_LOCK},
    {GLFW_KEY_SCROLL_LOCK, RSIM_KEY_SCROLL_LOCK},
    {GLFW_KEY_NUM_LOCK, RSIM_KEY_NUM_LOCK},
    {GLFW_KEY_PRINT_SCREEN, RSIM_KEY_PRINT_SCREEN},
    {GLFW_KEY_PAUSE, RSIM_KEY_PAUSE},
    {GLFW_KEY_F1, RSIM_KEY_F1},
    {GLFW_KEY_F2, RSIM_KEY_F2},
    {GLFW_KEY_F3, RSIM_KEY_F3},
    {GLFW_KEY_F4, RSIM_KEY_F4},
    {GLFW_KEY_F5, RSIM_KEY_F5},
    {GLFW_KEY_F6, RSIM_KEY_F6},
    {GLFW_KEY_F7, RSIM_KEY_F7},
    {GLFW_KEY_F8, RSIM_KEY_F8},
    {GLFW_KEY_F9, RSIM_KEY_F9},
    {GLFW_KEY_F10, RSIM_KEY_F10},
    {GLFW_KEY_F11, RSIM_KEY_F11},
    {GLFW_KEY_F12, RSIM_KEY_F12},
    {GLFW_KEY_F13, RSIM_KEY_F13},
    {GLFW_KEY_F14, RSIM_KEY_F14},
    {GLFW_KEY_F15, RSIM_KEY_F15},
    {GLFW_KEY_F16, RSIM_KEY_F16},
    {GLFW_KEY_F17, RSIM_KEY_F17},
    {GLFW_KEY_F18, RSIM_KEY_F18},
    {GLFW_KEY_F19, RSIM_KEY_F19},
    {GLFW_KEY_F20, RSIM_KEY_F20},
    {GLFW_KEY_F21, RSIM_KEY_F21},
    {GLFW_KEY_F22, RSIM_KEY_F22},
    {GLFW_KEY_F23, RSIM_KEY_F23},
    {GLFW_KEY_F24, RSIM_KEY_F24},
    {GLFW_KEY_KP_0, RSIM_KEY_KP_0},
    {GLFW_KEY_KP_1, RSIM_KEY_KP_1},
    {GLFW_KEY_KP_2, RSIM_KEY_KP_2},
    {GLFW_KEY_KP_3, RSIM_KEY_KP_3},
    {GLFW_KEY_KP_4, RSIM_KEY_KP_4},
    {GLFW_KEY_KP_5, RSIM_KEY_KP_5},
    {GLFW_KEY_KP_6, RSIM_KEY_KP_6},
    {GLFW_KEY_KP_7, RSIM_KEY_KP_7},
    {GLFW_KEY_KP_8, RSIM_KEY_KP_8},
    {GLFW_KEY_KP_9, RSIM_KEY_KP_9},
    {GLFW_KEY_KP_DECIMAL, RSIM_KEY_KP_DECIMAL},
    {GLFW_KEY_KP_DIVIDE, RSIM_KEY_KP_DIVIDE},
    {GLFW_KEY_KP_MULTIPLY, RSIM_KEY_KP_MULTIPLY},
    {GLFW_KEY_KP_SUBTRACT, RSIM_KEY_KP_SUBTRACT},
    {GLFW_KEY_KP_ADD, RSIM_KEY_KP_ADD},
    {GLFW_KEY_KP_ENTER, RSIM_KEY_KP_ENTER},
    {GLFW_KEY_KP_EQUAL, RSIM_KEY_KP_EQUAL},
    {GLFW_KEY_LEFT_SHIFT, RSIM_KEY_LEFT_SHIFT},
    {GLFW_KEY_LEFT_CONTROL, RSIM_KEY_LEFT_CONTROL},
    {GLFW_KEY_LEFT_ALT, RSIM_KEY_LEFT_ALT},
    {GLFW_KEY_LEFT_SUPER, RSIM_KEY_LEFT_SUPER},
    {GLFW_KEY_RIGHT_SHIFT, RSIM_KEY_RIGHT_SHIFT},
    {GLFW_KEY_RIGHT_CONTROL, RSIM_KEY_RIGHT_CONTROL},
    {GLFW_KEY_RIGHT_ALT, RSIM_KEY_RIGHT_ALT},
    {GLFW_KEY_RIGHT_SUPER, RSIM_KEY_RIGHT_SUPER},
    {GLFW_KEY_MENU, RSIM_KEY_MENU},
};
namespace RSIM {

  ImGuiLayer::ImGuiLayer() : Layer("ImGuiLayer") {}

  ImGuiLayer::~ImGuiLayer() {}

  void ImGuiLayer::OnAttach() {
    GLFW_KEY_TAB;

    ImGui::CreateContext();
    ImGuiIO &io = ImGui::GetIO();
    ImGui::StyleColorsDark();
    io.BackendFlags |= ImGuiBackendFlags_HasMouseCursors;
    io.BackendFlags |= ImGuiBackendFlags_HasSetMousePos;

    // TEMPORARY

    Application &app = Application::Get();
    ImGui_ImplGlfw_InitForOpenGL(app.GetWindow().GetNativeWindow(), false);
    ImGui_ImplOpenGL3_Init("#version 410");
  }

  void ImGuiLayer::OnDetach() {
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
  }

  void ImGuiLayer::OnUpdate() {
    ImGuiIO &io = ImGui::GetIO();
    Application &app = Application::Get();
    io.DisplaySize =
        ImVec2(app.GetWindow().GetWidth(), app.GetWindow().GetHeight());

    float time = (float)glfwGetTime();
    io.DeltaTime = m_time > 0.0 ? (time - m_time) : (1.0f / 60.0f);
    m_time = time;

    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();

    static bool show = true;
    ImGui::ShowDemoWindow(&show);

    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
  }

  void ImGuiLayer::OnEvent(Event &event) {
    EventDispatcher dispatcher(event);
    dispatcher.Dispatch<MouseButtonPressedEvent>(
        RSIM_BIND_FN(ImGuiLayer::OnMouseButtonPressedEvent));
    dispatcher.Dispatch<MouseButtonReleasedEvent>(
        RSIM_BIND_FN(ImGuiLayer::OnMouseButtonReleasedEvent));
    dispatcher.Dispatch<MouseMovedEvent>(
        RSIM_BIND_FN(ImGuiLayer::OnMouseMovedEvent));
    dispatcher.Dispatch<MouseScrolledEvent>(
        RSIM_BIND_FN(ImGuiLayer::OnMouseScrolledEvent));
    dispatcher.Dispatch<KeyPressedEvent>(
        RSIM_BIND_FN(ImGuiLayer::OnKeyPressedEvent));
    dispatcher.Dispatch<KeyReleasedEvent>(
        RSIM_BIND_FN(ImGuiLayer::OnKeyReleasedEvent));
    dispatcher.Dispatch<KeyTypedEvent>(
        RSIM_BIND_FN(ImGuiLayer::OnKeyTypedEvent));
    dispatcher.Dispatch<WindowResizeEvent>(
        RSIM_BIND_FN(ImGuiLayer::OnWindowResizeEvent));
  }

  bool ImGuiLayer::OnMouseButtonPressedEvent(MouseButtonPressedEvent &e) {

    ImGuiIO &io = ImGui::GetIO();
    io.AddMouseButtonEvent(e.GetMouseButton(), true);
    return false;
  }
  bool ImGuiLayer::OnMouseButtonReleasedEvent(MouseButtonReleasedEvent &e) {
    ImGuiIO &io = ImGui::GetIO();
    io.AddMouseButtonEvent(e.GetMouseButton(), false);

    return false;
  }
  bool ImGuiLayer::OnMouseMovedEvent(MouseMovedEvent &e) {
    ImGuiIO &io = ImGui::GetIO();
    io.AddMousePosEvent(e.GetX(), e.GetY());

    return false;
  }
  bool ImGuiLayer::OnMouseScrolledEvent(MouseScrolledEvent &e) {

    ImGuiIO &io = ImGui::GetIO();
    io.AddMouseWheelEvent(e.GetXOffset(), e.GetYOffset());

    return false;
  }
  bool ImGuiLayer::OnKeyPressedEvent(KeyPressedEvent &e) {
    ImGuiIO &io = ImGui::GetIO();
    io.AddKeyEvent(glfwKeyToImGuiKey[e.GetKeyCode()], true);

        return false;
  }
  bool ImGuiLayer::OnKeyReleasedEvent(KeyReleasedEvent &e) {
    ImGuiIO &io = ImGui::GetIO();
    io.AddKeyEvent(glfwKeyToImGuiKey[e.GetKeyCode()], false);

    return false;
  }

  bool ImGuiLayer::OnKeyTypedEvent(KeyTypedEvent &e) {
    ImGuiIO &io = ImGui::GetIO();
    io.AddInputCharacter((unsigned int)e.GetKeyCode());

    return false;
  }

  bool ImGuiLayer::OnWindowResizeEvent(WindowResizeEvent &e) {
    ImGuiIO &io = ImGui::GetIO();

    io.DisplaySize = ImVec2(e.GetWidth(), e.GetHeight());
    io.DisplayFramebufferScale = ImVec2(1.0f, 1.0f);

    glViewport(0, 0, e.GetWidth(), e.GetHeight());
    return false;
  }

} // namespace RSIM
