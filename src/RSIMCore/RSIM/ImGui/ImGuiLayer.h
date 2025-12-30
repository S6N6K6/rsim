#pragma once

#include "Core.h"
#include "Events/ApplicationEvent.h"
#include "Events/KeyEvent.h"
#include "Events/MouseEvent.h"
#include "Layer.h"

#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

#define RSIM_KEY_SPACE ImGuiKey_Space
#define RSIM_KEY_APOSTROPHE ImGuiKey_Apostrophe // '
#define RSIM_KEY_COMMA ImGuiKey_Comma           /* , */
#define RSIM_KEY_MINUS ImGuiKey_Minus           /* - */
#define RSIM_KEY_PERIOD ImGuiKey_Period         /* . */
#define RSIM_KEY_SLASH ImGuiKey_Slash           /* / */
#define RSIM_KEY_0 ImGuiKey_0
#define RSIM_KEY_1 ImGuiKey_1
#define RSIM_KEY_2 ImGuiKey_2
#define RSIM_KEY_3 ImGuiKey_3
#define RSIM_KEY_4 ImGuiKey_4
#define RSIM_KEY_5 ImGuiKey_5
#define RSIM_KEY_6 ImGuiKey_6
#define RSIM_KEY_7 ImGuiKey_7
#define RSIM_KEY_8 ImGuiKey_8
#define RSIM_KEY_9 ImGuiKey_9
#define RSIM_KEY_SEMICOLON ImGuiKey_Semicolon /* ; */
#define RSIM_KEY_EQUAL ImGuiKey_Equal         /* = */
#define RSIM_KEY_A ImGuiKey_A
#define RSIM_KEY_B ImGuiKey_B
#define RSIM_KEY_C ImGuiKey_C
#define RSIM_KEY_D ImGuiKey_D
#define RSIM_KEY_E ImGuiKey_E
#define RSIM_KEY_F ImGuiKey_F
#define RSIM_KEY_G ImGuiKey_G
#define RSIM_KEY_H ImGuiKey_H
#define RSIM_KEY_I ImGuiKey_I
#define RSIM_KEY_J ImGuiKey_J
#define RSIM_KEY_K ImGuiKey_K
#define RSIM_KEY_L ImGuiKey_L
#define RSIM_KEY_M ImGuiKey_M
#define RSIM_KEY_N ImGuiKey_N
#define RSIM_KEY_O ImGuiKey_O
#define RSIM_KEY_P ImGuiKey_P
#define RSIM_KEY_Q ImGuiKey_Q
#define RSIM_KEY_R ImGuiKey_R
#define RSIM_KEY_S ImGuiKey_S
#define RSIM_KEY_T ImGuiKey_T
#define RSIM_KEY_U ImGuiKey_U
#define RSIM_KEY_V ImGuiKey_V
#define RSIM_KEY_W ImGuiKey_W
#define RSIM_KEY_X ImGuiKey_X
#define RSIM_KEY_Y ImGuiKey_Y
#define RSIM_KEY_Z ImGuiKey_Z
#define RSIM_KEY_LEFT_BRACKET ImGuiKey_LeftBracket   /* [ */
#define RSIM_KEY_BACKSLASH ImGuiKey_Backslash        /* \ */
#define RSIM_KEY_RIGHT_BRACKET ImGuiKey_RightBracket /* ] */
#define RSIM_KEY_GRAVE_ACCENT ImGuiKey_GraveAccent   /* ` */

