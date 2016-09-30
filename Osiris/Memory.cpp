#include "Memory.hpp"
#include <windows.h>
#include <iostream>
#include <intrin.h>

#include "Ausar/Ausar.hpp"

namespace Memory
{
	namespace Editor
	{
		HANDLE getH5F = GetCurrentProcess();
		uint64_t BaseAddress = (uint64_t)GetModuleHandle(NULL);

		void WritePointer(int i0, long long i1, long long i2, int i3)
		{
			if (i0 != 1)
			{
				uint64_t Address = (BaseAddress + i1);

				uint64_t Entry = (Address);

				uint64_t getValue = (Entry + i2);

				uint32_t setValue = _byteswap_ulong(i3);
				WriteProcessMemory(getH5F, (void*)(getValue), &setValue, sizeof(setValue), 0);
			}

			if (i0 != 0)
			{
				uint64_t Address = (i1);

				uint64_t Entry = (Address);

				uint64_t getValue = (Entry + i2);

				uint32_t setValue = _byteswap_ulong(i3);
				WriteProcessMemory(getH5F, (void*)(getValue), &setValue, sizeof(setValue), 0);
			}
		}

		void WritePointerX1(int i0, long long i1, long long i2, long long i3, int i4)
		{
			if (i0 != 1)
			{
				uint64_t Address = (BaseAddress + i1);
				uint64_t Offset1 = i2;

				uint64_t data1;

				ReadProcessMemory(getH5F, (void*)(Address), &data1, sizeof(data1), 0);
				uint64_t Entry = (data1 + Offset1);

				uint64_t getValue = (Entry + i3);

				uint32_t setValue = _byteswap_ulong(i4);
				WriteProcessMemory(getH5F, (void*)(getValue), &setValue, sizeof(setValue), 0);
			}

			if (i0 != 0)
			{
				uint64_t Address = (i1);
				uint64_t Offset1 = i2;

				uint64_t data1;

				ReadProcessMemory(getH5F, (void*)(Address), &data1, sizeof(data1), 0);
				uint64_t Entry = (data1 + Offset1);

				uint64_t getValue = (Entry + i3);

				uint32_t setValue = _byteswap_ulong(i4);
				WriteProcessMemory(getH5F, (void*)(getValue), &setValue, sizeof(setValue), 0);
			}
		}

		void WritePointerX2(int i0, long long i1, long long i2, long long i3, long long i4, int i5)
		{
			if (i0 != 1)
			{
				uint64_t Address = (BaseAddress + i1);
				uint64_t Offset1 = i2;
				uint64_t Offset2 = i3;

				uint64_t data1;
				uint64_t data2;

				ReadProcessMemory(getH5F, (void*)(Address), &data1, sizeof(data1), 0);
				ReadProcessMemory(getH5F, (void*)(data1 + Offset1), &data2, sizeof(data2), 0);
				uint64_t Entry = (data2 + Offset2);

				uint64_t getValue = (Entry + i4);

				uint32_t setValue = _byteswap_ulong(i5);
				WriteProcessMemory(getH5F, (void*)(getValue), &setValue, sizeof(setValue), 0);
			}

			if (i0 != 0)
			{
				uint64_t Address = (i1);
				uint64_t Offset1 = i2;
				uint64_t Offset2 = i3;

				uint64_t data1;
				uint64_t data2;

				ReadProcessMemory(getH5F, (void*)(Address), &data1, sizeof(data1), 0);
				ReadProcessMemory(getH5F, (void*)(data1 + Offset1), &data2, sizeof(data2), 0);
				uint64_t Entry = (data2 + Offset2);

				uint64_t getValue = (Entry + i4);

				uint32_t setValue = _byteswap_ulong(i5);
				WriteProcessMemory(getH5F, (void*)(getValue), &setValue, sizeof(setValue), 0);
			}
		}

		void WritePointerX3(int i0, long long i1, long long i2, long long i3, long long i4, long long i5, int i6)
		{
			if (i0 != 1)
			{
				uint64_t Address = (BaseAddress + i1);
				uint64_t Offset1 = i2;
				uint64_t Offset2 = i3;
				uint64_t Offset3 = i4;

				uint64_t data1;
				uint64_t data2;
				uint64_t data3;

				ReadProcessMemory(getH5F, (void*)(Address), &data1, sizeof(data1), 0);
				ReadProcessMemory(getH5F, (void*)(data1 + Offset1), &data2, sizeof(data2), 0);
				ReadProcessMemory(getH5F, (void*)(data2 + Offset2), &data3, sizeof(data3), 0);
				uint64_t Entry = (data3 + Offset3);

				uint64_t getValue = (Entry + i5);

				uint32_t setValue = _byteswap_ulong(i6);
				WriteProcessMemory(getH5F, (void*)(getValue), &setValue, sizeof(setValue), 0);
			}

			if (i0 != 0)
			{
				uint64_t Address = (i1);
				uint64_t Offset1 = i2;
				uint64_t Offset2 = i3;
				uint64_t Offset3 = i4;

				uint64_t data1;
				uint64_t data2;
				uint64_t data3;

				ReadProcessMemory(getH5F, (void*)(Address), &data1, sizeof(data1), 0);
				ReadProcessMemory(getH5F, (void*)(data1 + Offset1), &data2, sizeof(data2), 0);
				ReadProcessMemory(getH5F, (void*)(data2 + Offset2), &data3, sizeof(data3), 0);
				uint64_t Entry = (data3 + Offset3);

				uint64_t getValue = (Entry + i5);

				uint32_t setValue = _byteswap_ulong(i6);
				WriteProcessMemory(getH5F, (void*)(getValue), &setValue, sizeof(setValue), 0);
			}
		}

		uint64_t Tls = Ausar::Threading::GetMainTls();

		void HackTls(int i0, long long i1, long long i2)
		{
			if (i0 != 1)
			{
				uint64_t Address = (BaseAddress + i1);

				uint64_t Entry = (Address);

				uint64_t getValue = (Entry + i2);

				uint64_t setValue = (Tls);
				WriteProcessMemory(getH5F, (void*)(getValue), &setValue, sizeof(setValue), 0);
			}

			if (i0 != 0)
			{
				uint64_t Address = (i1);

				uint64_t Entry = (Address);

				uint64_t getValue = (Entry + i2);

				uint64_t setValue = (Tls);
				WriteProcessMemory(getH5F, (void*)(getValue), &setValue, sizeof(setValue), 0);
			}
		}

		void WriteGlobalData(long long i0, long long i1, int i2)
		{
			uint64_t Address = (Tls);
			uint64_t Offset1 = i0;

			uint64_t data1;

			ReadProcessMemory(getH5F, (void*)(Address), &data1, sizeof(data1), 0);
			uint64_t Entry = (data1 + Offset1);

			uint64_t getValue = (Entry + i1);

			uint32_t setValue = _byteswap_ulong(i2);
			WriteProcessMemory(getH5F, (void*)(getValue), &setValue, sizeof(setValue), 0);
		}
	}
}
