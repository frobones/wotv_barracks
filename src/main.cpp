
//!
//! @file main.cpp
//!
//! @author https://github.com/frobones
//! @date 4/5/20
//!

#include "database/dbo.hpp"
#include "frontend/gui.hpp"

using namespace Wt;

int main(int argc, char **argv) {
  /*
   * Your main method may set up some shared resources, but should then
   * start the server application (FastCGI or httpd) that starts listening
   * for requests, and handles all of the application life cycles.
   *
   * The last argument to WRun specifies the function that will instantiate
   * new application objects. That function is executed when a new user surfs
   * to the Wt application, and after the library has negotiated browser
   * support. The function should return a newly instantiated application
   * object.
   */
  return WRun(argc, argv, [](const WEnvironment &env) {

    /*
     * You could read information from the environment to decide whether
     * the user has permission to start a new application
     */
    return std::make_unique<BarracksApplication>(env);
  });
}