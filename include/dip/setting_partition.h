#ifndef __SETTINGPARTITION_H__
#define __SETTINGPARTITION_H__

/*
 Class for a SettingPartition
*/

#include <list>
#include "setting.h"

namespace dip
{
    class SettingPartition
    {
    private:
        std::string __name;
        std::list<Setting> __settings;

    public:
        SettingPartition(std::string name)
            : __name(name)
        {
        }
    };
}

#endif /* __SETTINGPARTITION_H__ */