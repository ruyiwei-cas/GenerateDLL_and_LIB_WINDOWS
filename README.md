# GenerateDLL_and_LIB_WINDOWS
在windows下生成动态库与静态库，在动态库下导出需要的函数

---
## 在windows下利用visual studio生成静态库

利用visual studio 生成静态库相对的容易很多，如果我们已经有了已经工程，希望利用这个工程生成静态库，就只需要去掉工程中的main()函数所在的cpp文件，然后在
> 属性-常规-配置类型中，改为静态库(.lib)，同时目标文件扩展名改为.lib
就可以了，然后重新生成就可以在输出目录获得对应的静态库了

*因为静态库的生成相对简单很多，所以我们在git中放的是生成动态库的工程，但是如果要变成生成静态库的工程，只需要按照上面的方法修改一下就可以了*
---
## 在windows下利用visual studio生成动态库

和动态库连接的可执行文件中只含有函数引用表，而不是所有的函数代码，所以我们需要告诉动态库需要导出哪个函数，我们可以利用下面的模板来导出需要的函数，也很推荐这样的方式，因为这样可以在windows和linux下都可以使用这个文件，而不需要修改。
```c
#pragma once
#include<iostream>
#include<algorithm>
using namespace std;
#ifdef __linux__
#define FUNCTION_EXPORT __attribut__ ((visibility("default")))
#else
#define FUNCTION_EXPORT __declspec(dllexport)
#endif // __linux || __linux__

FUNCTION_EXPORT
int calcRectArea(int width, int height);
```
和生成静态库的过程类似，我们修改如下，同样需要去掉main入口
>属性-常规-配置类型中，改为静态库(.lib)，同时目标文件扩展名改为.lib
这样就可以生成静态库了

---
具体的，就下载工程自己体验吧，如果有问题联系我的邮箱 ruyiwei.cas@gmail.com
