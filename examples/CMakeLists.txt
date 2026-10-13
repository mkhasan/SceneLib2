############################################################
# SceneLib2 (https://)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

FIND_PACKAGE(SceneLib2 REQUIRED)
INCLUDE_DIRECTORIES(${SceneLib2_INCLUDE_DIRS})
LINK_DIRECTORIES(${SceneLib2_LIBRARY_DIRS})
LINK_LIBRARIES(${SceneLib2_LIBRARIES})

# Pangolin (https://github.com/stevenlovegrove/Pangolin)
FIND_PACKAGE(Pangolin REQUIRED)


INCLUDE_DIRECTORIES(${Pangolin_INCLUDE_DIRS})
LINK_DIRECTORIES(${Pangolin_LIBRARY_DIRS})




find_package(Boost REQUIRED COMPONENTS thread filesystem system)

ADD_EXECUTABLE(MonoSlamSceneLib1 MonoSlamSceneLib1.cpp)
#TARGET_LINK_LIBRARIES(MonoSlamSceneLib1 ${OpenCV_LIBS})
target_link_libraries(MonoSlamSceneLib1
        PUBLIC
        Boost::thread
        Boost::filesystem
        Boost::system 
        OpenGL::GL 
        GLUT::GLUT
)
