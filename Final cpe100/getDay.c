#include "getDay.h"
char* getDay() {
  time_t timer;
  static char buffer[26];
  struct tm* tm_info;

  timer = time(NULL);
  tm_info = localtime(&timer);

  strftime(buffer, 26, "%d", tm_info);
  return buffer;
}
