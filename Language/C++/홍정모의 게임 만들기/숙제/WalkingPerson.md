### WalkingPerson 구현
1. 여러 사람이 걷기
2. spacebar를 누르면 아이언맨 자세로 하늘을 날기
3. spacebar를 누르면 아아인맨 자세로 내려오기
4. 땅에 착륙하면 다시 걷기

```cpp
#pragma once

#include "Game2D.h"

namespace jm
{
	class WalkingPerson 
	{
	public:
		float time = 0.0f;
		float trans = 0.0f;

		void walking(float time, float walkTranslate)
		{
			// ground
			beginTransformation();
			translate(0.0f, -1.0f);
			drawFilledBox(Colors::brown, 4.0f, 0.5f);
			endTransformation();

			// gold face
			beginTransformation();
			translate(0.0f - walkTranslate, 0.12f);
			drawFilledCircle(Colors::gold, 0.08f);
			translate(0.05f, 0.03f);
			drawFilledCircle(Colors::white, 0.01f); // while eye
			endTransformation();

			// back yellow arm (뒷 팔)
			beginTransformation();
			translate(0.0f - walkTranslate, -0.1f);
			rotate(sin(time * -0.5f) * 30.0f);	// 속도에 (-)를 곱해서 역으로 움직이도록 함
			translate(0.0f, -0.1f);
			scale(1.0f, 2.0f);
			drawFilledBox(Colors::yellow, 0.05f, 0.18f);
			endTransformation();

			// back green leg (뒷 다리)
			beginTransformation();
			translate(0.0f - walkTranslate, -0.6f);
			translate(0.0f, 0.2f);
			rotate(sinf(time * -0.5f + 3.141592f) * 30.0f);	// 속도에 (-)를 곱해서 역으로 움직이도록 함
			translate(0.0f, -0.2f);
			drawFilledBox(Colors::green, 0.1f, 0.4f);
			endTransformation();

			// red body
			beginTransformation();
			scale(1.0f, 2.0f);
			translate(0.0f - walkTranslate, -0.1f);
			drawFilledBox(Colors::red, 0.13f, 0.2f);
			endTransformation();

			// yellow arm
			beginTransformation();
			translate(0.0f - walkTranslate, -0.1f);
			rotate(sin(time * 0.5f) * 30.0f);					// animation!
			translate(0.0f, -0.1f);
			scale(1.0f, 2.0f);
			drawFilledBox(Colors::yellow, 0.05f, 0.18f);
			endTransformation();

			// green leg
			beginTransformation();
			translate(0.0f - walkTranslate, -0.6f);
			translate(0.0f, 0.2f);
			rotate(sinf(time * 0.5f + 3.141592f) * 30.0f);	// animation!
			translate(0.0f, -0.2f);
			drawFilledBox(Colors::green, 0.1f, 0.4f);
			endTransformation();
		}
	};

	class JumpingPerson 
	{
	public:
		float dy = 0.0f;

		void jumping(float dy)
		{
			// ground
			beginTransformation();
			translate(0.0f, -1.0f);
			drawFilledBox(Colors::brown, 4.0f, 0.5f);
			endTransformation();

			// gold face
			beginTransformation();
			translate(0.0f, dy + 0.12f);
			drawFilledCircle(Colors::gold, 0.08f);
			translate(0.05f, 0.03f);
			drawFilledCircle(Colors::white, 0.01f); // while eye
			endTransformation();

			// red body
			beginTransformation();
			translate(0.0f, dy);
			scale(1.0f, 2.0f);
			translate(0.0f, -0.1f);
			drawFilledBox(Colors::red, 0.13f, 0.2f);
			endTransformation();

			// back yellow arm (뒷 팔)
			beginTransformation();
			translate(0.0f, 0.0f + dy);
			rotate(sin(-0.5f) * 75.0f);
			translate(0.25f, 0.002f);
			scale(2.0f, 1.0f);
			drawFilledBox(Colors::yellow, 0.18f, 0.05f);
			endTransformation();

			// yellow arm
			beginTransformation();
			translate(0.0f, 0.0f + dy);
			rotate(sin(0.5f) * 75.0f);
			translate(-0.25f, 0.002f);
			scale(2.0f, 1.0f);
			drawFilledBox(Colors::yellow, 0.18f, 0.05f);
			endTransformation();

			// green leg
			beginTransformation();
			translate(0.0f, dy + -0.6f);
			drawFilledBox(Colors::green, 0.1f, 0.4f);
			endTransformation();

			// rightHand beam
			beginTransformation();
			translate(0.0f, 0.0f + dy);
			scale(1.0f, 1.0f);
			translate(0.35f, -0.25f);
			drawFilledTriangle(Colors::red, 0.05f);
			endTransformation();

			// rightHand Orangebeam
			beginTransformation();
			translate(0.0f, 0.0f + dy);
			scale(0.7f, 0.7f);
			translate(0.5f, -0.353f);
			drawFilledTriangle(Colors::orange, 0.05f);
			endTransformation();

			// leftHand beam
			beginTransformation();
			translate(0.0f, 0.0f + dy);
			scale(1.0f, 1.0f);
			translate(-0.35f, -0.25f);
			drawFilledTriangle(Colors::red, 0.05f);
			endTransformation();

			// leftHand Orangebeam
			beginTransformation();
			translate(0.0f, 0.0f + dy);
			scale(0.7f, 0.7f);
			translate(-0.5f, -0.353f);
			drawFilledTriangle(Colors::orange, 0.05f);
			endTransformation();

			// leg beam
			beginTransformation();
			translate(0.0f, 0.0f + dy);
			scale(1.5f, 1.5f);
			translate(0.0f, -0.55f);
			rotate(180.0f);
			drawFilledTriangle(Colors::red, 0.05f);
			endTransformation();

			// leg Orangebeam
			beginTransformation();
			translate(0.0f, 0.0f + dy);
			scale(1.2f, 1.2f);
			translate(0.0f, -0.685f);
			rotate(180.0f);
			drawFilledTriangle(Colors::orange, 0.05f);
			endTransformation();
		}
	};

	class JustPerson : public Game2D
	{
		WalkingPerson wp;
		JumpingPerson jp;
		
		WalkingPerson walking_persons[2];

	public:
		void update() override
		{
			// spacebar를 누르면 위로 날기
			if (isKeyPressed(GLFW_KEY_SPACE))
			{
				jp.jumping(jp.dy);
				jp.dy += this->getTimeStep() * 0.05f;
			} 
			else // spacebar를 안누르면
			{
				// 캐릭터의 y 좌표가 0 이상이면 계속 내려오기
				if (jp.dy >= 0.0f)
				{
					jp.dy += this->getTimeStep() * -0.05f;
					jp.jumping(jp.dy);
				}
				else // 캐릭터의 y 좌표가 0 이하이면 걷기
				{
					wp.walking(wp.time, 0.0f);
					wp.time += this->getTimeStep();
				}
			}

			walking_persons[0].walking(walking_persons[0].time, -1.0f);
			walking_persons[0].time += this->getTimeStep();

			walking_persons[1].walking(walking_persons[1].time, 1.0f);
			walking_persons[1].time += this->getTimeStep();
		}
	};
}
```

좌표 맞추는데 애를 먹었다..

![Thisismydigitalcanvas2024-01-3117-59-20-ezgif com-video-to-gif-converter](https://github.com/SunFlower2819/Today-I-learned/assets/130738283/9202d0cc-7e96-4d9e-af22-d046e29a235b)
