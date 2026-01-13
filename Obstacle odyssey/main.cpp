#include <windows.h> // for MS Windows
#include <GL/glut.h> // GLUT, include glu.h and gl.h
#include<math.h>>
#include<cstdio>
#include <GL/gl.h>
#include <cmath>
#include <stdbool.h>
#define PI   3.14159265358979323846

// Setup OpenGL
void initOpenGL() {
    glClearColor(0.5f, 0.7f, 1.0f, 1.0f);  // Set background color (light blue)
    glOrtho(-1.0f, 1.0f, -1.0f, 1.0f, -1.0f, 1.0f);  // Orthographic projection (2D)
}

GLfloat position = 0.0f;
GLfloat speed = 0.01f;
void update(int value)
{
    if(position <-1.3)
        position = 1.50f;
    position -= speed;

	glutPostRedisplay();
	glutTimerFunc(100, update, 0);
}
GLfloat position4 = 0.0f; // Start at x = 1.0
GLfloat speed4 = 0.005f;   // Speed of movement

void update4(int value)
{
    if (position4 < -1.5f) // Reset position when it goes out of bounds
        position4 = 1.9f;

    position4 -= speed4; // Move left

    glutPostRedisplay();              // Redraw the scene
    glutTimerFunc(16, update4, 0);    // Call update4 after 16ms (~60 FPS)
}

//*********************
GLfloat position1 = 0.0f;
GLfloat speed1 = 0.1f;
void update1(int value)
{
    if(position1 <-1.365)
        position1 = 1.0f;
    position1 -= speed1;

	glutPostRedisplay();
	glutTimerFunc(100, update1, 0);
}
//******************
GLfloat position2 = -0.15f;  // Start at the top (positive Y-axis)
GLfloat speed2 = 0.015f;     // Speed at which it moves

void update2(int value)
{
    if(position2 < -0.35f)  // When it reaches the bottom (negative Y-axis), reset to the top
        position2 = -0.015f;

    position2 -= speed2;  // Move downward along the Y-axis (decrease position)

    glutPostRedisplay();  // Redraw the scene
    glutTimerFunc(100, update2, 0);  // Call update2 again after 100 ms
}
//***********************************************
// Function to draw a Rectangle
void drawRectangle(float x1, float y1, float x2, float y2) {
    glBegin(GL_POLYGON);
    glColor3f(0.5f, 0.5f, 0.5f); // Set the color to gray
    glVertex2f(x1, y1);
    glVertex2f(x1, y2);
    glVertex2f(x2, y2);
    glVertex2f(x2, y1);
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f); // Set the color to black
    glBegin(GL_LINE_LOOP);
    glVertex2f(x1, y1);
    glVertex2f(x1, y2);
    glVertex2f(x2, y2);
    glVertex2f(x2, y1);
    glEnd();
}

// Function to draw a Triangle with a fixed red color
void drawTriangle(float x1, float y1, float x2, float y2, float x3, float y3) {
    glColor3f(1.0f, 0.0f, 0.0f); // Set the color to red (RGB: 1.0, 0.0, 0.0)
    glBegin(GL_TRIANGLES);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glVertex2f(x3, y3);
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f); // Set outline color to black
    glBegin(GL_LINE_LOOP); // Draw the outline of the triangle
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glVertex2f(x3, y3);
    glEnd();
}
//****************rotation line
float angle = 0.0f;  // Initial rotation angle

