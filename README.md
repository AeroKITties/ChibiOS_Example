# ChibiOS_Example
Проект для обучения работе с операционной системой реального времени ChibiOS. Проект собран для отладочной платы nucleo64 с микроконтроллером STM32F411RET6.

## Установка
Для работы требуются:
- VS Code со следующими плагинами:
  - C/C++ (ms-vscode.cpptools)
  - C/C++ Extension Pack (ms-vscode.cpptools-extension-pack)
  - CMake (twxs.cmake)
  - CMake tools (ms-vscode.cmake-tools)
  - Makefile Tools (ms-vscode.makefile-tools)
  - Cortex-Debug (marus25.cortex-debug)
  - debug-tracker-vscode (mcu-debug.debug-tracker-vscode)
  - Serial Monitor (ms-vscode.vscode-serial-monitor)
  - Peripheral Viewer (mcu-debug.peripheral-viewer)
  - MemoryViewer (mcu-debug.memory-view)
- GNU Arm Embedded Toolchain 
  - [download](https://developer.arm.com/downloads/-/gnu-rm)
  - Распаковать чтобы путь до arm-none-eabi-gdb.exe был: "C:/gcc-arm-none-eabi/bin/arm-none-eabi-gdb.exe"
- J-Link Software and Documentation Pack
  - [download](https://www.segger.com/downloads/jlink/#J-LinkSoftwareAndDocumentationPack)
  - Установить чтобы путь до JLinkGDBServerCL.exe был: "C:/Program Files/SEGGER/JLink/JLinkGDBServerCL.exe"
- MSYS2 (только для сборки проекта в windows):
  - [download](https://www.msys2.org/)
  - Установка в C: (путь по умолчанию)
  - В консоли (MSYS2 MSYS) вводим слeдующие команды:
    - pacman -S git
    - pacman -S make
  - Команды в MSYS2 такие же как в linux (cd, ls, ...)
  - [Видео с установкой gcc-arm-none-eabi и msys2](https://youtu.be/-p26X8lTAvo)

## Сборка
### Linux:
В консоли переходим в директорию где находится Makefile и вводим команду make:
```sh
    make
``` 
### Windows
В MSYS2 MSYS переходим в директорию где находится Makefile и вводим команду make:
```sh
    make
``` 
### Ошибка "make: arm-none-eabi-gcc: No such file or directory"
Если возникает ошибка "make: arm-none-eabi-gcc: No such file or directory", то отстствует путь до /gcc-arm-none-eabi/bin.
Команда добавляет путь до папки где лежит arm-none-eabi-gcc.exe в path:
``` sh
    export PATH=$PATH:/c/gcc-arm-none-eabi/bin/
``` 
Аналогично путь указывается в linux

## Перепрошивка Stlink В Jlink
Будет добавлено позже 

## Отладка
Будет добавлено позже 


