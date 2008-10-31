/*
Bullet Continuous Collision Detection and Physics Library
Copyright (c) 2003-2006 Erwin Coumans  http://continuousphysics.com/Bullet/

This software is provided 'as-is', without any express or implied warranty.
In no event will the authors be held liable for any damages arising from the use of this software.
Permission is granted to anyone to use this software for any purpose, 
including commercial applications, and to alter it and redistribute it freely, 
subject to the following restrictions:

1. The origin of this software must not be misrepresented; you must not claim that you wrote the original software. If you use this software in a product, an acknowledgment in the product documentation would be appreciated but is not required.
2. Altered source versions must be plainly marked as such, and must not be misrepresented as being the original software.
3. This notice may not be removed or altered from any source distribution.
*/

#ifndef BSP_CONVERTER_H
#define BSP_CONVERTER_H

class BspLoader;
#include <vector>
#include "SimdVector3.h"

///BspConverter turns a loaded bsp level into convex parts (vertices)
class BspConverter
{
	public:

		void convertBsp(BspLoader& bspLoader,float scaling);

		///Utility function to create vertices from a Quake Brush. Brute force but it works. 
		///Bit overkill to use QHull package
		void	getVerticesFromPlaneEquations(const std::vector<SimdVector3>& planeEquations , std::vector<SimdVector3>& verticesOut );
		bool	isInside(const std::vector<SimdVector3>& planeEquations, const SimdVector3& point, float	margin);

		///this callback is called for each brush that succesfully converted into vertices
		virtual void	AddConvexVerticesCollider(std::vector<SimdVector3>& vertices, bool isEntity, const SimdVector3& entityTargetLocation) = 0;

};

#endif //BSP_CONVERTER_H
