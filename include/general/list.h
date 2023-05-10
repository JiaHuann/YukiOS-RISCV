/*
 * notice that this list does not perform any lock action, if you need please
 * add lock for your list personal
 */

#include <kernel/types.h>
#include <general/poison.h>


#define LIST_HEAD_INIT(name) { &(name), &(name) }

#define LIST_HEAD(name) \
        struct list_head name = LIST_HEAD_INIT(name)

static inline void INIT_LIST_HEAD(struct list_head *list){
        list->next = list;
        list->prev = list;
}

static inline void __list_add(struct list_head *new,
                              struct list_head *prev,
                              struct list_head *next){
        next->prev = new;
        new->next = next;
        new->prev = prev;
        prev->next = new;
}

static inline void list_add(struct list_head *new,
                            struct list_head *head){
        __list_add(new, head, head->next);
}

static inline void list_add_tail(struct list_head *new,
                               struct list_head *head){
        __list_add(new, head->prev, head);
}

static inline void __list_del(struct list_head *prev,
                            struct list_head *next)
{
        next->prev = prev;
        prev->next = next;
}

static inline void __list_del_allprev(struct list_head *item)
{
        __list_del(item->prev, item->next);
        item->prev = NULL;
}

static inline void __list_del_entry(struct list_head *entry)
{
        __list_del(entry->prev, entry->next);
}

static inline void list_del(struct list_head *entry)
{
        __list_del_entry(entry);
        entry->prev = LIST_POISON_P;
        entry->next = LIST_POISON_N;
}

static inline void list_replace(struct list_head *old,
                                struct list_head *new)
{
        new->next = old->next;
        new->next->prev = new;
        new->prev = old->prev;
        new->prev->next = new;
}

static inline void list_swap(struct list_head *item1,
                             struct list_head *item2)
{
        struct list_head *pos = item2->prev;

        list_del(item2);
        list_replace(item1, item2);
        if (pos == item1)
                pos = item2;
        list_add(item1, pos);
}

static inline bool is_list_empty(const struct list_head *list)
{
        return list->next == list;
}

#define list_entry(ptr, type, member) \
        containerof(ptr, type, member)


