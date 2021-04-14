#pragma once

Acess_BlackShot_Sea Acess_BS_SEA = Acess_BlackShot_Sea();

#define INGAME (*(DWORD*)(*(DWORD*)(Acess_BS_SEA.pPlayer) + Acess_BS_SEA.ofs_pPlayer) > 0x00400000)

void SetarPosicao(float x, float y, float z) {
	DWORD caller = Acess_BS_SEA.Teleport;
	__asm {
		push z
		push y
		push x
		call caller
	}
}

void MultiHackSea()
{
	int iStart, iEnd;
	while (1)
	{
		if (GetAsyncKeyState(VK_HOME) & 1)
			DesabiliteTeamEspSEA = !DesabiliteTeamEspSEA;

		if (GetAsyncKeyState(VK_INSERT) & 1)
			TeamEspSEA = !TeamEspSEA;

		if (INGAME && DesabiliteTeamEspSEA == FALSE) {
			if (TeamEspSEA)
			{
				*(BYTE*)Acess_BS_SEA.TeamEsp = 1;
				*(BYTE*)(*(DWORD*)(Acess_BS_SEA.pPlayer) + Acess_BS_SEA.ofs_TeamEsp) = 1;
				if (GetAsyncKeyState(VK_LBUTTON) < 0)
				{
					*(BYTE*)Acess_BS_SEA.TeamEsp = 0;
					*(BYTE*)(*(DWORD*)(Acess_BS_SEA.pPlayer) + Acess_BS_SEA.ofs_TeamEsp) = 0;
					Sleep(6);
				}
			}
			else
			{
				*(BYTE*)Acess_BS_SEA.TeamEsp = 0;
				*(BYTE*)(*(DWORD*)(Acess_BS_SEA.pPlayer) + Acess_BS_SEA.ofs_TeamEsp) = 0;
				if (GetAsyncKeyState(VK_LBUTTON) < 0)
				{
					*(BYTE*)Acess_BS_SEA.TeamEsp = 1;
					*(BYTE*)(*(DWORD*)(Acess_BS_SEA.pPlayer) + Acess_BS_SEA.ofs_TeamEsp) = 1;
					Sleep(6);
				}
			}
		}


		if (GetAsyncKeyState(VK_END) & 1)
			TelekillSEA = !TelekillSEA;

		if (INGAME) {
			if (TelekillSEA) {
				if ((*(int*)(Acess_BS_SEA.Slot) < 8)) {
					iStart = 8;
					iEnd = 15;
				}
				else {
					iStart = 0;
					iEnd = 7;
				}

				for (int i = iStart; i <= iEnd; i++) {
					while ((TelekillSEA == true) && (*(int*)(Acess_BS_SEA.PlayerBase + Acess_BS_SEA.ofs_Life + (Acess_BS_SEA.ofs_PlayerBaseSize * i)) > 0) && (*(int*)(Acess_BS_SEA.Slot) != 0xFF)) {
						if (GetAsyncKeyState(VK_END) & 1)
							TelekillSEA = !TelekillSEA;

						if (INGAME && TelekillSEA) {
							*(BYTE*)(*(DWORD*)(*(DWORD*)(Acess_BS_SEA.pPlayer) + Acess_BS_SEA.ofs_pPlayer) + 0x644) = 0; // LongKnife
							*(BYTE*)(*(DWORD*)(*(DWORD*)(Acess_BS_SEA.pPlayer) + Acess_BS_SEA.ofs_pPlayer) + 0x4A4) = 255; // Bullet Infinit
																															 //*(BYTE*)(*(DWORD*)(*(DWORD*)(Pointer.Trigger) + 0x44) + 0x81) = 1;
							SetarPosicao(*(float*)(Acess_BS_SEA.PlayerBase + Acess_BS_SEA.ofs_TeleportPosX + (Acess_BS_SEA.ofs_PlayerBaseSize * i)),
								*(float*)(Acess_BS_SEA.PlayerBase + Acess_BS_SEA.ofs_TeleportPosY + (Acess_BS_SEA.ofs_TeleportPosY * i)),
								*(float*)(Acess_BS_SEA.PlayerBase + Acess_BS_SEA.ofs_TeleportPosZ + (Acess_BS_SEA.ofs_PlayerBaseSize * i)) + 125.f);
							//*(float*)(*(DWORD*)(*(DWORD*)(Pointer.pPlayer) + Offsets.pPlayer) + Offsets.EditPith) = *(float*)(Pointer.PlayerBase + Offsets.LoopPith + (Offsets.PlayerSize * i)) + 150.0f;
							//*(float*)(*(DWORD*)(*(DWORD*)(Pointer.pPlayer) + Offsets.pPlayer) + Offsets.EditYaw) = *(float*)(Pointer.PlayerBase + Offsets.LoopYaw + (Offsets.PlayerSize * i));
							*(BYTE*)(*(DWORD*)(*(DWORD*)(Acess_BS_SEA.pPlayer) + Acess_BS_SEA.ofs_pPlayer) + Acess_BS_SEA.ofs_Invisible) = 100;
						}
						else
						{
							*(BYTE*)(*(DWORD*)(*(DWORD*)(Acess_BS_SEA.pPlayer) + Acess_BS_SEA.ofs_pPlayer) + Acess_BS_SEA.ofs_Invisible) = *(BYTE*)(*(DWORD*)(Acess_BS_SEA.pPlayer) + Acess_BS_SEA.ofs_TeamEsp);
						}
					}
				}
			}
		}
	}
}


