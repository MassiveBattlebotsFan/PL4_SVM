#include "headers/SVM.hpp"
#include "PL4_SVM_Config.hpp"

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

void SVM::exec(){
    #define AROM (this->rom[this->rom_pointer])
    #define ARAM (this->ram[this->ram_pointer])
    this->rom_pointer = 0;
    while(AROM != 0){
        #ifdef DEBUG
        std::clog << this->rom_pointer << " : " << AROM << '\n';
        #endif
        if(AROM == 's'){
            this->rom_pointer++;
            if(AROM == 'd'){
                this->rom_pointer++;
                if(AROM == '$'){
                    this->acc = ARAM;
                }else{
                    this->acc = this->varspace[AROM];
                }
            }else if(AROM == 'a'){
                this->rom_pointer++;
                this->acc = AROM;
            }else if(AROM == 'v'){
                this->rom_pointer++;
                if(AROM == '$'){
                    ARAM = this->acc;
                }else{
                    this->varspace[AROM] = this->acc;
                }
            }
        }else if(AROM == 'i'){
            this->rom_pointer++;
            if(AROM == 'a'){
                this->rom_pointer++;
                this->ram_pointer += AROM;
            }else if(AROM == 'o'){
                this->rom_pointer++;
                this->rom_pointer += 1 + AROM*4;
            }
        }else if(AROM == 'd'){
            this->rom_pointer++;
            if(AROM == 'a'){
                this->rom_pointer++;
                this->ram_pointer -= AROM;
            }else if(AROM == 'o'){
                this->rom_pointer++;
                this->rom_pointer -= 1 + AROM*4;
            }
        }else if(AROM == 'a'){
            this->rom_pointer++;
            if(AROM == 'd'){
                this->rom_pointer++;
                this->acc += AROM;
            }else if(AROM == 's'){
                this->rom_pointer++;
                this->acc -= AROM;
            }
        }else if(AROM == 'v'){
            this->rom_pointer++;
            if(AROM == 'd'){
                this->rom_pointer++;
                if(AROM == '$'){
                    this->acc += ARAM;
                }else{
                    this->acc += this->varspace[AROM];
                }
            }else if(AROM == 's'){
                this->rom_pointer++;
                if(AROM == '$'){
                    this->acc -= ARAM;
                }else{
                    this->acc -= this->varspace[AROM];
                }
            }
        }else if(AROM == 'l'){
            this->rom_pointer++;
            if(AROM == 'c'){
                this->rom_pointer++;
                if(this->acc == AROM){
                    this->rom_pointer+=4;
                }
            }
        }else if(AROM == 'w'){
            this->rom_pointer++;
            if(AROM == 'i'){
                this->rom_pointer++;
                if(AROM == '@'){
                    this->acc = getchar();
                }else if(AROM == '$'){
                    ARAM = getchar();
                }else{
                    this->varspace[AROM] = getchar();
                }
            }else if(AROM == 'o'){
                this->rom_pointer++;
                if(AROM == '@'){
                    std::cout << this->acc;
                }else if(AROM == '$'){
                    std::cout << ARAM;
                }else{
                    std::cout << this->varspace[AROM];
                }
            }
        }
        #ifdef DEBUG
        std::clog << "acc: " << (int)this->acc << '\n';
        #endif
        while(this->rom_pointer % 4 != 0) this->rom_pointer++;
    }
    #undef AROM
    #undef ARAM
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