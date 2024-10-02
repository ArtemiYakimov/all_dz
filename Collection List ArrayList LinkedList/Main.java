class Node {
    Integer data;
    Node next;

    Node(Integer data) {
        this.data = data;
        this.next = null;
    }
}

class LinkedList {
    private Node head;

    // Метод для добавления элемента в конец списка
    public void add(Integer data) {
        Node newNode = new Node(data);
        if (head == null) {
            head = newNode;
        } else {
            Node current = head;
            while (current.next != null) {
                current = current.next;
            }
            current.next = newNode;
        }
    }

    // Метод для замены первого и последнего элементов местами
    public LinkedList swapFirstAndLast() {
        if (head == null || head.next == null) {
            // Если список пуст или содержит только один элемент
            return this;
        }

        Node first = head;
        Node last = head;
        Node secondLast = null;

        // Ищем последний и предпоследний элементы
        while (last.next != null) {
            secondLast = last;
            last = last.next;
        }

        // Меняем местами данные первого и последнего элементов
        Integer temp = first.data;
        first.data = last.data;
        last.data = temp;

        return this;
    }

    // Метод для отображения списка
    public void printList() {
        Node current = head;
        while (current != null) {
            System.out.print(current.data + " ");
            current = current.next;
        }
        System.out.println();
    }
}

public class Main {
    public static void main(String[] args) {
        LinkedList list = new LinkedList();
        list.add(1);
        list.add(2);
        list.add(3);
        list.add(4);
        list.add(5);

        System.out.println("Исходный список:");
        list.printList();

        list.swapFirstAndLast();

        System.out.println("Список после замены местами:");
        list.printList();
    }
}
