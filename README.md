# Polygon_run

This project involves making 3 dodecahedrons, and adding basic camera and object functionalities to them. This includes translation and rotational motion for both camera and object. It is a good introduction to computer graphics.

#### Installation

The project requires the GLEW, GLM, and GLFW libraries primarily. Please ensure these are working properly in the system.
Once the libraries are in order, these steps will help setup the build folder and create the executable:

```
mkdir build
cd build
cmake ..
make
./Polygon_run <arg>
```
#### Parameters

To select a particular dodecahedron, the program takes in command line arguments. Thus, when running the executable, provide one of the following as arguments:

- poly1
- poly2
- poly3

The keys to control the object are:

<strong>Object Control:</strong>

- W: Move up
- A: Move left
- S: Move down
- D: Move right
- E: Move front
- X: Move back
- R: Rotate object around axis
 
<strong>Camera Control:</strong>

- Up: Move up
- Left: Move left
- Down: Move down
- Right: Move right
- F: Move front
- C: Move back
- T: Rotate camera around object
- 1: Go to camera preset #1
- 2: Go to camera preset #2
- 3: Go to camera preset #3

<br>
##
Aakash Jain
Roll No- 2019101028
