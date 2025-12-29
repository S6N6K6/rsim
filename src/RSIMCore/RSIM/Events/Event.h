#pragma once

#include "Core.h"

#include <functional>
#include <string>
#include <type_traits>
#include <utility>

namespace RSIM {

  // Blocking Events as of now

  // clang-format off
  enum class EventType{
    None = 0,
    WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
    AppTick, AppUpdate, AppRender,
    KeyPressed, KeyReleased,
    MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
  };

  // clang-format on
  enum class EventCategory {
    None = 0,
    EventCategoryApplication = bit(0),
    EventCategoryInput = bit(1),
    EventCategoryKeyboard = bit(2),
    EventCategoryMouse = bit(3),
    EventCategoryMouseButton = bit(4)
  };

  // Allow for bitmasking operators good for the EventCategory enum
  template <typename E>
  struct enable_bitmask_operators : std::false_type {};

  template <>
  struct enable_bitmask_operators<EventCategory> : std::true_type {};

  // Define the OR operator
  template <typename E>
  constexpr std::enable_if_t<enable_bitmask_operators<E>::value, E>
  operator|(E lhs, E rhs) {
    return static_cast<E>(std::to_underlying(lhs) | std::to_underlying(rhs));
  }
  // Define the AND operator
  template <typename E>
  constexpr std::enable_if_t<enable_bitmask_operators<E>::value, E>
  operator&(E lhs, E rhs) {
    return static_cast<E>(std::to_underlying(lhs) & std::to_underlying(rhs));
  }

  // helper macros

#define EVENT_CLASS_TYPE(type)                                                 \
  static EventType GetStaticType() { return EventType::type; }                 \
  virtual EventType GetEventType() const override { return GetStaticType(); }  \
  virtual const char *GetName() const override { return #type; }

#define EVENT_CLASS_CATEGORY(category)                                         \
  virtual EventCategory GetCategoryFlag() const override { return category; }

  // Main Event Class which is the parent of all events
  class RSIM_API Event {

      friend class EventDispatcher;

    public:
      virtual EventType GetEventType() const = 0;
      virtual const char *GetName() const = 0;
      virtual EventCategory GetCategoryFlag() const = 0;
      virtual std::string ToString() const { return GetName(); }

      inline bool IsInCategory(EventCategory category) {
        return static_cast<bool>(GetCategoryFlag() & category);
      }

      inline bool IsHandled() const { return m_Handled; }

    protected:
      bool m_Handled = false; // Decides whether the event was handled or not
  };

  class RSIM_API EventDispatcher {

      template <typename T>
      using EventFn = std::function<bool(T &)>;

    public:
      EventDispatcher(Event &event) : m_Event(event) {}

      template <typename T>
      bool Dispatch(EventFn<T> func) {
        if (m_Event.GetEventType() == T::GetStaticType()) {
          m_Event.m_Handled = func(*(T *)&m_Event);
          return true;
        }
        return false;
      }

    private:
      Event &m_Event;
  };

  inline std::ostream &operator<<(std::ostream &os, const Event &e) {
    return os << e.ToString();
  }
} // namespace RSIM
