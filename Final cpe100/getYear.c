#include "getYear.h"
char* getYear() {
  time_t timer;
  static char buffer[26];
  struct tm* tm_info;

  timer = time(NULL);
  tm_info = localtime(&timer);

  strftime(buffer, 26, "%Y", tm_info);
  return buffer;
}
