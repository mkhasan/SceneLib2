#include <pangolin/pangolin.h>

int main(int argc, char** argv) {
    // 1. Create an OpenGL window and bind it to the current thread
    pangolin::CreateWindowAndBind("Pangolin Sample Window", 640, 480);
    
    // 2. Enable depth testing for proper 3D rendering occlusion
    glEnable(GL_DEPTH_TEST);

    // 3. Define the Projection and initial ModelView camera state
    pangolin::OpenGlRenderState s_cam(
        pangolin::ProjectionMatrix(640, 480, 420, 420, 320, 240, 0.1, 1000),
        pangolin::ModelViewLookAt(-2, 2, -2, 0, 0, 0, pangolin::AxisY)
    );

    // 4. Create an interactive 3D Viewport layout
    pangolin::Handler3D handler(s_cam);
    pangolin::View& d_cam = pangolin::CreateDisplay()
        .SetBounds(0.0, 1.0, 0.0, 1.0, -640.0 / 480.0)
        .SetHandler(&handler);

    // 5. Main application loop
    while (!pangolin::ShouldQuit()) {
        // Clear screen and depth buffers
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // Activate the camera view state for drawing
        d_cam.Activate(s_cam);

        // Render a built-in sample 3D colored cube
        pangolin::glDrawColouredCube();

        // Swap frames and process window events
        pangolin::FinishFrame();
    }

    return 0;
}
