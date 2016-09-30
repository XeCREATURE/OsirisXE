#pragma once

namespace Memory
{
	namespace Editor
	{
		void WritePointer(int i0, long long i1, long long i2, int i3);
		void WritePointerX1(int i0, long long i1, long long i2, long long i3, int i4);
		void WritePointerX2(int i0, long long i1, long long i2, long long i3, long long i4, int i5);
		void WritePointerX3(int i0, long long i1, long long i2, long long i3, long long i4, long long i5, int i6);
		void HackTls(int i0, long long i1, long long i2);
		void WriteGlobalData(long long i0, long long i1, int i2);
	}
}
