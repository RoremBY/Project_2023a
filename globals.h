
/* TODO: Initial IC value - 0 or 100? */
#define IC_INIT_VALUE 100

/* Opcodes */
typedef enum opcode {
    MOV = 0,
    CMP = 1,
    ADD = 2,
    SUB = 3,
    NOT = 4,
    CLR = 5,
    LEA = 6,
    INC = 7,
    DEC = 8,
    JMP = 9,
    BNE = 10,
    RED = 11,
    PRN = 12,
    JSR = 13,
    RTS = 14,
    STOP = 15
} opcode;

/* Addressing types */
typedef enum addressing_type {
    IMMEDIATE = 0,
    DIRECT = 1,
    PARAMETER = 2,
    REGISTER = 3
} addressing_type;

/* Registers */
typedef enum reg {
    R0,
    R1,
    R2,
    R3,
    R4,
    R5,
    R6,
    R7
} reg;