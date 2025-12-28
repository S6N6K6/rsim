#include "Application.h"
#include "Events/ApplicationEvent.h"
#include "Events/Event.h"
#include "Events/MouseEvent.h"
#include "Log.h"

namespace RSIM {
  Application::Application() {}
  Application::~Application() {
    std::cout << "Ended application!" << std::endl;
  }
  void Application::Run() {
    WindowResizeEvent e(1200, 720);
    RSIM_TRACE(static_cast<const Event &>(e));
    RSIM_INFO(e.IsInCategory(EventCategory::EventCategoryApplication));
    RSIM_CORE_ERROR(e.GetName());

    while (true)
      ;
  }
} // namespace RSIM
