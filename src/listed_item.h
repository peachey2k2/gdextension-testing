#ifndef LISTED_ITEM_H
#define LISTED_ITEM_H

#include <godot_cpp/classes/ref_counted.hpp>

namespace godot {

class ListedItem : public RefCounted {
    GDCLASS(ListedItem, RefCounted);

protected:
    static void _bind_methods();

};

}

#endif // LISTED_ITEM_H