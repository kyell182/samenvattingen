# Gegeven: de 6502 microprocessor instructie set

## Instructies voor het laden en opslaan van registers

| Instructie | Betekenis         |
| ---------- | ----------------- |
| LDA        | Load Accumulator  |
| LDX        | Load X register   |
| LDY        | Load Y register   |
| STA        | Store Accumulator |
| STX        | Store X           |
| STY        | Store Y           |

## registers transfers

| Instructie | Betekenis |
| ---------- | --------- |
| TAX        | A → X     |
| TAY        | A → Y     |
| TXA        | X → A     |
| TYA        | Y → A     |
| TSX        | SP → X    |
| TXS        | X → SP    |

## stack operations

| Instructie | Betekenis        |
| ---------- | ---------------- |
| PHA        | Push A op stack  |
| PLA        | Pull A van stack |
| PHP        | Push status      |
| PLP        | Pull status      |

## rekenkundig instructies

| Instructie | Betekenis            |
| ---------- | -------------------- |
| ADC        | Add with Carry       |
| SBC        | Subtract with Borrow |
| INC        | Increment memory     |
| INX        | Increment X          |
| INY        | Increment Y          |
| DEC        | Decrement memory     |
| DEX        | Decrement X          |
| DEY        | Decrement Y          |

## logische instructies

| Instructie | Betekenis    |
| ---------- | ------------ |
| AND        | Bitwise AND  |
| ORA        | Bitwise OR   |
| EOR        | Exclusive OR |
| BIT        | Test bits    |

## shift en rotate instructies

| Instructie | Betekenis             |
| ---------- | --------------------- |
| ASL        | Arithmetic Shift Left |
| LSR        | Logical Shift Right   |
| ROL        | Rotate Left           |
| ROR        | Rotate Right          |

## vergelijkingsinstructies

| Instructie | Betekenis     |
| ---------- | ------------- |
| CMP        | Compare met A |
| CPX        | Compare met X |
| CPY        | Compare met Y |

## spongen en subroutine instructies

| Instructie | Betekenis              |
| ---------- | ---------------------- |
| JMP        | Jump                   |
| JSR        | Jump to SubRoutine     |
| RTS        | Return from Subroutine |
| RTI        | Return from Interrupt  |

## branch instructies

| Instructie | Springt als... | vertaling |
| ---------- | -------------- | ----------|
| BEQ        | Zero = 1       | branch if equal |
| BNE        | Zero = 0       | branch if not equal |
| BCS        | Carry = 1      | branch if carry set |
| BCC        | Carry = 0      | branch if carry clear |
| BMI        | Negative = 1   | branch if minus |
| BPL        | Negative = 0   | branch if plus  |
| BVS        | Overflow = 1   | branch if overflow set |
| BVC        | Overflow = 0   | branch if overflow clear |

## flag manipulatie instructies

| Instructie | Betekenis       |
| ---------- | --------------- |
| CLC        | Clear Carry     |
| SEC        | Set Carry       |
| CLI        | Clear Interrupt |
| SEI        | Set Interrupt   |
| CLV        | Clear Overflow  |
| CLD        | Clear Decimal   |
| SED        | Set Decimal     |

## systeem instructies

| Instructie | Betekenis       |
| ---------- | --------------- |
| NOP        | No operation    |
| BRK        | Force interrupt |
| WAI        | Wait for interrupt |

## flags

|     flag   |    Betekenis       |
| ---------- | ------------------ |
| N          | Negative           |
| V          | Overflow           |
| B          | Break Command      |
| D          | Decimal Mode       |
| I          | Interrupt Disable  |
| Z          | Zero               |
| C          | Carry              |


