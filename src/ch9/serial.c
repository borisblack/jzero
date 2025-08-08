#include "serial.h"

static int _id;

int serial_GetId() {
  return ++_id;
}
