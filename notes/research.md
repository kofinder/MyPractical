# Memory Fundamentals: PC and Embedded Systems Notes

---

## 1. Memory Overview

All memory types fall into **two main categories**:

- Memory locations are **read/write**
- The **CPU uses memory as working storage**

### Memory Classification

- **Volatile memory**  
  Loses data when power is **OFF**

- **Non-volatile memory**  
  Retains data when power is **OFF**

> In embedded C/C++, variables and functions are placed into different **memory segments**, and **startup code + linker scripts** decide how they are initialized and where they live.

---

## 2. Volatile Memory (RAM Family)

### 2.1 RAM (Random Access Memory)
- General term for **writable, volatile memory**
- Used as **working memory** by the CPU

---

### 2.2 SRAM (Static RAM)
- Very fast
- No refresh required
- Expensive
- Low density
- Used for:
  - MCU internal RAM
  - CPU cache

---

### 2.3 DRAM (Dynamic RAM)
- Slower than SRAM
- Requires periodic refresh
- Cheap
- High density
- Used for:
  - PC main memory
  - External RAM in embedded systems

---

### 2.4 SDRAM / DDR / DDR2 / DDR3 / DDR4 / DDR5
- Types of DRAM
- Increasing speed and bandwidth
- Used in:
  - PCs
  - Smartphones
  - High-end embedded systems

---

## 3. Non-Volatile Memory (ROM Family)

### 3.1 ROM (Read-Only Memory)
- Factory-programmed
- Cannot be modified
- Rarely used today

---

### 3.2 Flash Memory
- Most common "ROM" in modern systems
- Electrically erasable
- Types:
  - **NOR Flash** – code storage (XIP capable)
  - **NAND Flash** – data storage

---

### 3.3 EEPROM
- Electrically erasable
- Byte-level write access
- Slower
- Limited write cycles
- Used for:
  - Configuration data
  - Calibration values

---

### 3.4 FRAM (Ferroelectric RAM)
- Non-volatile
- Fast like RAM
- Low power
- Expensive
- Used in ultra-low-power devices

---

## 4. Physical Memory vs Software Segments

### Key Concepts

- **RAM and ROM are physical hardware**
- **Segments are software abstractions**
- The **linker** maps software segments to physical memory

---

## 5. Memory Segments in Embedded Systems

### ROM / Flash Layout

```
+----------------+
| .text          |  Program code (executed directly from Flash – XIP)
| .rodata        |  Read-only constants
| .data (init)   |  Initial values for global/static variables
+----------------+
```

- `.text` → executable code
- `.rodata` → constants (never copied to RAM)
- `.data (init)` → stored in Flash, copied to RAM at startup

---

### RAM Layout

```
+----------------+
| .data          |  Initialized variables
| .bss           |  Zero-initialized variables
| .noinit        |  Variables not initialized by startup code
| heap           |  Dynamic memory
| stack          |  Function calls / local variables
+----------------+
```

---

## 6. Startup Responsibilities

Startup code performs:
- Stack pointer initialization
- `.data` copy: Flash → RAM
- `.bss` zeroing
- Optional RAM code copy
- Call to `main()`

---

## 7. Instruction Execution Models

### CPU Instruction Fetch

```
CPU ── fetch instruction ──▶ ROM (Flash)
```

---

## 8. Program Execution: PC vs Embedded

### PC (General-Purpose Computer)

1. Program stored on disk (SSD/HDD)
2. OS loads program into RAM
3. CPU fetches instructions from RAM
4. CPU executes instructions

```
CPU ── fetch instruction ──▶ RAM
```

This is the **standard PC execution model**.

---

### Embedded Systems

#### Case 1: Execute from ROM (Most MCUs)
```
CPU ── fetch instruction ──▶ Flash (ROM)
```

- Execute-In-Place (XIP)
- RAM mainly for data

#### Case 2: Execute from RAM (Special cases)
```
Flash (ROM) ──▶ RAM ──▶ CPU
```

Used for:
- Speed-critical functions
- Flash programming
- CPUs without XIP support

---

## 9. System Comparison Table

| System        | Instruction Storage | Instruction Execution |
|---------------|---------------------|-----------------------|
| PC            | Disk → RAM          | RAM                   |
| Embedded MCU  | Flash (ROM)         | Flash                 |
| BIOS Firmware | Flash (ROM)         | Flash                 |

---

## 10. Final Takeaways (Remember This)

👉 CPU = processing unit  
👉 RAM = working memory  
👉 ROM = startup & program storage  
👉 Disk = long-term storage  

👉 ROM **starts** the system  
👉 RAM **runs** the program   

---

**Key Mental Model:**
> Hardware provides memory, software defines segments, the linker connects them, and startup code prepares the system.





# Program Execution: PC vs Embedded Systems

## How It Works on a PC (General-Purpose Computer)

1. The program is stored on **disk** (SSD/HDD).
2. The **operating system (OS)** loads the program into **RAM**.
3. The **CPU fetches instructions from RAM**.
4. The **CPU executes those instructions**.

```
CPU ── fetch instruction ──▶ RAM
```

This is the **normal and expected execution model** for PCs and laptops.

---

## How It Works on Embedded Systems

Embedded systems commonly use **two execution models**, depending on the hardware and requirements.

### 1. Execute from ROM / Flash (Most Common Case)

- Program code is stored in **Flash (ROM)**.
- The CPU **fetches and executes instructions directly from Flash**.
- RAM is mainly used for data (stack, heap, variables).

```
CPU ── fetch instruction ──▶ Flash (ROM)
```

This model is often called **Execute-In-Place (XIP)**.

---

### 2. Execute from RAM (Special / Optional Case)

- Program code is stored in **Flash (ROM)**.
- During startup, selected code is **copied from Flash to RAM**.
- The CPU executes that code **from RAM**.

```
Flash (ROM) ──▶ RAM ──▶ CPU
```

#### Why execute from RAM?

- Speed-critical functions (RAM is faster than Flash)
- Flash programming (Flash cannot be read while being written)
- CPUs or systems that **do not support execute-in-place (XIP)**

---

## Key Takeaway

- **PCs:** Programs are loaded into RAM and executed from RAM.
- **Embedded systems:** Programs usually execute directly from Flash, but can optionally execute from RAM when required.
