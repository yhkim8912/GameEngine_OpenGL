#ifndef __SELECTIONBOX_H
#define __SELECTIONBOX_H

#include <GL/glew.h>

struct SelectionBox {
	SelectionBox() {
		x_max = 0;
		x_min = 0;
		y_max = 0;
		y_min = 0;
		z_max = 0;
		z_min = 0;
	}

	float x_max;
	float x_min;
	float y_max;
	float y_min;
	float z_max;
	float z_min;
	glm::vec3 vertices[8];
};

#endif