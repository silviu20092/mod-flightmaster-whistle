/*
 * Credits: silviu20092
 */

#include "ScriptMgr.h"
#include "Player.h"
#include "Chat.h"
#include "flightmaster_whistle.h"

class mod_flightmaster_whistle_playerscript : public PlayerScript
{
public:
    mod_flightmaster_whistle_playerscript() : PlayerScript("mod_flightmaster_whistle_playerscript",
        {
            PLAYERHOOK_ON_LOGIN,
        })
    {
    }

    void OnPlayerLogin(Player* player) override
    {
        if (sFlightmasterWhistle->GetEnabled()
            && sFlightmasterWhistle->GetAddWhistleOnLogin()
            && !sFlightmasterWhistle->IsBot(player)
            && player->GetLevel() >= sFlightmasterWhistle->GetMinPlayerLevel())
        {
            if (!player->HasItemCount(FlightmasterWhistle::WHISTLE_ITEM_ID, 1, true))
            {
                player->AddItem(FlightmasterWhistle::WHISTLE_ITEM_ID, 1);
                ChatHandler(player->GetSession()).PSendSysMessage("You have received your Flightmaster Whistle! Use it to teleport to the nearest flightmaster.");
            }
        }
    }
};

void AddSC_mod_flightmaster_whistle_playerscript()
{
    new mod_flightmaster_whistle_playerscript();
}
