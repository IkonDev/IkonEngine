#include "InputHandler.h"

InputHandler* InputHandler::m_Instance = 0;
InputHandler::InputHandler()
{
	//Set all keys to released
	for (int i = 0; i < IkonKeyEnumLength; ++i)
	{
		Keys[i] = KeyState::RELEASED;
		KeysPrev[i] = KeyState::RELEASED;
	}
	MousePosition = glm::vec2(0);
}

InputHandler::~InputHandler()
{
}

void InputHandler::HandleInput(SDL_Event Event)
{
	//Set current keys
	SDL_Event e = Event;

	//Mouse Events
#pragma region MOUSE
	if (e.type == SDL_MOUSEMOTION || e.type == SDL_MOUSEBUTTONDOWN || e.type == SDL_MOUSEBUTTONUP)
	{
		//Get mouse position
		int x, y;
		SDL_GetMouseState(&x, &y);
		MousePosition = glm::vec2(x, y);
		//Left
		if (e.type == SDL_MOUSEBUTTONDOWN && e.button.button == SDL_BUTTON_LEFT)
		{
			Keys[MB_LEFT] = KeyState::PRESSED;
		}
		if (e.type == SDL_MOUSEBUTTONUP && e.button.button == SDL_BUTTON_LEFT)
		{
			Keys[MB_LEFT] = KeyState::RELEASED;
		}
		//Right
		if (e.type == SDL_MOUSEBUTTONDOWN && e.button.button == SDL_BUTTON_RIGHT)
		{
			Keys[MB_RIGHT] = KeyState::PRESSED;
		}
		if (e.type == SDL_MOUSEBUTTONUP && e.button.button == SDL_BUTTON_RIGHT)
		{
			Keys[MB_RIGHT] = KeyState::RELEASED;
		}
		//Middle
		if (e.type == SDL_MOUSEBUTTONDOWN && e.button.button == SDL_BUTTON_MIDDLE)
		{
			Keys[MB_MIDDLE] = PRESSED;
		}
		if (e.type == SDL_MOUSEBUTTONUP && e.button.button == SDL_BUTTON_MIDDLE)
		{
			Keys[MB_MIDDLE] = KeyState::RELEASED;
		}
	}
#pragma endregion MOUSE
	//Keyboard Events
#pragma region LETTERS
	//A
	if (e.key.keysym.sym == SDLK_a && e.type == SDL_KEYDOWN)
	{
		Keys[A] = KeyState::PRESSED;
	}
	if (e.key.keysym.sym == SDLK_a && e.type == SDL_KEYUP)
	{
		Keys[A] = KeyState::RELEASED;
	}
	//B
	if (e.key.keysym.sym == SDLK_b && e.type == SDL_KEYDOWN)
	{
		Keys[B] = KeyState::PRESSED;
	}
	if (e.key.keysym.sym == SDLK_b && e.type == SDL_KEYUP)
	{
		Keys[B] = KeyState::RELEASED;
	}
	//C
	if (e.key.keysym.sym == SDLK_c && e.type == SDL_KEYDOWN)
	{
		Keys[C] = KeyState::PRESSED;
	}
	if (e.key.keysym.sym == SDLK_c && e.type == SDL_KEYUP)
	{
		Keys[C] = KeyState::RELEASED;
	}
	//D
	if (e.key.keysym.sym == SDLK_d && e.type == SDL_KEYDOWN)
	{
		Keys[D] = KeyState::PRESSED;
	}
	if (e.key.keysym.sym == SDLK_d && e.type == SDL_KEYUP)
	{
		Keys[D] = KeyState::RELEASED;
	}
	//E
	if (e.key.keysym.sym == SDLK_e && e.type == SDL_KEYDOWN)
	{
		Keys[E] = KeyState::PRESSED;
	}
	if (e.key.keysym.sym == SDLK_e && e.type == SDL_KEYUP)
	{
		Keys[E] = KeyState::RELEASED;
	}
	//F
	if (e.key.keysym.sym == SDLK_f && e.type == SDL_KEYDOWN)
	{
		Keys[F] = KeyState::PRESSED;
	}
	if (e.key.keysym.sym == SDLK_f && e.type == SDL_KEYUP)
	{
		Keys[F] = KeyState::RELEASED;
	}
	//G
	if (e.key.keysym.sym == SDLK_g && e.type == SDL_KEYDOWN)
	{
		Keys[G] = KeyState::PRESSED;
	}
	if (e.key.keysym.sym == SDLK_g && e.type == SDL_KEYUP)
	{
		Keys[G] = KeyState::RELEASED;
	}
	//H
	if (e.key.keysym.sym == SDLK_h && e.type == SDL_KEYDOWN)
	{
		Keys[H] = KeyState::PRESSED;
	}
	if (e.key.keysym.sym == SDLK_h && e.type == SDL_KEYUP)
	{
		Keys[H] = KeyState::RELEASED;
	}
	//I
	if (e.key.keysym.sym == SDLK_i && e.type == SDL_KEYDOWN)
	{
		Keys[I] = KeyState::PRESSED;
	}
	if (e.key.keysym.sym == SDLK_i && e.type == SDL_KEYUP)
	{
		Keys[I] = KeyState::RELEASED;
	}
	//J
	if (e.key.keysym.sym == SDLK_j && e.type == SDL_KEYDOWN)
	{
		Keys[J] = KeyState::PRESSED;
	}
	if (e.key.keysym.sym == SDLK_j && e.type == SDL_KEYUP)
	{
		Keys[J] = KeyState::RELEASED;
	}
	//K
	if (e.key.keysym.sym == SDLK_k && e.type == SDL_KEYDOWN)
	{
		Keys[K] = KeyState::PRESSED;
	}
	if (e.key.keysym.sym == SDLK_k && e.type == SDL_KEYUP)
	{
		Keys[K] = KeyState::RELEASED;
	}
	//L
	if (e.key.keysym.sym == SDLK_l && e.type == SDL_KEYDOWN)
	{
		Keys[L] = KeyState::PRESSED;
	}
	if (e.key.keysym.sym == SDLK_l && e.type == SDL_KEYUP)
	{
		Keys[L] = KeyState::RELEASED;
	}
	//M
	if (e.key.keysym.sym == SDLK_m && e.type == SDL_KEYDOWN)
	{
		Keys[M] = KeyState::PRESSED;
	}
	if (e.key.keysym.sym == SDLK_m && e.type == SDL_KEYUP)
	{
		Keys[M] = KeyState::RELEASED;
	}
	//N
	if (e.key.keysym.sym == SDLK_n && e.type == SDL_KEYDOWN)
	{
		Keys[N] = KeyState::PRESSED;
	}
	if (e.key.keysym.sym == SDLK_n && e.type == SDL_KEYUP)
	{
		Keys[N] = KeyState::RELEASED;
	}
	//O
	if (e.key.keysym.sym == SDLK_o && e.type == SDL_KEYDOWN)
	{
		Keys[O] = KeyState::PRESSED;
	}
	if (e.key.keysym.sym == SDLK_o && e.type == SDL_KEYUP)
	{
		Keys[O] = KeyState::RELEASED;
	}
	//P
	if (e.key.keysym.sym == SDLK_p && e.type == SDL_KEYDOWN)
	{
		Keys[P] = KeyState::PRESSED;
	}
	if (e.key.keysym.sym == SDLK_p && e.type == SDL_KEYUP)
	{
		Keys[P] = KeyState::RELEASED;
	}
	//Q
	if (e.key.keysym.sym == SDLK_q && e.type == SDL_KEYDOWN)
	{
		Keys[Q] = KeyState::PRESSED;
	}
	if (e.key.keysym.sym == SDLK_q && e.type == SDL_KEYUP)
	{
		Keys[Q] = KeyState::RELEASED;
	}
	//R
	if (e.key.keysym.sym == SDLK_r && e.type == SDL_KEYDOWN)
	{
		Keys[R] = KeyState::PRESSED;
	}
	if (e.key.keysym.sym == SDLK_r && e.type == SDL_KEYUP)
	{
		Keys[R] = KeyState::RELEASED;
	}
	//S
	if (e.key.keysym.sym == SDLK_s && e.type == SDL_KEYDOWN)
	{
		Keys[S] = KeyState::PRESSED;
	}
	if (e.key.keysym.sym == SDLK_s && e.type == SDL_KEYUP)
	{
		Keys[S] = KeyState::RELEASED;
	}
	//T
	if (e.key.keysym.sym == SDLK_t && e.type == SDL_KEYDOWN)
	{
		Keys[T] = KeyState::PRESSED;
	}
	if (e.key.keysym.sym == SDLK_t && e.type == SDL_KEYUP)
	{
		Keys[T] = KeyState::RELEASED;
	}
	//U
	if (e.key.keysym.sym == SDLK_u && e.type == SDL_KEYDOWN)
	{
		Keys[U] = KeyState::PRESSED;
	}
	if (e.key.keysym.sym == SDLK_u && e.type == SDL_KEYUP)
	{
		Keys[U] = KeyState::RELEASED;
	}
	//V
	if (e.key.keysym.sym == SDLK_v && e.type == SDL_KEYDOWN)
	{
		Keys[V] = KeyState::PRESSED;
	}
	if (e.key.keysym.sym == SDLK_v && e.type == SDL_KEYUP)
	{
		Keys[V] = KeyState::RELEASED;
	}
	//W
	if (e.key.keysym.sym == SDLK_w && e.type == SDL_KEYDOWN)
	{
		Keys[W] = KeyState::PRESSED;
	}
	if (e.key.keysym.sym == SDLK_w && e.type == SDL_KEYUP)
	{
		Keys[W] = KeyState::RELEASED;
	}
	//X
	if (e.key.keysym.sym == SDLK_x && e.type == SDL_KEYDOWN)
	{
		Keys[X] = KeyState::PRESSED;
	}
	if (e.key.keysym.sym == SDLK_x && e.type == SDL_KEYUP)
	{
		Keys[X] = KeyState::RELEASED;
	}
	//Y
	if (e.key.keysym.sym == SDLK_y && e.type == SDL_KEYDOWN)
	{
		Keys[Y] = KeyState::PRESSED;
	}
	if (e.key.keysym.sym == SDLK_y && e.type == SDL_KEYUP)
	{
		Keys[Y] = KeyState::RELEASED;
	}
	//Z
	if (e.key.keysym.sym == SDLK_z && e.type == SDL_KEYDOWN)
	{
		Keys[Z] = KeyState::PRESSED;
	}
	if (e.key.keysym.sym == SDLK_z && e.type == SDL_KEYUP)
	{
		Keys[Z] = KeyState::RELEASED;
	}
#pragma endregion LETTERS
#pragma region NUMBERS
	//1
	if (e.key.keysym.sym == SDLK_1 && e.type == SDL_KEYDOWN)
	{
		Keys[KEY_1] = KeyState::PRESSED;
	}
	if (e.key.keysym.sym == SDLK_1 && e.type == SDL_KEYUP)
	{
		Keys[KEY_1] = KeyState::RELEASED;
	}
	//2
	if (e.key.keysym.sym == SDLK_2 && e.type == SDL_KEYDOWN)
	{
		Keys[KEY_2] = KeyState::PRESSED;
	}
	if (e.key.keysym.sym == SDLK_2 && e.type == SDL_KEYUP)
	{
		Keys[KEY_2] = KeyState::RELEASED;
	}
	//3
	if (e.key.keysym.sym == SDLK_3 && e.type == SDL_KEYDOWN)
	{
		Keys[KEY_3] = KeyState::PRESSED;
	}
	if (e.key.keysym.sym == SDLK_3 && e.type == SDL_KEYUP)
	{
		Keys[KEY_3] = KeyState::RELEASED;
	}
	//4
	if (e.key.keysym.sym == SDLK_4 && e.type == SDL_KEYDOWN)
	{
		Keys[KEY_4] = KeyState::PRESSED;
	}
	if (e.key.keysym.sym == SDLK_4 && e.type == SDL_KEYUP)
	{
		Keys[KEY_4] = KeyState::RELEASED;
	}
	//5
	if (e.key.keysym.sym == SDLK_5 && e.type == SDL_KEYDOWN)
	{
		Keys[KEY_5] = KeyState::PRESSED;
	}
	if (e.key.keysym.sym == SDLK_5 && e.type == SDL_KEYUP)
	{
		Keys[KEY_5] = KeyState::RELEASED;
	}
	//6
	if (e.key.keysym.sym == SDLK_6 && e.type == SDL_KEYDOWN)
	{
		Keys[KEY_6] = KeyState::PRESSED;
	}
	if (e.key.keysym.sym == SDLK_6 && e.type == SDL_KEYUP)
	{
		Keys[KEY_6] = KeyState::RELEASED;
	}
	//7
	if (e.key.keysym.sym == SDLK_7 && e.type == SDL_KEYDOWN)
	{
		Keys[KEY_7] = KeyState::PRESSED;
	}
	if (e.key.keysym.sym == SDLK_7 && e.type == SDL_KEYUP)
	{
		Keys[KEY_7] = KeyState::RELEASED;
	}
	//8
	if (e.key.keysym.sym == SDLK_8 && e.type == SDL_KEYDOWN)
	{
		Keys[KEY_8] = KeyState::PRESSED;
	}
	if (e.key.keysym.sym == SDLK_8 && e.type == SDL_KEYUP)
	{
		Keys[KEY_8] = KeyState::RELEASED;
	}
	//9
	if (e.key.keysym.sym == SDLK_9 && e.type == SDL_KEYDOWN)
	{
		Keys[KEY_9] = KeyState::PRESSED;
	}
	if (e.key.keysym.sym == SDLK_9 && e.type == SDL_KEYUP)
	{
		Keys[KEY_9] = KeyState::RELEASED;
	}
	//0
	if (e.key.keysym.sym == SDLK_0 && e.type == SDL_KEYDOWN)
	{
		Keys[KEY_0] = KeyState::PRESSED;
	}
	if (e.key.keysym.sym == SDLK_0 && e.type == SDL_KEYUP)
	{
		Keys[KEY_0] = KeyState::RELEASED;
	}
#pragma endregion NUMBERS
#pragma region UTILITIES
	//SPACE
	if (e.key.keysym.sym == SDLK_SPACE && e.type == SDL_KEYDOWN)
	{
		Keys[KEY_SPACE] = KeyState::PRESSED;
	}
	if (e.key.keysym.sym == SDLK_SPACE && e.type == SDL_KEYUP)
	{
		Keys[KEY_SPACE] = KeyState::RELEASED;
	}
	//BACKSPACE
	if (e.key.keysym.sym == SDLK_BACKSPACE && e.type == SDL_KEYDOWN)
	{
		Keys[KEY_BACKSPACE] = KeyState::PRESSED;
	}
	if (e.key.keysym.sym == SDLK_BACKSPACE && e.type == SDL_KEYUP)
	{
		Keys[KEY_BACKSPACE] = KeyState::RELEASED;
	}
#pragma endregion UTILITIES
#pragma region ARROWKEYS
	//RIGHT
	if (e.key.keysym.sym == SDLK_RIGHT && e.type == SDL_KEYDOWN)
	{
		Keys[RIGHT] = KeyState::PRESSED;
	}
	if (e.key.keysym.sym == SDLK_RIGHT && e.type == SDL_KEYUP)
	{
		Keys[RIGHT] = KeyState::RELEASED;
	}
	//LEFT
	if (e.key.keysym.sym == SDLK_LEFT && e.type == SDL_KEYDOWN)
	{
		Keys[LEFT] = KeyState::PRESSED;
	}
	if (e.key.keysym.sym == SDLK_LEFT && e.type == SDL_KEYUP)
	{
		Keys[LEFT] = KeyState::RELEASED;
	}
	//UP
	if (e.key.keysym.sym == SDLK_UP && e.type == SDL_KEYDOWN)
	{
		Keys[UP] = KeyState::PRESSED;
	}
	if (e.key.keysym.sym == SDLK_UP && e.type == SDL_KEYUP)
	{
		Keys[UP] = KeyState::RELEASED;
	}
	//DOWN
	if (e.key.keysym.sym == SDLK_DOWN && e.type == SDL_KEYDOWN)
	{
		Keys[DOWN] = KeyState::PRESSED;
	}
	if (e.key.keysym.sym == SDLK_DOWN && e.type == SDL_KEYUP)
	{
		Keys[DOWN] = KeyState::RELEASED;
	}
#pragma endregion ARROWKEYS
#pragma region KEYMODS
	//SHIFT
	if (e.key.keysym.sym != 0)
	{
		if (e.key.keysym.sym == SDLK_LSHIFT && e.type == SDL_KEYDOWN)
		{
			Keys[SHIFT] = KeyState::PRESSED;
		}
		if (e.key.keysym.sym == SDLK_LSHIFT && e.type == SDL_KEYUP)
		{
			Keys[SHIFT] = KeyState::RELEASED;
		}
		//CTRL
		if (e.key.keysym.sym == SDLK_LCTRL && e.type == SDL_KEYDOWN)
		{
			Keys[CTRL] = KeyState::PRESSED;
		}
		if (e.key.keysym.sym == SDLK_LCTRL && e.type == SDL_KEYUP)
		{
			Keys[CTRL] = KeyState::RELEASED;
		}
		//ALT
		if (e.key.keysym.sym == SDLK_LALT && e.type == SDL_KEYDOWN)
		{
			Keys[ALT] = KeyState::PRESSED;
		}
		if (e.key.keysym.sym == SDLK_LALT && e.type == SDL_KEYUP)
		{
			Keys[ALT] = KeyState::RELEASED;
		}
	}
#pragma endregion KEYMODS

}

void InputHandler::SetPrevKeys()
{
	//Set previous frames keys
	for (int i = 0; i < IkonKeyEnumLength; ++i)
	{
		KeysPrev[i] = Keys[i];
	}
}
//WAS-IS KEY IN STATE
const bool InputHandler::WasKeyReleased(IkonKey Key)
{
	if (GetKey(Key)		== KeyState::RELEASED &&
		GetKeyLast(Key) == KeyState::PRESSED)
	{
		return true;
	}
	return false;
}

const bool InputHandler::IsKeyReleased(IkonKey Key)
{
	if (GetKey(Key)		== KeyState::RELEASED &&
		GetKeyLast(Key) == KeyState::RELEASED)
	{
		return true;
	}
	return false;
}

const bool InputHandler::WasKeyPressed(IkonKey Key)
{
	if (GetKey(Key)     == KeyState::PRESSED &&
		GetKeyLast(Key) == KeyState::RELEASED)
	{
		return true;
	}
	return false;
}

const bool InputHandler::IsKeyPressed(IkonKey Key)
{
	if (GetKey(Key)		== KeyState::PRESSED &&
		GetKeyLast(Key) == KeyState::PRESSED)
	{
		return true;
	}
	return false;
}