void AntKickSea()
{
	while (1)
	{
		if (GetAsyncKeyState(VK_DELETE) & 1)
			KickSEA = !KickSEA;

		if (INGAME) {
			if (KickSEA) {
				*(BYTE*)(Acess_BS_SEA.AntKick1) = 0x85;
				*(BYTE*)(Acess_BS_SEA.AntKick2) = 0x75;
				Sleep(100);
				*(BYTE*)(Acess_BS_SEA.AntKick1) = 0x84;
				*(BYTE*)(Acess_BS_SEA.AntKick2) = 0x74;
				Sleep(1000);
			}
		}
	}
}


enum Maps {
	Hunting = 0x676E69,
	Sand1 = 0x6E61,
	CoreProject = 0x63757274,
	BrokenCityII = 0x3900,
	BallRoom = 0x3536,
	CargoShip = 0x3936,
	Savage = 0x3036,
	Galata = 0x3235,
	Quarry = 0x3932,
	BrokenCage = 0x3033,
	Xitang = 0x676E
};


void TeleFlagSEA() {
	while (1) {
		if (GetAsyncKeyState(VK_PRIOR) & 1)
			bTeleFlagSEA = !bTeleFlagSEA;

		if (bTeleFlagSEA && INGAME) {
			switch (*(DWORD*)Acess_BS_SEA.NameRoom) {
			case Hunting:
				SetarPosicao(1134.079956f, -637.4400024f, 61.43999863f);
				Sleep(1);
				SetarPosicao(-1328.640015f, 721.9199829f, 66.55999756f);
				Sleep(1);
				break;

			case Sand1:
				SetarPosicao(-729.5999756f, 2798.080078f, 2.559999943f);
				Sleep(1);
				SetarPosicao(1090.560059f, -2109.439941f, 35.84000015f);
				Sleep(1);
				break;

			case CoreProject:
				SetarPosicao(10.23999977f, 2498.560059f, 0.f);
				Sleep(1);
				SetarPosicao(-25.60000038f, -2667.52002f, 0.f);
				Sleep(1);
				break;

			case BrokenCityII:
				SetarPosicao(-2613.76001f, -632.3200073f, 69.12000275f);
				Sleep(1);
				SetarPosicao(1425.920044f, -1848.319946f, 87.04000092f);
				Sleep(1);
				break;

			case BallRoom:
				SetarPosicao(-1832.959961f, -1036.800049f, 2.559999943f);
				Sleep(1);
				SetarPosicao(2421.76001f, 716.7999878f, 20.47999954f);
				Sleep(1);
				break;

			case CargoShip:
				SetarPosicao(-204.8000031f, -3596.800049f, 1159.680054f);
				Sleep(1);
				SetarPosicao(-30.71999931f, 2270.719971f, 1144.319946f);
				Sleep(1);
				break;

			case Savage:
				SetarPosicao(-2478.080078f, -1177.599976f, 64.f);
				Sleep(1);
				SetarPosicao(2844.159912f, 2058.23999f, -12.80000019f);
				Sleep(1);
				break;

			case Galata:
				SetarPosicao(1984.f, -939.5200195f, 15.35999966f);
				Sleep(1);
				SetarPosicao(-2119.679932f, 1850.880005f, 10.23999977f);
				Sleep(1);
				break;

			case Quarry:
				SetarPosicao(-721.9199829f, 3261.439941f, 0.f);
				Sleep(1);
				SetarPosicao(581.1199951f, -3200.f, 0.f);
				Sleep(1);
				break;

			case BrokenCage:
				SetarPosicao(2764.800049f, -343.0400085f, 128.f);
				Sleep(1);
				SetarPosicao(-2667.52002f, -97.27999878f, 89.59999847f);
				Sleep(1);
				break;

			case Xitang:
				SetarPosicao(-1000.960022f, 3328.f, 2.559999943f);
				Sleep(1);
				SetarPosicao(-675.8400269f, -3450.879883f, 230.3999939f);
				Sleep(1);
				break;
			}
		}
		Sleep(5);
	}
}