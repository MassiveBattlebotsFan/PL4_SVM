# PL4 SVM implementation specification (subject to change)

## Glossary

- `[byte]` - a 1 byte unsigned integer
- `[word]` - a 2 byte unsigned integer
- `[@]` - byte representing accumulator
- `[$]` - byte representing RAM
- `[null]` - no argument
- `[var]` - unsigned byte representing section of varspace, @ and $ are reserved
- acc - accumulator
- RAM pointer - register denoting current RAM position
- ROM pointer - register denoting current ROM position

## Commands

Each command uses a total of 4 bytes, where `[command]` = 2 bytes, `[arg]` = 2 bytes.    
Syntax: `[command] [arg]`
- `sd [var | $]` - load `[var | $]` into acc
- `sv [var | $]` - load acc into `[var | $]`
- `sa [byte]` - load `[byte]` into acc
- `ia [word]` - increment RAM pointer by `[word]`
- `io [word]` - increment ROM pointer by `[word]`
- `ir [@ | var]` - increment ROM pointer by `[@ | var]`
- `da [word]` - decrement RAM pointer by `[word]`
- `do [word]` - decrement ROM pointer by `[word]`
- `dr [@ | var]` - decrement ROM pointer by `[@ | var]`
- `ja [word]` - set RAM pointer to `[word]`
- `jo [word]` - set ROM pointer to `[word]`
- `ad [byte]` - add `[byte]` to acc
- `as [byte]` - sub `[byte]` from acc
- `aa [byte]` - arithmetic right shift acc by `[byte]`
- `ar [byte]` - logical right shift acc by `[byte]`
- `al [byte]` - left shift acc by `[byte]`
- `lo [byte]` - or acc by `[byte]`
- `ln [null]` - not acc
- `la [byte]` - and acc by `[byte]`
- `lx [byte]` - xor acc by `[byte]`
- `lc [byte]` - skip next instruction if acc == `[byte]`
- `wi [@ | var | $]` - read 1 byte from input to `[@ | var | $]`
- `wo [@ | var | $]` - write 1 byte from `[@ | var | $]` to output
- `vd [var | $]` - add `[var | $]` to acc
- `vs [var | $]` - sub `[var | $]` from acc
- `va [var | $]` - arithmetic right shift acc by `[var | $]`
- `vr [var | $]` - logical right shift acc by `[var | $]`
- `vl [var | $]` - left shift acc by `[var | $]`