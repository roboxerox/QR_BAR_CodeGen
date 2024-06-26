// -*- mode:c++; tab-width:2; indent-tabs-mode:nil; c-basic-offset:2 -*-
#ifndef __BIT_ARRAY_H__
#define __BIT_ARRAY_H__



#include <zqrdecode/ZQrdecode.h>
#include <zqrdecode/common/Counted.h>
#include <zqrdecode/common/IllegalArgumentException.h>
#include <zqrdecode/common/Array.h>
#include <vector>
#include <limits>
#include <iostream>
#include <vector>

namespace zqrdecode {

class BitArray : public Counted {
public:
    static const int bitsPerWord = std::numeric_limits<unsigned int>::digits;

private:
    int size;
    ArrayRef<int> bits;
    static const int logBits = ZX_LOG_DIGITS(bitsPerWord);
    static const int bitsMask = (1 << logBits) - 1;

public:
    BitArray();
    BitArray(int size);
    ~BitArray();
    int getSize() const;
    int getSizeInBytes() const;

    bool get(int i) const {
        return (bits[i >> logBits] & (1 << (i & bitsMask))) != 0;
    }

    void set(int i) {
        bits[i >> logBits] |= 1 << (i & bitsMask);
    }

    int getNextSet(int from);
    int getNextUnset(int from);

    void setBulk(int i, int newBits);
    void setRange(int start, int end);
    void clear();
    bool isRange(int start, int end, bool value);
    std::vector<int>& getBitArray();

    void appendBit(bool bit);
    void appendBits(int value, int numBits);
    void appendBitArray(const BitArray& other);
    void ensureCapacity(int size);

    void xor_(const BitArray& other);

    void toBytes(int bitOffset, std::vector<char>& array, int offset, int numBytes) const;

    static ArrayRef<int> makeArray(int size) {
        return ArrayRef<int>((size + 31) / 32);
      }

    void reverse();

    class Reverse {
    private:
        Ref<BitArray> array;
    public:
        Reverse(Ref<BitArray> array);
        ~Reverse();
    };

private:
    static int makeArraySize(int size);
};

std::ostream& operator << (std::ostream&, BitArray const&);

}

#endif // __BIT_ARRAY_H__
