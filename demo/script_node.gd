extends Node

# JsonLoadManager管理器
@onready var json_load = $"../JsonLoadManager"
# 内容添加
@onready var other_position = %other
@onready var title_position = %title
@onready var content_positon = %Content

# 页面
@onready var start_panel = %StartPanel
@onready var process_panal = $"../UI/PanelContainer"

# 动画
@onready var animation = %AnimationPlayer


# Called when the node enters the scene tree for the first time.
func _ready() -> void:
	json_load.initialize();
	pass # Replace with function body.


# 开始屏幕按钮按下
func _on_button_button_down() -> void:
	# 动画
	animation.play("new_animation") # 隐藏开始屏幕动画
	await  animation.animation_finished
	animation.play("new_animation_2") # 显示主页面动画
	
	# 按钮隐藏，不可点
	start_panel.hide();
	
	
	# 获取随机数
	var a = randi_range(1, 64);
	var b = json_load.get_json_use_key(var_to_str(a));
	
	# 设置标题内容
	title_position.get_node("mark").set_text(b["signal"])
	title_position.get_node("text").set_text(b["name"]);
	# 设置杂卦、其他
	other_position.set_text(b["za_gua"]);
	# 设置卦辞
	content_positon.get_node("VBoxContainer/title").set_text(b["gua_ci"])
	# 设置爻辞
	content_positon.get_node("VBoxContainer/one").set_text(b["yao_ci_1"])
	content_positon.get_node("VBoxContainer/two").set_text(b["yao_ci_2"])
	content_positon.get_node("VBoxContainer/three").set_text(b["yao_ci_3"])
	content_positon.get_node("VBoxContainer/four").set_text(b["yao_ci_4"])
	content_positon.get_node("VBoxContainer/five").set_text(b["yao_ci_5"])
	content_positon.get_node("VBoxContainer/six").set_text(b["yao_ci_6"])
	
	pass # Replace with function body.
	
	
func _on_button_down_return() -> void:
	#print("xxxxxxxx")
	start_panel.show()
	
	animation.play("content_disappear")
	await animation.animation_finished
	animation.play("title_display")
	pass
