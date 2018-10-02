﻿//
// Лабораторная работа №8. Классы. Конструктор копирования
// dyn_array.h
//
#pragma once
#include <iostream>
class dyn_array
{
public:
    // Тип данных, хранящийся в массиве
    typedef double datatype;

private:
    // Указатель на массив
    datatype *data;

    // Количество элементов в массиве
    int size;

    // Функция копирования знасений из массива в массив
    void copy(const datatype *from, datatype* to, int size);

public:

    /*
    Инициализация
    */

    // Конструктор по умолчанию
    dyn_array();

    // Конструктор от размера
    dyn_array(int size);

    // Деструктор
    ~dyn_array();

    // Конструктор копии
    dyn_array(const dyn_array& d);

    /*
    Операции
    */

    // Операция присваивания
    dyn_array &operator=(const dyn_array& d);

    // Операция доступа к элементам
    datatype &operator[](int index)
	{
			return data[index];
	}

    // Операция доступа к элементам для чтения
    datatype operator[](int index) const
	{
		return data[index];
	}


    /*
    Методы
    */

    // Количество элементов в массиве
	int count() const { return size; };

    // Изменение размера массива
    void resize(int new_size);

    // Добавление элемента в конец массива
    // с увеличением размера массива
    void append(const datatype &x);

    // Вставка элемента по заданному индексу
    void insert(int index, const datatype &x);

    // Удаление элемента по заджанному индексу
    void remove(int index);

    // Поиск заданного элемента
    int find(const datatype &x) const;

	// ввод из фаила
	friend std::istream &operator>>(std::istream &is, dyn_array &p);
	friend std::ostream &operator<<(std::ostream &os, const dyn_array &p);
};
