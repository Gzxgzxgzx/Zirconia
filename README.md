## Zirconia
Zirconia is a set of scripts which aim to correct the poor support for Lattice Diamond on Linux.
Currently, Diamond will not run on Gentoo/Fedora/etc. because of the way Diamond checks for your MAC address (see: [here](https://github.com/Gzxgzxgzx/ProjectZirconia/blob/master/diamond.strace#L1867)).

### Installing
    git clone https://github.com/Gzxgzxgzx/Zirconia.git
    
### Running
If you are running a distribution which does not name the first ethernet interface eth0 

    sh unflex
If you want to see the outputs of *gethostid()* and the hardware address reported by eth0

    make && ./unflex-test
### Required Modules
* Dummy (Linux/drivers/net/dummy.ko) - Used to emulate eth0
* FTDI (Linux/drivers/usb/serial/ftdi_sio.ko) - Required for the development board

### Troubleshooting
If you are having problems with Diamond first make sure you have the right modules loaded. A '$' indicates that the command is ran as root.

1. Plugging the board in should show up when connected

        dmesg | tail
2. Load the proper kernel module

        $ modprobe ftdi_sio
3. Load the kernel module on startup by changing the line to modules="ftdi_sio"

        $ nano /etc/conf.d/modules
