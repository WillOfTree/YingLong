/**
 * 所有类继承的父类，除了资源节点
 */
#ifndef __JsonLoadManager_CPP_H__
#define __JsonLoadManager_CPP_H__

#include <godot_cpp/classes/file_access.hpp>
#include <godot_cpp/classes/json.hpp>

#include "main_node.h"

using namespace godot;

class JsonLoadManager : public A_MainNode
{
    GDCLASS(JsonLoadManager, A_MainNode);

public:
    void initialize();
    Dictionary get_json_data(String key); // 根据key获取json数据

protected:
    static void _bind_methods();

private:
    String m_json_path = "res://script/json/64gua_mark.json"; // json路径
    Dictionary m_json; // json对象
    // JSON m_json_object;
    Ref<FileAccess> f = nullptr; // 文件指针

    // 资源设置
    void set_json_path(String a);
    String get_json_path();

};
#endif