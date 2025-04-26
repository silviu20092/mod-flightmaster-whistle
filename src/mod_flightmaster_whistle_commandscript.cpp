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
private:
    static std::unordered_map<uint32, uint32> timerMap;
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
        Player* player = handler->GetPlayer();
        uint32 currentTime = getMSTime();
        uint32 lastTime = timerMap[player->GetGUID().GetCounter()];
        uint32 diff = getMSTimeDiff(lastTime, currentTime);

        if (lastTime > 0 && diff < sFlightmasterWhistle->GetTimer() && !player->IsGameMaster())
        {
            handler->PSendSysMessage("Please try again in {}.", FlightmasterWhistle::FormatTimer(sFlightmasterWhistle->GetTimer() - diff));
            return true;
        }

        if (sFlightmasterWhistle->TeleportToNearestFlightmaster(player))
            timerMap[player->GetGUID().GetCounter()] = currentTime;

        return true;
    }
};

std::unordered_map<uint32, uint32> mod_flightmaster_whistle_commandscript::timerMap;

void AddSC_mod_flightmaster_whistle_commandscript()
{
    new mod_flightmaster_whistle_commandscript();
}