# Creating an embedded Linux distribution and writing Kernel modules

## Outcomes:

- Build Linux kernel image for ARM Versatile board
- Build a root file system with Busybox
- Use Buildroot to build an embedded Linux file system, and test application
- Write and install a kernel module
- Pass parameters to a kernel module
- Write a kernel module that accesses kernel variable

## Steps:

- Build Kernel Image
- Install Linux cross compiler toolchain (Ubuntu/Linaro)
- Build root file system with Busybox

### Do the following:

Write a kernel module that accepts as command line parameters the name of the person to be greeted and the number of times the greeting is to be printed.

The /proc file system mechanism for the kernel and kernel modules to send
information to processes. Originally designed to allow easy access to information
about processes (hence the name), it is now used by every bit of the kernel
which has something interesting to report, such as /proc/modules which provides
the list of modules and /proc/meminfo ​ which stats memory usage statistics.
Examine the ​ /proc ​ on your Linux machine (VM or laptop).

System timers interrupt the processor at programmable frequencies. This
frequency, or the number of timer ticks per second, is contained in the kernel
variable HZ. The jiffies variable holds the number of times the system timer
popped since the system booted. The kernel increments jiffies HZ times every
second. Thus, on a kernel with a HZ value of 100, a “jiffy” is a 10-millisecond
duration, while on a kernel with HZ set to 1000, a jiffy is only 1-millisecond. Write
a kernel module (jiffies module) that uses the jiffies and HZ kernel variables to
write the value of time since bootup to ​ /proc ​ .
