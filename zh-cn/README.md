<h1 align="center">TPCL(Tools Public Class Library)</h1>

<div align="center">
  <a href="mailto:whitecat.this@gmail.com">
    <img src="https://img.shields.io/badge/AUTHOR-RAINBOWSCAT-brightgreen" alt="AUTHOR">
  </a>
  <a href="https://github.com/Cloudwhile/TPCL/releases/latest">
    <img src="https://img.shields.io/badge/VERSION-v0.0.1.7998_Alpha.1-ff69b4" alt="Latest Download">
  </a>
  <a href="https://github.com/Cloudwhile/TPCL/blob/master/LICENSE">
    <img src="https://img.shields.io/badge/LICENSE-Apache_2.0-blue" alt="LICENSE">
  </a>
</div>

<div align="center">
  <h3>
    <a>
      💮能够更快更便捷地编写C++！🤍
    </a>
  </h3>
  <h3>
    <a href="https://www.dofozero.top/tpcltools-public-class-library-for-cpp/">
      网站
    </a>
    <span> | </span>
    <a href="#description">
      描述
    </a>
    <span> | </span>
    <a href="https://github.com/Cloudwhile/TPCL/releases/tag/v0.0.1.6001-Alpha.1">
      下载
    </a>
     <span> | </span>
     <a href="#use-tpcl">
       使用 TPCL
     </a>
  </h3>
  <sub>
    适用于 Windows。
    <br>
    <a href="https://github.com/Cloudwhile/TPCL/">en-us</a> | <a href="https://github.com/Cloudwhile/TPCL/blob/master/zh-cn">中文</a>
  </sub>
</div>

<h2 align="center">描述</h2>
能够使编写C++更快更简单。

<h2 align="center">使用 TPCL</h2>

你可以 先[浏览这里](https://www.dofozero.top/tpcltools-public-class-library-for-cpp/) 来查看更多的细节。

1. 在你的项目中使用 TPCL。
   
   - 请确保你的C++编译器支持ISO/C++11标准。
   - 请确保你下载的 TPCL源文件是完整的。
   - 解压 TPCL源文件到你的项目文件根目录下。

2. 在你的项目文件夹中使用 ```#include "tpcl.h"``` 这条语句来导入 TPCL的功能。

3. 初始化 (实例化) tools 来使用这个类中可用的功能。像这样:
   
   ```C++
   #include "tpcl.h"
   #include <iostream>
   
   using namesapce std;
   int main(){
     stdtool::tools tool;
     //......语句
     return 0;
   }
   ```

<h2 align="center">TODO</h2>

- [x] 创建 TPCL 项目
- [x] 加入基础功能
- [x] 发布 TPCL第一个版本
- [x] 优化 TPCL的结构 ***[已完成！ Ver 0.0.1.7998 Alpha.1]***
- [x] 添加 **Windows** Ftp 通信功能
- [x] 添加 控制台字体颜色功能
- [x] 添加 进度条功能
- [x] 添加 writeFile **基本多功能**
- [x] 添加 **基本** readFile 功能
- [ ] 优化 TPCL 结构
- [ ] 支持 **Linux** & **Mac Os** 系统
- [ ] 添加 writeFile函数的**多功能模式**
- [ ] 添加 readFile函数**的多功能模式**
- [ ] 添加**基于sqlite**的本地数据库读写功能
- [ ] 添加**字符、字符串查找**功能
- [ ] 优化 TPCL结构
- [ ] 添加 **Windows** Http通信功能
- [ ] 升级 Https通信功能
