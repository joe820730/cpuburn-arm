cpuburn
=======

A collection of cpuburn programs tuned for different ARM hardware

Compile:
--------
Download NDK from https://developer.android.com/ndk/downloads and extract it.
Set NDK_ROOT path:
```bash
export NDK_ROOT=/path/to/your/ndk
```
Run the build script:
```bash
./build.sh
```

Run:
----
Push the binary to your device:
```bash
adb push out/cpuburn-arm64 /data/local/tmp/
```
Run the binary on your device:
```bash
adb shell
cd /data/local/tmp
chmod +x cpuburn-arm64
./cpuburn-arm64
```
