#pragma once

#include "Application.h"
#include "Core.h"
#include "Log.h"

extern RSIM::Application* RSIM::CreateApplication();

int main(int argc, char** argv){

  RSIM::Log::Init();
  RSIM_CORE_WARN("Initialized Log from Core");
  RSIM_INFO("Initialized Log from App");
  int a = 55;
  RSIM_TRACE("Variable: {0}", a);

  auto app = RSIM::CreateApplication();
  app->Run();
  delete app;
  return 0;
}
