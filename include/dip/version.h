#ifndef __VERSION_H__
#define __VERSION_H__

/*
 Structure to create version identifiers. A version exists of four elements:
 - A major relaase number (as a integer)
 - A minor release number (as a integer)
 - A revision number (as a integer)
 - A name for the release
*/

#include <string>

namespace dip
{
    struct Version
    {
        // Structure for version information
        uint16_t major;
        uint16_t minor;
        uint16_t revision;
        std::string name;
    };
}

#endif /* __VERSION_H__ */