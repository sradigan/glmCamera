#define GLM_FORCE_RADIANS
#include "glmCamera.h"

///
glmCamera::glmCamera()
{
	ar = 4.0f / 3.0f;
	#ifdef GLM_FORCE_RADIANS
		angle = 0.785398f; //45 degrees
	#else
		angle = 45.0f; //45 degrees
	#endif
	near = 0.1f;
	far = 100.0f;
}

void glmCamera::setCameraPos(const glm::vec3& v)
{
	pos = v;
}

void glmCamera::setCameraFocus(const glm::vec3& v)
{
	fp = v;
}

void glmCamera::setCameraUpVec(const glm::vec3& v)
{
	up = v;
}

void glmCamera::setAspectRatio(const float ar)
{
	this->ar = ar;
}

void glmCamera::setViewAngle(const float a)
{
	angle = a;
}

void glmCamera::setNearClipDist(const float d)
{
	near = d;
}

void glmCamera::setFarClipDist(const float d)
{
	far = d;
}

glm::mat4 glmCamera::getViewMat()
{
	return view;
}

float* glmCamera::getViewMatRef()
{
	return glm::value_ptr(view);
}

glm::mat4 glmCamera::getProjMat()
{
	return proj;
}

float* glmCamera::getProjMatRef()
{
	return glm::value_ptr(proj);
}

void glmCamera::genViewMat()
{
	view = glm::lookAt(pos, fp, up);
}

void glmCamera::genProjMat()
{
	proj = glm::perspective(angle, ar, near, far);
}
