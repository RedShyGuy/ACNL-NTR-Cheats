#include "Game.hpp"
#include "RAddress.hpp"
#include "Offsets.hpp"
#include "Values.hpp"
#include "cheats.hpp"

namespace CTRPluginFramework
{
    // Initialize properties
    void    Game::Initialize(void)
    {
        Building = AutoRegion(USA_BUILDING_ADDR, TO_EUR(USA_BUILDING_ADDR), TO_JAP(USA_BUILDING_ADDR), TO_WA_USA(USA_BUILDING_ADDR), TO_WA_EUR(USA_BUILDING_ADDR), TO_WA_JAP(USA_BUILDING_ADDR))();
        ClubItem = reinterpret_cast<u32 *>(AutoRegion(USA_CLUB_ADDR, TO_EUR(USA_CLUB_ADDR), TO_JAP(USA_CLUB_ADDR), TO_WA_USA(USA_CLUB_ADDR), TO_WA_EUR(USA_CLUB_ADDR), TO_WA_JAP(USA_CLUB_ADDR))());
        Garden = AutoRegion(USA_GARDEN, TO_EUR(USA_GARDEN), TO_JAP(USA_GARDEN), TO_WA_USA(USA_GARDEN), TO_WA_EUR(USA_GARDEN), TO_WA_JAP(USA_GARDEN))();
        Gravity = AutoRegion(USA_GRAVITY_OUT_ADDR, TO_EUR(USA_GRAVITY_OUT_ADDR), TO_JAP(USA_GRAVITY_OUT_ADDR), TO_WA_USA(USA_GRAVITY_OUT_ADDR), TO_WA_EUR(USA_GRAVITY_OUT_ADDR), TO_WA_JAP(USA_GRAVITY_OUT_ADDR))();
        IslandItem = reinterpret_cast<u32 *>(AutoRegion(USA_ISLAND_ITEMS_ADDR, TO_EUR(USA_ISLAND_ITEMS_ADDR), TO_JAP(USA_ISLAND_ITEMS_ADDR), TO_WA_USA(USA_ISLAND_ITEMS_ADDR), TO_WA_EUR(USA_ISLAND_ITEMS_ADDR), TO_WA_EUR(USA_ISLAND_ITEMS_ADDR))());
        MainStreetItem = reinterpret_cast<u32 *>(AutoRegion(USA_MAINSTREET_ITEMS, TO_EUR(USA_MAINSTREET_ITEMS), TO_JAP(USA_MAINSTREET_ITEMS), TO_WA_USA(USA_ISLAND_ITEMS_ADDR), TO_WA_EUR(USA_ISLAND_ITEMS_ADDR), TO_WA_EUR(USA_ISLAND_ITEMS_ADDR))()); //
        MainStreetPos = reinterpret_cast<Position *>(AutoRegion(USA_MAINSTREET_X, TO_EUR(USA_MAINSTREET_X), TO_JAP(USA_MAINSTREET_X), TO_WA_USA(USA_ISLAND_ITEMS_ADDR), TO_WA_EUR(USA_ISLAND_ITEMS_ADDR), TO_WA_EUR(USA_ISLAND_ITEMS_ADDR))());
        Room = reinterpret_cast<u8 *>(AutoRegion(USA_ROOM_ID_ADDR, EUR_ROOM_ID_ADDR, JAP_ROOM_ID_ADDR, USA_WA_ROOM_ID_ADDR, EUR_WA_ROOM_ID_ADDR, JAP_WA_ROOM_ID_ADDR)());
        BuildingSlots = reinterpret_cast<u8 *>(AutoRegion(USA_BUILDING_BYTE, TO_EUR(USA_BUILDING_BYTE), TO_JAP(USA_BUILDING_BYTE), TO_WA_USA(USA_BUILDING_BYTE), TO_WA_EUR(USA_BUILDING_BYTE), TO_WA_JAP(USA_BUILDING_BYTE))());
        TCPImage = Garden + 0x5758;
        TimeReal = reinterpret_cast<u64 *>(AutoRegion(USA_REALTIME_ADDR, EUR_REALTIME_ADDR, JAP_REALTIME_ADDR, USA_WA_REALTIME_ADDR, EUR_WA_REALTIME_ADDR, JAP_WA_REALTIME_ADDR)());
        TimeSave = reinterpret_cast<u64 *>(AutoRegion(USA_SAVETIME_ADDR, TO_EUR(USA_SAVETIME_ADDR), TO_JAP(USA_SAVETIME_ADDR), TO_WA_USA(USA_SAVETIME_ADDR), TO_WA_EUR(USA_SAVETIME_ADDR), TO_WA_JAP(USA_SAVETIME_ADDR))());
        TownItem = reinterpret_cast<u32 *>(AutoRegion(USA_TOWN_ITEMS_ADDR, TO_EUR(USA_TOWN_ITEMS_ADDR), TO_JAP(USA_TOWN_ITEMS_ADDR), TO_WA_USA(USA_TOWN_ITEMS_ADDR), TO_WA_EUR(USA_TOWN_ITEMS_ADDR), TO_WA_JAP(USA_TOWN_ITEMS_ADDR))());
        Velocity = AutoRegion(USA_VELOCITY_ADDR, TO_EUR(USA_VELOCITY_ADDR), TO_JAP(USA_VELOCITY_ADDR), TO_WA_USA(USA_VELOCITY_ADDR), TO_WA_EUR(USA_VELOCITY_ADDR), TO_WA_JAP(USA_VELOCITY_ADDR))();
        Hour = reinterpret_cast<u8 *>(AutoRegion(USA_HOURS_ADDR, EUR_HOURS_ADDR, JAP_HOURS_ADDR, USA_WA_HOURS_ADDR, EUR_WA_HOURS_ADDR, JAP_WA_HOURS_ADDR)());
        CodeDifference = reinterpret_cast<u32 *>(AutoRegion(USA_CODE_DIFFERENCE, EUR_CODE_DIFFERENCE, JAP_CODE_DIFFERENCE, USA_WA_CODE_DIFFERENCE, EUR_WA_CODE_DIFFERENCE, JAP_WA_CODE_DIFFERENCE)());
        Minute = reinterpret_cast<u8 *>(AutoRegion(USA_MINUTES_ADDR, EUR_MINUTES_ADDR, JAP_MINUTES_ADDR, USA_WA_MINUTES_ADDR, EUR_WA_MINUTES_ADDR, JAP_WA_MINUTES_ADDR)());
        WorldPos = reinterpret_cast<Position *>(AutoRegion(USA_WORLD_X_ADDR, TO_EUR(USA_WORLD_X_ADDR), TO_JAP(USA_WORLD_X_ADDR), TO_WA_USA(USA_WORLD_X_ADDR), TO_WA_EUR(USA_WORLD_X_ADDR), TO_WA_JAP(USA_WORLD_X_ADDR))());
        Nook = reinterpret_cast<u32 *>(AutoRegion(USA_NOOK_ADDR, TO_EUR(USA_NOOK_ADDR), TO_JAP(USA_NOOK_ADDR), TO_WA_USA(USA_NOOK_ADDR), TO_WA_EUR(USA_NOOK_ADDR), TO_WA_JAP(USA_NOOK_ADDR))());
        TownFruit = AutoRegion(USA_TOWN_FRUIT, TO_EUR(USA_TOWN_FRUIT), TO_JAP(USA_TOWN_FRUIT), TO_WA_USA(USA_TOWN_FRUIT), TO_WA_EUR(USA_TOWN_FRUIT), TO_WA_JAP(USA_TOWN_FRUIT))();
        TownGrass = AutoRegion(USA_GRASS_TYPE, TO_EUR(USA_GRASS_TYPE), TO_JAP(USA_GRASS_TYPE), TO_WA_USA(USA_GRASS_TYPE), TO_WA_EUR(USA_GRASS_TYPE), TO_WA_JAP(USA_GRASS_TYPE))();
        Permit = AutoRegion(USA_PERMIT_ADDRESS, TO_EUR(USA_PERMIT_ADDRESS), TO_JAP(USA_PERMIT_ADDRESS), TO_WA_USA(USA_PERMIT_ADDRESS), TO_WA_EUR(USA_PERMIT_ADDRESS), TO_WA_JAP(USA_PERMIT_ADDRESS))();
        TownTree = AutoRegion(USA_TREE_SIZE, TO_EUR(USA_TREE_SIZE), TO_JAP(USA_TREE_SIZE), TO_WA_USA(USA_TREE_SIZE), TO_WA_EUR(USA_TREE_SIZE), TO_WA_JAP(USA_TREE_SIZE))();
        PWP = AutoRegion(USA_PWP_ADDRESS, TO_EUR(USA_PWP_ADDRESS), TO_JAP(USA_PWP_ADDRESS), TO_WA_USA(USA_PWP_ADDRESS), TO_WA_EUR(USA_PWP_ADDRESS), TO_WA_JAP(USA_PWP_ADDRESS))();
        Grass = reinterpret_cast<u32 *>(AutoRegion(USA_GRASS_START_ADDR, TO_EUR(USA_GRASS_START_ADDR), TO_JAP(USA_GRASS_START_ADDR), TO_WA_USA(USA_GRASS_START_ADDR), TO_WA_EUR(USA_GRASS_START_ADDR), TO_WA_JAP(USA_GRASS_START_ADDR))());
        GrassEnd = reinterpret_cast<u32 *>(AutoRegion(USA_GRASS_END_ADDR, TO_EUR(USA_GRASS_END_ADDR), TO_JAP(USA_GRASS_END_ADDR), TO_WA_USA(USA_GRASS_END_ADDR), TO_WA_EUR(USA_GRASS_END_ADDR), TO_WA_JAP(USA_GRASS_END_ADDR))());
        GameSpeed = reinterpret_cast<u32 *>(AutoRegion(USA_GAME_SPEED, EUR_GAME_SPEED, JAP_GAME_SPEED, USA_WA_GAME_SPEED, EUR_GAME_SPEED, JAP_GAME_SPEED)());
        ItemForm = AutoRegion(USA_ITEM_FORM, TO_EUR(USA_ITEM_FORM), TO_JAP(USA_ITEM_FORM), TO_WA_USA(USA_ITEM_FORM), TO_WA_EUR(USA_ITEM_FORM), TO_WA_JAP(USA_ITEM_FORM))();
        Location = reinterpret_cast<u32 *>(AutoRegion(USA_LOCATION_ADDR, TO_EUR(USA_LOCATION_ADDR), TO_JAP(USA_LOCATION_ADDR), TO_WA_USA(USA_LOCATION_ADDR), TO_WA_EUR(USA_LOCATION_ADDR), TO_WA_JAP(USA_LOCATION_ADDR))());
        Keyboard = AutoRegion(USA_KEYBOARD, EUR_KEYBOARD, JAP_KEYBOARD, USA_WA_KEYBOARD, EUR_WA_KEYBOARD, JAP_WA_KEYBOARD)();
        StaticNPC = reinterpret_cast<u32 >(AutoRegion(USA_NPC_ADDR, EUR_NPC_ADDR, JAP_NPC_ADDR, USA_WA_NPC_ADDR, EUR_WA_NPC_ADDR, JAP_WA_NPC_ADDR)());
        DynamicNPC = reinterpret_cast<u32 >(AutoRegion(USA_ISABELLE_ADDR, TO_EUR(USA_ISABELLE_ADDR), TO_JAP(USA_ISABELLE_ADDR), TO_WA_USA(USA_ISABELLE_ADDR), TO_WA_EUR(USA_ISABELLE_ADDR), TO_WA_JAP(USA_ISABELLE_ADDR))());
        BottomScreen = reinterpret_cast<u8 *>(AutoRegion(USA_BOTTOM_ADDR, EUR_BOTTOM_ADDR, JAP_BOTTOM_ADDR, USA_WA_BOTTOM_ADDR, EUR_WA_BOTTOM_ADDR, JAP_WA_BOTTOM_ADDR)());
        Consciousness = reinterpret_cast<u16 *>(AutoRegion(USA_FAINT_ADDR, TO_EUR(USA_FAINT_ADDR), TO_JAP(USA_FAINT_ADDR), TO_WA_USA(USA_FAINT_ADDR), TO_WA_EUR(USA_FAINT_ADDR), TO_WA_JAP(USA_FAINT_ADDR))());
        KeyboardText = reinterpret_cast<u32 *>(AutoRegion(USA_TEXT_KEYBOARD, EUR_TEXT_KEYBOARD, JAP_TEXT_KEYBOARD, USA_WA_TEXT_KEYBOARD, EUR_WA_TEXT_KEYBOARD, JAP_WA_TEXT_KEYBOARD)());
        EnterBool = reinterpret_cast<u8 *>(AutoRegion(USA_ENTER_BOOL, EUR_ENTER_BOOL, JAP_ENTER_BOOL, USA_WA_ENTER_BOOL, EUR_WA_ENTER_BOOL, JAP_WA_ENTER_BOOL)());
        Visibility = reinterpret_cast<u32>(AutoRegion(USA_VISIBILITY_ADDR, EUR_VISIBILITY_ADDR, JAP_VISIBILITY_ADDR, USA_WA_VISIBILITY_ADDR, EUR_WA_VISIBILITY_ADDR, JAP_WA_VISIBILITY_ADDR)());
        CatalogItem = reinterpret_cast<u32>(AutoRegion(USA_CATALOG_ITEM, EUR_CATALOG_ITEM, JAP_CATALOG_ITEM, USA_WA_CATALOG_ITEM, EUR_WA_CATALOG_ITEM, JAP_WA_CATALOG_ITEM)());
        MapBool = reinterpret_cast<u8 *>(AutoRegion(USA_MAP_BOOL, EUR_MAP_BOOL, JAP_MAP_BOOL, USA_WA_MAP_BOOL, EUR_WA_MAP_BOOL, JAP_WA_MAP_BOOL)());
        Tours = reinterpret_cast<u32 *>(AutoRegion(USA_TOURS, EUR_TOURS, JAP_TOURS, USA_WA_TOURS, EUR_WA_TOURS, JAP_WA_TOURS)());
        EmoteASM = reinterpret_cast<u32 >(AutoRegion(USA_EMOTE, EUR_EMOTE, JAP_EMOTE, USA_WA_EMOTE, EUR_WA_EMOTE, JAP_WA_EMOTE)());
        PatternEdit = reinterpret_cast<u32 >(AutoRegion(USA_PATTERNEDIT, EUR_PATTERNEDIT, JAP_PATTERNEDIT, USA_WA_PATTERNEDIT, EUR_WA_PATTERNEDIT, JAP_WA_PATTERNEDIT)());
        NoBreakFlowers = reinterpret_cast<u32 >(AutoRegion(USA_NOBREAKFLOWERS, EUR_NOBREAKFLOWERS, JAP_NOBREAKFLOWERS, USA_WA_NOBREAKFLOWERS, EUR_WA_NOBREAKFLOWERS, JAP_WA_NOBREAKFLOWERS)());
        CountryASM = reinterpret_cast<u32 >(AutoRegion(USA_COUNTRY, EUR_COUNTRY, JAP_COUNTRY, USA_WA_COUNTRY, EUR_WA_COUNTRY, JAP_WA_COUNTRY)());
        Weather = reinterpret_cast<u32 >(AutoRegion(USA_WEATHER, EUR_WEATHER, JAP_WEATHER, USA_WA_WEATHER, EUR_WA_WEATHER, JAP_WA_WEATHER)());
        Confetti = reinterpret_cast<u32 >(AutoRegion(USA_CONFETTI, EUR_CONFETTI, JAP_CONFETTI, USA_WA_CONFETTI, EUR_WA_CONFETTI, JAP_WA_CONFETTI)());
        CherryBlossom = reinterpret_cast<u32 >(AutoRegion(USA_CHERRYBLOSSOM, EUR_CHERRYBLOSSOM, JAP_CHERRYBLOSSOM, USA_WA_CHERRYBLOSSOM, EUR_WA_CHERRYBLOSSOM, JAP_WA_CHERRYBLOSSOM)());
        AlwaysOpen_Retail = reinterpret_cast<u32 >(AutoRegion(USA_ALWAYSOPEN_RETAIL, EUR_ALWAYSOPEN_RETAIL, JAP_ALWAYSOPEN_RETAIL, USA_WA_ALWAYSOPEN_RETAIL, EUR_WA_ALWAYSOPEN_RETAIL, JAP_WA_ALWAYSOPEN_RETAIL)());
        AlwaysOpen_Nookling = reinterpret_cast<u32 >(AutoRegion(USA_ALWAYSOPEN_NOOKLING, EUR_ALWAYSOPEN_NOOKLING, JAP_ALWAYSOPEN_NOOKLING, USA_WA_ALWAYSOPEN_NOOKLING, EUR_WA_ALWAYSOPEN_NOOKLING, JAP_WA_ALWAYSOPEN_NOOKLING)());
        AlwaysOpen_Garden = reinterpret_cast<u32 >(AutoRegion(USA_ALWAYSOPEN_GARDEN, EUR_ALWAYSOPEN_GARDEN, JAP_ALWAYSOPEN_GARDEN, USA_WA_ALWAYSOPEN_GARDEN, EUR_WA_ALWAYSOPEN_GARDEN, JAP_WA_ALWAYSOPEN_GARDEN)());
        AlwaysOpen_Ables = reinterpret_cast<u32 >(AutoRegion(USA_ALWAYSOPEN_ABLES, EUR_ALWAYSOPEN_ABLES, JAP_ALWAYSOPEN_ABLES, USA_WA_ALWAYSOPEN_ABLES, EUR_WA_ALWAYSOPEN_ABLES, JAP_WA_ALWAYSOPEN_ABLES)());
        AlwaysOpen_Sham = reinterpret_cast<u32 >(AutoRegion(USA_ALWAYSOPEN_SHAMPOODLE, EUR_ALWAYSOPEN_SHAMPOODLE, JAP_ALWAYSOPEN_SHAMPOODLE, USA_WA_ALWAYSOPEN_SHAMPOODLE, EUR_WA_ALWAYSOPEN_SHAMPOODLE, JAP_WA_ALWAYSOPEN_SHAMPOODLE)());
        AlwaysOpen_Kicks = reinterpret_cast<u32 >(AutoRegion(USA_ALWAYSOPEN_KICKS, EUR_ALWAYSOPEN_KICKS, JAP_ALWAYSOPEN_KICKS, USA_WA_ALWAYSOPEN_KICKS, EUR_WA_ALWAYSOPEN_KICKS, JAP_WA_ALWAYSOPEN_KICKS)());
        AlwaysOpen_Nook = reinterpret_cast<u32 >(AutoRegion(USA_ALWAYSOPEN_NOOKS, EUR_ALWAYSOPEN_NOOKS, JAP_ALWAYSOPEN_NOOKS, USA_WA_ALWAYSOPEN_NOOKS, EUR_WA_ALWAYSOPEN_NOOKS, JAP_WA_ALWAYSOPEN_NOOKS)());
        AlwaysOpen_Katrina = reinterpret_cast<u32 >(AutoRegion(USA_ALWAYSOPEN_KATRINA, EUR_ALWAYSOPEN_KATRINA, JAP_ALWAYSOPEN_KATRINA, USA_WA_ALWAYSOPEN_KATRINA, EUR_WA_ALWAYSOPEN_KATRINA, JAP_WA_ALWAYSOPEN_KATRINA)());
        AlwaysOpen_Redd = reinterpret_cast<u32>(AutoRegion(USA_ALWAYSOPEN_REDD, EUR_ALWAYSOPEN_REDD, JAP_ALWAYSOPEN_REDD, USA_WA_ALWAYSOPEN_REDD, EUR_WA_ALWAYSOPEN_REDD, JAP_WA_ALWAYSOPEN_REDD)());
        Internal_FurnFix = reinterpret_cast<u32>(AutoRegion(USA_FURN_FIX, EUR_FURN_FIX, JAP_FURN_FIX, USA_WA_FURN_FIX, EUR_WA_FURN_FIX, JAP_WA_FURN_FIX)());
        FishCantScare = reinterpret_cast<u32>(AutoRegion(USA_FISH_CANT_BE_SCARED, EUR_FISH_CANT_BE_SCARED, JAP_FISH_CANT_BE_SCARED, USA_WA_FISH_CANT_BE_SCARED, EUR_FISH_CANT_BE_SCARED, JAP_FISH_CANT_BE_SCARED)());
        FishBiteRightAway = reinterpret_cast<u32>(AutoRegion(USA_FISH_BITE_RIGHT_AWAY, EUR_FISH_BITE_RIGHT_AWAY, JAP_FISH_BITE_RIGHT_AWAY, USA_WA_FISH_BITE_RIGHT_AWAY, EUR_FISH_BITE_RIGHT_AWAY, JAP_FISH_BITE_RIGHT_AWAY)());
        FishSetId = reinterpret_cast<u32>(AutoRegion(USA_FISH_SET_FISH_ID, EUR_FISH_SET_FISH_ID, JAP_FISH_SET_FISH_ID, USA_WA_FISH_SET_FISH_ID, EUR_FISH_SET_FISH_ID, JAP_FISH_SET_FISH_ID)());
        GameMode = reinterpret_cast<u32 *>(AutoRegion(USA_GAMEMODE_PTR, EUR_GAMEMODE_PTR, JAP_GAMEMODE_PTR, USA_WA_GAMEMODE_PTR, EUR_WA_GAMEMODE_PTR, JAP_WA_GAMEMODE_PTR)());
        InstantText = reinterpret_cast<u32>(AutoRegion(USA_INSTANTTEXT, EUR_INSTANTTEXT, JAP_INSTANTTEXT, USA_WA_INSTANTTEXT, EUR_INSTANTTEXT, JAP_INSTANTTEXT)());
        EchoTheMusic = reinterpret_cast<u32>(AutoRegion(USA_ECHOTHEMUSIC, EUR_ECHOTHEMUSIC, JAP_ECHOTHEMUSIC, USA_WA_ECHOTHEMUSIC, EUR_ECHOTHEMUSIC, JAP_ECHOTHEMUSIC)());
    }

