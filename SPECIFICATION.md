# PL4 SVM implementation specification (subject to change)

## Glossary

- [byte] - a 1 byte signed integer
- [!byte] - a 1 byte unsigned integer
- [word] - a 2 byte signed integer
- [!word] - a 2 byte unsigned integer
- [@] - byte representing accumulator
- [$] - byte representing RAM
- [null] - no argument
- [var] - unsigned byte representing section of varspace, @ and $ are reserved

## Commands

Syntax: [command] [arg]
- ld [var | \$] - load [var | \$] into acc
- sv [var | \$] - load acc into [var | \$]
- sa [byte] - load [byte] into acc
- ra [word] - increment RAM pointer by [word]
- pc [word] - increment ROM pointer by [word]
- ad [byte] - add [byte] to acc
- or [!byte] - or acc by [!byte]
- nt [null] - not acc
- an [!byte] - and acc by [!byte]
- xr [!byte] - xor acc by [!byte]
- cp [!byte] - skip next instruction if acc == [!byte]
- in [@ | var | \$] - read 1 byte from input to [@ | var | \$]
- wr [@ | var | \$] - write 1 byte from [@ | var | \$] to output