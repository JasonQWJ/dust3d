/*
 *  Copyright (c) 2016-2021 Jeremy HU <jeremy-at-dust3d dot org>. All rights reserved. 
 *
 *  Permission is hereby granted, free of charge, to any person obtaining a copy
 *  of this software and associated documentation files (the "Software"), to deal
 *  in the Software without restriction, including without limitation the rights
 *  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *  copies of the Software, and to permit persons to whom the Software is
 *  furnished to do so, subject to the following conditions:

 *  The above copyright notice and this permission notice shall be included in all
 *  copies or substantial portions of the Software.

 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 *  SOFTWARE.
 */

#ifndef DUST3D_MESH_MESH_STROKETIFIER_H_
#define DUST3D_MESH_MESH_STROKETIFIER_H_

#include <dust3d/base/vector3.h>
#include <dust3d/base/matrix4x4.h>

namespace dust3d
{
    
class MeshStroketifier
{
public:
    struct Node
    {
        Vector3 position;
        float radius;
    };
	void setCutRotation(float cutRotation);
    void setDeformThickness(float deformThickness);
    void setDeformWidth(float deformWidth);
    bool prepare(const std::vector<Node> &strokeNodes, 
        const std::vector<Vector3> &vertices);
    void stroketify(std::vector<Vector3> *vertices);
    void stroketify(std::vector<Node> *nodes);
private:
	float m_cutRotation = 0.0;
    float m_deformThickness = 1.0;
    float m_deformWidth = 1.0;

    Vector3 m_modelOrigin;
    float m_modelLength = 0.0;
    float m_scaleAmount = 1.0;
    Vector3 m_modelAlignDirection;
    Vector3 m_modelBaseNormal;
    std::vector<Vector3> m_modelJointPositions;
    std::vector<Matrix4x4> m_modelTransforms;
    Matrix4x4 m_modelRotation;

    static float calculateStrokeLengths(const std::vector<Node> &strokeNodes,
        std::vector<float> *lengths);
    static void calculateBoundingBox(const std::vector<Vector3> &vertices,
        float *minX, float *maxX,
        float *minY, float *maxY,
        float *minZ, float *maxZ);
        
    void translate(std::vector<Vector3> *vertices);
    void scale(std::vector<Vector3> *vertices);
    void transform(std::vector<Vector3> *vertices);
    void rotate(std::vector<Vector3> *vertices);
    void deform(std::vector<Vector3> *vertices);
};

}

#endif
