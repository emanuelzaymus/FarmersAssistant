#include "memory_routines.h"

namespace structures {
	byte & MemoryRoutines::byteSet(byte & B)
	{
		B = 255;
		return B;
	}
	byte & MemoryRoutines::byteReset(byte & B)
	{
		B = 0;
		return B;
	}
	byte & MemoryRoutines::byteXOR(byte & B)
	{
		B = ~B;
		return B;
	}
	byte & MemoryRoutines::byteSHL(byte & B)
	{
		B <<= 1;	//B = B << 1;
		return B;
	}
	byte & MemoryRoutines::byteSHR(byte & B)
	{
		B >>= 1;	//B = B >> 1;
		return B;
	}
	bool MemoryRoutines::byteNthBitGet(byte & B, int n)
	{
		return B & (1 << n);
	}

	byte & MemoryRoutines::byteNthBitTo0(byte & B, int n)
	{
		B &= ~(1 << n);
		return B;
	}

	byte & MemoryRoutines::byteNthBitTo1(byte & B, int n)
	{
		B |= (1 << n);
		return B;
	}

	byte & MemoryRoutines::byteNthBitToggle(byte & B, int n)
	{
		B ^= (1 << n);
		return B;
	}

	int MemoryRoutines::bitIndexOfBitMask(const byte * bytes, int bytesCount, byte bitMask)
	{
		if (bitMask == bytes[0])
			return 0;

		byte b = bytes[0];
		for (size_t i = 1; i < bytesCount; i++)
		{
			for (size_t j = 0; j < 8; j++)
			{
				b <<= 1;
				b |= ((bytes[i] >> 7 - j) & 1);

				if (bitMask == b)
					return j + 8 * i - 7;
			}
		}
		return -1;
	}

	MemoryRoutines::MemoryRoutines()
	{
	}

}
