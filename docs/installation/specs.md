# Hardware specification of development environment

```sh
$ uname -r
5.0.0-27-generic
```

```sh
Some of the Hardware Information:

*-shashank-inspiron-15-3567   
    description: Laptop
    product: Inspiron 15-3567 (078B)
    vendor: Dell Inc.
    serial: DW462F2
    width: 64 bits
    capabilities: smbios-3.1 dmi-3.1 smp vsyscall32

*-memory
          description: System Memory
          physical id: 3d
          slot: System board or motherboard
          size: 8GiB
        *-bank:0
             description: SODIMM DDR4 Synchronous Unbuffered (Unregistered) 2400 MHz (0.4 ns)
             product: 4ATF51264HZ-2G3B1
             vendor: Micron Technology
             physical id: 0
             serial: 1279CD2A
             slot: DIMM A
             size: 4GiB
             width: 64 bits
             clock: 2400MHz (0.4ns)
        *-bank:1
             description: SODIMM DDR4 Synchronous Unbuffered (Unregistered) 2400 MHz (0.4 ns)
             product: 4ATF51264HZ-2G3B1
             vendor: Micron Technology
             physical id: 1
             serial: 13F7A7EE
             slot: DIMM B
             size: 4GiB
             width: 64 bits
             clock: 2400MHz (0.4ns)
*-core
       description: Motherboard
       product: 0D53F5
       vendor: Dell Inc.
       physical id: 0
       version: A00
       serial: /DW462F2/CNWSC0072K016C/
     *-firmware
          description: BIOS
          vendor: Dell Inc.
          physical id: 0
          version: 2.8.0
          date: 12/05/2018
          size: 64KiB
          capacity: 15MiB
          capabilities: pci pnp upgrade shadowing cdboot bootselect edd int13floppynec int13floppy1200 int13floppy720 int13floppy2880 int5printscreen int9keyboard int14serial int17printer acpi usb smartbattery biosbootspecification netboot uefi
*-cpu
          description: CPU
          product: Intel(R) Core(TM) i5-7200U CPU @ 2.50GHz
          vendor: Intel Corp.
          physical id: 44
          bus info: cpu@0
          version: Intel(R) Core(TM) i5-7200U CPU @ 2.50GHz
          serial: To Be Filled By O.E.M.
          slot: U3E1
          size: 1769MHz
          capacity: 3100MHz
          width: 64 bits
          clock: 100MHz
          capabilities: x86-64 fpu fpu_exception wp vme de pse tsc msr pae mce cx8 apic sep mtrr pge mca cmov pat pse36 clflush dts acpi mmx fxsr sse sse2 ss ht tm pbe syscall nx pdpe1gb rdtscp constant_tsc art arch_perfmon pebs bts rep_good nopl xtopology nonstop_tsc cpuid aperfmperf tsc_known_freq pni pclmulqdq dtes64 monitor ds_cpl vmx est tm2 ssse3 sdbg fma cx16 xtpr pdcm pcid sse4_1 sse4_2 x2apic movbe popcnt tsc_deadline_timer aes xsave avx f16c rdrand lahf_lm abm 3dnowprefetch cpuid_fault epb invpcid_single pti ssbd ibrs ibpb stibp tpr_shadow vnmi flexpriority ept vpid ept_ad fsgsbase tsc_adjust bmi1 avx2 smep bmi2 erms invpcid mpx rdseed adx smap clflushopt intel_pt xsaveopt xsavec xgetbv1 xsaves dtherm ida arat pln pts hwp hwp_notify hwp_act_window hwp_epp md_clear flush_l1d cpufreq
          configuration: cores=2 enabledcores=2 threads=4
*-network
       description: Ethernet interface
       physical id: 2
       logical name: docker0
       serial: 02:42:8b:8d:29:74
       capabilities: ethernet physical
       configuration: broadcast=yes driver=bridge driverversion=2.3 firmware=N/A ip=172.17.0.1 link=no multicast=yes
```