    u32     Game::GetWorldOffset(void)
    {
        u8      room = *Room;
        Position *pos = room == 0x01 ? MainStreetPos : WorldPos;

        u32     x = pos->x;
        u32     y = pos->y;
        u32     reg0;
        u32     reg1;

#ifdef DEBUG
        OSD::Notify(Utils::Format("X: %i Y: %i", x, y));
#endif // DEBUG

        
        if (room == 0x01)
        {
            reg0 = x % 0x10;
            x /= 0x10;
            reg1 = y % 0x10;
            y /= 0x10;
            reg0 *= 0x4;
            reg1 *= 0x40;
            x *= 0x400;
            y *= 0x1400;
        }
        else
        {
            x -= 0x10;
            y -= 0x10;
            reg0 = x % 0x10;
            x /= 0x10;
            reg1 = y % 0x10;
            y /= 0x10;
            reg0 *= 0x4;
            reg1 *= 0x40;
            x *= 0x400;
            y *= 0x1400;
        }
        return (reg0 + reg1 + x + y);
    }

    u32     *Game::GetItem(void)
    {
        u32   items;

        if (*Room == 0x0) items = reinterpret_cast<u32>(TownItem);
        else if (*Room == 0x01) items = reinterpret_cast<u32>(MainStreetItem);
        else if (*Room == 0x68) items = reinterpret_cast<u32>(IslandItem);
        else if (*Room == 0x6F) items = reinterpret_cast<u32>(ClubItem);
        else return (nullptr);

        return (reinterpret_cast<u32 *>(items + GetWorldOffset()));
    }

