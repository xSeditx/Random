#ifndef _SCENE_H
#define _SCENE_H
#pragma once

#include"Object.h"
#include"EventHandler.h"
//TODO: Likely have a single scene per window as that is all there will ever be anyway. Perhaps this should somehow be merged with window... or the other way around perhaps.
// That would make Application class a collection of Scenes.  

// Properties.
// Handles the Rendering for the FrameBuffer. Contains and handles all Objects, GameObjects and Components, Lights
// Controls the Camera
class Scene
{
	std::vector<Object> Parts;

	void PostMessage(Event msg);
	std::queue<Event> MSGQueue;
};




#endif // _SCENE_H