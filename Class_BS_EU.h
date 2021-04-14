#pragma once

class Acess_BlackShot_Global
{
public:
	DWORD ExpHack = 0x00000000;
	DWORD HostHack = 0x00000000;
	DWORD Life = 0x00000000;
	DWORD LookingPlayer = 0x00000000;
	DWORD NameRoom = 0x00000000;
	DWORD PlayerBase = 0x00000000;
	DWORD pPlayer = 0x00000000;
	DWORD Slot = 0x00000000;
	DWORD TeamEsp = 0x00000000;
	DWORD Teleport = 0x00000000;
	DWORD WeaponMGR = 0x00000000;
	DWORD AntKick1 = 0x00000000;
	DWORD AntKick2 = 0x00000000;
	////////////////////////////////////////////
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
	///////////////////////////////////////////
	DWORD ofs_NoRecoil = 0x00000000;
	DWORD ofs_NoSpread = 0x00000000;
	DWORD ofs_Damage = 0x00000000;
	DWORD ofs_Speed = 0x00000000;
	DWORD ofs_RapidFire = 0x00000000;
	DWORD ofs_Silencer = 0x00000000;
	DWORD ofs_Scope = 0x00000000;
	DWORD ofs_All2Melle = 0x00000000;
	DWORD ofs_AutoShot = 0x00000000;
	DWORD ofs_FixAim = 0x00000000;
};