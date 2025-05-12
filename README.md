# PnL Calculator

A C++ program for calculating Profit and Loss (PnL) using either FIFO (First-In-First-Out) or LIFO (Last-In-First-Out) accounting methods.

## Building and Running

### Build the project

```bash
./build.sh
```

### Run the program

```bash
./build/pnl_calc <input_file> <method>
```

for example: `./build/pnl_calc data/test_input_3.csv fifo`

`method` can be either `fifo` or `lifo`

### Unit test

```bash
./build.sh --test
```
