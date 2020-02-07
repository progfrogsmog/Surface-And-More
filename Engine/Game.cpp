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
	for (int y = 0; y < s.GetHeight(); y++)
	{
		for (int x = 0; x < s.GetWidth(); x++)
		{
			s.PutPixel(x, y, Color(
				(x - 25) * (x - 25) + (y - 25) * (y - 25),
				(x - 50) * (x - 50) + (y - 50) * (y - 50),
				(x - 75) * (x - 75) + (y - 75) * (y - 75)
				));
			s2.PutPixel(x, y, Color(
				(x - 75) * (x - 75) + (y - 75) * (y - 75),
				(x - 50) * (x - 50) + (y - 50) * (y - 50),
				(x - 25) * (x - 25) + (y - 25) * (y - 25)
			));
		}
	}
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
}

void Game::ComposeFrame()
{
	gfx.DrawSprite(100, 100, s);
	gfx.DrawSprite(200, 100, s2);
}
