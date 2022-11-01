/**
  * target_include_directories(a.out PUBLIC glm/include/glm/)
  * then here glm/vec3.hpp is right 
  */

#include <glm/vec3.hpp> // this will be searched in PUBLIC ../..
#include <iostream>

inline std::ostream &operator<<(std::ostream &os, glm::vec3 const &v){
    return os << v.x << ' ' << v.y << ' ' << v.z;
}

int main() {
    glm::vec3 v(1, 2, 3);
    v += 1;
    std::cout << v << std::endl;
    return 0;

}
