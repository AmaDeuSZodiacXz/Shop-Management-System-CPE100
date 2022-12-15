#include "getDate.h"
char* getDate() {
  time_t timer;
  static char buffer[26];
  struct tm* tm_info;

  timer = time(NULL);
  tm_info = localtime(&timer);

  strftime(buffer, 26, "%d/%m/%Y", tm_info);
  return buffer;
}