    u8     Game::GetMode(void)
    {
        u8 mode = 0;
        Process::Read8(*GameMode + 0x1329D, mode);
        return mode;
    }

	int		Game::TeleportRoom(u8 id, Coordinates coords)
	{
		static const u32 offset = AutoRegion(0x9513D3, 0x9503CF, 0x94A3CF, 0x9503C3, 0x9503CF, 0x9493CF)();
		static const u32 offset2 = AutoRegion(0xAC2990, 0xAC1990, 0xABB990, 0xAC1990, 0xAC1990, 0xABA990)();
		static const u32 InfoOffsetCheck = AutoRegion(0x330773BC, TO_EUR(0x330773BC), TO_JAP(0x330773BC), TO_WA_USA(0x330773BC), TO_WA_EUR(0x330773BC), TO_WA_JAP(0x330773BC))();
		u32 InfoOffset = Player::GetInstance()->GetInfoOffset();
		u8 AnimID = Player::GetInstance()->GetAnimationID();
		u8 banner = 0;
		if (InfoOffset != InfoOffsetCheck && InfoOffset != InfoOffsetCheck + 0x12C)
		{
			return -1;
		}
		if (GetMode() == 2) // if on club tortimer
		{
			return -2;
		}
		if ((*Game::Room >= 0x5F && *Game::Room <= 0x62) || (*Game::Room >= 0x69 && *Game::Room <= 0x9E)) //Check if on tour, in HHA, saving, formatting, or loading or prologue
		{
			return -3;
		}
		if (AnimID == 6 || AnimID == 0xD || AnimID == 0x1F || AnimID == 0x20) //check if idle (also idle when swimming)
		{
			Process::Write8(offset, 0x01);
			Process::Write16(offset + 1, 0x0001);
			*(Game::Room + 1) = id; //Set the 'next' id and not actual ID, hence the +1
			//Process::Write16(offset2, 0x0001);
			//Sleep(Seconds(2));
			Process::Write8(offset2 + 0x14, AnimID);
			*(reinterpret_cast<Coordinates*>(offset2)) = coords; // copy coordinates
			return 1;
		}
		else
		{
			return -4;
		}
	}

