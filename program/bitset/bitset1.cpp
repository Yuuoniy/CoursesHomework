# include "Bitset.h"
#define N 5

bitset :: bitset() {
    for (int i = 0; i < N; i++) {
        a[i] = 0;
    }
}

void bitset :: set(int pos) {
    int i = pos / 32;
    int j = pos % 32;
    a[i] = a[i] | (1 << j);
}

void bitset :: reset(int pos) {
    int i = pos / 32;
    int j = pos % 32;
    int value = 0;
    a[i] &= (~value^(1 << j));
}

int bitset :: count() const {
    int num[N];
    for (int i = 0; i < N; i++) {
        num[i] = a[i];
    }
    int count = 0;
    for (int i = 0; i < N; i++) {
        while (num[i]) {
            count++;
            num[i] &= num[i]-1;
        }
    }
    return count;
}

bool bitset :: test(int pos) const {
    int i = pos / 32;
    int j = pos % 32;
    if (a[i] & (1 << j)) {
        return true;
    }
    return false;
}

bool bitset :: any() const {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 32; j++) {
            if (a[i] & (1 << j)) {
                return true;
            }
        }
    }
    return false;
}

bool bitset :: none() const {
    for (int i = 0; i < N; i++) {
        if (a[i] != 0) {
            return false;
        }
    }
    return true;
}

bool bitset :: all() const {
    for (int i = 0; i < N; i++) {
        if (~a[i] != 0) {
            return false;
        }
    }
    return true;
}

bitset& bitset :: operator&= (const bitset& b) {
    for (int i = 0; i < N; i++) {
        a[i] &= b.a[i];
    }
    return *this;
}

bitset& bitset :: operator|= (const bitset& b) {
    for (int i = 0; i < N; i++) {
        a[i] |= b.a[i];
    }
    return *this;
}

bitset& bitset :: operator^= (const bitset& b) {
    for (int i = 0; i < N; i++) {
        a[i] ^= b.a[i];
    }
    return *this;
}

bitset& bitset :: operator= (const bitset& b) {
    for (int i = 0; i < N; i++) {
        a[i] = b.a[i];
    }
    return *this;
}

bitset& bitset :: operator <<= (int pos) {
    for (int i = N-1; i >= 1; i--) {
        a[i] <<= pos;
        for (int j = 0; j < pos; j++) {
            if (test(i*32+j-pos)) {
                (*this).set(i*32+j);
            } else {
                (*this).reset(i*32+j);
            }
        }
    }
    a[0] <<= pos;
    for (int i = 0; i < pos; i++) {
        (*this).reset(i);
    }
}

bitset& bitset :: operator >>= (int pos) {
    for (int i = 0; i < N-1; i++) {
        a[i] >>= pos;
        for (int j = 0; j < pos; j++) {
            if (test((i+1)*32+j)) {
                (*this).set((i+1)*32+j-pos);
            } else {
                (*this).reset((i+1)*32+j-pos);
            }
        }
    }
    a[N-1] >>= pos;
    for (int i = 0; i < pos; i++) {
        (*this).set(32*N-1-i);
    }
}

bitset bitset :: operator~() const {
    bitset copy;
    for (int i = 0; i < N; i++) {
        copy.a[i] = ~a[i];
    }
    return copy;
}

bitset bitset :: operator&(const bitset& b) const {
    bitset copy;
    for (int i = 0; i < N; i++) {
        copy.a[i] = a[i] & b.a[i];
    }
    return copy;
}

bitset bitset :: operator|(const bitset& b) const {
    bitset copy;
    for (int i = 0; i < N; i++) {
        copy.a[i] = a[i] | b.a[i];
    }
    return copy;
}

bitset bitset :: operator^(const bitset& b) const {
    bitset copy;
    for (int i = 0; i < N; i++) {
        copy.a[i] = a[i] ^ b.a[i];
    }
    return copy;
}

bitset bitset :: operator<<(int pos) const {
    bitset copy;
    copy = *this;
    for (int i = N-1; i >= 1; i--) {
        copy.a[i] <<= pos;
        for (int j = 0; j < pos; j++) {
            if (copy.test(i*32+j-pos)) {
                copy.set(i*32+j);
            } else {
                copy.reset(i*32+j);
            }
        }
    }
    copy.a[0] <<= pos;
    for (int i = 0; i < pos; i++) {
        copy.reset(i);
    }
    return copy;
}

bitset bitset :: operator>>(int pos) const {
    bitset copy;
    copy = *this;
    for (int i = 0; i < N-1; i++) {
        copy.a[i] >>= pos;
        for (int j = 0; j < pos; j++) {
            if (copy.test((i+1)*32+j)) {
                copy.set((i+1)*32+j-pos);
            } else {
                copy.reset((i+1)*32+j-pos);
            }
        }
    }
    copy.a[N-1] >>= pos;
    for (int i = 0; i < pos; i++) {
        copy.set(32*N-1-i);
    }
    return copy;
}

bool bitset :: operator== (const bitset& b) const {
    for (int i = 0; i < N; i++) {
        if (a[i] != b.a[i]) {
            return false;
        }
    }
    return true;
}

bool bitset :: operator!= (const bitset& b) const {
    int count = 0;
    for (int i = 0; i < N; i++) {
        if (a[i] == b.a[i]) {
            count++;
        }
    }
    if (count == N) {
        return false;
    }
    return true;
}

bool bitset :: operator[] (int pos) const {
    int i = pos / 32;
    int j = pos % 32;
    if (a[i] & (1 << j)) {
        return true;
    }
    return false;
}
