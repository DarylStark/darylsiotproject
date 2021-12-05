#ifndef __IOT_APP_H__
#define __IOT_APP_H__

/*
 Class to create 'default' IOT apps with WiFi, a webserver and a MQTT client.
 Will try to connect to WiFi. If it fails, it goes into 'WiFi connection mode',
 which will cause the device to create a WiFi Access Point and serve a page on
 which the user can configure his WiFi settings. When the device is in this
 mode, it will restart every 5 minutes. That way, if a WiFi connection fails
 for some external reason, it will reconnect if the reason is solved.
*/

#include <list>
#include "app.h"
#include "setting_partition.h"

namespace dip
{
    class IOTApp : public App
    {
    private:
        // The mode in which the device is
        bool __wifi_connection_mode;

    protected:
        // Linked lists for configuration
        std::list<SettingPartition> _configuration;

        // Helper functions for subclasses
        bool _setup()
        {
            // The setup function will return true when the device is not in
            // WiFi connection mode. If it is IN WiFi connection mode it
            // returns false, so the client knows not to do anyhting.

            // Start the setup from App
            App::_setup();

            // Add configuration for the WiFi
            SettingPartition wifi_settings("WiFi settings");
            _configuration.push_front(wifi_settings);
        }

        bool _loop()
        {
            // The loop function will return true when the device is not in
            // WiFi connection mode. If it is IN WiFi connection mode it
            // returns false, so the client knows not to do anyhting.

            // Start the loop from App
            App::_loop();
        }

        bool _connect_to_wifi()
        {
            // Method to connect to the WiFi
            // TODO: Implement
        }

        void _start_ap_mode()
        {
            // Method to start the AP mode
            // TODO: Implement
        }

    public:
        IOTApp(std::string app_name, Version app_version)
            : App(app_name, app_version), __wifi_connection_mode(false)
        {
        }
    };
}

#endif /* __IOT_APP_H__ */