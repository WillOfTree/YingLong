#include "../include/json_load_manager.h"

void JsonLoadManager::_bind_methods()
{
    // 初始化方�?
    ClassDB::bind_method(D_METHOD("initialize"), &JsonLoadManager::initialize);
    ClassDB::bind_method(D_METHOD("get_json_use_key", "a"), &JsonLoadManager::get_json_data);

    ClassDB::bind_method(D_METHOD("set_json_path", "a"), &JsonLoadManager::set_json_path);
    ClassDB::bind_method(D_METHOD("get_json_path"), &JsonLoadManager::get_json_path);
    ClassDB::add_property("JsonLoadManager",
        PropertyInfo(Variant::STRING, "Json Path"),
        "set_json_path",
        "get_json_path");

    // json 文件
    // ClassDB::bind_method(D_METHOD("set_json_object", "a"), &JsonLoadManager::set_json_object);
    // ClassDB::bind_method(D_METHOD("get_json_object"), &JsonLoadManager::get_json_object);
    // ClassDB::add_property("JsonLoadManager",
    //     PropertyInfo(Variant::OBJECT, "Json Object"),
    //     "set_json_object",
    //     "get_json_object");
}


void JsonLoadManager::set_json_path(String a)
{
    m_json_path = a;
};
String JsonLoadManager::get_json_path()
{
    return m_json_path;
};


/**
 * 根据key返回json字典，没找到key返回nullptr
 */
Dictionary JsonLoadManager::get_json_data(String key)
{
    return m_json.get(key, nullptr);
}


/**
 * 初始化方法
 */
void JsonLoadManager::initialize()
{
    // 打开文件
    f = FileAccess::open(m_json_path, FileAccess::READ);
    String a = f->get_as_text();

    // 转换文本为json对象,并存放到指定变量中
    m_json = JSON::parse_string(a);

    f->close();
};