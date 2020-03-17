# 火绒安全软件漏洞

## 描述

火绒安全软件的名声一直挺不错的（至少我看来），并且以查杀准确、快速而收到不少好评。但是我在测试的时候发现其自我防护还尚有欠缺，还望尽快修复。值得一提的是，这个仓库里面涉及到的技术并不深奥，并且有些漏洞甚至不需要管理员权限就能被利用。

## 警告

创建该仓库的目的是测试及学习用途。对于您如何使用这个仓库里的内容，本人概不负责。请不要把该仓库里的内容用于任何不正当的用途。您只应该在自己的设备上或者你的虚拟机中测试该仓库里面涉及到的技术。

## 测试环境

火绒安全软件版本: 5.0.39.7

操作系统: Windows 10 1909 x64

## 漏洞

请进入文件夹查看对应漏洞的详情

| 文件夹 | 需要管理员权限 | 描述 |
|-----------------------------------|----------------|------------------------------------------|
| [KillHipsDaemon](/KillHipsDaemon) | 是 | 火绒防护程序HipsDaemon.exe的自我保护漏洞 |
| [KillTray1](/KillTray1) | 是 | 火绒托盘程序HipsTray.exe的自我保护漏洞 |
| [KillTray2](/KillTray2) | 否 | 火绒托盘程序HipsTray.exe的自我保护漏洞 |
| [PromptBypass1](/PromptBypass1) | 否 | 火绒的防护弹窗的漏洞 |
| [PromptBypass2](/PromptBypass2) | 否 | 火绒防护程序的通讯漏洞 |

# Huorong Internet Security Vulnerabilities

## Description

Huorong Internet Security has a good reputation (at least in my opinion) and it received a lot of praise for its accuracy and rapidity. However, during my testing, I found that there are still some flaws in its self-protection. I hope they can be repaired as soon as possible. It is worth mentioning that the technology involved in this repository is not difficult, and some vulnerability can be exploited even without administrative privilege.

## Warning

This repository is created for testing and educational purposes. I do not take any responsibility for what you do with the contents in this repository. Do not use the contents of this repository for any improper purpose. You should only test the technology involved in this repository on your own equipment or in your virtual machine.

## Testing Environment

Huorong Internet Security Version: 5.0.39.7

Operating System: Windows 10 1909 x64

## Vulnerabilities

Please enter the folders to see corresponding vulnerability details

| Folder | Administrative Privilege Required | Description |
|-----------------------------------|----------------|------------------------------------------|
| [KillHipsDaemon](/KillHipsDaemon) | Yes | Self-protection vulnerability of Huorong Internet Security daemon process HipsDaemon.exe |
| [KillTray1](/KillTray1) | Yes | Self-protection vulnerability of Huorong Internet Security Tray process HipsTray.exe |
| [KillTray2](/KillTray2) | No | Self-protection vulnerability of Huorong Internet Security Tray process HipsTray.exe |
| [PromptBypass1](/PromptBypass1) | No | Huorong popup prompt vulnerability |
| [PromptBypass2](/PromptBypass2) | No | Communication vulnerability of Huorong Internet Security |
