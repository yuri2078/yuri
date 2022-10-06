#ifndef MY_COMPONENTS
#define MY_COMPONENTS

#include "cyber/cyber.h"
#include "cyber/component/component.h"
#include "cyber/demo_cpp/components/Student.pb.h"

using apollo::cyber::Component;
using apollo::cyber::demo_cpp::Student;

class my_components : public Component<Student>
{
private:
    /* data */
public:

    bool Init() override;
    bool Proc(const std::shared_ptr<Student> &stu) override;
    
};

CYBER_REGISTER_COMPONENT(my_components) //注册组件
#endif