ADD_SUBDIRECTORY(buffers)

ADD_LIBRARY(graphics window.cpp shader.cpp renderable2d.cpp sprite.cpp staticsprite.cpp simple2drenderer.cpp batchrenderer2d.cpp)

TARGET_LINK_LIBRARIES(graphics ${GLEW_LIBRARIES})
