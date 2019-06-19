#pragma once
#include <vector>
#include <string>
#include <glm/glm.hpp>
#include "OctreeFile.h"

// TODO: W OctreeFile zrobi� drzewo wska�nik�w (node to Node)
// na za�adowane dane octreeFile_, na po�redniczace woksele oczywi�cie te�,
// ale doda� do nich pozycje, kolor [, normalne].
class InnerNode;

class Octree
{
public:    
    class Node
    {
    public:
        Node() {}

        void addChild(std::unique_ptr<Node>& node)
        {
            children.push_back(std::move(node));
        }

    private:
        std::vector<std::unique_ptr<Node>> children;
        InnerNode* parent = nullptr;
    };

    class InnerNode : public Node
    {
    public:
        InnerNode() {}
    };

    class OuterNode : public Node
    {
    public:
        OuterNode() {}
    };

    Octree(OctreeFile& octreeFile);
    
    std::unique_ptr<Node> loadNodesRecursively(OctreeFile::Node& dataNode, Node& parentOctreeNode);

private:
    std::unique_ptr<Node> rootNode_;

    OctreeFile& octreeFile_;
};