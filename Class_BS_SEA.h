#define EASY_UPDATE(a, b, c)this->a = FindPattern("BlackShot.exe", b, c)

class Acess_BlackShot_Sea
{
public:
	DWORD AntKick1, AntKick2, ExpHack, HostHack, Life, LookingPlayer, NameRoom, PlayerBase, pPlayer, Slot, TeamEsp, Teleport, WeaponMGR;
	Acess_BlackShot_Sea()
	{
		EASY_UPDATE(AntKick1,
			"\x0F\x84\x00\x00\x00\x00\xE8\x00\x00\x00\x00\x80\xB8\x00\x00\x00\x00\x00\x0F\x85\x00\x00\x00\x00\x8B\x4E\x00",
			"xx????x????xx????xxx????xx?");

		EASY_UPDATE(AntKick2,
			"\x74\x00\xE8\x35\x9F\xEC\xFF\x33\xC9\x41\x88\x88\x00\x00\x00\x00",
			"x?xxxxxxxxxx????");

		//EASY_UPDATE(PlayerBase,
		//	"\x50\x72\x6F\x67\x72\x61\x6D\x6D\x65\x72\x30\x30\x31\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x2D",
		//	"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx");

		EASY_UPDATE(pPlayer,
			"\xA1\x00\x00\x00\x00\xE8\xA8\xB2\x31\x00",
			"x????xxxxx");

		EASY_UPDATE(Slot,
			"\xEB\x44\x09\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x01",
			"xxxxxxxxxxxxxxxx");

		EASY_UPDATE(TeamEsp, 
			"\xA9\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x01",
			"x????xxxxxxxxxxxxxxxx");

		EASY_UPDATE(Teleport, 
			"\x55\x8B\xEC\xD9\x45\x00\x83\xEC\x00\xB9\x00\x00\x00\x00\xD9\x5C\x24\x00",
			"xxxxx?xx?x????xxx?");

	}
	DWORD ofs_pPlayer = 0x3C;
	DWORD ofs_Life = 0xF0;
	DWORD ofs_Fly = 0x32A;
	DWORD ofs_TeleportPosX = 0x420;
	DWORD ofs_TeleportPosY = 0x0424;
	DWORD ofs_TeleportPosZ = 0x0428;
	DWORD ofs_PlayerBaseSize = 0x538;
	DWORD ofs_PlayerBasePith = 0x43C;
	DWORD ofs_PlayerBaseYaw = 0x430;
	DWORD ofs_pPlayerPith = 0x62C;
	DWORD ofs_pPlayerYaw = 0x630;
	DWORD ofs_TeamEsp = 0x61;
	DWORD ofs_Invisible = 0x64F;
	DWORD ofs_NoRecoil = 0x0;
	DWORD ofs_NoSpread = 0x0;
	DWORD ofs_Damage = 0x0;
	DWORD ofs_Speed = 0x0;
	DWORD ofs_RapidFire = 0x0;
	DWORD ofs_Silencer = 0x0;
	DWORD ofs_Scope = 0x0;
	DWORD ofs_All2Melle = 0x0;
	DWORD ofs_AutoShot = 0x0;
	DWORD ofs_FixAim = 0x0;
};