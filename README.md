# Hikari | 光
[![Build Status](https://travis-ci.org/HikariObfuscator/Hikari.svg?branch=release_60)](https://travis-ci.org/HikariObfuscator/Hikari)

[English Documentation](https://naville.gitbooks.io/hikari/content/)   
Hikari(Light in Japanese, name stolen from the Nintendo Switch game [Xenoblade Chronicles 2](http://www.nintendo.co.uk/Games/Nintendo-Switch/Xenoblade-Chronicles-2-1233955.html)) is my hackathon-ishtoy project for the 2017 Christmas to kill time.It's already stable enough to use in production environment. However, as initially planned, Hikari  has been ported to LLVM 6.0 release version and no longer being actively maintained due to the time and effort it takes. You can find the history of its development at ``developer`` branch. Further enhancements include more features like Code-Intergrity Checking and a full anti-hook implementation. These are not open-source and will probably be released as a commercial product. If you know me close enough we can discuss the license model and pricing issue because I might not be able to provide real-time bug fix and stuff.

 
[中文文档](https://naville.gitbooks.io/hikaricn/content/)  
Hikari(即日语中的光,命名来源自NS游戏异度之刃2) 是我在2017年圣诞节期间的玩具项目,目前已经足够稳定可以在生产环境中使用。然而，正如一开始所计划的那样。Hikari已经被移植到LLVM 6.0Release版本并由于时间和精力成本等原因终止支持。你可以在``developer`` 分支上找到开发历史。后续的额外更新包含例如代码完整性校验以及完整的反Hook等功能，这一部分并不开源并且可能会在机会合适的情况下作为商业产品的一部分放出。 如果您私底下认识我，我们或许可以讨论授权模式和价格等问题。 新浪微博@UnifiedFieldTheory 

# License | 授权
Hikari is relicensed from Obfuscator-LLVM and LLVM upstream's permissive NCSA license to GNU Affero General Public License Version 3. tl;dr: The obfuscated LLVM IR and/or obfuscated binary is not restricted in anyway, however **any other project containing code from Hikari needs to be open source and licensed under AGPLV3 as well, even for web-based obfuscation services**.  
光由Obfuscator-LLVM的宽松NCSA开源许可转授权至AGPL V3. 简单的说: 编译出来的混淆后二进制或LLVM中间表示不受任何限制，但**任何使用了Hikari代码的项目都必须以同样的AGPL V3许可开源,即使是作为在线的服务提供**。

# macOS快速安装 | macOS Quick Installation
This script assumes current working directory is not the user's home directory(aka ``~/``). ``cd`` to some where else if this is the case.  This script also assumes you have ``cmake`` and ``ninja`` installed, if not, use [Homebrew](https://brew.sh) and similar package managers to install them    
这个脚本假设当前工作目录不是用户的家目录(即``~/``) ，如果是的话请先cd到其他目录。这个脚本也假设您的macOS中有安装cmake和ninja，如果没有的话请使用[Homebrew](https://brew.sh)之类的包管理工具先行安装

```
git clone -b release_60 https://github.com/HikariObfuscator/Hikari.git Hikari \
&& mkdir Build && cd Build && \
cmake -G "Ninja" -DCMAKE_BUILD_TYPE=MinSizeRel -DLLVM_APPEND_VC_REV=on -DLLVM_CREATE_XCODE_TOOLCHAIN=on \
-DCMAKE_INSTALL_PREFIX=~/Library/Developer/ ../Hikari && ninja &&ninja install-xcode-toolchain && git clone \
https://github.com/HikariObfuscator/Resources.git ~/Hikari && rsync -ua \ /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/ \ ~/Library/Developer/Toolchains/Hikari.xctoolchain/ && \
rm ~/Library/Developer/Toolchains/Hikari.xctoolchain/ToolchainInfo.plist
```

# 已知问题 Known Issues
- Running AntiClassDump On A File Without ObjC Class will crash the executable.在没有ObjC类的源码里打开反class-dump后编译产物会崩溃

# 商业版功能 Extra Features in Commercial Version:
- 虚拟化 | Virtualization (WIP)
- 全局变量引用混淆 | GlobalVariable Reference Obfuscation
- 间接跳转目标地址混淆 | Target Jump Address in IndirectBranch Obfuscation
- 特定架构下花指令 | Anti Disassembler on Certain Archs
- 常量加密 | Constant Encryption
- 代码完整性校验(即反内连Hook,反Patch)(目前只支持iOS) | Code Integrity Protection(aka Anti InlineHook,Anti Patching)(Currently supports iOS only)
- Swift 4.1 | 支持Swift混淆。基于Swift4.1版本
- 以及许多许多的Bug修复 | And many bug fixes

# 售价及购买模式 | Commercial Pricing Options
## 单次购买 | Pay-Per-Usage
- 1000RMB / 1 usage(Up to 3 architectures of the same code). Discount on bulk purchasing
- You provide the original bitcode or a buildable source code, specify the obfuscation options to use and get obfuscated binary
- Any undiscovered potential bugs affecting the obfuscated binary are fixed during obfuscation so you get a workable binary.

- 单次收费1000元，每次最多可支持同一份代码的最多三种架构。一次性购买多份有折扣。
- 你需要提供原始Bitcode或者是可编译工程。指明混淆选项，得到混淆后二进制
- 任何未发现的导致混淆后二进制不可用的Bug将在混淆过程中被修复

## 订阅制 | Subscription-Based
- You get the whole toolchain for offline usage. Protected under VMProtect and watermarked
- 30000RMB / year
- Regular Updates
- Bugs are fixed at a "best-effort" basis since under rare circumstances the bug is related to LLVM upstream in which case is difficult to fix personally.
- Porting to other LLVM/Swift versions is available upon request, however help regarding to intergration with the IDE of your choice is not guaranteed. (Usually easy and could be found using Google)


- 你获得完整的离线工具链。使用VMProtect加壳并有水印
- 30000RMB / 年
- 定期更新
- 尽最大努力进行Bug修复，这是由于在极少数情况下Bug来自LLVM上流而非混淆，故需提交Bug至上流以待修复
- 提供其他LLVM/Swift版本的移植，但与IDE等开发环境的集成教程恕不保证提供。(大多数时候都可以在Google上找到且并不耗时)


## 定制混淆 | Customized Obfuscation Pass
- You specify a requirement that is suitable to your organization's need.
- I will evaluate if the requirement if possible and how much it will cost you.
- You get the full source of the obfuscation pass as well as following updates.
- This pass is exclusive to your copy is not provided to anyone else.

- 你按照企业需求提出定制的混淆Pass
- 我在分析需求后决定是否制作以及定制价格
- 你获得Pass的完整源码以及后续更新服务
- 这个Pass由你或你的组织独享，不在其他任何副本中提供


# 演示 Demo
**这远非完整效果，请下载文档中的Demo自行分析查看**    
**This only demonstrates a limited part of Hikari's capabilities. Download the complete demo and analyze yourself, link in the documentation**  
- 反class-dump
	![AntiClassDump](https://github.com/HikariObfuscator/Hikari/blob/master/Images/AntiClassDump.jpeg?raw=true)  
- 函数封装
	![FunctionWrapper](https://github.com/HikariObfuscator/Hikari/blob/master/Images/FunctionWrapper.jpeg?raw=true)  
- 间接跳转
	![IndirectBranch](https://github.com/HikariObfuscator/Hikari/blob/master/Images/IndirectBranch.jpeg?raw=true)
- 指令替换
	![InstructionReplacement](https://github.com/HikariObfuscator/Hikari/blob/master/Images/InstructionReplacement.jpeg?raw=true)
- 字符串加密
	![StringEncryption](https://github.com/HikariObfuscator/Hikari/blob/master/Images/StringEncryption.jpeg?raw=true)
