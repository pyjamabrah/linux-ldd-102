# Our own tiny initramfs

Ramfs are an extension to the kernel image which can act as a Root File sytem.
TODO: Add more notes

Steps to generate an initramfs:

* We need a utility like `busybox` which provides very minimal set of users-space tools for us to work with
  * The `busybox` binary is statically compiled (if we have the source).
  * For our purpose we have grabbed an already compiled version `busybox-static_1.37.0-4_arm64.deb`
  * `.deb` files are just another archive files, extract it out.
    * `ar x busybox-static_1.37.0-4_arm64.deb`
    * This should extract out `control.tar.xz`, `data.tar.xz` and `debian-binary`.
    * Since we are going minimal, we are only interested in `data.tar.xz`. Let's extract that out.
    * `tar -xvf data.tar.xz`
      * This should leave us with `usr/` directory and a bunch of files in it.
      * We are only interested in `busybox` binary which can be found in `usr/bin/busybox`

* Provide a configuration file for the `initramfs-tools` (a set of utilities which run along with kernel compilation)
  * Config file -> List of files (virtual files and inodes are also allowed), directories along with permissions
  * `./initramfs_config` is that file in our source
  * Notice that busybox entry is already available, that will tell to pickup the busybox binary from the correct location
  * We will also add correct locations to all the kernel module files along with other files which are needed for testing.

* Finally, we will need to tell the kernel to generate the initramfs and provide the path for the config file.
  * `cd rpi4-linux-kernel`
  * `KERNEL=kernel8`
  * `make ARCH=arm64 CROSS_COMPILE=aarch64-linux-gnu- menuconfig`
  * `General Setup` > `Initial RAM filesystem and RAM disk` > `Initramfs source file(s)` > `../our_own_tiny_initramfs/initramfs.config` (Provide the path of the config file)
  * Compile the kernel: `make -j$(nproc) ARCH=arm64 CROSS_COMPILE=aarch64-linux-gnu- Image modules dtbs`

* The generated kernel image will have contain initramfs archive at the end of it.