	int		Game::TeleportRoom(u8 id)
	{
		static const u32 offset = AutoRegion(0x9513D3, 0x9503CF, 0x94A3CF, 0x9503C3, 0x9503CF, 0x9493CF)();
		static const u32 offset2 = AutoRegion(0xAC298C, 0xAC198C, 0xABB98C, 0xAC198C, 0xAC198C, 0xABA98C)();
		static const u32 InfoOffsetCheck = AutoRegion(0x330773BC, TO_EUR(0x330773BC), TO_JAP(0x330773BC), TO_WA_USA(0x330773BC), TO_WA_EUR(0x330773BC), TO_WA_JAP(0x330773BC))();
		u32 InfoOffset = Player::GetInstance()->GetInfoOffset();
		u8 AnimID = Player::GetInstance()->GetAnimationID();
		u8 banner = 0;
		static Clock clock;
		if (InfoOffset != InfoOffsetCheck && InfoOffset != InfoOffsetCheck + 0x12C)
		{
			return -1;
		}
		if (GetMode() == 2) // if on club tortimer
		{
			return -2;
		}
		if ((*Game::Room >= 0x5F && *Game::Room <= 0x62) || (*Game::Room >= 0x69 && *Game::Room <= 0x9E)) //Check if on tour, in HHA, saving, formatting, or loading or prologue
		{
			return -3;
		}
		if (AnimID == 6 || AnimID == 0xD || AnimID == 0x1F || AnimID == 0x20) //check if idle (also idle when swimming)
		{
			clock.Restart();
			Process::Write8(offset, 0x01);
			Process::Write16(offset + 1, 0x0001);
			*(Game::Room + 1) = id; //Set the 'next' id and not actual ID, hence the +1
			Process::Write16(offset2, 0x0001);
			return 1;
		}
		else
		{
			return -4;
		}
	}