void drawRotatedLine() {
    glPushMatrix();  // Save the current transformation state

    // Move the origin to the midpoint of the line (for rotation around its center)
    float centerX = -0.3f;  // X coordinate of the center
    float centerY = 0.2f; // Y coordinate of the center

    glTranslatef(centerX, centerY, 0.0f); // Translate to the center
    glRotatef(angle, 0.0f, 0.0f, 1.0f);  // Rotate around the Z-axis (in 2D)

    glTranslatef(-centerX, -centerY, 0.0f); // Translate back to the original position

    // Draw the line (now rotated around its center)
    glBegin(GL_LINES);
    glColor3f(1.0f, 0.0f, 0.0f);  // Red color
    glVertex2f(-0.3f, 0.2f);
    glVertex2f(-0.3f, 0.35f);
    glEnd();

    glPopMatrix();  // Restore the previous transformation state
}
void drawRotatedLine1() {
    glPushMatrix();  // Save the current transformation state

    // Move the origin to the midpoint of the line (for rotation around its center)
    float centerX = 0.5f;  // X coordinate of the center
    float centerY = 0.2f;  // Y coordinate of the center

    glTranslatef(centerX, centerY, 0.0f);  // Translate to the center
    glRotatef(-angle, 0.0f, 0.0f, 1.0f);  // Rotate clockwise (negative angle)

    glTranslatef(-centerX, -centerY, 0.0f); // Translate back to the original position

    // Draw the line (now rotated around its center)
    glBegin(GL_LINES);
    glColor3f(1.0f, 0.0f, 0.0f);  // Red color
    glVertex2f(0.5f, 0.2f);
    glVertex2f(0.5f, 0.35f);
    glEnd();

    glPopMatrix();  // Restore the previous transformation state
}


void updateR(int value) {
    angle += 1.0f;  // Increase the angle to rotate continuously (you can adjust speed)
    if (angle > 360.0f) {
        angle -= 360.0f;  // Keep angle within [0, 360]
    }

    glutPostRedisplay();  // Redraw the screen

    glutTimerFunc(16, updateR, 0);  // Call update every 16ms (60 FPS)
}
// Function to draw a circle
void drawCircle(GLfloat x, GLfloat y, GLfloat radius) {
    int i;
    int triangleAmount = 200; // Number of lines used to draw the circle
    GLfloat twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(x, y); // Center of circle
        for(i = 0; i <= triangleAmount; i++) {
            glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)),
                       y + (radius * sin(i * twicePi / triangleAmount)));
        }
    glEnd();
}






//Player
// Player Properties
float playerX = -0.95f;  // Initial X position
float playerY = -0.85f;   // Initial Y position
float playerRadius = 0.04f;  // Player radius for collision detection
float velocityY = 0.0f;   // Vertical velocity
float gravity = -0.0015f; // Gravity effect
float jumpForce = 0.03f;  // Jump force
bool isOnGround = false;  // Flag to check if the player is on the ground

// Platform properties for collision detection
struct Platform {
    float left, right, top, bottom;
};

// Multiple platforms
Platform platforms[] = {
    {-1.0f, 1.0f, -0.9f, -1.0f},  // Platform 1
    //{-1.0f, -0.6f, -0.4f, -0.5f},
    {-0.65f, -0.45f, -0.8f, -0.9f},
    {0.2f, 0.4f, -0.65f, -0.75f},  // First rectangle
    {0.4f, 0.2f, -0.7f, -0.5f},      // Platform 3
    {0.6f, 1.0f, 0.2f, 0.1f},      // Platform 4
    {-0.8f, -0.4f, 0.6f, 0.5f}     // Platform 5
};

// Function to check if the player is on any platform
bool checkCollision(const Platform& platform) {
    return (playerX + playerRadius > platform.left &&
            playerX - playerRadius < platform.right &&
            playerY - playerRadius <= platform.top &&
            playerY - playerRadius >= platform.bottom);
}


