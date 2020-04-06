
//!
//! @file main.cpp
//!
//! @author https://github.com/frobones
//! @date 4/5/20
//!

#include <getopt.h>
#include "database/dbo.hpp"
#include "frontend/gui.hpp"

using namespace Wt;

const char* get_jsonfile(int argc, char **argv) {
  optind = 1;

  const char* const short_opts = "f:";
  constexpr option long_options[] = {
      {"jsonfile", required_argument, 0, 'f'},
      {"docroot", no_argument, 0, 'a'},
      {"http-listen", no_argument, 0, 'a'},
      {0,0,0,0}
  };

  while (true) {
    fprintf(stderr, "OPTIND=%d\n", optind);
    const auto opt = getopt_long(argc, argv, "f:", long_options, nullptr);

    if (-1 == opt)
      break;

    switch (opt) {
      case 'f':
        return optarg;
    }
  }
  return "";
}

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
  return WRun(argc, argv, [=](const WEnvironment &env) {
    /*
     * You could read information from the environment to decide whether
     * the user has permission to start a new application
     */
    return std::make_unique<BarracksApplication>(env, get_jsonfile(argc, argv));
  });
}