#include "fzf_list.h"
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/variant/utility_functions.hpp>

using namespace godot;

void FuzzyFindList::initialize_internal_nodes() {
    item_list = memnew(ItemList);
    item_list->set_v_size_flags(SIZE_EXPAND_FILL);
    add_child(item_list, false, Node::INTERNAL_MODE_FRONT);

    search_box = memnew(LineEdit);
    add_child(search_box, false, Node::INTERNAL_MODE_FRONT);
}

FuzzyFindList::FuzzyFindList() {
    initialize_internal_nodes();

    UtilityFunctions::print(get_child_count(true));
    
    Error err = search_box->connect("text_changed", Callable(this, "_on_search_box_text_changed"));
    if (err) UtilityFunctions::printerr("Error connecting \"text_changed\". Code: " + err);
}

FuzzyFindList::~FuzzyFindList() {
}

void FuzzyFindList::_on_search_box_text_changed(String p_text) {
    UtilityFunctions::print("Text changed to: " + p_text);
}


void FuzzyFindList::_bind_methods() {
    ClassDB::bind_method(D_METHOD("_on_search_box_text_changed", "p_text"), &FuzzyFindList::_on_search_box_text_changed);

    ClassDB::bind_method(D_METHOD("get_item_list"), &FuzzyFindList::get_item_list);
    ClassDB::bind_method(D_METHOD("get_search_box"), &FuzzyFindList::get_search_box);

    // below are the exported properties
    ClassDB::bind_method(D_METHOD("set_search_bar_position"), &FuzzyFindList::set_search_bar_position);
    ClassDB::bind_method(D_METHOD("get_search_bar_position"), &FuzzyFindList::get_search_bar_position);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "search_bar_position", PROPERTY_HINT_ENUM, "Top, Bottom"), "set_search_bar_position", "get_search_bar_position");

}

ItemList *FuzzyFindList::get_item_list() {
    return item_list;
}

LineEdit *FuzzyFindList::get_search_box() {
    return search_box;
}

void FuzzyFindList::set_search_bar_position(int p_value) {
    search_bar_position = p_value;
    switch (search_bar_position) {
        case TOP:
            move_child(search_box, 0);
            break;
        case BOTTOM:
            move_child(search_box, -1);
            break;
    }
}

int FuzzyFindList::get_search_bar_position() {
    return search_bar_position;
}
