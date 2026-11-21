# Number System Converter

A C++ command-line program for converting numbers between:

- Binary (base 2)
- Quaternary (base 4)
- Octal (base 8)
- Decimal (base 10)
- Hexadecimal (base 16)

The program asks for the input number system and a valid number in that system, then displays its representation in all five supported bases.

## Requirements

- A C++ compiler, such as `g++` or MinGW
- A terminal or command prompt

## Compile

This project must be compiled manually. Compile `main.cpp` only:

### Linux/macOS

```bash
g++ -std=c++11 main.cpp -o numbersystem
```

### Windows (MinGW)

```bash
g++ -std=c++11 main.cpp -o numbersystem.exe
```

## Run

### Linux/macOS

```bash
./numbersystem
```

### Windows

```bash
numbersystem.exe
```

## Usage

1. Enter the source base: `2`, `4`, `8`, `10`, or `16`.
2. Enter a number using valid digits for that base.
3. View the converted value in all supported number systems.
4. Choose whether to convert another number.

Enter `exit` at the source-base prompt to close the program.

### Valid digits

| Base | Valid digits |
| --- | --- |
| 2 | `0-1` |
| 4 | `0-3` |
| 8 | `0-7` |
| 10 | `0-9` |
| 16 | `0-9`, `A-F`, `a-f` |

### Example

For the source base `10` and value `42`, the program produces:

```text
Base2 --> 101010
Base4 --> 222
Base8 --> 52
Base10 -> 42
Base16 -> 2A
```

## Project files

- `main.cpp` — complete number system converter

Only `main.cpp` should be compiled to run the number system converter.
