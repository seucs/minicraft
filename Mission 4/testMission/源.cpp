#include <gl/GLUT.h>

int main()
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Passenger and plane");
	init();

	//纹理相关设置
	//启用2D纹理和材质初始化
	glEnable(GL_TEXTURE_2D);
	// 在这里做一些初始化
	glEnable(GL_DEPTH_TEST);
	texGround = load_texture("ground.bmp");
	texWall = load_texture("wall.bmp");
	glTexParameterf(GL_NEAREST, GL_TEXTURE_WRAP_S, GL_REPEAT);


	refresh(0);

	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutPassiveMotionFunc(passiveMotion);

	glutMouseFunc(mouseButton);
	glutMotionFunc(mouseMotion);
	glutKeyboardUpFunc(controlup);
	glutKeyboardFunc(control);
	glutMainLoop();
	return 0;
}