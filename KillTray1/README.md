# 结束HipsTray.exe

## 描述

非常出乎我的意料。火绒保护它的进程不被结束，却忘记了保护它的线程... 于是思路很简单: 使用`RtlAdjustPrivilege`函数提权，然后找到它的进程，列出对应的所有线程，然后全部杀光。搞定！原理跟[KillHipsDaemon](/KillHipsDaemon)里介绍的一样，只不过换了个进程名而已。

源码: [KillHipsTray.c](KillHipsTray.c)

# Termiante HipsTray.exe

## Description

Very unexpected. Huorong protects its process from being terminated, but forgets to protect its threads... So the idea is very simple: use `RtlAdjustPrivilege` function to raise privilege, then find its process, list all corresponding threads, and then kill them all. Done! The idea is the same as introduced in [KillHipsDaemon](/KillHipsDaemon), except the process name is different.

Source code: [KillHipsTray.c](KillHipsTray.c)

# 效果 / Effect
![](GIF.gif)