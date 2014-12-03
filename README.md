glmCamera
=========

A simple camera class that uses glm as a backend
This class is about as simple as it gets, it barely does any work for you.
It is just about as unimpressive as it gets.

I've only built this on Linux, but I believe there is no platform specific code.

Usage
-----
To initalize the camera simply use the provided functions, or access the data
directly, then generate the matrices:
```C++
cam.pos = glm::vec3(10.0f, 10.0f, 8.0f); // Some arbitrary position for the cam
cam.up = glm::vec3(0.0f, 1.0f, 0.0f); // Set the up vector as Y
cam.ar = 640.0f / 480.0f; // Set the aspect ratio, window size is 640x480
cam.angle = 1.13446; //65 degrees // Set the field of view angle
cam.near = 0.1; // Set the near clipping plane distance
cam.far = 100.0; // Set the far clipping plane distance
cam.genViewMat(); // Generate the View matrix
cam.genProjMat(); // Generate the Projection Matrix
```

For the most part this isn't any different from using glm to manipulate a
graphics matrix in the first place, for example, rotate the view matrix
1 degree(0.017453 in radians) about the Y axis:
```C++
cam.view = glm::rotate(cam.view, 0.017453f, glm::vec3(0.0f, 1.0f, 0.0f));
```

### Use with OpenGL
Note: This code uses uniforms in the shader code to manipulate the vertices
being drawn, so if you want to use it with legacy OpenGL, you'll probably
just have to look into how to load a glm matrix into the fixed pipeline
I'm sure the documentation is abundant.
```C++
glBindVertexArray(vao);
glUseProgram(shaderProgram);
glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
glClear(GL_COLOR_BUFFER_BIT);
glUniformMatrix4fv(uni_model, 1, GL_FALSE, glm::value_ptr(model));
glUniformMatrix4fv(uni_view, 1, GL_FALSE, cam.getViewMatRef());
glUniformMatrix4fv(uni_proj, 1, GL_FALSE, cam.getProjMatRef());
glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_SHORT, 0);
glUseProgram(0);
glBindVertexArray(0);
```

TODO
----
* Include an orthographic interface
* Upload an example program using the code

