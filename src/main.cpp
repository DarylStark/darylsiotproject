#include <dip/iot_app.h>

class LEDStrips : public dip::IOTApp
{
private:
  uint32_t __counter;

public:
  // Constructors
  LEDStrips() : IOTApp("Testproject", {0, 0, 0, "Testing"}), __counter(0) {}

  void setup()
  {
    // Begin the Serial
    Serial.begin(115200);

    // Start the setup from IOTApp
    IOTApp::_setup();

    // Set default values
    _set_default_delay(1000);
  }

  void loop()
  {
    // Start the loop from IOTApp
    std::cout << "Looping #" << __counter++ << std::endl;
    IOTApp::_loop();
  }
} my_app;

void setup()
{
  my_app.setup();
}

void loop()
{
  my_app.loop();
}