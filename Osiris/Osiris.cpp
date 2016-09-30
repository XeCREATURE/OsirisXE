#include "Memory.hpp"

Osiris::Osiris()
{
	//Test Code Cave.
	//Memory::Editor::HackTls(0, 0x03A25DA0, 0x5E610);

	//Patch MP Biped.
	Memory::Editor::WritePointerX3(0, 0x0738A158, 0x10, 0x48, 0x1F4, 0x4, 0x50179E4B);
}
