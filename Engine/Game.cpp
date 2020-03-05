/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd )
{
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	float dt = ft.Mark();
	vel = { 0,0 };
	if (wnd.kbd.KeyIsPressed(VK_LEFT))
	{
		vel.x -= 1;
	}
	if (wnd.kbd.KeyIsPressed(VK_RIGHT))
	{
		vel.x += 1;
	}
	if (wnd.kbd.KeyIsPressed(VK_UP))
	{
		vel.y -= 1;
	}
	if (wnd.kbd.KeyIsPressed(VK_DOWN))
	{
		vel.y += 1;
	}

	//test for key is pressed
	if (!wnd.kbd.KeyIsEmpty())
	{
		gfx.DrawRect(500, 500, 10, 10, Colors::Red);

		const Keyboard::Event e = wnd.kbd.ReadKey();
		if (e.IsPress())
		{
			input.UpdateText(e.GetCode());
		}
	}

	//test for mouseEvent and call inputWindow
	if (wnd.mouse.LeftIsPressed() && leftMouseReleased)
	{
		input.OnClick(wnd.mouse.GetPos());
		leftMouseReleased = false;
	}
	else if(!wnd.mouse.LeftIsPressed())
	{
		leftMouseReleased = true;
	}

	link.Update(dt,vel);
	fps.Update(dt);
	input.Update(dt);
}

void Game::ComposeFrame()
{
	//myText.Draw(Vei2(300,300), "Come over here.\nAnd another Text! :)", Colors::Yellow, gfx);
	fps.Draw(Vei2(750, 10), Colors::Green, gfx);
	link.Draw(gfx);
	input.Draw(gfx);
}
