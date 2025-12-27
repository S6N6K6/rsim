#include <iostream>

#include "RSIM.h"

class  RSIM_API Sandbox : public RSIM::Application {
    public:
  Sandbox() {}
  ~Sandbox() {}
  void Run(){
    std::cout << "Hello from client!" << std::endl;
  }
};

RSIM::Application* RSIM::CreateApplication(){
  return new Sandbox();
}
