#include "Application.h"

namespace RSIM {
  Application::Application(){}
  Application::~Application(){
  std::cout << "Ended application!" << std::endl;
}
  void Application::Run(){
  std::cout << "Hello World" << std::endl;
  int i = 0;
  for (i = 0; i < 10; i++){
    std::cout << "[" << i << "]" << std::endl;
  }
}
}
