#include "CInput.h"
#include "CApplication.h"

namespace kyr
{
	int ASCII[(UINT)eKeyCode::END] =
	{
		'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P',
		'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L',
		'Z', 'X', 'C', 'V', 'B', 'N', 'M',

		VK_UP, VK_DOWN, VK_LEFT, VK_RIGHT, VK_SPACE,

		VK_LBUTTON, VK_RBUTTON,
	};

	std::vector<CInput::Key> CInput::mKeys{};
	Vector2 CInput::mMousePos{};

	void CInput::Initialize()
	{
		for (UINT i = 0; i < (UINT)eKeyCode::END; i++)
		{
			Key keyInfo{};
			keyInfo.key = (eKeyCode)i;
			keyInfo.state = eKeyState::None;
			keyInfo.bPressed = false;

			mKeys.push_back(keyInfo);
		}
	}

	void CInput::Update()
	{
		if (GetFocus())
		{
			for (UINT i = 0; i < (UINT)eKeyCode::END; i++)
			{
				if (GetAsyncKeyState(ASCII[i]) & 0x8000)
				{
					// 이전 프레임에도 눌려 있었다
					if (mKeys[i].bPressed)
						mKeys[i].state = eKeyState::Pressed;
					else
						mKeys[i].state = eKeyState::Down;

					mKeys[i].bPressed = true;
				}
				else // 현재 프레임에 키가 눌려있지 않다.
				{
					// 이전 프레임에 내키가 눌려있엇다.
					if (mKeys[i].bPressed)
						mKeys[i].state = eKeyState::Up;
					else
						mKeys[i].state = eKeyState::None;

					mKeys[i].bPressed = false;
				}
			}

			POINT mousePos{};

			GetCursorPos(&mousePos);

			ScreenToClient(CApplication::GetHWnd(), &mousePos);

			mMousePos = mousePos;

			if (IsZoomed(CApplication::GetHWnd()))
			{
				mMousePos *= 0.833333f;
			}
		}
		else
		{
			for (UINT i = 0; i < (UINT)eKeyCode::END; i++)
			{
				if (eKeyState::Down == mKeys[i].state
					|| eKeyState::Pressed == mKeys[i].state)
				{
					mKeys[i].state = eKeyState::Up;
				}
				else if (eKeyState::Up == mKeys[i].state)
				{
					mKeys[i].state = eKeyState::None;
				}

				mKeys[i].bPressed = false;
			}
		}

	}

	void CInput::Render(Gdiplus::Graphics* gp)
	{

	}
}
