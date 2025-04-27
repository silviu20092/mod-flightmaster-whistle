/*
 * Credits: silviu20092
 */

#include "ScriptMgr.h"
#include "Config.h"
#include "flightmaster_whistle.h"

class mod_flightmaster_whistle_worldscript : public WorldScript
{
public:
    mod_flightmaster_whistle_worldscript() : WorldScript("mod_flightmaster_whistle_worldscript",
        {
            WORLDHOOK_ON_AFTER_CONFIG_LOAD,
            WORLDHOOK_ON_BEFORE_WORLD_INITIALIZED
        })
    {
    }

    void OnAfterConfigLoad(bool reload) override
    {
        sFlightmasterWhistle->SetEnabled(sConfigMgr->GetOption<bool>("Flightmaster.Whistle.Enable", true));
        sFlightmasterWhistle->SetTimer(sConfigMgr->GetOption<int32>("Flightmaster.Whistle.Timer", 900));
        sFlightmasterWhistle->SetPreserveZone(sConfigMgr->GetOption<bool>("Flightmaster.Whistle.Preserve.Zone", true));
        sFlightmasterWhistle->SetLinkMainCities(sConfigMgr->GetOption<bool>("Flightmaster.Whistle.LinkMainCities", false));
        sFlightmasterWhistle->SetMinPlayerLevel(sConfigMgr->GetOption<int32>("Flightmaster.Whistle.MinPlayerLevel", 1));
    }

    void OnBeforeWorldInitialized() override
    {
        sFlightmasterWhistle->LoadFlightmasters();
    }
};

void AddSC_mod_flightmaster_whistle_worldscript()
{
    new mod_flightmaster_whistle_worldscript();
}
