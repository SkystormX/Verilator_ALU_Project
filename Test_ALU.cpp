#include "VALU.h"
#include "verilated.h"
#include <iostream>
#include <iomanip>

int main(int argc, char **argv) {
    Verilated::commandArgs(argc, argv);
    VALU* top = new VALU;

    uint8_t A_vals[] = {10, 15, 255};
    uint8_t B_vals[] = {5, 3, 1};

    std::cout << "A\tB\topcode\tResult\tCarry\tZero\n";
    std::cout << "---------------------------------\n";

    for (int i = 0; i < 3; i++) {
        for (int op = 0; op < 8; op++) {
            top->A = A_vals[i];
            top->B = B_vals[i];
            top->opcode = op;
            top->eval();

            std::cout << std::dec
                      << (int)top->A << "\t"
                      << (int)top->B << "\t"
                      << op << "\t"
                      << (int)top->Result << "\t"
                      << (int)top->Carry << "\t"
                      << (int)top->Zero << "\n";
        }
    }

    delete top;
    return 0;
}
