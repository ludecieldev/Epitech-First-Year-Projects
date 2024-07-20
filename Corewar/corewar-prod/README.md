# 📦 Corewar

> **Short Description**: Creatin a Program simulating a Virtual Machine and make Robots coded in Assembly fighting for memory space.

## 📖 Presentation

Welcome to Corewar!

    What is Corewar?
        Corewar is a programming game where players write warriors (programs) that battle each other in a virtual arena.
        It was designed to be both a challenging and educational experience, honing players' coding and strategic thinking skills.

### Objectives

Project Objectives :

- **Develop the Corewar Virtual Machine**:
        Create an environment where warriors can execute and interact.
        Ensure compliance with the Corewar standard rules.

- **Design an Assembler**:
        Convert human-readable warrior programs into machine code. (Robot-Factory)

- **Implement a Disassembler**:
        Translate machine code back into hex.


## 💻 Technical Presentation

### Technologies Used

- ![C](https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white)
- **Makefile** for compilation.

### Installation

To get started with the project, clone the repository and make the program :

```bash
git clone https://github.com/ludeciedev/corewar.git
cd corewar
make
```

### Usage

To run the project locally :
```
USAGE
./corewar [-dump nbr_cycle] [[-n prog_number] [-a load_address] prog_name] ...
DESCRIPTION
-dump nbr_cycle dumps the memory after the nbr_cycle execution (if the round isn’t
already over) with the following format: 32 bytes/line in hexadecimal (A0BCDEFE1DD3...)
-n prog_number sets the next program’s number. By default, the first free number in the
parameter order
-a load_address sets the next program’s loading address. When no address is specified,
optimize the addresses so that the processes are as far away from each other as
possible. The addresses are MEM_SIZE modulo.
```

## ▶️ Project Structure

```
corewar/
├── bonus/
│   ├── Graphical/ (Currently not working)
├── include/
├── lib/
├── src/
├── Makefile
├── README.md
```

## ↪️ Sources

```
/src/
├── arguments/
│   ├── get_args.c
├── corewar_loop/
│   ├── check_win.c
│   ├── corewar_loop.c
│   ├── get_adress.c
├── instructions/
│   ├── add_sub.c
│   ├── aff.c
│   ├── and_or_xor.c
│   ├── fork.c
│   ├── ld.c
│   ├── ldi.c
│   ├── live.c
│   ├── st.c
│   ├── sti.c
│   ├── zjmp.c
├── parsing/
│   ├── parsing.c
│   ├── setup_corewar.c
├── main.c
├── op.c
```
### 📜 Details

`arguments` :
- `get_args.c` : functions to determine the types and values of instruction parameters for a process, handling different parameter types such as direct, indirect, and register values, and providing utilities to retrieve these arguments from memory.
`corewar_loop`:
- `check_win.c` : function to check if Corewar is ended and wich warrior wins it.
- `corewar_loop.c` : functions to manage the main execution loop of the Corewar game, including updating and executing instructions for each champion, handling the process of loading instructions and parameters, determining when champions die, and ultimately declaring a winner.
- `get_adress.c` : function that return target's adress.
`instructions` are here to interpret assembly :
- `add_sub.c` : contains the add and sub functions, which perform addition and subtraction operations on the values stored in the process's registers, updating the process's carry flag and the target register accordingly.
- `aff.c` : contains the aff function, which retrieves a value from a register, converts it to a character, and outputs it to the standard output.
- `and_or_xor.c` : contains the and_inst, or_inst, and xor_inst functions, which perform bitwise AND, OR, and XOR operations on the values retrieved from the parameters, update the process's carry flag based on the result, and store the result in the specified register.
- `fork.c` : contains the my_fork and lfork functions, which handle the creation of new processes (forks) for a champion by duplicating the state of an existing process and adjusting the program counter (PC) based on the given parameters. The dup_process helper function initializes the new process with the same register values and carry flag as the original process.
- `ld.c` : contains the ld_inst and lld functions, which load values into registers. The ld_inst function loads a value from a parameter and updates the carry flag, considering the IDX_MOD restriction, while the lld function performs a similar operation without the IDX_MOD restriction.
- `ldi.c` : contains the ldi and lldi functions. These functions load a value into a register based on the sum of two arguments, updating the carry flag accordingly. The ldi function considers the IDX_MOD restriction for addressing, while the lldi function does not.
- `live.c` : contains the live function, which updates the last live cycle for a champion if the given parameter matches the champion's ID, increments the live count, and prints a message indicating the champion is alive. If the number of live calls reaches a threshold (NBR_LIVE), it resets the live count and decreases the cycle-to-die value.
- `st.c` : contains the st_inst function, which stores a value from a register into another register or memory location. If the second parameter is a register, it stores the value there; otherwise, it stores the value at the specified memory address, considering the IDX_MOD restriction for addressing.
- `sti.c` : contains the sti function, which stores a value from a register into a memory location determined by the sum of two parameters and the process's program counter (PC). The function updates the carry flag based on the result of the sum and handles the memory address calculation with the IDX_MOD restriction.
- `zjmp.c` : contains the zjmp function, which updates the program counter (PC) of a process to a new address calculated from the current PC and a parameter if the process's carry flag is set. If the carry flag is not set, it does nothing. The address calculation respects the IDX_MOD restriction.
`parsing` :
- `parsing.c` : contains functions for initializing, parsing, and freeing the command-line arguments. The free_parsing function releases memory allocated for parsed data, the init_parsing function initializes the parsing structure, and the parsing function processes command-line arguments to set up the game's parameters, including champion file paths and the dump flag.
- `setup_corewar.c` : contains functions for initializing and setting up the Corewar game state, including the corewar environment, processes, and champions. The init_corewar function initializes the main game structure, init_process initializes a new process, init_champ initializes a champion, and get_champ loads champion data from a file. The setup_corewar function orchestrates the overall setup, loading champions into memory and preparing the game for execution.

`main.c` : contains the main entry point for the Corewar project. It includes functions to print numbers and memory contents in hexadecimal format (my_putnbr_hex, hex_print, dump_mem), and the main function to parse command-line arguments, set up the corewar environment, and execute the main game loop. If errors occur during parsing or setup, appropriate cleanup is performed.

`op.c` : defines an array of operation descriptors (op_tab). Each entry in the array represents an operation with its name, number of arguments, argument types, opcode, number of cycles it takes to execute, and a description. This array is used by the Corewar interpreter to handle various instructions during the game.


## 👥 Contributors

We are grateful for the contributions of the following people:

- [Enzo Dubeaurepaire](https://github.com/EnzoDubeaurepaire) : **Head of Project**
- [Alexandre Garbé](https://github.com/ludecieldev) : **Developper and Tester**

We welcome new contributors to help us improve this project.

## 🎉 Conclusion

Thank you for checking out our **Corewar**! We hope you find it useful and engaging. If you have any questions, suggestions, or feedback, feel free to reach out to us by opening an issue or submitting a pull request.
