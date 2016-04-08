#pragma once
#include"Param.h"
GLuint base;

GLvoid BuildFont(GLvoid)										// Build Our Font Display List
{
	base = glGenLists(95);										// Creating 95 Display Lists
	glBindTexture(GL_TEXTURE_2D, Cube::texWater);			// Bind Our Font Texture
	for (int loop = 0; loop<95; loop++)							// Loop Through All 95 Lists
	{
		float cx = float(loop % 16) / 16.0f;							// X Position Of Current Character
		float cy = float(loop / 16) / 8.0f;							// Y Position Of Current Character

		glNewList(base + loop, GL_COMPILE);						// Start Building A List
		glBegin(GL_QUADS);									// Use A Quad For Each Character
		glTexCoord2f(cx, 1.0f - cy - 0.120f); glVertex2i(0, 0);	// Texture / Vertex Coord (Bottom Left)
		glTexCoord2f(cx + 0.0625f, 1.0f - cy - 0.120f); glVertex2i(16, 0);	// Texutre / Vertex Coord (Bottom Right)
		glTexCoord2f(cx + 0.0625f, 1.0f - cy);		  glVertex2i(16, 16);// Texture / Vertex Coord (Top Right)
		glTexCoord2f(cx, 1.0f - cy);		  glVertex2i(0, 16);	// Texture / Vertex Coord (Top Left)
		glEnd();											// Done Building Our Quad (Character)
		glTranslated(10, 0, 0);								// Move To The Right Of The Character
		glEndList();											// Done Building The Display List
	}															// Loop Until All 256 Are Built
}
GLvoid glPrint(GLint x, GLint y, const char *string, ...)		// Where The Printing Happens
{
	char		text[256];										// Holds Our String
	va_list		ap;												// Pointer To List Of Arguments

	if (string == NULL)											// If There's No Text
		return;													// Do Nothing

	va_start(ap, string);										// Parses The String For Variables
	vsprintf(text, string, ap);								// And Converts Symbols To Actual Numbers
	va_end(ap);													// Results Are Stored In Text

	glColor3f(0.0f, 0.0f, 0.0f);
	glPushMatrix();												// Store The Modelview Matrix
	glLoadIdentity();											// Reset The Modelview Matrix
	glTranslated(x, y, 0);										// Position The Text (0,0 - Bottom Left)
	glListBase(base - 32);										// Choose The Font Set
	glCallLists(strlen(text), GL_UNSIGNED_BYTE, text);			// Draws The Display List Text
	glPopMatrix();												// Restore The Old Projection Matrix
}

void initLable()
{
	RECT window;												// Storage For Window Dimensions					// Get Window Dimensions
	glMatrixMode(GL_PROJECTION);								// Select The Projection Matrix
	glPushMatrix();												// Store The Projection Matrix
	glLoadIdentity();											// Reset The Projection Matrix
	glOrtho(0,WindowWidth, 0, WindowHeight, -1, 1);				// Set Up An Ortho Screen
	glMatrixMode(GL_MODELVIEW);									// Select The Modelview Matrix


																// Game Stats / Title
	glPrint(240, 450, "NeHe Productions");						// Print Title




	glMatrixMode(GL_PROJECTION);								// Select The Projection Matrix
	glPopMatrix();												// Restore The Old Projection Matrix
	glMatrixMode(GL_MODELVIEW);									// Select The Modelview Matrix

	glFlush();
}

