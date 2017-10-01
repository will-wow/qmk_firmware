# Default plank, but move ctrl to the edge and arrows to hjkl

commands for making:

```bash
make planck-rev4-wow
```

Commands for flashing:

```bash
sudo dfu-programmer atmega32u4 erase
sudo dfu-programmer atmega32u4 flash planck_rev4_wow.hex
sudo dfu-programmer atmega32u4 reset
```