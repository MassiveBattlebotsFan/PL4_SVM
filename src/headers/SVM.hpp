#ifndef SVM_H
#define SVM_H

#include <vector>
#include <array>
#include <string>

class SVM{
private:
    std::array<uint8_t, 256> varspace;
    uint16_t rom_pointer;
    uint16_t ram_pointer;
    uint8_t acc;
public:
    std::array<uint8_t, 0xFFFF> ram;
    std::array<uint8_t, 0xFFFF> rom;
    SVM();
    void reset_pc();
};

#endif