// Update player physics
// Update player physics
void updatePlayer(int value) {
    // Apply gravity
    velocityY += gravity;
    playerY += velocityY;

    // Check for collision with any platform
    bool collisionDetected = false;
    for (int i = 0; i < sizeof(platforms) / sizeof(platforms[0]); i++) {
        if (checkCollision(platforms[i])) {
            playerY = platforms[i].top + playerRadius;  // Position player on the platform
            velocityY = 0.0f;  // Reset vertical velocity
            isOnGround = true;  // Player is on the ground
            collisionDetected = true;
            break;  // Exit loop as we found a collision
        }
    }

    if (!collisionDetected) {
        isOnGround = false;  // Player is not on the ground
    }

    // Auto-reset if the player falls off the screen
    if (playerY < -1.0f) {
        playerX = -0.875f;  // Reset to starting position
        playerY = 0.675f;
        velocityY = 0.0f;
        isOnGround = true;
    }

    glutPostRedisplay();  // Redraw the screen
    glutTimerFunc(16, updatePlayer, 0);  // Call updatePlayer every 16ms (60 FPS)
}


// Handle user input
void handleInput(unsigned char key, int x, int y) {
    if (key == 'w' && isOnGround) {  // Spacebar to jump
        velocityY = jumpForce;
        isOnGround = false;
    }

    if (key == 'a') {  // Move left
        playerX -= 0.02f;
    }
    if (key == 'd') {  // Move right
        playerX += 0.05f;
    }
}

// Render the player (circle representation)
void renderPlayer() {
    glColor3f(0.0f, 0.5f, 0.0f);  // Set the player color to green (RGB: 0.0f, 0.5f, 0.0f)

    int numSegments = 50;  // Number of segments to approximate the circle
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(playerX, playerY);  // Center of the circle
    for (int i = 0; i <= numSegments; i++) {
        float angle = 2 * M_PI * i / numSegments;
        float dx = playerRadius * cos(angle);
        float dy = playerRadius * sin(angle);
        glVertex2f(playerX + dx, playerY + dy);  // Calculate the position of each point on the circle
    }
    glEnd();
}

// Render all platforms
void renderPlatforms() {
    for (int i = 0; i < sizeof(platforms) / sizeof(platforms[0]); i++) {
        Platform plat = platforms[i];
        glBegin(GL_QUADS);
        glVertex2f(plat.left, plat.bottom);
        glVertex2f(plat.right, plat.bottom);
        glVertex2f(plat.right, plat.top);
        glVertex2f(plat.left, plat.top);
        glEnd();
    }
}

