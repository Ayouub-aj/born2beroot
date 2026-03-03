# BORN2BEROOT with Kerberos setup

## Your simplified Cheatsheet for an easy configuration of your Debian based VMs

----------------------------step 1: INSTALLATION -----------------------------------------------------------
 
 - choose whatever os you want as long as it is Debian based(Debian, Ubuntu, Parrot os, mint, ..)and download its iso file.
 - enable HYPER-V on windows features if you're under a windows machine.
 - chose your hypervisor type 2 application (virtual box, VMware workstation or fusion, ...)
 - create a new vm on your hypervisor and choose your os image to boot from.
 - partition your vdi into two sections, one for your system boot and the other for your data.
 - partition your volumes manually to get your desired structure.
 - encrypt your data partition so that a passphrase is required on every boot. "$(wget https://www.debian.org/releases/stretch/armel/ch06s03.html.en#idm2034)".
 ->>> Debian uses LUKS (linux unified key setup )/ dm_crypt to encrypt your data "$(wget https://gitlab.com/cryptsetup/cryptsetup/-/wikis/LUKS-standard/on-disk-format.pdf)"
 - encryption is basically ciphering you you disk to protect it mostly from any "physical exploits". And unfortunately you can only encrypt your data partitions and not your boot volume since encryption on boot volumes are not yet implemented at the kernel level !!

 -after encrypting your data partition now you have to manage and set your LVMs(logical volume manager),
It’s better to install your os using LVM just in case you want to use snapshots or even just to extend your root partition just in case it gets saturated.

 - for your partition sizes use Bytes instead of Gb to use all of your desired allocation.
 - for the 500mb in your boot partition use 501mb and convert it to bytes so that your get exactly 500mb after installation.
 - for your last partition var/log just select continue for the remaining of 30.8GB the end result will be 4GB.

----------------------------step 1: CONFIGURATION -----------------------------------------------------------

 - once you start your VM unlock your encrypted partitions and connect with your login and password.
 - check if your partition structure and sizes are the same as the required ones with the command lsblk (list specified memory blocks)
 - 
