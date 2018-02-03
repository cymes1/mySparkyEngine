#include "window.h"

namespace Sparky { namespace Graphics
{
	bool Window::m_keys[MAX_KEYS];
	bool Window::m_mouseButtons[MAX_BUTTONS];
	double Window::m_mx;
	double Window::m_my;

	Window::Window(string name, int width, int height)
		: m_name(name), m_width(width), m_height(height)
	{
		m_isClosed = false;

		if(!init())
			glfwTerminate();

		for(int i = 0; i < MAX_KEYS; i++)
			m_keys[i] = false;
		for(int i = 0; i < MAX_BUTTONS; i++)
			m_mouseButtons[i] = false;
	}


	Window::~Window()
	{
		glfwTerminate();
	}


	void Window::clear() const
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}


	void Window::update()
	{
		glfwPollEvents();
		glfwGetFramebufferSize(m_window, &m_width, &m_height);
		glfwSwapBuffers(m_window);
	}


	bool Window::isClosed() const
	{
		return glfwWindowShouldClose(m_window);
	}


	void window_resize(GLFWwindow* window, int width, int height);
	void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
	void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
	void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);
	bool Window::init()
	{
		if(!glfwInit())
		{
			cout << "Failed to initialize GLFW" << endl;
			return false;
		}

		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		m_window = glfwCreateWindow(m_width, m_height, m_name.c_str(), NULL, NULL);
		if(!m_window)
		{
			cout << "Failed to create GLFW window" << endl;
			return false;
		}

		glfwMakeContextCurrent(m_window);
		glfwSetWindowUserPointer(m_window, this);
		glfwSetWindowSizeCallback(m_window, window_resize);
		glfwSetKeyCallback(m_window, key_callback);
		glfwSetMouseButtonCallback(m_window, mouse_button_callback);
		glfwSetCursorPosCallback(m_window, cursor_position_callback);
		glfwSwapInterval(0);

		GLenum err;
		err = glewInit();

		if(err != GLEW_OK)
		{
			cout << "Failed to initialize GLEW" << endl;
			cout << glewGetErrorString(err) << endl;
			return false;
		}
		
		cout << "OpenGL version: " << glGetString(GL_VERSION) << endl;
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		return true;
	}


	bool Window::isKeyPressed(unsigned int keycode)
	{
		if(keycode >= MAX_KEYS)
			return false;

		return m_keys[keycode];
	}


	bool Window::isMouseButtonPressed(unsigned int buttoncode)
	{
		if(buttoncode >= MAX_BUTTONS)
			return false;

		return m_mouseButtons[buttoncode];
	}


	int Window::width() const
	{
		return m_width;
	}


	int Window::height() const
	{
		return m_height;
	}
		
		
	void Window::mousePosition(double& mx, double& my)
	{
		mx = m_mx;
		my = m_my;
	}


	void window_resize(GLFWwindow* window, int width, int height)
	{
		glViewport(0, 0, width, height);
	}

	
	void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
	{
		Window* win = (Window*)glfwGetWindowUserPointer(window);
		win->m_keys[key] = action != GLFW_RELEASE;
	}


	void mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
	{
		Window* win = (Window*)glfwGetWindowUserPointer(window);
		win->m_mouseButtons[button] = action != GLFW_RELEASE;
	}


	void cursor_position_callback(GLFWwindow* window, double xpos, double ypos)
	{
		Window* win = (Window*)glfwGetWindowUserPointer(window);
		win->m_mx = xpos;
		win->m_my = ypos;
	}
}}
