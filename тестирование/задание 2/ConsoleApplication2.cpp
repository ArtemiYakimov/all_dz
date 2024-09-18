#include <catch2/catch_test_macros.hpp>
#include <iostream>
#include <Windows.h>

struct ListNode
{
public:
    ListNode(int value, ListNode* prev = nullptr, ListNode* next = nullptr)
        : value(value), prev(prev), next(next)
    {
        if (prev != nullptr) prev->next = this;
        if (next != nullptr) next->prev = this;
    }

public:
    int value;
    ListNode* prev;
    ListNode* next;
};


class List
{
public:
    List()
        : m_head(new ListNode(static_cast<int>(0))), m_size(0),
        m_tail(new ListNode(0, m_head))
    {
    }

    virtual ~List()
    {
        Clear();
        delete m_head;
        delete m_tail;
    }

    bool Empty() { return m_size == 0; }

    unsigned long Size() { return m_size; }

    void PushFront(int value)
    {
        new ListNode(value, m_head, m_head->next);
        ++m_size;
    }

    void PushBack(int value)
    {
        new ListNode(value, m_tail->prev, m_tail);
        ++m_size;
    }

    int PopFront()
    {
        if (Empty()) throw std::runtime_error("list is empty");
        auto node = extractPrev(m_head->next->next);
        int ret = node->value;
        delete node;
        return ret;
    }

    int PopBack()
    {
        if (Empty()) throw std::runtime_error("list is empty");
        auto node = extractPrev(m_tail);
        int ret = node->value;
        delete node;
        return ret;
    }

    void Clear()
    {
        auto current = m_head->next;
        while (current != m_tail)
        {
            current = current->next;
            delete extractPrev(current);
        }
    }

private:
    ListNode* extractPrev(ListNode* node)
    {
        auto target = node->prev;
        target->prev->next = target->next;
        target->next->prev = target->prev;
        --m_size;
        return target;
    }

private:
    ListNode* m_head;
    ListNode* m_tail;
    unsigned long m_size;
};

TEST_CASE("checking list", "[class List]") {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    List list;

    SECTION("Этап 0. Проверка что список пуст") {

        INFO("Список не является пустым ...");
        CHECK(list.Empty() == true);
        CHECK(list.Size() == 0);

    }

    SECTION("Этап 1. Пробуем удалять элементы из пустого списока") {

        INFO("Я как-то не увидел, чтобы мы учились правильно реагировать на ошибки, видимо так и нужно");
        CHECK_THROWS(list.PopBack() == 0);
        CHECK_THROWS(list.PopFront() == 0);
        //CHECK(list.PopBack() == 0);
        //CHECK(list.PopFront() == 0);

    }

    list.PushFront(1);  // [1]                  // а то я сам уже запутался ...
    list.PushBack(5);   // [1, 5]
    list.PushFront(2);  // [2, 1, 5]
    list.PushBack(6);   // [2, 1, 5, 6]
    list.PushFront(3);  // [3, 2, 1, 5, 6]
    list.PushBack(7);   // [3, 2, 1, 5, 6, 7]

    SECTION("Этап 2. Проверка на заполненность списока") {

        INFO("Должно было добавиться 6 элементов");
        CHECK(list.Size() == 6);

        INFO("Список не должен быть пустым !");
        CHECK(list.Empty() == false);

    }

    SECTION("Этап 3. Очистика 2-х элементов с конца") {
        CHECK(list.PopBack() == 7);
        CHECK(list.PopBack() == 6);

        INFO("После 2-х удалений, в списке должно остаться 4");
        CHECK(list.Size() == 4);
    }

    SECTION("Этап 4. Очистика 4-х элементов с начала") {
        CHECK(list.PopFront() == 3);
        CHECK(list.PopFront() == 2);
        CHECK(list.PopFront() == 1);
        CHECK(list.PopFront() == 5);

        INFO("После 4-х удалений, в списке должно остаться 2");
        CHECK(list.Size() == 2);
    }

    SECTION("Этап 5. Очистка списка, и попеременное добавление и удаление элементов") {
        list.Clear();

        // добавил в конец, удалил в начале
        list.PushBack(5);
        CHECK(list.PopFront() == 5);

        // добавил в начале, удалил в конце
        list.PushFront(1);
        CHECK(list.PopBack() == 1);

        // а если несколько раз ?
        list.PushBack(11);
        list.PushBack(12);
        CHECK(list.PopFront() == 11);
        CHECK(list.PopBack() == 12);


        INFO("Всё что добавили должно было удалиться!");
        CHECK(list.Size() == 0);
    }

    /*
    * Вот на этом моменте, я вообще выпал из реальности ...
    * Получается так, что каждый модуль SECTION, отдельно
    * двигается дальше по иписку, игнорируя другие SECTION ???
    *
    * После "Этап 3", код дошёл до этого условия и выдал ошибку, что : 4 != 6
    * После "Этап 4", код дошёл до этого условия и выдал ошибку, что : 2 != 6
    * После "Этап 5", код дошёл до этого условия и выдал ошибку, что : 0 != 6
    *
        INFO("Длинна не должна была измениться!");
        CHECK(list.Size() == 6);
    */

    SECTION("Этап 5. Очистка списка") {
        list.Clear();
        INFO("Удаление всех эл-тов потерпело крах ... =(");
        CHECK(list.Size() == 0);
    }
}