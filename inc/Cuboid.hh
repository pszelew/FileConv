#ifndef CUBOID_HH
#define CUBOID_HH
#include "MobileObject.hh"

class Cuboid: public MobileObject
{        
    public:
        Cuboid(std::string in_name, double in_rot_z, Vector3D in_pos): MobileObject(in_name, in_rot_z, in_pos) {};
        Cuboid(){};
        std::string Name() const { return name; }
        std::string& Name() { return name; }
        double Rot_z() const{ return rot_z; }
        double& Rot_z() { return rot_z; }
        Vector3D Pos() const { return pos; }
        Vector3D& Pos() { return pos; }

};


#endif