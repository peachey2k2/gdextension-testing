#ifndef FZF_LIST_H
#define FZF_LIST_H

#include <godot_cpp/classes/v_box_container.hpp>
#include <godot_cpp/classes/item_list.hpp>
#include <godot_cpp/classes/line_edit.hpp>
#include <godot_cpp/classes/json.hpp>
#include <godot_cpp/classes/object.hpp>

namespace godot {

class FuzzyFindList : public VBoxContainer {
    GDCLASS(FuzzyFindList, VBoxContainer);

public:
    enum SearchBarPosition {
        TOP, BOTTOM
    };

private:
    // internal nodes
    ItemList *item_list;
    LineEdit *search_box;

    // exported properties
    SearchBarPosition search_bar_position = BOTTOM;
    Array items;

    // signal handlers
    void _on_search_box_text_changed(String);

    // internal methods
    void initialize_internal_nodes();

protected:
    static void _bind_methods();

public:
    FuzzyFindList();
    ~FuzzyFindList();

    ItemList *get_item_list();
    LineEdit *get_search_box();

    void set_search_bar_position(SearchBarPosition);
    SearchBarPosition get_search_bar_position();

    void set_items(Array);
    Array get_items();

};

}

VARIANT_ENUM_CAST(FuzzyFindList::SearchBarPosition);

#endif // FZF_LIST_H