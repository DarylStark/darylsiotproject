#ifndef __SETTING_H__
#define __SETTING_H__

/*
 Classes for settings. Contains the 'Setting' class which will be a interface
 for concrete settings, like StringSetting, BoolSetting and UInt8 setting.
*/

#include <string>

#define STRING_SETTING 0x01
#define STRING_BOOL 0x02
#define STRING_UINT8 0x03

namespace dip
{
    class Setting
    {
    private:
        // Settings for the type
        uint8_t __type;

        // Setting-settings
        std::string __name;
        std::string __partition;
        std::string __setting;

    public:
        // Constructors
        Setting(std::string name, uint8_t type, std::string partition, std::string setting)
            : __type(type), __name(name), __partition(partition), __setting(setting)
        {
        }

        // Getters for the global information of settings
        std::string get_name()
        {
            return __name;
        }

        // Pure virtual functions that should be overriden
        virtual void update_value() = 0;
    };

    class StringSetting : public Setting
    {
    private:
        std::string __default_value;
        std::string __value;

    public:
        // Constructors
        StringSetting(std::string name, std::string partition, std::string setting, std::string default_value)
            : Setting(name, STRING_SETTING, partition, setting), __default_value(default_value)
        {
            // TODO: Implement
        }

        // Methods to update the settings from the device
        void update_value()
        {
            // TODO: Implement
        }
    };

    class BoolSetting : public Setting
    {
    private:
        bool __default_value;
        bool __value;

    public:
        // Constructors
        BoolSetting(std::string name, std::string partition, std::string setting, bool default_value)
            : Setting(name, STRING_BOOL, partition, setting), __default_value(default_value)
        {
            // TODO: Implement
        }

        // Methods to update the settings from the device
        void update_value()
        {
            // TODO: Implement
        }
    };

    class UInt8Setting : public Setting
    {
    private:
        bool __default_value;
        uint8_t __value;

    public:
        // Constructors
        UInt8Setting(std::string name, std::string partition, std::string setting, uint8_t default_value)
            : Setting(name, STRING_UINT8, partition, setting), __default_value(default_value)
        {
            // TODO: Implement
        }

        // Methods to update the settings from the device
        void update_value()
        {
            // TODO: Implement
        }
    };
}

#endif /* __SETTING_H__ */