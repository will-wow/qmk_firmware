# Default plank, but move ctrl to the edge and parens to homerow

commands for making:

```bash
make planck-rev4-khaaansolo
```

Commands for flashing:

```bash
sudo dfu-programmer atmega32u4 erase
sudo dfu-programmer atmega32u4 flash planck_rev4_khaaansolo.hex
sudo dfu-programmer atmega32u4 reset
```