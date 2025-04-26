/*
 * Credits: silviu20092
 */

#ifndef _FLIGHTMASTER_WHISTLE_H_
#define _FLIGHTMASTER_WHISTLE_H_

#include "ObjectGuid.h"
#include "Position.h"

class FlightmasterWhistle
{
private:
	FlightmasterWhistle();
	~FlightmasterWhistle();
public:
	struct CreatureSpawnInfo
	{
		ObjectGuid::LowType guid;
		WorldLocation pos;
	};
	typedef std::vector<CreatureSpawnInfo> CreatureSpawnInfoContainer;
public:
	static FlightmasterWhistle* instance();

	void LoadFlightmasters();
	void TeleportToNearestFlightmaster(Player* player) const;

	void SetEnabled(bool enabled);
	bool GetEnabled() const;
	void SetTimer(int32 timer);
	uint32 GetTimer() const;
    void SetPreserveZone(bool preserveZone);
    bool GetPreserveZone() const;
private:
	CreatureSpawnInfoContainer flightmasters;
	bool enabled;
	uint32 timer;
    bool preserveZone;

    static std::unordered_map<uint32, uint32> timerMap;

    bool HandleTeleport(Player* player) const;
	const CreatureSpawnInfo* ChooseNearestSpawnInfo(const Player* player) const;
	bool EnemiesNearby(const Player* player, float range = 50.0f) const;

    static void SendPlayerMessage(const Player* player, const std::string& message);
    static std::string FormatTimer(const uint32 ms);
};

#define sFlightmasterWhistle FlightmasterWhistle::instance()

#endif
