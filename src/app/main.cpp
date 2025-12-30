#include <iostream>

// #include "ImGui/ImGuiLayer.h"
#include "RSIM.h"
class ExampleLayer : public RSIM::Layer {
  public:
    ExampleLayer()
      :RSIM::Layer("Example") {}

  void OnUpdate() override {
    RSIM_INFO("ExampleLayer::OnUpdate()");
  }

  void OnEvent(RSIM::Event& e) override {
    RSIM_TRACE("{0}", static_cast<RSIM::Event&>(e));
  }
};

class RSIM_API Sandbox : public RSIM::Application {
  public:
    Sandbox() {
    // PushLayer(new ExampleLayer());
    PushOverlay(new RSIM::ImGuiLayer());
 }
    ~Sandbox() {}
};

RSIM::Application *RSIM::CreateApplication() { return new Sandbox(); }
