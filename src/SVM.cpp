#include "headers/SVM.hpp"
#include "PL4_SVM_Config.hpp"

#define AROM (this->rom[this->rom_pointer])
#define ARAM (this->ram[this->ram_pointer])

void SVM::reset(){
    this->varspace.fill(0);
    this->ram.fill(0);
    this->rom.fill(0);
    this->rom_pointer = 0;
    this->ram_pointer = 0;
    this->acc = 0;
}

SVM::SVM(){
}

void SVM::runcmd(uint8_t cmd[3], uint8_t arg8, uint16_t arg16){
    if(cmd[0] == 's'){
        if(cmd[1] == 'd'){
            if(arg8 == '$'){
                this->acc = ARAM;
            }else{
                this->acc = this->varspace[arg8];
            }
        }else if(cmd[1] == 'a'){
            this->acc = arg8;
        }else if(cmd[1] == 'v'){
            if(arg8 == '$'){
                ARAM = this->acc;
            }else{
                this->varspace[arg8] = this->acc;
            }
        }
    }else if(cmd[0] == 'i'){
        if(cmd[1] == 'a'){
            this->ram_pointer += arg16;
        }else if(cmd[1] == 'o'){
            this->rom_pointer += arg16;
        }else if(cmd[1] == 'r'){
            if(arg8 == '@'){
                this->rom_pointer += this->acc;
            }else{
                this->rom_pointer += this->varspace[arg8];
            }
        }
    }else if(cmd[0] == 'd'){
        if(cmd[1] == 'a'){
            this->ram_pointer -= arg16;
        }else if(cmd[1] == 'o'){
            this->rom_pointer -= arg16;
        }else if(cmd[1] == 'r'){
            if(arg8 == '@'){
                this->rom_pointer -= this->acc;
            }else{
                this->rom_pointer -= this->varspace[arg8];
            }
        }
    }else if(cmd[0] == 'j'){
        if(cmd[1] == 'a'){
            this->ram_pointer = arg16;
        }else if(cmd[1] == 'o'){
            this->rom_pointer = arg16;
        }
    }else if(cmd[0] == 'a'){
        if(cmd[1] == 'd'){
            this->acc += arg8;
        }else if(cmd[1] == 's'){
            this->acc -= arg8;
        }else if(cmd[1] == 'r'){
            this->acc >>= arg8;
        }else if(cmd[1] == 'l'){
            this->acc <<= arg8;
        }
    }else if(cmd[0] == 'v'){
        if(cmd[1] == 'd'){
            if(AROM == '$'){
                this->acc += ARAM;
            }else{
                this->acc += this->varspace[arg8];
            }
        }else if(cmd[1] == 's'){
            if(AROM == '$'){
                this->acc -= ARAM;
            }else{
                this->acc -= this->varspace[arg8];
            }
        }else if(cmd[1] == 'r'){
            if(AROM == '$'){
                this->acc >>= ARAM;
            }else{
                this->acc >>= this->varspace[arg8];
            }
        }else if(cmd[1] == 'l'){
            if(AROM == '$'){
                this->acc <<= ARAM;
            }else{
                this->acc <<= this->varspace[arg8];
            }
        }
    }else if(cmd[0] == 'l'){
        if(cmd[1] == 'c'){
            if(this->acc == arg8){
                this->rom_pointer+=4;
            }
        }else if(cmd[1] == 'o'){
            this->acc |= arg8;
        }else if(cmd[1] == 'n'){
            this->acc = ~this->acc;
        }else if(cmd[1] == 'a'){
            this->acc &= arg8;
        }else if(cmd[1] == 'x'){
            this->acc ^= arg8;
        }
    }else if(cmd[0] == 'w'){
        if(cmd[1] == 'i'){
            if(arg8 == '@'){
                this->acc = getchar();
            }else if(arg8 == '$'){
                ARAM = getchar();
            }else{
                this->varspace[arg8] = getchar();
            }
        }else if(cmd[1] == 'o'){
            if(arg8 == '@'){
                std::cout << this->acc;
            }else if(arg8 == '$'){
                std::cout << ARAM;
            }else{
                std::cout << this->varspace[arg8];
            }
        }
    }
}

void SVM::exec(){
    this->rom_pointer = 0;
    uint8_t cmd[3] = {0,0,0};
    uint16_t arg16 = 0;
    uint8_t arg8 = 0;
    while(AROM != 0){
        cmd[0] = AROM;
        this->rom_pointer++;
        cmd[1] = AROM;
        this->rom_pointer++;
        arg16 = 0;
        arg16 = (AROM)<<8;
        this->rom_pointer++;
        arg16 |= AROM;
        arg8 = AROM;
        this->rom_pointer++;
        #ifdef DEBUG
        std::clog << (this->rom_pointer+1)/4 << ',' << cmd << " : " << (int)arg8 << ',' << arg16 << '\n';
        #endif
        this->runcmd(cmd, arg8, arg16);
        #ifdef DEBUG
        std::clog << "acc: " << (int)this->acc << '\n';
        #endif
    }
}

uint16_t SVM::get_rom_ptr(){
    return this->rom_pointer;
}

void SVM::set_rom_ptr(uint16_t val){
    this->rom_pointer = val;
}

uint16_t SVM::inc_rom_ptr(uint16_t val){
    uint16_t ret = this->rom_pointer;
    this->rom_pointer += val;
    return ret;
}

#undef AROM
#undef ARAM