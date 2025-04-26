/*
 * Credits: silviu20092
 */

#include "ScriptMgr.h"
#include "Chat.h"
#include "CommandScript.h"
#include "flightmaster_whistle.h"

using namespace Acore::ChatCommands;

class mod_flightmaster_whistle_commandscript : public CommandScript
{
public:
    mod_flightmaster_whistle_commandscript() : CommandScript("mod_flightmaster_whistle_commandscript") {}

    ChatCommandTable GetCommands() const override
    {
        static ChatCommandTable commandTable =
        {
            { "fmw", HandleTeleportNearestFlightmaster, SEC_PLAYER, Console::No }
        };

        return commandTable;
    }
private:
    static bool HandleTeleportNearestFlightmaster(ChatHandler* handler)
    {
        sFlightmasterWhistle->TeleportToNearestFlightmaster(handler->GetPlayer());
        return true;
    }
};

void AddSC_mod_flightmaster_whistle_commandscript()
{
    new mod_flightmaster_whistle_commandscript();
}
