/*
 * Credits: silviu20092
 */

#include "ScriptMgr.h"
#include "flightmaster_whistle.h"

class flightmaster_whistle : public ItemScript
{
public:
    flightmaster_whistle() : ItemScript("flightmaster_whistle") {}

    bool OnUse(Player* player, Item* /*item*/, SpellCastTargets const& /*targets*/) override
    {
        sFlightmasterWhistle->TeleportToNearestFlightmaster(player);
        return true;
    }
};

void AddSC_mod_flightmaster_whistle_itemscript()
{
    new flightmaster_whistle();
}