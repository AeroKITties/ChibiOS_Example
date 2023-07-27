# ChibiOS_Example
Проект для обучения работе с операционной системой реального времени ChibiOS. Проект собран для отладочной платы nucleo64 с микроконтроллером STM32F411RET6.


## Установка
Для работы требуются:
- VS Code
  - [download](https://code.visualstudio.com/download)
- Плагины для VS Code (рекомендуется сделать отдельный профиль)
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
  - Скачать zip и распаковать так, чтобы путь до arm-none-eabi-gdb.exe был "C:/gcc-arm-none-eabi/bin/arm-none-eabi-gdb.exe".
- J-Link Software and Documentation Pack
  - [download](https://www.segger.com/downloads/jlink/#J-LinkSoftwareAndDocumentationPack)
  - Установить так, чтобы путь до JLinkGDBServerCL.exe был "C:/Program Files/SEGGER/JLink/JLinkGDBServerCL.exe" (путь установки по умолчанию).
- MSYS2 (только для сборки проекта в windows):
  - [download](https://www.msys2.org/)
  - Установка в C: (путь по умолчанию)
  - В консоли MSYS2 MSYS (фиолетовая иконка) вводим слeдующие команды:
    - ```sh pacman -S git```
    - ```sh pacman -S make```
  - Команды в MSYS2 такие же как в linux (cd, ls, ...)
    - Команда перехода в нужный диск: cd <название диска>:
      -  Пример - ```sh cd C:```
   - переход в папку: ```sh cd <название папки>```
   - переход на 1 уровень наверх: ```sh cd ..```
   - просмотр содержимого: ```sh ls```
- [Видео с установкой gcc-arm-none-eabi и msys2](https://youtu.be/-p26X8lTAvo)
- Установка репозитория 
  - через консоль
    - ```sh git clone https://github.com/AeroKITties/ChibiOS_Example```
    - ```sh cd ChibiOS_Example```
    - ```sh git submodule update --init --recursive```
  - через Github Desktop
    - file -> Clone repository -> URL -> https://github.com/AeroKITties/ChibiOS_Example -> Clone
    - В этом случае все подмодули скачаются автоматически.


## Перепрошивка Stlink в Jlink (только windows)
[Инструкция на сайте](https://www.segger.com/products/debug-probes/j-link/models/other-j-links/st-link-on-board/)
1. Установить драйвера для stlink [download](https://www.st.com/en/development-tools/stsw-link009.html)
2. Установить комплект ПО от segger [download](https://www.segger.com/downloads/jlink/)
3. Скачать и распаковать ST-Link Reflash Utility  https://www.segger.com/downloads/jlink#STLink_Reflash во временную папку
4. Запустить STLinkReflash
5. Дважды согласиться с пользовательским соглашением
6. Присоединить stlink к компьютеру
7. Выбрать "Upgrade to J-Link"
8. Выбрать "Upgrade J-link firmware"
После этого в диспетчере устройтсв в разделе "Контроллеры USB" будет "J-link driver"


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
Аналогично путь указывается в linux. 
Данная команда работает до закрытия консоли, в которой она была введена.


## Запуск и отладка
1. В VS code отрываем папку с проектом (там лежит makefile).
2. Открываем слева "Run and Debug"
3. Если все установлено правильно, то сверху должна быть зеленая стрелка и выбор варианта отладки.
   - Если вариантов отладки нет (новый проект), то создаем в папке с проектом папку ".vscode" и помещаем туда settings.json и launch.json из аналогичной папки в этом проекте. В launch.json требуется указать модель микроконтроллера и путь к исполняемому файлу (.elf).
4. Нажимаем на зеленый треугольник, после чего запускается режим отладки.

Важно! 
- Данные действия не комплируют код, это нужно делать отдельно.
- В случае если в отладке значения переменных отмечены как "optimized out" нужно уменьшить уровень оптимизации до 0, поменяв в makefule -Ox на -O0