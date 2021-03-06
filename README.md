## Zirconia
Zirconia is a set of scripts which aim to correct the poor support for Lattice Diamond on Linux.
Currently, Diamond will not run on Gentoo, Fedora, etc., because of the way Diamond checks for your MAC address (see: [here](https://github.com/Gzxgzxgzx/ProjectZirconia/blob/master/diamond.strace#L1867)).

**Notice:** This was not created as a patch. It is a script you will use to launch Diamond every time.

**Errors:** If the script is not working please create an issue with relevant information [here](https://github.com/Gzxgzxgzx/Zirconia/issues/new) so we can fix it.

### How Do I Know If I Need This?
Open up a terminal and run the following command. If your first networking interface isn't named "eth0," then you need this script.
``` bash
ifconfig
```

### Installing
    git clone https://github.com/Gzxgzxgzx/Zirconia.git
    cd Zirconia && make
    
### Running
Always make sure that you have a valid license for Diamond.

If you are running a distribution which does not name the first ethernet interface eth0. Notice: This will launch Diamond and requires that it is in your path.

``` bash
sh unflex /path/to/license.dat # This stores the location for future use in LICENSE.unf
sh unflex # Once you successfully load your license you don't need to specify the path anymore
```
If Diamond is not in your path you will want to add it
``` bash
export PATH=$PATH:/path/to/diamond
```
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
