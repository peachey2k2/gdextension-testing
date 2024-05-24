@tool
class_name TestNode extends Node

enum TestEnum {foo, bar, asd}

@export var real_enum_variable:TestEnum = TestEnum.foo
@export_enum("foo", "bar", "asd") var fake_enum_variable:int = TestEnum.foo
@export var typed_array:Array[Rect2] = []
@export var typed_custom_class_array:Array[Resource] = []

@export var test:bool:
	set(val):
		print(JSON.stringify(get_property_list(), "\t", false))
