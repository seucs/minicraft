//#include <gl/glut.h>
//#include <cstdlib>
//#include <iostream>
//#include <vector>
//#include <string>
//#include <algorithm>
//#include <fstream>
//#include <cstdio>
//using namespace std;
//
//float angle=10.0;        //旋转角度
//int graph;
//
//struct coordinate
//{
//  float x,y,z;
//  coordinate(float a, float b, float c) : x(a), y(b), z(c) {};
//};
//
//// 表面结构体，可以表示三角形或者四边形，变量flag表示
//struct face
//{
//    int facenum;
//    bool flag;
//    int faces[4];
//    face(int facen,int f1,int f2,int f3) : facenum(facen)
//    {
//      // 三角形
//      faces[0] = f1;
//      faces[1] = f2;
//      faces[2] = f3;
//      flag = false;
//    }
//    face(int facen,int f1,int f2,int f3,int f4) : facenum(facen)
//    {
//      // 重载的构造函数->四边形
//      faces[0] = f1;
//      faces[1] = f2;
//      faces[2] = f3;
//      faces[3] = f4;
//      flag = true;
//    }
//};
//
//int objLoader(const char* filename)
//
//{
//  vector<string*> coord;                                                        // 读入obj文件的每一行作为一个字符串
//  vector<coordinate*> vertex;                                                   // 顶点坐标 v
//  vector<face*> faces;                                                          // 表面 f
//  vector<coordinate*> normals;                                                  // 表面的法线向量 vn
//
//  ifstream in(filename);                                                        // 读文件
//
//  if(!in)                                                                       // 文件打开失败
//  {
//    cerr << "Cannot open " << filename << endl;
//    exit(1);
//  }
//
//  char buf[256];                                                                // 存字符串
//
//  // 把文件中每行读入 coord
//  while(!in.eof())
//  {
//    in.getline(buf,256);
//    coord.push_back(new string(buf));                                           // 读取到的一行字符串压入 coord
//  }
//
//  // 遍历 coord 的每个元素，判断匀速类型
//  for(int i=0; i<coord.size(); i++)
//  {
//    if((*coord[i])[0] == '#')                                                   // 字符串开头为 "#"，跳过
//      continue;
//    else if((*coord[i])[0] == 'v' && (*coord[i])[1] == ' ')                     // 假如是顶点坐标
//    {
//      float tmpx,tmpy,tmpz;
//      sscanf_s(coord[i] -> c_str(), "v %f %f %f", &tmpx, &tmpy, &tmpz);           // 读取3个float型变量到tmpx,tmpy,tmpz
//      vertex.push_back(new coordinate(tmpx, tmpy, tmpz));                       // 把 tmpx,tmpy,tmpz加到 vertex 数组末尾
//    }
//    else if((*coord[i])[0] == 'v' && (*coord[i])[1] == 'n')                     // 假如是表面的法线向量
//    {
//      float tmpx,tmpy,tmpz;
//      sscanf_s(coord[i]->c_str(), "vn %f %f %f", &tmpx, &tmpy, &tmpz);            // 读取指定格式的内容到变量中
//      // c_str()函数返回一个指向正规C字符串的指针, 内容与本string串相同.
//      // 这是为了与c语言兼容，在c语言中没有string类型，故必须通过string类对象的成员函数c_str()把string对象转换成c中的字符串样式。
//      normals.push_back(new coordinate(tmpx, tmpy, tmpz));
//    }
//    else if((*coord[i])[0] == 'f')                                              // 假如是表面
//    {
//      int a,b,c,d,e;
//			if(count(coord[i]->begin(),coord[i]->end(),' ')==3)	                      // 假如face是三角形，有3空格
//			{
//		    sscanf_s(coord[i]->c_str(),"f %d//%d %d//%d %d//%d",&a,&b,&c,&b,&d,&b);
//				faces.push_back(new face(b,a,c,d));
//			}
//      else                                                                      // 假如face是四边形，有4空格
//      {
//				sscanf_s(coord[i]->c_str(),"f %d//%d %d//%d %d//%d %d//%d",&a,&b,&c,&b,&d,&b,&e,&b);
//				faces.push_back(new face(b,a,c,d,e));
//			}
//		}
//	}
//
//  // 输出每种元素的个数
//  cout<<"v: "<<vertex.size()<<endl;
//  cout<<"vn: "<<normals.size()<<endl;
//  cout<<"f: "<<faces.size()<<endl;
//
//  // 画图
//	int num = 0;	                                                                // 列表id
//	num=glGenLists(1);	                                                          // 创造一个独特的列表id
//	glNewList(num,GL_COMPILE);                                                    // 显示列表函数原型
//
//	for(int i=0;i<faces.size();i++)
//	{
//		if(faces[i]->flag)	                                                        // 假如是四边形就画四边形
//		{
//			glBegin(GL_QUADS);
//				//basically all I do here, is use the facenum (so the number of the face) as an index for the normal, so the 1st normal owe to the first face
//				//I subtract 1 because the index start from 0 in C++
//				glNormal3f(normals[faces[i]->facenum-1]->x,normals[faces[i]->facenum-1]->y,normals[faces[i]->facenum-1]->z);
//				// 画表面
//				glVertex3f(vertex[faces[i]->faces[0]-1]->x,vertex[faces[i]->faces[0]-1]->y,vertex[faces[i]->faces[0]-1]->z);
//				glVertex3f(vertex[faces[i]->faces[1]-1]->x,vertex[faces[i]->faces[1]-1]->y,vertex[faces[i]->faces[1]-1]->z);
//				glVertex3f(vertex[faces[i]->faces[2]-1]->x,vertex[faces[i]->faces[2]-1]->y,vertex[faces[i]->faces[2]-1]->z);
//				glVertex3f(vertex[faces[i]->faces[3]-1]->x,vertex[faces[i]->faces[3]-1]->y,vertex[faces[i]->faces[3]-1]->z);
//			glEnd();
//		}
//    else
//    {
//			glBegin(GL_TRIANGLES);
//				glNormal3f(normals[faces[i]->facenum-1]->x,normals[faces[i]->facenum-1]->y,normals[faces[i]->facenum-1]->z);
//				glVertex3f(vertex[faces[i]->faces[0]-1]->x,vertex[faces[i]->faces[0]-1]->y,vertex[faces[i]->faces[0]-1]->z);
//				glVertex3f(vertex[faces[i]->faces[1]-1]->x,vertex[faces[i]->faces[1]-1]->y,vertex[faces[i]->faces[1]-1]->z);
//				glVertex3f(vertex[faces[i]->faces[2]-1]->x,vertex[faces[i]->faces[2]-1]->y,vertex[faces[i]->faces[2]-1]->z);
//			glEnd();
//		}
//	}
//	glEndList();
//
//	// 销毁内存
//	for(int i=0;i<coord.size();i++)
//		delete coord[i];
//	for(int i=0;i<faces.size();i++)
//		delete faces[i];
//	for(int i=0;i<normals.size();i++)
//		delete normals[i];
//	for(int i=0;i<vertex.size();i++)
//		delete vertex[i];
//
//	return num;
//}
//
//void reshape(int w, int h)
//{
//  GLfloat nRange = 80.0f;
//  // Prevent a divide by zero
//  if(h == 0)
//    h = 1;
//
//  // Set Viewport to window dimensions
//  glViewport(0, 0, w, h);
//
//  // Reset coordinate system
//  glMatrixMode(GL_PROJECTION);
//  glLoadIdentity();
//
//  // Establish clipping volume (left, right, bottom, top, near, far)
//  if (w <= h)
//    glOrtho (-nRange, nRange, -nRange*h/w, nRange*h/w, -nRange, nRange);
//  else
//    glOrtho (-nRange*w/h, nRange*w/h, -nRange, nRange, -nRange, nRange);
//
//  glMatrixMode(GL_MODELVIEW);
//  glLoadIdentity();
//}
//
//void key(unsigned char key, int x, int y)
//{
//    // 按ESC退出
//    if(key == 27)
//    {
//        cout<<"exit"<<endl;
//        exit(0);
//    }
//}
//
//void init()
//{
//  glClearColor(0.0,0.0,0.0,1.0);
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	// gluPerspective(45,640.0/480.0,1.0,500.0);
//	glMatrixMode(GL_MODELVIEW);
//	glEnable(GL_DEPTH_TEST);
//  graph = objLoader("test.obj");
//	glEnable(GL_LIGHTING);
//  glEnable(GL_LIGHT0);
//  GLfloat lightColor[] = {1.0f, 1.0f, 1.0f, 1.0f};                              // 光照颜色为白色
//  glLightfv(GL_LIGHT0, GL_DIFFUSE, lightColor);                                 // 光源中的散射光强度
//  glClearColor(1.0,1.0,1.0,0.0);                                                // 背景颜色
//}
//
//void display()
//{
//  angle += 0.01;
//  glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
//  glLoadIdentity();
//  float posLight0[]={-1.0,1.0,-2.0,1.0};                                        // 设置位置
//  glLightfv(GL_LIGHT0,GL_POSITION,posLight0);                                   // 指定第0号光源的位置      
//  cout << "14" << endl;// 保存当前矩阵
//  glScalef(10.0f, 10.0f, 10.0f);                                                // 缩放模型
//  glTranslatef(0.0,0.0,-5.0);
//  glRotatef(angle,0.0,0.0,1.0);
//	glCallList(graph);                                                            // 执行显示列表
//	glPopMatrix();                                                                // 弹出栈顶的矩阵
//	glutSwapBuffers();     // 交换两个缓冲区指针
//}
//
//int main(int argc,char** argv)
//{
//  glutInit(&argc, argv);
//  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
//  // 设置程序的窗口大小
//  GLint windowWidth = 800;
//  GLint windowHeight = 600;
//  glutInitWindowSize(windowWidth, windowHeight);
//  // 获取屏幕的宽和高
//  GLint SCREEN_WIDTH=glutGet(GLUT_SCREEN_WIDTH);
//  GLint SCREEN_HEIGHT=glutGet(GLUT_SCREEN_HEIGHT);
//  glutInitWindowPosition((SCREEN_WIDTH-windowWidth)/2,(SCREEN_HEIGHT-windowHeight)/2);
//  glutCreateWindow("objLoader");
//  init();
//  glutKeyboardFunc(key);
//  glutDisplayFunc(display);
//  glutReshapeFunc(reshape);
//  glutMainLoop();
//	return 0;
//}
