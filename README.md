# OpenGL-For-MineCraft
本学期上了一门计算机与图形学课，决定趁势研究一下minecraft怎么做出来的，每周更新！

### Mission impossible Update:
###按键控制：
W-人物前进  
A-人物左移  
S-人物后退  
D-人物右移

H-模式切换  
>0-上帝模式  
1-第一人称视角模式   
2-第三人称视角模式   
3-虚拟球模式  

R——虚拟球模式    
Z——飞机复位  

###鼠标操作：
上帝模式下，点击左键——放大视角，点击右键——缩小视角  
第一人称视角模式，点击左键——放置TNT，点击右键——放置火炬  

### Mission 4 Update:
1. 添加了光照
2. 添加了obj读写文件方式

###本程序在 OSX 10.11.1 系统下编译通过。
如果要在Windows下编译运行运行需要把当前程序中的 #include <GLUT/glut.h> 替换成 #include <gl/GLUT.h> ，再将源文件和头文件拷贝入 Visual Studio 新工程，用 Visual Studio 编译运行即可。

Mac OSX 编译运行方法：
打开终端，cd到程序所在的路径，然后在终端中输入 g++ -framework OpenGL -framework GLUT -framework Foundation 源程序.cpp -o 1，运行则输入 ./1

举个栗子：
加入现在在 User/yanshengjia/Desktop 路径下有我们的OpenGL小程序 opengl.cpp

那么我们只需要在 终端 中输入：
cd /User/yanshengjia/Desktop, 回车
g++ -framework OpenGL -framework GLUT -framework Foundation opengl.cpp -o 1, 回车
./1, 回车
这样就能成功编译运行了。

