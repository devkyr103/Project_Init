#include "CInput.h"

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

	std::vector<CInput::Key> CInput::mKeys;

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
		for (UINT i = 0; i < (UINT)eKeyCode::END; i++)
		{
			if (GetAsyncKeyState(ASCII[i]) & 0x8000)
			{
				// ���� �����ӿ��� ���� �־���
				if (mKeys[i].bPressed)
					mKeys[i].state = eKeyState::Pressed;
				else
					mKeys[i].state = eKeyState::Down;

				mKeys[i].bPressed = true;
			}
			else // ���� �����ӿ� Ű�� �������� �ʴ�.
			{
				// ���� �����ӿ� ��Ű�� �����־���.
				if (mKeys[i].bPressed)
					mKeys[i].state = eKeyState::Up;
				else
					mKeys[i].state = eKeyState::None;

				mKeys[i].bPressed = false;
			}
		}
	}

	void CInput::Render(Gdiplus::Graphics* gp)
	{

	}
}
