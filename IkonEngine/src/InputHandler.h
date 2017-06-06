#pragma once
#include <glm\vec2.hpp>
#include <SDL.h>

class InputHandler
{
private:
	static InputHandler* m_Instance;
public:

	enum KeyState
	{
		RELEASED = 0,
		PRESSED = 1
	};
	enum IkonKey
	{
		//Letters
		A, B, C, D,
		E, F, G, H,
		I, J, K, L,
		M, N, O, P,
		Q, R, S, T,
		U, V, W, X,
		Y, Z,
		//Number Keys
		KEY_1, KEY_2, KEY_3, KEY_4, KEY_5,
		KEY_6, KEY_7, KEY_8, KEY_9, KEY_0,
		//Numpad Keys
		NUM_1, NUM_2, NUM_3, NUM_4, NUM_5,
		NUM_6, NUM_7, NUM_8, NUM_9, NUM_0,
		NUM_ENTER,
		NUM_PLUS,
		NUM_MINUS,
		NUM_DIVIDE,
		NUM_MULTIPLY,
		NUM_DOT,
		//Some Utility keys
		KEY_BACKSPACE,
		KEY_SPACE,
		//Arrow keys
		UP, DOWN, LEFT, RIGHT,
		//Mouse Buttons
		MB_LEFT, MB_RIGHT, MB_MIDDLE,
		//Key Mods
		SHIFT, CTRL, ALT,
		IkonKeyEnumLength
	};

	InputHandler();
	~InputHandler();
	static InputHandler* Instance()
	{
		if (!m_Instance)
		{
			m_Instance = new InputHandler;
		}
		return m_Instance;
	}
	KeyState GetKey(IkonKey Key) const { return Keys[Key]; }
	KeyState GetKeyLast(IkonKey Key) const { return KeysPrev[Key]; }
	const bool WasKeyReleased(IkonKey Key);
	const bool IsKeyReleased(IkonKey Key);
	const bool WasKeyPressed(IkonKey Key);
	const bool IsKeyPressed(IkonKey Key);

	void HandleInput(SDL_Event Event);
	void SetPrevKeys();
	
	glm::vec2 MousePosition;
private:
	KeyState Keys[IkonKeyEnumLength];
	KeyState KeysPrev[IkonKeyEnumLength];
};