//SUN
void drawGradientCircle(float centerX, float centerY, float radius) {
    int numSegments = 100;  // Number of segments for the circle
    glBegin(GL_TRIANGLE_FAN);

    // Center of the circle (bright yellow like the sun's core)
    glColor3f(1.0f, 1.0f, 0.0f);  // Yellow
    glVertex2f(centerX, centerY);

    // Outer edges of the circle (lighter gradient to orange)
    for (int i = 0; i <= numSegments; ++i) {
        float angle = 2.0f * M_PI * i / numSegments;
        float x = centerX + cos(angle) * radius;
        float y = centerY + sin(angle) * radius;

        // Gradient color transition
        glColor3f(1.0f, 0.5f, 0.0f);  // Orange-like gradient at the edges
        glVertex2f(x, y);
    }

    glEnd();
}
void display() {
    glClearColor(0.529f, 0.808f, 0.922f, 1.0f); // Set background color to skyblue and opaque
    glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer (background)

    // Draw the player
    glLoadIdentity();  // Reset transformations
    renderPlayer();
    //glutSwapBuffers();  // Swap buffers to display the result
    //sun
    drawGradientCircle(-0.65f, 0.8f, 0.15f);
    //CLoud
    {
    glPushMatrix();
    glTranslatef(position,0.0f, -1.0f);

    glColor3f(1.0f, 1.0f, 1.0f); // Set color to white
    drawCircle(0.0f, 0.75f, 0.1f); // First circle
    drawCircle(0.05f, 0.8f, 0.1f); // First circle
    drawCircle(0.09f, 0.75f, 0.1f); // First circle

    glPopMatrix();
    }
    {
    glPushMatrix();
    glTranslatef(position4,0.0f, -1.0f);

    glColor3f(1.0f, 1.0f, 1.0f); // Set color to white
    drawCircle(-0.1f, 0.8f, 0.15f); // First circle
    drawCircle(-0.3f, 0.75f, 0.1f); // First circle
    drawCircle(0.1f, 0.75f, 0.15f); // First circle

    glPopMatrix();
    }

    //PLAYER
    //glColor3f(0.0f, 0.5f, 0.0f); // Set color to white
    //drawCircle(-0.95f, -0.85f, 0.04f); // First circle

    for (float x = -1.0f; x < -0.5f; x += 0.1f) {
        drawRectangle(x, 0.3f, x + 0.1f, 0.2f);
        // Drawing triangles with different positions
        drawTriangle(-0.75f, 0.2f, -0.65f, 0.2f, -0.7f, 0.15f);
        {
        glPushMatrix();
        glTranslatef(0.0f, position2, 0.0f);  // Translate along the Y-axis

        glColor3f(1.0f, 0.0f, 0.0f); // Set color to red
        drawCircle(-0.7f, 0.15f, 0.015f); // First circle

        glPopMatrix();
        }

    }
    for (float x = -1.0f; x < 1.0f; x += 0.1f) {
        drawRectangle(x, -1.0f, x + 0.1f, -0.9f);
    }
    for (float x = -0.65f; x < -0.45f; x += 0.1f) {
        drawRectangle(x, -0.9f, x + 0.1f, -0.8f);
    }
    for (float x = 0.7f; x < 0.8f; x += 0.1f) {
        drawRectangle(x, -0.75f, x + 0.1f, -0.65f);
    }
    for (float x = 0.2f; x < 0.4f; x += 0.1f) {
        drawRectangle(x, -0.75f, x + 0.1f, -0.65f);
    }
    drawTriangle(0.4f, -0.75f, 0.45f, -0.75f, 0.425f, -0.7f);
    drawTriangle(0.45f, -0.75f, 0.5f, -0.75f, 0.475f, -0.7f);
    drawTriangle(0.5f, -0.75f, 0.55f, -0.75f, 0.525f, -0.7f);
    drawTriangle(0.55f, -0.75f, 0.6f, -0.75f, 0.575f, -0.7f);
    drawTriangle(0.6f, -0.75f, 0.65f, -0.75f, 0.625f, -0.7f);
    drawTriangle(0.65f, -0.75f, 0.7f, -0.75f, 0.675f, -0.7f);

    for (float x = 0.5f; x < 0.6f; x += 0.01f) {
        drawRectangle(x, -0.6f, x + 0.01f, -0.57f);
    }

    for (float x = 0.1f; x < 0.3f; x += 0.01f) {
        drawRectangle(x, -0.4f, x + 0.01f, -0.43f);
    }
    for (float x = -0.3f; x < -0.1f; x += 0.01f) {
        drawRectangle(x, -0.4f, x + 0.01f, -0.43f);
    }
    for (float x = 0.85f; x < 1.0f; x += 0.01f) {
        drawRectangle(x, -0.57f, x + 0.01f, -0.54f);
    }
    for (float x = 0.8f; x < 1.0f; x += 0.1f) {
        drawRectangle(x, -0.0f, x + 0.1f, -0.1f);
        // Drawing triangles with different positions
        drawTriangle(0.92f, -0.1f, 0.82f, -0.1f, 0.87f, -0.15f);
        {
        glPushMatrix();
        glTranslatef(0.0f, position2, 0.0f);  // Translate along the Y-axis

        glColor3f(1.0f, 0.0f, 0.0f); // Set color to red
        drawCircle(0.87f, -0.15f, 0.015f); // First circle

        glPopMatrix();
        }
    }
    for (float x = -1.0f; x < -0.8f; x += 0.1f) {
        drawRectangle(x, -0.35f, x + 0.1f, -0.25f);
    }
    for (float x = -0.65f; x < 0.75f; x += 0.1f) {
        drawRectangle(x, -0.2f, x + 0.1f, -0.1f);
    }
    for (float x = -0.5f; x < -0.1f; x += 0.1f) {
        drawRectangle(x, -0.1f, x + 0.1f, -0.0f);

        drawTriangle(0.0f, -0.1f, 0.05f, -0.1f, 0.025f, -0.05f);
        drawTriangle(0.05f, -0.1f, 0.1f, -0.1f, 0.075f, -0.05f);
        drawTriangle(0.1f, -0.1f, 0.15f, -0.1f, 0.125f, -0.05f);
        drawTriangle(0.15f, -0.1f, 0.2f, -0.1f, 0.175f, -0.05f);
        drawTriangle(0.7f, -0.1f, 0.75f, -0.1f, 0.725f, -0.05f);
    }
    for (float x = 0.2f; x < 0.7f; x += 0.1f) {
        drawRectangle(x, -0.1f, x + 0.1f, -0.0f);
    }

    // Drawing triangles with different positions
    drawTriangle(1.0f, -0.8f, 1.0f, -0.9f, 0.95f, -0.85f);
    {
    glPushMatrix();
    glTranslatef(position1,0.0f, 0.0f);

    glColor3f(1.0f, 0.0f, 0.0f); // Set color to white
    drawCircle(0.95f, -0.85f, 0.015f); // First circle

    glPopMatrix();
    }
    // draw a circle
    glColor3f(1.0f, 0.0f, 0.0f); // Set color to white
    drawCircle(0.5f, 0.2f, 0.015f); // First circle

    glColor3f(1.0f, 0.0f, 0.0f); // Set color to white
    drawCircle(-0.3f, 0.2f, 0.015f); // First circle

    drawRotatedLine();
    drawRotatedLine1();


    for (float x = 0.89f; x < 0.98f; x += 0.01f) {
        drawRectangle(x, 0.28f, x + 0.01f, 0.25f);
    }

    for (float x = -0.4f; x < 0.8f; x += 0.1f) {
        drawRectangle(x, 0.4f, x + 0.1f, 0.5f);
        drawTriangle(-0.2f, 0.5f, -0.25f, 0.5f, -0.225f, 0.55f);
        drawTriangle(0.0f, 0.5f, 0.05f, 0.5f, 0.025f, 0.55f);
        drawTriangle(0.05f, 0.5f, 0.1f, 0.5f, 0.075f, 0.55f);
        drawTriangle(0.2f, 0.5f, 0.25f, 0.5f, 0.225f, 0.55f);
        drawTriangle(0.25f, 0.5f, 0.3f, 0.5f, 0.275f, 0.55f);
        drawTriangle(0.5f, 0.5f, 0.55f, 0.5f, 0.525f, 0.55f);
    }

    glBegin (GL_LINES);
    glColor3f(1.0f, 0.0f, 1.0f);
    glVertex2f(-0.88f, 0.3f);
    glVertex2f(-0.88f, 0.625f);
    glEnd();
    drawTriangle(-0.88f, 0.62f, -0.88f, 0.5f, -0.75f, 0.56f);
glutSwapBuffers();  // Swap buffers to display the result
    glFlush(); // Render now
}
// Main function: GLUT runs as a console application starting at main()
int main(int argc, char** argv) {
    glutInit(&argc, argv);
glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(640, 480); // Set the window's initial width & height
    glutInitWindowPosition(80, 50);  // Set the window's initial position according to the monitor
    glutCreateWindow("OpenGL Setup Test"); // Create a window with the given title
    glutDisplayFunc(display); // Register display callback handler for window re-paint
    glutIdleFunc(display);
glutKeyboardFunc(handleInput);
glutTimerFunc(16, updatePlayer, 0);
glutTimerFunc(16, updateR, 0);
    glutTimerFunc(100, update, 0);
    glutTimerFunc(100, update1, 0);
    glutTimerFunc(100, update2, 0);
    glutTimerFunc(100, update4, 0);
    glutMainLoop(); // Enter the event-processing loop

    return 0;
}
