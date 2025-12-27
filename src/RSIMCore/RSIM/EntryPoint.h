#pragma once

#include "Application.h"
#include "Core.h"

extern RSIM::Application* RSIM::CreateApplication();

int main(int argc, char** argv){

  auto app = RSIM::CreateApplication();
  app->Run();
  delete app;
  return 0;
}
