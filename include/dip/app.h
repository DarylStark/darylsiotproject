#ifndef __DIP_H__
#define __DIP_H__

/*
 Main class for Daryl's IOT Project, named App. Should be used as base class
 for all other projects.
*/

#include <Arduino.h>
#include <iostream>
#include <string>
#include "version.h"

#define VERSION_MAJOR 0
#define VERSION_MINOR 0
#define VERSION_REVISION 0
#define VERSION_NAME "Initial development"
#define DEFAULT_DELAY 1000

namespace dip
{
    class App
    {
    private:
        // DIP information
        Version __dip_version = {
            VERSION_MAJOR,
            VERSION_MINOR,
            VERSION_REVISION,
            VERSION_NAME};

        // App information
        std::string __app_name;
        Version __app_version;

        // App configuration
        uint16_t __default_delay;

    protected:
        // Helper functions for subclasses
        void _setup()
        {
            // First, we print a header
            std::cout << std::endl;
            std::cout << std::endl;
            std::cout << std::endl;

            std::cout << "DIP version "
                      << __dip_version.major << "."
                      << __dip_version.minor << "."
                      << __dip_version.revision
                      << " (" << __dip_version.name << ")" << std::endl;
            std::cout << __app_name << " version "
                      << __app_version.major << "."
                      << __app_version.minor << "."
                      << __app_version.revision
                      << " (" << __app_version.name << ")" << std::endl;

            for (uint8_t i = 0; i < 80; i++)
            {
                std::cout << '-';
            }
            std::cout << std::endl;
            std::cout << "Initializing default values" << std::endl;

            // Set default values
            __default_delay = DEFAULT_DELAY;

            // Done! The app can start doing his work
            std::cout << "DIP is done" << std::endl;
        }

        void _loop(uint16_t end_delay = 0)
        {
            // Start the delay
            if (end_delay == 0)
            {
                end_delay = __default_delay;
            }
            delay(end_delay);
        }

        // Default delay modifiers
        void _set_default_delay(uint16_t default_delay)
        {
            __default_delay = default_delay;
        }

        uint16_t _get_default_delay()
        {
            return __default_delay;
        }

    public:
        // Constructors
        App(std::string app_name, Version app_version)
            : __app_name(app_name), __app_version(app_version)
        {
        }

        // Pure virtual methods that the subclass should overwrite
        virtual void setup() = 0;
        virtual void loop() = 0;
    };
}

#endif /* __DIP_H__ */