    u32         Game::Building = 0;
    u32         *Game::ClubItem = nullptr;
    u32         Game::Garden = 0;
    u32         Game::Gravity = 0;
    u32         *Game::IslandItem = nullptr;
    u32         *Game::MainStreetItem = nullptr;
    Position    *Game::MainStreetPos = nullptr;
    u8          *Game::Room = nullptr;
    u32         Game::TCPImage = 0;
    u64         *Game::TimeReal = nullptr;
    u64         *Game::TimeSave = nullptr;
    u32         *Game::TownItem = nullptr;
    u32         Game::Velocity = 0;
    u8          *Game::Hour = nullptr;
    u8          *Game::Minute = nullptr;
    u8         *Game::BuildingSlots = nullptr;
    Position    *Game::WorldPos = nullptr;
    u32         *Game::CodeDifference = nullptr;
    u32         *Game::Nook = nullptr;
    u32         Game::TownFruit = 0;
    u32         Game::TownGrass = 0;
    u32         Game::TownTree = 0;
    u32         Game::Permit = 0;
    u32         Game::PWP = 0;
    u32         *Game::Grass = nullptr;
    u32         *Game::GrassEnd = nullptr;
    u32         Game::FishCantScare = 0;
    u32         Game::FishBiteRightAway = 0;
    u32         Game::FishSetId = 0;
    u32         *Game::GameSpeed = nullptr;
    u32         Game::ItemForm = 0;
    u32         *Game::Location = nullptr;
    u32         Game::Keyboard = 0;
    u32         Game::StaticNPC = 0;
    u32         Game::DynamicNPC = 0;
    u8          *Game::BottomScreen = nullptr;
    u16         *Game::Consciousness = nullptr;
    u32         *Game::KeyboardText = nullptr;
    u8          *Game::EnterBool = nullptr;
    u32         Game::Visibility = 0;
    u32         Game::CatalogItem = 0;
    u8          *Game::MapBool = nullptr;
    u32         *Game::Tours = nullptr;
    u32         Game::EmoteASM = 0;
    u32         Game::PatternEdit = 0;
    u32         Game::NoBreakFlowers = 0;
    u32         Game::CountryASM = 0;
    u32         Game::Weather = 0;
    u32         Game::Confetti = 0;
    u32         Game::CherryBlossom = 0;
    u32         Game::AlwaysOpen_Retail = 0;
    u32         Game::AlwaysOpen_Nookling = 0;
    u32         Game::AlwaysOpen_Garden = 0;
    u32         Game::AlwaysOpen_Ables = 0;
    u32         Game::AlwaysOpen_Sham = 0;
    u32         Game::AlwaysOpen_Kicks = 0;
    u32         Game::AlwaysOpen_Nook = 0;
    u32         Game::AlwaysOpen_Katrina = 0;
    u32         Game::AlwaysOpen_Redd = 0;
    u32         Game::Internal_FurnFix = 0;
    u32         *Game::GameMode = nullptr;
    u32         Game::InstantText = 0;
    u32         Game::EchoTheMusic = 0;
}
