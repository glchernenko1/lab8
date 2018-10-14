﻿//
// Лабораторная работа №8. Классы. Конструктор копирования
// dyn_array.h
//
#pragma once
#include <iostream>
#include <string>


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

	//swap
	void swap(dyn_array &a);
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

    // Конструктор копии (перемещаюший)
    dyn_array( dyn_array &&d);
    dyn_array(const dyn_array & d);
    /*
    Операции
    */

    // Операция присваивания (перемещаюший)
    dyn_array &operator=(dyn_array d);

	

	dyn_array &operator=(dyn_array &&d);


    // Операция доступа к элементам
    datatype &operator[](int index)
	{

		try {
			if (index >= size) throw std::out_of_range("Выход за пределы массива!!! ");
			return data[index];
		}
		catch (std::out_of_range a)
		{
			std::cout << a.what();
		}
	}

    // Операция доступа к элементам для чтения
    datatype operator[](int index) const
	{
		try {
			if (index >= size) throw std::out_of_range("Выход за пределы массива!!! ");
		return data[index];
	}
	catch (std::out_of_range a)
	{
		std::cout << a.what();
	}
	}


    /*
    Методы
    */
	//сортировка массива (a=true по возрастанию)
	void sort(bool a = true);
	//удаление дубликатов 
	void unique();
	// добовление в конец строки другого массива
	void append(dyn_array &a);

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

	//сравнение на равенство
	friend bool operator==(dyn_array a, dyn_array b);
};