/* Function keys */
#define RSIM_KEY_ESCAPE ImGuiKey_Escape
#define RSIM_KEY_ENTER ImGuiKey_Enter
#define RSIM_KEY_TAB ImGuiKey_Tab
#define RSIM_KEY_BACKSPACE ImGuiKey_Backspace
#define RSIM_KEY_INSERT ImGuiKey_Insert
#define RSIM_KEY_DELETE ImGuiKey_Delete
#define RSIM_KEY_RIGHT ImGuiKey_RightArrow
#define RSIM_KEY_LEFT ImGuiKey_LeftArrow
#define RSIM_KEY_DOWN ImGuiKey_DownArrow
#define RSIM_KEY_UP ImGuiKey_UpArrow
#define RSIM_KEY_PAGE_UP ImGuiKey_PageUp
#define RSIM_KEY_PAGE_DOWN ImGuiKey_PageDown
#define RSIM_KEY_HOME ImGuiKey_Home
#define RSIM_KEY_END ImGuiKey_End
#define RSIM_KEY_CAPS_LOCK ImGuiKey_CapsLock
#define RSIM_KEY_SCROLL_LOCK ImGuiKey_ScrollLock
#define RSIM_KEY_NUM_LOCK ImGuiKey_NumLock
#define RSIM_KEY_PRINT_SCREEN ImGuiKey_PrintScreen
#define RSIM_KEY_PAUSE ImGuiKey_Pause
#define RSIM_KEY_F1 ImGuiKey_F1
#define RSIM_KEY_F2 ImGuiKey_F2
#define RSIM_KEY_F3 ImGuiKey_F3
#define RSIM_KEY_F4 ImGuiKey_F4
#define RSIM_KEY_F5 ImGuiKey_F5
#define RSIM_KEY_F6 ImGuiKey_F6
#define RSIM_KEY_F7 ImGuiKey_F7
#define RSIM_KEY_F8 ImGuiKey_F8
#define RSIM_KEY_F9 ImGuiKey_F9
#define RSIM_KEY_F10 ImGuiKey_F10
#define RSIM_KEY_F11 ImGuiKey_F11
#define RSIM_KEY_F12 ImGuiKey_F12
#define RSIM_KEY_F13 ImGuiKey_F13
#define RSIM_KEY_F14 ImGuiKey_F14
#define RSIM_KEY_F15 ImGuiKey_F15
#define RSIM_KEY_F16 ImGuiKey_F16
#define RSIM_KEY_F17 ImGuiKey_F17
#define RSIM_KEY_F18 ImGuiKey_F18
#define RSIM_KEY_F19 ImGuiKey_F19
#define RSIM_KEY_F20 ImGuiKey_F20
#define RSIM_KEY_F21 ImGuiKey_F21
#define RSIM_KEY_F22 ImGuiKey_F22
#define RSIM_KEY_F23 ImGuiKey_F23
#define RSIM_KEY_F24 ImGuiKey_F24
#define RSIM_KEY_KP_0 ImGuiKey_Keypad0
#define RSIM_KEY_KP_1 ImGuiKey_Keypad1
#define RSIM_KEY_KP_2 ImGuiKey_Keypad2
#define RSIM_KEY_KP_3 ImGuiKey_Keypad3
#define RSIM_KEY_KP_4 ImGuiKey_Keypad4
#define RSIM_KEY_KP_5 ImGuiKey_Keypad5
#define RSIM_KEY_KP_6 ImGuiKey_Keypad6
#define RSIM_KEY_KP_7 ImGuiKey_Keypad7
#define RSIM_KEY_KP_8 ImGuiKey_Keypad8
#define RSIM_KEY_KP_9 ImGuiKey_Keypad9
#define RSIM_KEY_KP_DECIMAL ImGuiKey_KeypadDecimal
#define RSIM_KEY_KP_DIVIDE ImGuiKey_KeypadDivide
#define RSIM_KEY_KP_MULTIPLY ImGuiKey_KeypadMultiply
#define RSIM_KEY_KP_SUBTRACT ImGuiKey_KeypadSubtract
#define RSIM_KEY_KP_ADD ImGuiKey_KeypadAdd
#define RSIM_KEY_KP_ENTER ImGuiKey_KeypadEnter
#define RSIM_KEY_KP_EQUAL ImGuiKey_KeypadEqual
#define RSIM_KEY_LEFT_SHIFT ImGuiKey_LeftShift
#define RSIM_KEY_LEFT_CONTROL ImGuiKey_LeftCtrl
#define RSIM_KEY_LEFT_ALT ImGuiKey_LeftAlt
#define RSIM_KEY_LEFT_SUPER ImGuiKey_LeftSuper
#define RSIM_KEY_RIGHT_SHIFT ImGuiKey_RightShift
#define RSIM_KEY_RIGHT_CONTROL ImGuiKey_RightCtrl
#define RSIM_KEY_RIGHT_ALT ImGuiKey_RightAlt
#define RSIM_KEY_RIGHT_SUPER ImGuiKey_RightSuper
#define RSIM_KEY_MENU ImGuiKey_Menu

#include "GLFW/glfw3.h"

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
      bool OnMouseButtonPressedEvent(MouseButtonPressedEvent &e);
      bool OnMouseButtonReleasedEvent(MouseButtonReleasedEvent &e);
      bool OnMouseMovedEvent(MouseMovedEvent &e);
      bool OnMouseScrolledEvent(MouseScrolledEvent &e);
      bool OnKeyPressedEvent(KeyPressedEvent &e);
      bool OnKeyReleasedEvent(KeyReleasedEvent &e);
      bool OnKeyTypedEvent(KeyTypedEvent &e);
      bool OnWindowResizeEvent(WindowResizeEvent &e);

    private:
      float m_time = 0.0f;
  };

} // namespace RSIM
