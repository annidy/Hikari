# Hikari
[![Build Status](https://travis-ci.org/HikariObfuscator/Hikari.svg?branch=release_60)](https://travis-ci.org/HikariObfuscator/Hikari)

[English Documentation](https://naville.gitbooks.io/hikari/content/)   
Hikari(Light in Japanese, name stolen from the Nintendo Switch game [Xenoblade Chronicles 2](http://www.nintendo.co.uk/Games/Nintendo-Switch/Xenoblade-Chronicles-2-1233955.html)) is my hackathon-ishtoy project for the 2017 Christmas to kill time.It's already stable enough to use in production environment. However, as initially planned, Hikari  has been ported to LLVM 6.0 release version and no longer being actively maintained due to the time and effort it takes. You can find the history of its development at ``developer`` branch. Further enhancements include more features like Code-Intergrity Checking and a full anti-hook implementation. These are not open-source and will probably be released as a commercial product. If you know me close enough we can discuss the license model and pricing issue because I might not be able to provide real-time bug fix and stuff.

# License
Hikari is relicensed from Obfuscator-LLVM and LLVM upstream's permissive NCSA license to GNU Affero General Public License Version 3. tl;dr: The obfuscated LLVM IR and/or obfuscated binary is not restricted in anyway, however **any other project containing code from Hikari needs to be open source and licensed under AGPLV3 as well, even for web-based obfuscation services**.  

# macOS Quick Install
This script assumes current working directory is not the user's home directory(aka ``~/``). ``cd`` to some where else if this is the case.  This script also assumes you have ``cmake`` and ``ninja`` installed, if not, use [Homebrew](https://brew.sh) and similar package managers to install them    

```
git clone -b release_70 https://github.com/HikariObfuscator/Hikari.git Hikari \
&& mkdir Build && cd Build && \
cmake -G "Ninja" -DCMAKE_BUILD_TYPE=MinSizeRel -DLLVM_APPEND_VC_REV=on -DLLVM_CREATE_XCODE_TOOLCHAIN=on \
-DCMAKE_INSTALL_PREFIX=~/Library/Developer/ ../Hikari && ninja &&ninja install-xcode-toolchain && git clone \
https://github.com/HikariObfuscator/Resources.git ~/Hikari && rsync -a --ignore-existing \ /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/ \ ~/Library/Developer/Toolchains/Hikari.xctoolchain/ && \
rm ~/Library/Developer/Toolchains/Hikari.xctoolchain/ToolchainInfo.plist
```

# Building on Unix
Most parts are the same, you just remove all the commands related to Xcode

```
git clone -b release_70 https://github.com/HikariObfuscator/Hikari.git Hikari \
&& mkdir Build && cd Build && \
cmake -G "Ninja" -DCMAKE_BUILD_TYPE=MinSizeRel -DLLVM_APPEND_VC_REV=on -DLLVM_CREATE_XCODE_TOOLCHAIN=on \
-DCMAKE_INSTALL_PREFIX=~/Library/Developer/ ../Hikari && ninja && ninja install && git clone \
https://github.com/HikariObfuscator/Resources.git ~/Hikari
```

# Building on Windows
You can either use a UNIX-Like environment like MinGW / Cygwin, or just edit ``lib/Transforms/Obfuscation/FunctionCallObfuscate.cpp`` ,remove ``#include <dlfcn.h>`` and then clean up all function bodies in this file, and add ``return false`` if required. Since that thingy isn't supported on Windows anyway.

~~Or, you know, try switch to another OS that isn't developed by retards instead of using some expensive and buggy OS that nobody really cares about.~~


# Known Issues
- Running AntiClassDump On A File Without ObjC Class will crash the executable.

# Extra Features in Commercial Version:
- GlobalVariable Reference Obfuscation
- Target Jump Address in IndirectBranch Obfuscation
- Anti Disassembler on Certain Archs
- Constant Encryption
- Code Integrity Protection(aka Anti InlineHook,Anti Patching)(Currently supports iOS/macOS only)
- Swift 4.1 Support
- Support all terminators in Flattening, open-source version simply skips the whole function if it contains unsupported instruction
- And many bug fixes

# Work In Progress Features in Commercial Version
- Virtualization
- C++ RTTI Obfuscation
- Syscall Lowering

# Demo   
**This only demonstrates a limited part of Hikari's capabilities. Download the complete demo and analyze yourself, link in the documentation**  
![AntiClassDump](https://github.com/HikariObfuscator/Hikari/blob/master/Images/AntiClassDump.jpeg?raw=true)  
![FunctionWrapper](https://github.com/HikariObfuscator/Hikari/blob/master/Images/FunctionWrapper.jpeg?raw=true)  
![IndirectBranch](https://github.com/HikariObfuscator/Hikari/blob/master/Images/IndirectBranch.jpeg?raw=true)
![InstructionReplacement](https://github.com/HikariObfuscator/Hikari/blob/master/Images/InstructionReplacement.jpeg?raw=true)
![StringEncryption](https://github.com/HikariObfuscator/Hikari/blob/master/Images/StringEncryption.jpeg?raw=true)
