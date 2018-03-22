# Hikari
Hikari(Light in Japanese, name stolen from the Nintendo Switch game [Xenoblade Chronicles 2](http://www.nintendo.co.uk/Games/Nintendo-Switch/Xenoblade-Chronicles-2-1233955.html)) is my hackathon-ishtoy project for the 2017 Christmas to kill time.It's already stable enough to use in production environment. However, as initially planned, Hikari will be ported to LLVM 6.0 release version after it's released, then it will no longer be maintained for obvious reasons (Time & effort it takes, retards spamming my personal email asking for support,etc). You can find the history of its development at ``developer`` branch. Further enhancements include more features like Code-Intergrity Checking and a full anti-hook implementation. These are not open-source and will probably be released as a commercial product. If you know me close enough we can discuss the license model and pricing issue because I might not be able to provide real-time bug fix and stuff.
[English Documentation](https://naville.gitbooks.io/hikari/content/)    

# 光
[中文文档](https://naville.gitbooks.io/hikaricn/content/)  
Hikari(即日语中的光,命名来源自NS游戏异度之刃2) 是我在2017年圣诞节期间的玩具项目,目前已经足够稳定可以在生产环境中使用。然而，正如一开始所计划的那样。在LLVM6.0正式Release之后, Hikari将被移植到Release版本并由于显而易见的原因终止支持(时间和精力成本,吸引来的弱智骚扰我的私人联系方式，等等)。你可以在``developer`` 分支上找到开发历史。后续的额外更新包含例如代码完整性校验以及完整的反Hook等功能，这一部分并不开源并且可能会在机会合适的情况下作为商业产品的一部分放出。 如果您私底下认识我，我们或许可以讨论授权模式和价格等问题

# macOS快速安装 macOS Quick Installation
**这基于LLVM6.0 RC3而非正式发布版，您可能会遇到一些奇怪的问题**  
**2018/03/02 LLVM6.0最终版已经确定，和下面的RC3版唯一的区别是X86后端的一处Bug修复，我懒得再移植一次了，如果您有需要请按照Wiki的描述手动移植**  
**This is based on top of LLVM6.0 RC3, which is not a final release version.Things might break!**  
**6.0.0 has been finalized on 2018/03/02, the only major difference between final and RC3 is a bug fix in X86 backend.I didn't bother porting Hikari all over again.If you are concerned about this, port Hikari yourself following the Wiki page**

```
git clone -b 6.0-rc3 https://github.com/HikariObfuscator/Hikari.git Hikari \
&& mkdir Build && cd Build && \
cmake -G "Ninja" -DCMAKE_BUILD_TYPE=MinSizeRel -DLLVM_APPEND_VC_REV=on -DLLVM_CREATE_XCODE_TOOLCHAIN=on \
-DCMAKE_INSTALL_PREFIX=~/Library/Developer/ ../Hikari && ninja &&ninja install-xcode-toolchain && git clone \
https://github.com/HikariObfuscator/Resources.git ~/Hikari && rsync -ua \ /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/ \ ~/Library/Developer/Toolchains/Hikari.xctoolchain/ && \
rm ~/Library/Developer/Toolchains/Hikari.xctoolchain/ToolchainInfo.plist
```

# 已知问题 Known Issues
- Running AntiClassDump On A File Without ObjC Class will crash the executable.在没有ObjC类的源码里打开反class-dump后编译产物会崩溃
- AntiHook is broken in many many ways to an extent beyond fixable. 不要打开AntiHook

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


